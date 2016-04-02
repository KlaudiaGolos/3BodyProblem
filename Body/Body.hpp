#ifndef Body_hpp
#define Body_hpp

#include "Point2D.hpp"

class Body{
public:
    Body(Point2D positionLast,
         Point2D velocityLast,
		 Point2D positionNow,
		 Point2D velocityNow,
		 Point2D positionFuture,
		 Point2D velocityFuture);
    Body();
    static void StepEuler(Body &body1, Body &body2, Body &body3);
    static void StepVerlet(Body &body1, Body &body2, Body &body3);
    friend std::ostream& operator << (std::ostream& out, const Body& body);
    static void WriteToOStream(const Body &body1,
							   const Body &body2,
							   const Body &body3,
							   std::ostream &ostr);
	
	const static std::string HeaderString;
private:
    Point2D positionLast_;
    Point2D velocityLast_;
    Point2D positionNow_;
    Point2D velocityNow_;
    Point2D positionFuture_;
    Point2D velocityFuture_;
    
    Point2D calcAccFactor(const Body &body1,const Body &body2) const;
    void makeFutureNow();
};

#endif /* Body_hpp */
