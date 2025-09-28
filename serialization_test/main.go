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
	var r, g, b byte = 0, 0, 0
	m := newObj(3)
	m["r"] = r
	m["g"] = g
	m["b"] = b
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
	var head int = 0

	fmt.Printf("Buffer length: %d\n", len(buffer))
	fmt.Printf("Buffer data: %v\n", buffer)

	m := NewPoint2D()
	for key, val := range m /* map[string]any */ {
		t := reflect.TypeOf(val)
		fmt.Printf("Key %q has type %v (kind %v)\n", key, t, t.Kind())
	}
	// m["x"] = bytesToFloat32(buffer[0:4])
	// m["y"] = bytesToFloat32(buffer[4:8])
	var err error
	m["x"], err = dsrl.Decode(buffer, &head, reflect.TypeOf(m["x"]))
	if err != nil {
		fmt.Printf("WHAT THE FUCK: %v\n", err)
	}
	m["y"], err = dsrl.Decode(buffer, &head, reflect.TypeOf(m["y"]))
	if err != nil {
		fmt.Printf("WHAT THE FUCK: %v\n", err)
	}
	fmt.Printf("Point struct that we got: %v", m)

	m2 := NewColor()
	for key, val := range m2 {
		t := reflect.TypeOf(val)
		fmt.Printf("Key %q has type %v (kind %v)\n", key, t, t.Kind())
	}
	// m2["r"] = buffer[8]
	// m2["g"] = buffer[9]
	// m2["b"] = buffer[10]
	m2["r"], err = dsrl.Decode(buffer, &head, reflect.TypeOf(m2["r"]))
	if err != nil {
		fmt.Printf("WHAT THE FUCK: %v\n", err)
	}
	m2["g"], err = dsrl.Decode(buffer, &head, reflect.TypeOf(m2["g"]))
	if err != nil {
		fmt.Printf("WHAT THE FUCK: %v\n", err)
	}
	m2["b"], err = dsrl.Decode(buffer, &head, reflect.TypeOf(m2["b"]))
	if err != nil {
		fmt.Printf("WHAT THE FUCK: %v\n", err)
	}
	fmt.Printf("Color struct that we got: %v", m2)

	fmt.Println("Done!")
}
