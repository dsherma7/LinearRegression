#include <Eigen/Dense>
/*
  Helper functions that support operations like
  data wrangling and transformations.
*/


Eigen::MatrixXd insert_bias(Eigen::MatrixXd X) {
  /*
    Inserts the bias into a dataset X by
    preprending a column of all ones.
  */
  Eigen::MatrixXd biased;
  int n_rows, n_cols;

  n_rows = X.rows();
  n_cols = X.cols() + 1;  // With extra bias column

  biased = Eigen::MatrixXd::Constant(n_rows, n_cols, 1.0);
  for (int col = 1; col < n_cols; col++) {
    biased.col(col) = X.col(col - 1);
  }

  return biased;
}