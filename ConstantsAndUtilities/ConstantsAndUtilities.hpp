//
//  ConstantsAndUtilities.hpp
//  3BodyProblem
//
//  Created by Klaudia Golos on 2016-03-22.
//  Copyright © 2016 Klaudia Golos. All rights reserved.
//

#ifndef ConstantsAndUtilities_hpp
#define ConstantsAndUtilities_hpp

namespace constants{
    const double G = 1; //gravitational constant
    const double m = 1; //mass of a body
    const double dt = 0.001; //time step
    const int StepsNum = 40000;
    
    //initial conditions
    //Body1
    const double x1 = 0.97000436, y1 = -0.24308753, v_x1 = -0.5*0.93240737, v_y1 = -0.5*0.86473146;
    const double x2 = -0.97000436, y2 = 0.24308753, v_x2 = -0.5*0.93240737, v_y2 = -0.5*0.86473146;
    const double x3 = 0, y3 = 0, v_x3 = 0.93240737, v_y3 = 0.86473146;
}

#endif /* ConstantsAndUtilities_hpp */