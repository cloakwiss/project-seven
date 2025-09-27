package main

/*
#cgo CFLAGS: -I.
#include "geometry.h"
#include "geometry.c"
#include "buffer.c"
#include <stdint.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t i32;
typedef float f32;
*/
import "C"
import (
	"fmt"
	"unsafe"
)

type ShapeType int32

const (
	ShapePoint  ShapeType = 0
	ShapeLine   ShapeType = 1
	ShapeCircle ShapeType = 2
)

type Point2D struct {
	X float32
	Y float32
}

type Color struct {
	R uint8
	G uint8
	B uint8
}

type Line struct {
	Start Point2D
	End   Point2D
	Color Color
}

type Circle struct {
	Center Point2D
	Radius float32
	Color  Color
}

type ShapeData struct {
	Point  Point2D
	Line   Line
	Circle Circle
}

type Shape struct {
	Type ShapeType
	Data ShapeData
	ID   uint32
}

type Scene struct {
	Shapes     [3]Shape
	ShapeCount uint32
}

func main() {
	fmt.Println("Simple CGO Buffer Test")

	var length C.u64
	cBuffer := C.get_buffer(&length)

	goBuffer := C.GoBytes(unsafe.Pointer(cBuffer), C.int(length))

	fmt.Printf("Buffer length: %d\n", len(goBuffer))
	fmt.Printf("Buffer data: %s\n", goBuffer)

	C.free_buffer(cBuffer)

	fmt.Println("Done!")
}
