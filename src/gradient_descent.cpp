#include <Eigen/Dense>

double mse(Eigen::MatrixXd X, Eigen::VectorXd W, Eigen::VectorXd Y);

Eigen::VectorXd _derivative(Eigen::MatrixXd X, Eigen::VectorXd W,
                            Eigen::VectorXd Y) {
  /*
  Computes the jth derivative given W, X, Y
  by following gradient descent where
       D_j J(W,X) = (Y - X * W) * X_j
  */
  return -1 * X.transpose() * (Y - X * W);
}

Eigen::VectorXd _gradient_descent_step(Eigen::MatrixXd X, Eigen::VectorXd W,
                                       Eigen::VectorXd Y, double alpha) {
  /*
  Runs gradient descent for each row in the dataset X
  */
  Eigen::VectorXd W_temp = W;
  for (int j = 0; j < X.rows(); j++) {
    W_temp -= alpha * _derivative(X, W, Y);
  }

  return W_temp;
}

Eigen::VectorXd gradient_descent(Eigen::MatrixXd X, Eigen::MatrixXd Y,
                                 int *iter, bool *converged,
                                 int max_iterations, double threshold,
                                 double learning_rate) {
  Eigen::VectorXd W;
  /*
    Starting from a random set of weights W, use
    gradient descent to determine the optimal W. Stop
    when either the max iterations (not converged)
    or the error threshold (converged) is reached.
  */
  *converged = true;
  W = Eigen::MatrixXd::Random(X.cols(), 1);

  for (*iter = 0; *iter < max_iterations; *iter = *iter + 1) {
    W = _gradient_descent_step(X, W, Y, learning_rate);

    double error = mse(X, W, Y);
    if (error < threshold) {
      *converged = true;
      break;
    }
  }

  return W;
}