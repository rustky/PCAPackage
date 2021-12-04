/* -*- compile-command: "R CMD INSTALL .." -*- */

#include "PCA.h"
#include <RcppArmadillo.h>
#include <stdio.h>
using namespace Rcpp;
using namespace arma;


// [[Rcpp::depends(RcppArmadillo)]]
//' @export 
int PCA(
  const double * data_ptr,
  const int N_rows,
  const int N_cols,
  const int num_comps,
  double * low_dim_ptr
){
  if(num_comps > N_cols){
    return ERROR_TOO_MANY_COMPONENTS;
  }
  
  arma::mat data_mat(data_ptr,N_rows,N_cols);
  arma::mat U;
  arma::vec s;
  arma::mat V;
  
  arma::svd_econ(U, s, V, data_mat);
  arma::mat diagonal_mat = diagmat(s);
  arma::mat rotation_ele = U * diagonal_mat;
  arma::mat V_trans = V.cols(0,num_comps-1).t();
  arma::mat principal_comps = rotation_ele.cols(0,num_comps-1) *
    V_trans;
  for(int rows = 0; rows < N_rows; rows++){
    for(int cols = 0; cols < N_cols; cols++){
      low_dim_ptr[cols*N_rows + rows] = principal_comps(rows,cols);
    }
  }
  return 0;
}
