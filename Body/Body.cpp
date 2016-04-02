#include "Body.hpp"
#include "ConstantsAndUtilities.hpp"
#include <cmath>

namespace
{
    
Point2D calcPosEuler(Point2D positionNow,
                     Point2D velocityNow,
                     Point2D accFactor)
{
    return positionNow + velocityNow * constants::dt
            + 0.5 * accFactor * pow(constants::dt,2);
}
    
Point2D calcPosVerlet(Point2D positionNow,
                      Point2D positionLast,
                      Point2D accFactor)
{
    return  2 * positionNow - positionLast + accFactor * pow(constants::dt,2);
}
    
}

Body::Body(Point2D positionLast,
           Point2D velocityLast,
           Point2D positionNow,
           Point2D velocityNow,
           Point2D positionFuture,
           Point2D velocityFuture):
									positionLast_(positionLast),
									velocityLast_(velocityLast),
									positionNow_(positionNow),
									velocityNow_(velocityNow),
                                    positionFuture_(positionFuture),
									velocityFuture_(velocityFuture)
{}

Body::Body() : Body(Point2D(), Point2D(), Point2D(), Point2D(), Point2D(), Point2D())
{}

void Body::StepEuler(Body &body1, Body &body2, Body &body3)
{
    body1.positionFuture_ = calcPosEuler(body1.positionNow_,
                                         body1.velocityNow_,
                                         body1.calcAccFactor(body2, body3));
    body2.positionFuture_ = calcPosEuler(body2.positionNow_,
                                         body2.velocityNow_,
                                         body2.calcAccFactor(body1, body3));
    body3.positionFuture_ = calcPosEuler(body3.positionNow_,
                                         body3.velocityNow_,
                                         body3.calcAccFactor(body1, body2));
    body1.makeFutureNow();
    body2.makeFutureNow();
    body3.makeFutureNow();
}

void Body::StepVerlet(Body &body1, Body &body2, Body &body3)
{
    body1.positionFuture_ = calcPosVerlet(body1.positionNow_,
                                          body1.positionLast_,
                                          body1.calcAccFactor(body2, body3));
    body2.positionFuture_ = calcPosVerlet(body2.positionNow_,
                                          body2.positionLast_,
                                          body2.calcAccFactor(body3, body1));
    body3.positionFuture_ = calcPosVerlet(body3.positionNow_,
                                          body3.positionLast_,
                                          body3.calcAccFactor(body1, body2));
    body1.makeFutureNow();
    body2.makeFutureNow();
    body3.makeFutureNow();
}

std::ostream& operator<<(std::ostream& out, const Body& body)
{
    out << body.positionNow_;
    return out;
}

void Body::WriteToOStream(const Body &body1,
                          const Body &body2,
                          const Body &body3,
                          std::ostream &ostr)
{
    ostr << body1 << "\t" << body2 << "\t" << body3 << "\n";
}

const std::string Body::HeaderString{"#x1\ty1\tx2\ty2\tx3\ty3\n"};

Point2D Body::calcAccFactor(const Body &body1,const Body &body2) const
{
    return  - constants::m * constants::G * (positionNow_ -
            body1.positionNow_) / pow((positionNow_ -
            body1.positionNow_).norm(),3) - constants::m*constants::G *
            (positionNow_ - body2.positionNow_) / pow((positionNow_ -
            body2.positionNow_).norm(),3);
}

void Body::makeFutureNow()
{
    positionLast_ = positionNow_;
    positionNow_ = positionFuture_;
    velocityLast_ = velocityNow_;
    velocityNow_ = velocityFuture_;
}

