#include "graphObject.h"
#include <GL/glut.h>
#include <vector>
#include <cmath>

int factorial(int n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

double binomialCoefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

double BSplineBasis(int i, int degree, double t) {
    if (degree == 0)
        return (i <= t && t < i + 1) ? 1.0 : 0.0;
    else
        return ((t - i) / degree * BSplineBasis(i, degree - 1, t) +
            (i + degree + 1 - t) / degree * BSplineBasis(i + 1, degree - 1, t));
}

void BezierCurve::draw() {
    glBegin(GL_LINE_STRIP);
    for (double t = 0.0; t <= 1.0; t += 0.01) {
        std::pair<float, float> point = { 0, 0 };
        int n = controlPoints.size() - 1;
        for (int i = 0; i <= n; i++) {
            double b = binomialCoefficient(n, i) * pow(t, i) * pow(1 - t, n - i);
            point.first += b * controlPoints[i].first;
            point.second += b * controlPoints[i].second;
        }
        glVertex2f(point.first, point.second);
    }
    glEnd();
}

void BSplineCurve::draw() {
    glBegin(GL_LINE_STRIP);
    for (double t = 0.0; t <= 1.0; t += 0.01) {
        std::pair<float, float> point = { 0, 0 };
        int n = controlPoints.size() - 1;
        for (int i = 0; i <= n; i++) {
            double b = BSplineBasis(i, 3, t);
            point.first += b * controlPoints[i].first;
            point.second += b * controlPoints[i].second;
        }
        glVertex2f(point.first, point.second);
    }
    glEnd();
}

void BezierCurve::setControlPoints(const std::vector<std::pair<float, float>>& points) {
    controlPoints = points;
}

void BSplineCurve::setControlPoints(const std::vector<std::pair<float, float>>& points) {
    controlPoints = points;
}