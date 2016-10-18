#ifndef _SHAPE_H_
#define _SHAPE_H_

typedef struct Shape Shape;

typedef struct {
    float x;
    float y;
} Point;

struct Shape {
    int type;
    Point pos;
    void (*_draw)(void *self, int virt);
    float (*_distance)(void *self, int virt, Point *p);
};

void shape_draw(void *self, int virt);
float shape_distance(void *self, int virt, Point *p);
void init_shape(Shape *s, float x, float y, int type);

#define draw(self) _draw(self, 0)
#define vdraw(self) _draw(self, 1)
#define distance(self, p) _distance(self, 0, p)
#define vdistance(self, p) _distance(self, 1, p)

#endif //_SHAPE_H_
