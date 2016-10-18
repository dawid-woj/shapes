#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Shape.h"

#define CIRCLE_TYPE 1

typedef struct Circle Circle;

struct Circle {
    Shape parent;
    float radius;
    void (*_draw)(void *self, int virt);
    float (*_distance)(void *self, int virt, Point *p);
};

void circle_draw(void *self, int virt);
void init_circle(Circle *c, float x, float y, float radius);
Circle * create_circle(float x, float y, float radius);

#endif //_CIRCLE_H_
