#include <Eigen/Dense>
#include <iostream>

/*
  Constants for linear regression using gradient descent
*/
#define THRESHOLD 0.001      // When should the algorithm stop
#define LEARNING_RATE 0.001  // Approximation of differential step
#define MAX_ITERATIONS 1000  // Stop if too many iterations are run

// Prototypes
Eigen::MatrixXd insert_bias(Eigen::MatrixXd X);
double mse(Eigen::MatrixXd X, Eigen::VectorXd W, Eigen::VectorXd Y);
Eigen::VectorXd gradient_descent(Eigen::MatrixXd X, Eigen::MatrixXd Y,
                                 int *iteration, bool *converged,
                                 int max_iterations, double threshold,
                                 double learning_rate);
