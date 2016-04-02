#include "Body.hpp"
#include "Point2D.hpp"
#include "ConstantsAndUtilities.hpp"
#include <fstream>

int main()
{
    Body b1 = Body(Point2D(), Point2D(),
                   Point2D(constants::x1, constants::y1),
                   Point2D(constants::v_x1, constants::v_y1),
                   Point2D(), Point2D());
    Body b2 = Body(Point2D(), Point2D(),
                   Point2D(constants::x2, constants::y2),
                   Point2D(constants::v_x2, constants::v_y2),
                   Point2D(), Point2D());
    Body b3 = Body(Point2D(), Point2D(),
                   Point2D(constants::x3, constants::y3),
                   Point2D(constants::v_x3, constants::v_y3),
                   Point2D(), Point2D());
    std::ofstream dataFile ("/Users/Klaudia/Documents/3BodyProblem/dataPositions.txt",
                            std::ofstream::out);
    if (dataFile.is_open() == false)
        return 1;
    
    dataFile << Body::HeaderString;
    Body::WriteToOStream(b1, b2, b3, dataFile);
    
    Body::StepEuler(b1, b2, b3);
    Body::WriteToOStream(b1, b2, b3, dataFile);
    
    for (int i{0}; i <= constants::StepsNum ; ++i)
    {
        Body::StepVerlet(b1, b2, b3);
        Body::WriteToOStream(b1, b2, b3, dataFile);
    }
    dataFile.close();
    return 0;
}