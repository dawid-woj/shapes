#include "Circle.h"

#include <stdio.h>
#include <stdlib.h>


void circle_draw(void *self, int virt) {
    Circle *c = (Circle *)self;
    printf("Circle: pos = (%.1f,%.1f), radius = %.1f\n",
           c->parent.pos.x, c->parent.pos.y, c->radius);
}

void init_circle(Circle *c, float x, float y, float radius) {
    init_shape(&(c->parent), x, y, CIRCLE_TYPE);
    c->radius = radius;
    c->_distance = c->parent._distance;
    c->_draw = circle_draw;
}

Circle * create_circle(float x, float y, float radius) {
    Circle *c = calloc(1, sizeof(Circle));
    init_circle(c, x, y, radius);
    return c;
}
