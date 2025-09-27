#include <stdlib.h>
#include <string.h>

#include "geometry.h"
#include "sugars.h"

#define MAX_BUFFER_SIZE 256

#include <stdint.h>

void
add_geometry(u8 *buffer, u64 *bytes_copied, GeometryType type) {

    Point2D point = {0};
    point.x       = 1.1f;
    point.y       = 2.2f;

    Color color = {0};
    color.r     = 0x11;
    color.g     = 0x22;
    color.b     = 0x33;

    Line line    = {0};
    line.start.x = 3.3f;
    line.start.y = 4.4f;

    line.end.x = 5.5f;
    line.end.y = 6.6f;

    line.color.r = 0x44;
    line.color.g = 0x55;
    line.color.b = 0x66;

    Circle circle = {.center = {.x = 7.7f, .y = 8.8f},
                     .radius = 9.9f,
                     .color  = {.r = 0x77, .g = 0x88, .b = 0x99}};

    Shape shape_point = {.type = SHAPE_POINT, .data.point = {.x = 10.1f, .y = 11.1f}, .id = 1001};

    Shape shape_line = {.type      = SHAPE_LINE,
                        .data.line = {.start = {.x = 12.2f, .y = 13.3f},
                                      .end   = {.x = 14.4f, .y = 15.5f},
                                      .color = {.r = 0xAA, .g = 0xBB, .b = 0xCC}},
                        .id        = 1002};

    Shape shape_circle = {.type        = SHAPE_CIRCLE,
                          .data.circle = {.center = {.x = 16.6f, .y = 17.7f},
                                          .radius = 18.8f,
                                          .color  = {.r = 0xDD, .g = 0xEE, .b = 0xFF}},
                          .id          = 1003};

    Scene scene = {.shapes = {shape_point, shape_line, shape_circle}, .shape_count = 3};

    switch (type) {
        case (ST_Point2D): {
        } break;

        case (ST_Color): {
        } break;

        case (ST_Line): {
        } break;

        case (ST_Circle): {
        } break;

        case (ST_ShapeData): {
        } break;

        case (ST_Shape): {
        } break;

        case (ST_Scene): {
        } break;
    };
}

u8 *
get_buffer(u64 *len) {
    u8 *buffer = calloc(MAX_BUFFER_SIZE, sizeof(char));
    *len       = MAX_BUFFER_SIZE;

    char *line     = "what is my purpose in this world.\n";
    u64   line_len = strlen(line);
    for (u32 i = 0; i < strlen(line); i += 1) {
        buffer[i] = line[i];
    }

    return buffer;
}

void
free_buffer(u8 *buffer) {
    free(buffer);
}
