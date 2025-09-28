package dsrl

import (
	"encoding/binary"
	"errors"
	"fmt"
	"math"
	"reflect"
)

// Give 4 bytes get a float32. or get garbage
func bytesToFloat32(b []byte) float32 {
    bits := binary.LittleEndian.Uint32(b) 
    return math.Float32frombits(bits)
}

// Give 8 bytes get a float64, or get garbage
func bytesToFloat64(b []byte) float64 {
    bits := binary.LittleEndian.Uint64(b) 
    return math.Float64frombits(bits)
}

// Decode returns a deserialized value of the given type (‘valueType’) by reading from buf at offset *head, and advances *head.
// Strings are treated as C-strings (null-terminated). Integers and unsigned are unified.
func Decode(buf []byte, head *int, valueType reflect.Type) (any, error) {
	// Create a new value of that type (possibly a pointer if typ is pointer)
	rvPtr := reflect.New(valueType) // a *T
	rv := rvPtr.Elem()              // the T (or underlying)
	if err := decodeValue(buf, head, rv); err != nil {
		return nil, err
	}
	return rv.Interface(), nil
}

// decodeValue decodes data into the reflect.Value rv. It assumes rv is addressable, settable.
func decodeValue(buf []byte, head *int, rv reflect.Value) error {
	if !rv.CanSet() {
		return fmt.Errorf("cannot set value for kind %s", rv.Kind())
	}
	kind := rv.Kind()

	readBytes := func(n int) ([]byte, error) {
		if *head+n > len(buf) {
			return nil, fmt.Errorf("buffer overrun: need %d bytes, have %d", n, len(buf)-*head)
		}
		b := buf[*head : *head+n]
		*head += n
		return b, nil
	}

	switch kind {
	case reflect.Bool:
		b, err := readBytes(1)
		if err != nil {
			return err
		}
		rv.SetBool(b[0] != 0)
		return nil


	// case reflect.Int, reflect.Int8, reflect.Int16, reflect.Int32, reflect.Int64:
	// 	bitSize := rv.Type().Bits()
	// 	byteCount := int(bitSize / 8)
	// 	if byteCount == 0 {
	// 		byteCount = 1
	// 	}
	// 	b, err := readBytes(byteCount)
	// 	if err != nil {
	// 		return err
	// 	}
	// 	var u uint64
	// 	switch byteCount {
	// 	case 1:
	// 		u = uint64(b[0])
	// 	case 2:
	// 		u = uint64(order.Uint16(b))
	// 	case 4:
	// 		u = uint64(order.Uint32(b))
	// 	case 8:
	// 		u = order.Uint64(b)
	// 	default:
	// 		return fmt.Errorf("unsupported int size: %d bytes", byteCount)
	// 	}
	// 	// convert to signed
	// 	var signed int64
	// 	switch byteCount {
	// 	case 1:
	// 		signed = int64(int8(u))
	// 	case 2:
	// 		signed = int64(int16(u))
	// 	case 4:
	// 		signed = int64(int32(u))
	// 	case 8:
	// 		signed = int64(u)
	// 	}
	// 	rv.SetInt(signed)
	// 	return nil

	case reflect.Uint, reflect.Uint8, reflect.Uint16, reflect.Uint32, reflect.Uint64:
		bitSize := rv.Type().Bits()
		byteCount := int(bitSize / 8)
		if byteCount == 0 {
			byteCount = 1
		}
		b, err := readBytes(byteCount)
		if err != nil {
			return err
		}
		var u uint64
		switch byteCount {
		case 1:
			u = uint64(b[0])
		case 2:
			u = uint64(binary.LittleEndian.Uint16(b))
		case 4:
			u = uint64(binary.LittleEndian.Uint32(b))
		case 8:
			u = binary.LittleEndian.Uint64(b)
		default:
			return fmt.Errorf("unsupported uint size: %d bytes", byteCount)
		}
		rv.SetUint(u)
		return nil

	case reflect.Float32:
		b, err := readBytes(4)
		if err != nil {
			return err
		}
		rv.SetFloat(float64(bytesToFloat32(b)))
		return nil

	case reflect.Float64:
		b, err := readBytes(8)
		if err != nil {
			return err
		}
		rv.SetFloat(bytesToFloat64(b))
		return nil

	case reflect.String:
		start := *head
		for *head < len(buf) {
			if buf[*head] == 0 {
				break
			}
			*head++
		}
		if *head >= len(buf) {
			return errors.New("unterminated C string")
		}
		s := string(buf[start:*head])
		rv.SetString(s)
		*head++ // skip null terminator
		return nil

	// case reflect.Pointer:
	// 	b, err := readBytes(1)
	// 	if err != nil {
	// 		return err
	// 	}
	// 	if b[0] == 0 {
	// 		// nil pointer
	// 		rv.Set(reflect.Zero(rv.Type()))
	// 		return nil
	// 	}
	// 	newVal := reflect.New(rv.Type().Elem())
	// 	rv.Set(newVal)
	// 	return decodeValue(buf, head, order, newVal.Elem())

	default:
		return fmt.Errorf("unsupported kind %s", kind)
	}
}
