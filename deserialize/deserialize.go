package deserialize

import (
	"encoding/binary"
	"errors"
	"fmt"
	"math"
)

type Values struct {
	Name string
	Val  any
}

// bytesToFloat32 converts 4 bytes to a float32 using little-endian encoding.
func bytesToFloat32(b []byte) float32 {
	bits := binary.LittleEndian.Uint32(b)
	return math.Float32frombits(bits)
}

// bytesToFloat64 converts 8 bytes to a float64 using little-endian encoding.
func bytesToFloat64(b []byte) float64 {
	bits := binary.LittleEndian.Uint64(b)
	return math.Float64frombits(bits)
}

// Decode returns a deserialized value of the given type (‘valueType’) by reading from buf at offset *head,
// and advances *head. Strings are treated as C-strings (null-terminated).
func Decode(buf []byte, head *int, value any) (any, error) {
	readBytes := func(n int) ([]byte, error) {
		if *head+n > len(buf) {
			return nil, errors.New("buffer overrun: insufficient bytes in buffer")
		}
		b := buf[*head : *head+n]
		*head += n
		return b, nil
	}

	switch v := value.(type) {
	case bool:
		b, err := readBytes(1)
		if err != nil {
			return nil, err
		}
		return (b[0] != 0), nil

	case int8:
		b, err := readBytes(1)
		if err != nil {
			return nil, err
		}
		return int8(b[0]), nil

	case int16:
		b, err := readBytes(2)
		if err != nil {
			return nil, err
		}
		u := binary.LittleEndian.Uint16(b)
		return int16(u), nil

	case int32:
		b, err := readBytes(4)
		if err != nil {
			return nil, err
		}
		u := binary.LittleEndian.Uint32(b)
		return int32(u), nil

	case int64:
		b, err := readBytes(8)
		if err != nil {
			return nil, err
		}
		u := binary.LittleEndian.Uint64(b)
		return int64(u), nil

	case uint8:
		b, err := readBytes(1)
		if err != nil {
			return nil, err
		}
		return uint8(b[0]), nil

	case uint16:
		b, err := readBytes(2)
		if err != nil {
			return nil, err
		}
		u := binary.LittleEndian.Uint16(b)
		return u, nil

	case uint32:
		b, err := readBytes(4)
		if err != nil {
			return nil, err
		}
		u := binary.LittleEndian.Uint32(b)
		return u, nil

	case uint64:
		b, err := readBytes(8)
		if err != nil {
			return nil, err
		}
		u := binary.LittleEndian.Uint64(b)
		return u, nil

	case float32:
		b, err := readBytes(4)
		if err != nil {
			return nil, err
		}
		return bytesToFloat32(b), nil

	case float64:
		b, err := readBytes(8)
		if err != nil {
			return nil, err
		}
		return bytesToFloat64(b), nil

	case string:
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

	case []Values:
		val := v
		err := DecodeValue(&val, buf, head)
		if err != nil {
			return nil, err
		}
		return val, nil

	default:
		return nil, errors.New("unsupported kind for Decode")
	}
}

// DecodeValue recursively decodes all entries in a slice of Values.
func DecodeValue(structure *[]Values, buffer []byte, head *int) error {
	for i := range *structure {
		val, err := Decode(buffer, head, (*structure)[i].Val)
		if err != nil {
			id := fmt.Sprintf(" Id: %d] ", i)
			return errors.New("error decoding buffer: " + err.Error() + id)
		}
		(*structure)[i].Val = val
	}
	return nil
}

// DeepEqualValues recursively compares two slices of Values.
// It does not use reflect — only type assertions and recursion.
func DeepEqualValues(a, b []Values) bool {
	if len(a) != len(b) {
		return false
	}

	for i := range a {
		if a[i].Name != b[i].Name {
			return false
		}

		switch av := a[i].Val.(type) {
		case []Values:
			bv, ok := b[i].Val.([]Values)
			if !ok {
				return false
			}
			if !DeepEqualValues(av, bv) {
				return false
			}

		case string:
			bv, ok := b[i].Val.(string)
			if !ok || av != bv {
				return false
			}

		case int:
			bv, ok := b[i].Val.(int)
			if !ok || av != bv {
				return false
			}

		case int32:
			bv, ok := b[i].Val.(int32)
			if !ok || av != bv {
				return false
			}

		case int64:
			bv, ok := b[i].Val.(int64)
			if !ok || av != bv {
				return false
			}

		case float32:
			bv, ok := b[i].Val.(float32)
			if !ok || av != bv {
				return false
			}

		case float64:
			bv, ok := b[i].Val.(float64)
			if !ok || av != bv {
				return false
			}

		case bool:
			bv, ok := b[i].Val.(bool)
			if !ok || av != bv {
				return false
			}

		case nil:
			if b[i].Val != nil {
				return false
			}

		default:
			// Unknown type – must match by type and pointer
			if av != b[i].Val {
				return false
			}
		}
	}

	return true
}

func GetDefaultVal(dataType string) (any, error) {
	switch dataType {
	case "int8":
		{
			return int8(0), nil
		}
	case "int16":
		{
			return int16(0), nil
		}
	case "int32":
		{
			return int32(0), nil
		}
	case "int64":
		{
			return int64(0), nil
		}
	case "uint8":
		{
			return uint8(0), nil
		}
	case "uint16":
		{
			return uint16(0), nil
		}
	case "uint32":
		{
			return uint32(0), nil
		}
	case "uint64":
		{
			return uint64(0), nil
		}
	case "float32":
		{
			return float32(0.0), nil
		}
	case "float64":
		{
			return float64(0.0), nil
		}
	case "cstring":
		{
			return string(""), nil
		}
	case "null":
		{
			return int8(0x78), nil
		}
	default:
		{
			return nil, fmt.Errorf("Non std dataType found %s", dataType)
		}
	}
}
