#include "PID.h"

//using namespace std;

/*
* TODO: Complete the PID class.
*/


// The paramators are chosen manually
// 1, finding the best paramator only by P control itself
// 2, increase Kd from 0.05, found 0.5
// 3, tuning Ki if it's needed, in my case PD control was enough
PID::PID() {
  Kp = 0.1;
  Kd = 0.5;
  Ki = 0.0001;
  pre_cte = 0.0;
}

PID::~PID() {}


void PID::UpdateError(double cte) {
  diff_cte = cte - pre_cte;
  pre_cte = cte;
  sum_cte += cte;
}


