//
//  Point.hpp
//  3BodyProblem
//
//  Created by Klaudia Golos on 2016-03-21.
//  Copyright © 2016 Klaudia Golos. All rights reserved.
//

#ifndef Point2D_hpp
#define Point2D_hpp
#include <iostream>

class Point2D {
    double x_, y_;
public:
    Point2D(double x, double y);
    Point2D();
    friend Point2D operator+(const Point2D &point1, const Point2D &point2);
    friend Point2D operator-(const Point2D &point1, const Point2D &point2);
    friend Point2D operator*(const double factor, const Point2D &point);
    friend Point2D operator*(const Point2D &point, const double factor);
    friend Point2D operator/(const Point2D &point, const double factor);
    friend std::ostream& operator << (std::ostream& out, const Point2D& point);
    double calcNorm();
};
#include <cmath>
#endif /* Point_hpp */
