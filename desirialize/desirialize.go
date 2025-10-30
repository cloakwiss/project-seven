package desirialize

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
