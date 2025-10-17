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
	"unsafe"

	"serialization_test/dsrl"
)

func NewPoint2D() []dsrl.StructField {
	var x, y float32 = 0.0, 0.0
	fields := make([]dsrl.StructField, 2)

	fields[0].Name = "x"
	fields[0].Val = x

	fields[1].Name = "y"
	fields[1].Val = y

	return fields
}

func NewColor() []dsrl.StructField {
	var r, g, b uint8 = 0, 0, 0
	fields := make([]dsrl.StructField, 3)

	fields[0].Name = "r"
	fields[0].Val = r

	fields[1].Name = "g"
	fields[1].Val = g

	fields[2].Name = "b"
	fields[2].Val = b

	return fields
}

func NewLine() []dsrl.StructField {
	fields := make([]dsrl.StructField, 3)

	fields[0].Name = "start"
	fields[0].Val = NewPoint2D()

	fields[1].Name = "end"
	fields[1].Val = NewPoint2D()

	fields[2].Name = "color"
	fields[2].Val = NewColor()

	return fields
}

func NewCircle() []dsrl.StructField {
	fields := make([]dsrl.StructField, 3)

	fields[0].Name = "center"
	fields[0].Val = NewPoint2D()

	fields[1].Name = "radius"
	fields[1].Val = float32(0.0)

	fields[2].Name = "color"
	fields[2].Val = NewColor()

	return fields
}

func NewShapeData() []dsrl.StructField {
	fields := make([]dsrl.StructField, 3)

	fields[0].Name = "point"
	fields[0].Val = nil

	fields[1].Name = "line"
	fields[1].Val = nil

	fields[2].Name = "circle"
	fields[2].Val = nil

	return fields
}

func NewShape() []dsrl.StructField {
	fields := make([]dsrl.StructField, 3)

	fields[0].Name = "type"
	fields[0].Val = nil

	fields[1].Name = "data"
	fields[1].Val = NewShapeData()

	fields[2].Name = "id"
	fields[2].Val = nil

	return fields
}

func NewScene(capShapes int) []dsrl.StructField {
	fields := make([]dsrl.StructField, 2)

	// Shapes is a slice of dsrl.StructField slices
	shapes := make([][]dsrl.StructField, capShapes)
	for i := range shapes {
		shapes[i] = NewShape()
	}

	fields[0].Name = "shapes"
	fields[0].Val = shapes

	fields[1].Name = "shape_count"
	fields[1].Val = nil

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

type HookCall struct {
	name  string
	depth uint64
	args  []dsrl.StructField
}

type HookReturn struct {
	name    string
	depth   uint64
	time    float64
	returns []dsrl.StructField
}

func GetMesssageBoxHookCall() []dsrl.StructField {
	var handle, utype uint32 = 0, 0
	var text, caption string = "", ""
	params := make([]dsrl.StructField, 4)

	params[0].Name = "hWnd"
	params[0].Val = handle

	params[0].Name = "lpText"
	params[0].Val = text

	params[0].Name = "lpCaption"
	params[0].Val = caption

	params[0].Name = "uType"
	params[0].Val = utype

	return params
}

func GetMesssageBoxHookReturn() []dsrl.StructField {
	var result uint32 = 0
	params := make([]dsrl.StructField, 1)

	params[0].Name = "result"
	params[0].Val = result

	return params
}

func main() {
	buffer := getBuffer()
	var head int = 0

	fmt.Printf("Buffer length: %d\n", len(buffer))
	fmt.Printf("Buffer data: %v\n", buffer)

	point := NewPoint2D()
	dsrl.DecodeStructure(&point, buffer, &head)
	fmt.Printf("\nPoint struct that we got: %v\n\n", point)

	color := NewColor()
	dsrl.DecodeStructure(&color, buffer, &head)
	fmt.Printf("\nColor struct that we got: %v\n", color)

	line := NewLine()
	dsrl.DecodeStructure(&line, buffer, &head)
	fmt.Printf("\nLine struct that we got: %v\n", line)

	circle:= NewCircle()
	dsrl.DecodeStructure(&circle, buffer, &head)
	fmt.Printf("\nCircle struct that we got: %v\n", circle)


	fmt.Println("Done!")
}
