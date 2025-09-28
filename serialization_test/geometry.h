#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <stdint.h>

#include "sugars.h"

typedef enum { SHAPE_POINT = 0, SHAPE_LINE = 1, SHAPE_CIRCLE = 2 } ShapeType;

typedef struct {
    f64 x;
    f32 y;
} Point2D;

typedef struct {
    u8 r;
    u8 g;
    u8 b;
} Color;

typedef struct {
    Point2D start;
    Point2D end;
    Color   color;
} Line;

typedef struct {
    Point2D center;
    f32     radius;
    Color   color;
} Circle;

typedef union {
    Point2D point;
    Line    line;
    Circle  circle;
} ShapeData;

typedef struct {
    ShapeType type;
    ShapeData data;
    u32       id;
} Shape;

typedef struct {
    Shape shapes[3];
    u32   shape_count;
} Scene;

typedef enum {
    T_Point2D,
    T_Color,
    T_Line,
    T_Circle,
    T_ShapeData,
    T_Shape,
    T_Scene,
} GeometryType;

#endif
