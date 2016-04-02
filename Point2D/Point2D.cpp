//
//  Point.cpp
//  3BodyProblem
//
//  Created by Klaudia Golos on 2016-03-21.
//  Copyright © 2016 Klaudia Golos. All rights reserved.
//
#include "Point2D.hpp"
#include <string>

Point2D::Point2D(double x, double y) : x_(x), y_(y) {}

Point2D::Point2D() : Point2D::Point2D(0,0) {}

Point2D operator+(const Point2D &point1, const Point2D &point2)
{
    return Point2D(point1.x_ + point2.x_, point1.y_ + point2.y_);
}
Point2D operator-(const Point2D &point1, const Point2D &point2)
{
    return Point2D(point1.x_ - point2.x_, point1.y_ - point2.y_);
}
Point2D operator*(const double factor, const Point2D &point)
{
    return Point2D(factor*point.x_, factor*point.y_);
}
Point2D operator*(const Point2D &point, const double factor)
{
    return Point2D(factor*point.x_, factor*point.y_);
}
Point2D operator/(const Point2D &point, const double factor)
{
    return Point2D(point.x_/factor, point.y_/factor);
}

std::ostream& operator << (std::ostream& out, const Point2D& point)
{
    out << std::to_string(point.x_) << "\t";
    out << std::to_string(point.y_);
    return out;
}

double Point2D::calcNorm()
{
    return sqrt((pow(x_, 2) + (pow(y_, 2))));
}