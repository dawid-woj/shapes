#include "Triangle.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


static Point calculate_barycenter(
        float x1, float y1, float x2, float y2, float x3, float y3)
{
    Point q;
    q.x = (x1 + x2 + x3) / 3;
    q.y = (y1 + y2 + y3) / 3;
    return q;
}

void triangle_draw(void *self, int virt)
{
    Triangle *t = (Triangle *)self;
    printf("Triangle: pos = (%.1f,%.1f), p1 = (%.1f,%.1f), p2 = (%.1f,%.1f), p3 = (%.1f,%.1f)\n",
           t->parent.pos.x, t->parent.pos.y, t->p1.x, t->p1.y, t->p2.x, t->p2.y,
           t->p3.x, t->p3.y);
}

void init_triangle(Triangle *t, float x1, float y1,
                   float x2, float y2, float x3, float y3)
{
    Point q = calculate_barycenter(x1, y1, x2, y2, x3, y3);
    init_shape(&(t->parent), q.x, q.y, TRIANGLE_TYPE);
    t->p1.x = x1; t->p1.y = y1;
    t->p2.x = x2; t->p2.y = y2;
    t->p3.x = x3; t->p3.y = y3;
    t->_distance = t->parent._distance;
    t->_draw = triangle_draw;
}

Triangle * create_triangle(float x1, float y1,
                           float x2, float y2, float x3, float y3)
{
    Triangle *t = calloc(1, sizeof(Triangle));
    init_triangle(t, x1, y1, x2, y2, x3, y3);
    return t;
}
