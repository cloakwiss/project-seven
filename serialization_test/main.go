package main

/*
#cgo CFLAGS: -O0 -g
#cgo LDFLAGS: -L.\ -lbuffer
#include "buffer_lib.h"
*/
import "C"
import (
	// "encoding/binary"
	"fmt"
	"reflect"
	"unsafe"

	"serialization_test/dsrl"
)

type StructField struct {
	name string
	val  any
}

func NewPoint2D() []StructField {
	var x float64 = 0.0
	var y float32 = 0.0
	fields := make([]StructField, 2)

	fields[0].name = "x"
	fields[0].val = x

	fields[1].name = "y"
	fields[1].val = y

	return fields
}

func NewColor() []StructField {
	var r, g, b uint8 = 0, 0, 0
	fields := make([]StructField, 3)

	fields[0].name = "r"
	fields[0].val = r

	fields[1].name = "g"
	fields[1].val = g

	fields[2].name = "b"
	fields[2].val = b

	return fields
}

func NewLine() []StructField {
	fields := make([]StructField, 3)

	fields[0].name = "start"
	fields[0].val = NewPoint2D()

	fields[1].name = "end"
	fields[1].val = NewPoint2D()

	fields[2].name = "color"
	fields[2].val = NewColor()

	return fields
}

func NewCircle() []StructField {
	fields := make([]StructField, 3)

	fields[0].name = "center"
	fields[0].val = NewPoint2D()

	fields[1].name = "radius"
	fields[1].val = nil

	fields[2].name = "color"
	fields[2].val = NewColor()

	return fields
}

func NewShapeData() []StructField {
	fields := make([]StructField, 3)

	fields[0].name = "point"
	fields[0].val = nil

	fields[1].name = "line"
	fields[1].val = nil

	fields[2].name = "circle"
	fields[2].val = nil

	return fields
}

func NewShape() []StructField {
	fields := make([]StructField, 3)

	fields[0].name = "type"
	fields[0].val = nil

	fields[1].name = "data"
	fields[1].val = NewShapeData()

	fields[2].name = "id"
	fields[2].val = nil

	return fields
}

func NewScene(capShapes int) []StructField {
	fields := make([]StructField, 2)

	// Shapes is a slice of StructField slices
	shapes := make([][]StructField, capShapes)
	for i := range shapes {
		shapes[i] = NewShape()
	}

	fields[0].name = "shapes"
	fields[0].val = shapes

	fields[1].name = "shape_count"
	fields[1].val = nil

	return fields
}

func getBuffer() []byte {
	var length C.u64 = 0
	cBuffer := C.get_buffer(&length)
	defer func() {
		C.free_buffer(cBuffer)
	}()

	return C.GoBytes(unsafe.Pointer(cBuffer), C.int(length))
}

func main() {
	buffer := getBuffer()
	var head int = 0

	fmt.Printf("Buffer length: %d\n", len(buffer))
	fmt.Printf("Buffer data: %v\n", buffer)

	point := NewPoint2D()
	var err error
	for i := range point {
		point[i].val, err = dsrl.Decode(buffer, &head, reflect.TypeOf(point[i].val))
		if err != nil {
			fmt.Printf("WHAT THE FUCK: %v\n", err)
		}
	}
	fmt.Printf("Point struct that we got: %v\n\n", point)

	color := NewColor()
	for i := range color {
		color[i].val, err = dsrl.Decode(buffer, &head, reflect.TypeOf(color[i].val))
		if err != nil {
			fmt.Printf("WHAT THE FUCK: %v\n", err)
		}
	}
	fmt.Printf("Color struct that we got: %v\n", color)

	line := NewLine()
	// NewCircle()
	// NewShapeData()
	// NewShape()
	// NewScene(capShapes int)

	fmt.Println("Done!")
}
