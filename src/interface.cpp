/* -*- compile-command: "R CMD INSTALL .." -*- */

#include <R.h>
#include <R_ext/Rdynload.h>
#include <stdlib.h>
#include <Rcpp.h>
#include "PCA.h"
using namespace Rcpp;
//' Principal Component Analysis
//' @param data_mat numeric data matrix [n x p]
//' @param num_components int desired number of components
//' @importFrom Rcpp evalCpp
//' @returns Lower dimension representation of input matrix  [n x num_components]
//' @export
// [[Rcpp::export]]
NumericMatrix PCA_interface(NumericMatrix data_mat,
                                  int num_components) {
  double *data_ptr = &data_mat[0];
  int N_rows = data_mat.nrow();
  int N_cols = data_mat.ncol();
  NumericMatrix low_dim_mat(N_rows,num_components);
  double *low_dim_ptr = &low_dim_mat[0];
  int status = PCA(data_ptr, N_rows, N_cols, num_components, low_dim_ptr);
  if(status == ERROR_TOO_MANY_COMPONENTS){
    Rcpp::stop("num_comps must be less than or equal to N_cols!");
  }
  return low_dim_mat;
}