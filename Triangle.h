#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Shape.h"

#define TRIANGLE_TYPE 2

typedef struct Triangle Triangle;

struct Triangle {
    Shape parent;
    Point p1, p2, p3;
    void (*_draw)(void *self, int virt);
    float (*_distance)(void *self, int virt, Point *p);
};

void triangle_draw(void *self, int virt);
void init_triangle(Triangle *t, float x1, float y1,
                   float x2, float y2, float x3, float y3);
Triangle * create_triangle(float x1, float y1,
                           float x2, float y2, float x3, float y3);

#endif //_TRIANGLE_H_
