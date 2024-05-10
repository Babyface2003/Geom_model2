#include "graphObject.h"
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    BezierCurve bezier;
    bezier.setControlPoints({ {0.1, 0.1}, {0.2, 0.4}, {0.3, 0.6}, {0.4, 0.8} });
    bezier.draw();

    BSplineCurve bspline;
    bspline.setControlPoints({ {0.1, 0.9}, {0.2, 0.8}, {0.3, 0.7} });
    bspline.draw();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Bezier and B-Spline Curves");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
/*
#include "graphObject.h"
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    BezierCurve bezier;
    bezier.setControlPoints({ {0.1, 0.1}, {0.2, 0.4}, {0.8, 0.5}, {0.9, 0.1} });
    bezier.draw();

    BSplineCurve bspline;
    bspline.setControlPoints({ {0.1, 0.9}, {0.2, 0.6}, {0.8, 0.5}, {0.9, 0.9}, {0.85, 0.4}, {0.4, 0.9} });
    bspline.draw();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Bezier and B-Spline Curves");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
*/