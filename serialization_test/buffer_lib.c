#include <stdlib.h>
#include <stdio.h>

#include "sugars.h"
#include "geometry.h"

#define MAX_BUFFER_SIZE 256

#include <stdint.h>

void
copy_n_bytes(u64 count, void *source, u8 *buffer, u64 *buffer_head) {
    u8 *source_bytes = (u8 *)source;
    for (u64 i = 0; i < count; i += 1) {

        buffer[(*buffer_head)++] = source_bytes[i];

        if (*buffer_head >= MAX_BUFFER_SIZE) {
            printf("Crashing cuz ran out of buffer\n");
            exit(69);
        }
    }
}

void
add_geometry(u8 *buffer, u64 *buffer_head, GeometryType type) {

    // ------------------------------- //

    Point2D point = {0};
    point.x       = 1.1f;
    point.y       = 2.2f;

    // ------------------------------- //

    Color color = {0};
    color.r     = sizeof(GeometryType);
    color.g     = sizeof(ShapeType);
    color.b     = 0x3;

    // ------------------------------- //

    Line line    = {0};
    line.start.x = 3.3f;
    line.start.y = 4.4f;

    line.end.x = 5.5f;
    line.end.y = 6.6f;

    line.color.r = 44;
    line.color.g = 55;
    line.color.b = 66;

    // ------------------------------- //

    Circle circle   = {0};
    circle.center.x = 7.7f;
    circle.center.y = 8.8f;
    circle.radius   = 9.9f;
    circle.color.r  = 77;
    circle.color.g  = 88;
    circle.color.b  = 99;

    // ------------------------------- //

    Shape shape_point        = {0};
    shape_point.type         = SHAPE_POINT;
    shape_point.data.point.x = 10.1f;
    shape_point.data.point.y = 11.1f;
    shape_point.id           = 1001;

    // ------------------------------- //

    Shape shape_line             = {0};
    shape_line.type              = SHAPE_LINE;
    shape_line.data.line.start.x = 12.2f;
    shape_line.data.line.start.y = 13.3f;
    shape_line.data.line.end.x   = 14.4f;
    shape_line.data.line.end.y   = 15.5f;
    shape_line.data.line.color.r = 33;
    shape_line.data.line.color.g = 44;
    shape_line.data.line.color.b = 55;
    shape_line.id                = 1002;

    // ------------------------------- //

    Shape shape_circle                = {0};
    shape_circle.type                 = SHAPE_CIRCLE;
    shape_circle.data.circle.center.x = 16.6f;
    shape_circle.data.circle.center.y = 17.7f;
    shape_circle.data.circle.radius   = 18.8f;
    shape_circle.data.circle.color.r  = 33;
    shape_circle.data.circle.color.g  = 44;
    shape_circle.data.circle.color.b  = 55;
    shape_circle.id                   = 1003;

    // ------------------------------- //

    Scene scene       = {0};
    scene.shapes[0]   = shape_point;
    scene.shapes[1]   = shape_line;
    scene.shapes[2]   = shape_circle;
    scene.shape_count = 3;

    // ------------------------------- //

    switch (type) {
        case (T_Point2D): {
            copy_n_bytes(4, &point.x, buffer, buffer_head);
            copy_n_bytes(4, &point.y, buffer, buffer_head);
        } break;

        case (T_Color): {
            copy_n_bytes(1, &color.r, buffer, buffer_head);
            copy_n_bytes(1, &color.g, buffer, buffer_head);
            copy_n_bytes(1, &color.b, buffer, buffer_head);
        } break;

        case (T_Line): {
            copy_n_bytes(4, &line.start.x, buffer, buffer_head);
            copy_n_bytes(4, &line.start.y, buffer, buffer_head);

            copy_n_bytes(4, &line.end.x, buffer, buffer_head);
            copy_n_bytes(4, &line.end.y, buffer, buffer_head);

            copy_n_bytes(1, &line.color.r, buffer, buffer_head);
            copy_n_bytes(1, &line.color.g, buffer, buffer_head);
            copy_n_bytes(1, &line.color.b, buffer, buffer_head);
        } break;

        case (T_Circle): {
            copy_n_bytes(4, &circle.center.x, buffer, buffer_head);
            copy_n_bytes(4, &circle.center.y, buffer, buffer_head);
            copy_n_bytes(4, &circle.radius, buffer, buffer_head);
            copy_n_bytes(1, &circle.color.r, buffer, buffer_head);
            copy_n_bytes(1, &circle.color.g, buffer, buffer_head);
            copy_n_bytes(1, &circle.color.b, buffer, buffer_head);
        } break;

        case (T_ShapeData): {
        } break;

        case (T_Shape): {
        } break;

        case (T_Scene): {
        } break;
    };
}

u8 *
get_buffer(u64 *len) {
    u8 *buffer = calloc(MAX_BUFFER_SIZE, sizeof(char));
    if (buffer == 0) {
        printf("Invalid calloc\n");
        exit(69);
    }
    *len            = MAX_BUFFER_SIZE;
    u64 buffer_head = 0;


    add_geometry(buffer, &buffer_head, T_Point2D);
    add_geometry(buffer, &buffer_head, T_Color);
    add_geometry(buffer, &buffer_head, T_Line);
    add_geometry(buffer, &buffer_head, T_Circle);

    return buffer;
}

void
free_buffer(u8 *buffer) {
    free(buffer);
}
