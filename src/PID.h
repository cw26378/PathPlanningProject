#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;
    
  /* add cte_before for the calculation of d_error (not used) */
  //double cte_before;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double vel_error);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
  
};
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
#endif /* PID_H */
