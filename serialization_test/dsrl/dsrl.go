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
	fmt.Printf("float32 bytes: %v\n", b)
	bits := binary.LittleEndian.Uint32(b)
	return math.Float32frombits(bits)
}

// Give 8 bytes get a float64, or get garbage
func bytesToFloat64(b []byte) float64 {
	fmt.Printf("float64 bytes: %v\n", b)
	bits := binary.LittleEndian.Uint64(b)
	return math.Float64frombits(bits)
}

// Decode returns a deserialized value of the given type (‘valueType’) by reading from buf at offset *head, and advances *head.
// Strings are treated as C-strings (null-terminated). Integers and unsigned are unified.
func Decode(buf []byte, head *int, valueType reflect.Type) (any, error) {

	readBytes := func(n int) ([]byte, error) {
		if *head+n > len(buf) {
			return nil, fmt.Errorf("buffer overrun: need %d bytes, have %d", n, len(buf)-*head)
		}
		b := buf[*head : *head+n]
		*head += n
		return b, nil
	}

	switch valueType.Kind() {
	case reflect.Bool:
		b, err := readBytes(1)
		if err != nil {
			return nil, err
		}
		return (b[0] != 0), nil

	case reflect.Int8:
		b, err := readBytes(1)
		if err != nil {
			return nil, err
		}
		return int8(b[0]), nil

	case reflect.Int16:
		b, err := readBytes(2)
		if err != nil {
			return nil, err
		}
		u := binary.LittleEndian.Uint16(b)
		return int16(u), nil

	case reflect.Int32:
		b, err := readBytes(4)
		if err != nil {
			return nil, err
		}
		u := binary.LittleEndian.Uint32(b)
		return int32(u), nil

	case reflect.Int64:
		b, err := readBytes(8)
		if err != nil {
			return nil, err
		}
		u := binary.LittleEndian.Uint64(b)
		return int64(u), nil

	case reflect.Uint8:
		b, err := readBytes(1)
		if err != nil {
			return nil, err
		}
		return uint8(b[0]), nil

	case reflect.Uint16:
		b, err := readBytes(2)
		if err != nil {
			return nil, err
		}
		u := binary.LittleEndian.Uint16(b)
		return u, nil

	case reflect.Uint32:
		b, err := readBytes(4)
		if err != nil {
			return nil, err
		}
		u := binary.LittleEndian.Uint32(b)
		return u, nil

	case reflect.Uint64:
		b, err := readBytes(8)
		if err != nil {
			return nil, err
		}
		u := binary.LittleEndian.Uint64(b)
		return u, nil

	case reflect.Float32:
		b, err := readBytes(4)
		if err != nil {
			return nil, err
		}
		return bytesToFloat32(b), nil

	case reflect.Float64:
		b, err := readBytes(8)
		if err != nil {
			return nil, err
		}
		return bytesToFloat64(b), nil

	case reflect.String:
		start := *head
		for *head < len(buf) {
			if buf[*head] == 0 {
				break
			}
			*head++
		}
		if *head >= len(buf) {
			return nil, errors.New("unterminated C string")
		}
		s := string(buf[start:*head])
		*head++
		return s, nil

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
		return nil, fmt.Errorf("unsupported kind %s", valueType.Kind())
	}
}
