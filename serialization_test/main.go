package main

/*
#cgo CFLAGS: -O0 -g
#cgo LDFLAGS: -L.\ -lbuffer
#include "buffer_lib.h"
*/
import "C"
import (
	"fmt"
	"reflect"
	"unsafe"
)

func newObj(cap int) map[string]any {
	return make(map[string]any, cap)
}

func NewPoint2D() map[string]any {
	var x, y float64 = 0.0, 0.0
	m := newObj(2)
	m["x"] = x
	m["y"] = y
	return m
}

func NewColor() map[string]any {
	m := newObj(3)
	m["r"] = nil
	m["g"] = nil
	m["b"] = nil
	return m
}
func NewLine() map[string]any {
	m := newObj(3)
	m["start"] = NewPoint2D()
	m["end"] = NewPoint2D()
	m["color"] = NewColor()
	return m
}

func NewCircle() map[string]any {
	m := newObj(3)
	m["center"] = NewPoint2D()
	m["radius"] = nil
	m["color"] = NewColor()
	return m
}

func NewShapeData() map[string]any {
	m := newObj(3)
	m["point"] = nil
	m["line"] = nil
	m["circle"] = nil
	return m
}

func NewShape() map[string]any {
	m := newObj(3)
	m["type"] = nil
	m["data"] = NewShapeData()
	m["id"] = nil
	return m
}

func NewScene(capShapes int) map[string]any {
	m := newObj(2)
	// You could initialize shapes as a slice of empty maps
	shapes := make([]map[string]any, capShapes)
	for i := range shapes {
		shapes[i] = NewShape()
	}
	m["shapes"] = shapes
	m["shape_count"] = nil
	return m
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

	m := NewPoint2D()
	for key, val := range m {
		t := reflect.TypeOf(val)
		fmt.Printf("Key %q has type %v (kind %v)\n", key, t, t.Kind())
	}

	fmt.Printf("Buffer length: %d\n", len(buffer))
	fmt.Printf("Buffer data: %v\n", buffer)

	fmt.Println("Done!")
}
