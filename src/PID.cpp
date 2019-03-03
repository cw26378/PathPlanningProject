#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_in, double Ki_in, double Kd_in) {
// this->Kp = Kp;
    Kp = Kp_in;
    Ki = Ki_in;
    Kd = Kd_in;
  
    p_error = 0;
    i_error = 0;
    d_error = 0;
}

void PID::UpdateError(double vel_error) {
    // trick for d_error
    d_error = vel_error - p_error;
    p_error = vel_error;
    i_error += vel_error;
    //d_error = cte - cte_before;
    //cte_before = cte;
    
    
}

double PID::TotalError() {
    double error_cal;
    return error_cal = -Kp * p_error - Ki * i_error - Kd * d_error;
    
}

