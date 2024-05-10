#pragma once
#include <GL/glut.h>
#include <vector>

class Curve {
public:
    virtual void draw() = 0;
    virtual void setControlPoints(const std::vector<std::pair<float, float>>& points) = 0;
};

class BezierCurve : public Curve {
private:
    std::vector<std::pair<float, float>> controlPoints;
public:
    void draw() override;
    void setControlPoints(const std::vector<std::pair<float, float>>& points) override;
};

class BSplineCurve : public Curve {
private:
    std::vector<std::pair<float, float>> controlPoints;
public:
    void draw() override;
    void setControlPoints(const std::vector<std::pair<float, float>>& points) override;
};