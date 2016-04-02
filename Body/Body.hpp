//
//  Body.hpp
//  3BodyProblem
//
//  Created by Klaudia Golos on 2016-03-21.
//  Copyright © 2016 Klaudia Golos. All rights reserved.
//

#ifndef Body_hpp
#define Body_hpp

#include "Point2D.hpp"

class Body{
    Point2D positionLast_;
    Point2D velocityLast_;
    Point2D positionNow_;
    Point2D velocityNow_;
    Point2D positionFuture_;
    Point2D velocityFuture_;
    void makeFutureNow();
public:
    Body(Point2D positionLast, Point2D velocityLast,
         Point2D positionNow, Point2D velocityNow,
         Point2D positionFuture, Point2D velocityFuture);
    Body();
    Point2D calcAccFactor(const Body &body1,const Body &body2);
    static void StepEuler(Body &body1, Body &body2, Body &body3);
    static void StepVerlet(Body &body1, Body &body2, Body &body3);
    friend std::ostream& operator << (std::ostream& out, const Body& body);
    static void WriteToOStream(const Body &body1, const Body &body2,
                               const Body &body3, std::ostream &ostr);
};

#endif /* Body_hpp */
