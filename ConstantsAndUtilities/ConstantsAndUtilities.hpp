#ifndef ConstantsAndUtilities_hpp
#define ConstantsAndUtilities_hpp

namespace constants
{
    
const double G = 1; //gravitational constant
const double m = 1; //mass of a body
const double dt = 0.001; //time step
const int StepsNum = 10000;
    
//initial conditions
const double x1 = 0.97000436, y1 = -0.24308753, v_x1 = -0.5*0.93240737, v_y1 = -0.5*0.86473146;
const double x2 = -0.97000436, y2 = 0.24308753, v_x2 = -0.5*0.93240737, v_y2 = -0.5*0.86473146;
const double x3 = 0, y3 = 0, v_x3 = 0.93240737, v_y3 = 0.86473146;
    
}

#endif /* ConstantsAndUtilities_hpp */
