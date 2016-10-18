#include <stdio.h>

#include "Circle.h"
#include "Triangle.h"


int main(int argc, char** argv)
{
    int i;

    Point p = {.x = 1.f, .y = 2.f};

    Shape * shapes[3];
    Circle *c1 = create_circle(3, 2, 5);
    Triangle *t = create_triangle(1, 1, 0, 0, 5, 2);
    Circle c2;
    init_circle(&c2, 7, 1, 2);

    c1->draw(c1);
    t->draw(t);
    c2.draw(&c2);
    printf("\n");

    c1->parent.draw(c1);
    t->parent.draw(t);
    c2.parent.draw(&c2);
    printf("\n");

    shapes[0] = (Shape *)c1;
    shapes[1] = (Shape *)t;
    shapes[2] = (Shape *)&c2;

    for (i = 0; i < 3; i++) {
        shapes[i]->draw(shapes[i]);
        shapes[i]->vdraw(shapes[i]);
        printf("shape.x = %.1f\n", shapes[i]->pos.x);
        shapes[i]->distance(shapes[i], &p);
        printf("\n");
    }

    return 0;
}
