#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


static void __draw(Shape *shape)
{
    printf("Shape: pos = (%.1f,%.1f)\n",
           shape->pos.x, shape->pos.y);
}

void shape_draw(void *self, int virt) {
    Shape *s = (Shape *)self;

    if (virt) {
        if (s->type == TRIANGLE_TYPE) {
            ((Triangle *)s)->_draw(self, 0);
        } else if (s->type == CIRCLE_TYPE) {
            ((Circle *)s)->_draw(self, 0);
        } else {
            __draw(s);
        }
    } else {
        __draw(s);
    }
}

float __distance(Shape *shape, Point *p)
{
    float dx, dy, dist;

    dx = p->x - shape->pos.x;
    dy = p->y - shape->pos.y;
    dist = sqrt(dx*dx + dy*dy);

    return dist;
}

float shape_distance(void *self, int virt, Point *p) {
    Shape *s = (Shape *)self;

    if (virt) {
        if (s->type == TRIANGLE_TYPE) {
            return ((Triangle *)s)->_distance(self, 0, p);
        } else if (s->type == CIRCLE_TYPE) {
            return ((Circle *)s)->_distance(self, 0, p);
        } else {
            return __distance(s, p);
        }
    } else {
        return __distance(s, p);
    }
}

void init_shape(Shape *s, float x, float y, int type) {
    s->type = type;
    s->pos.x = x;
    s->pos.y = y;
    s->_draw = shape_draw;
    s->_distance = shape_distance;
}
