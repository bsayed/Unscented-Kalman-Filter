#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
  Eigen::VectorXd rmse(4);
  rmse << 0, 0, 0, 0;

  int n1 = estimations.size();
  int n2 = ground_truth.size();

  // check the validity of the following inputs:
  //  * the estimation vector size should not be zero
  //  * the estimation vector size should equal ground truth vector size
  if((n1+n2 == 0) || (n1 != n2)) {
    std::cout << "estimations and ground truth vectors must not be empty and must be of equal dimensions." << std::endl;
    return rmse;
  }

  //accumulate squared residuals
  Eigen::VectorXd residual;
  for (int i = 0; i < n1; ++i) {
    residual = estimations[i]-ground_truth[i];
    residual = residual.array()*residual.array();
    rmse += residual;
  }

  rmse = rmse.array()/n1; //calculates the mean
  rmse = rmse.array().sqrt(); //calculates the squared root
  return rmse;
}