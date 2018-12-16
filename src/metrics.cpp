#include <Eigen/Dense>

/*
   A collection of metrics to use for determining the
   error between the predicted and actual Y values.
*/

double mse(Eigen::MatrixXd X, Eigen::VectorXd W, Eigen::VectorXd Y) {
	/*
	  Computes the mean squared error for a XW and Y.
	*/
	return 0.5 * (Y - X * W).transpose() * (Y - X * W);
}
