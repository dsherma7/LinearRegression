#include "linear_regression.h"

int main() {
  Eigen::MatrixXd X;
  Eigen::VectorXd Y, W;
  bool *converged;
  int *iteration;

  /*
    Build a trial dataset with features X and labels Y.
    X is is a random matrix with the first column all
    ones to provide a bias term. Thus we are finding the
    affine model given as Y ~ W * X + C.
  */
  X = Eigen::MatrixXd::Random(12, 3);
  X = insert_bias(X);
  Y = X * Eigen::MatrixXd::Random(X.cols(), 1);

  W = gradient_descent(X, Y, iteration, converged,
                       MAX_ITERATIONS, THRESHOLD, LEARNING_RATE);

  if (*converged) {
    std::cout << "Converged at iteration " << *iteration << std::endl;
  } else {
    std::cout << "The model was unable to converge with the provided dataset. "
              << std::endl;
  }

  std::cout << "Final Error: " << mse(X, W, Y) << std::endl;
}
