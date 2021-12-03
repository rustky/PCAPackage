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
  // Eigen::Map<Eigen::MatrixXd> data_mat(
  //   data_ptr, N_rows, N_cols);
  
  arma::mat data_mat(data_ptr,N_rows,N_cols);
  arma::mat U;
  arma::vec s;
  arma::mat V;
  
  
  // V = arma::shuffle(data_mat);
  cx_vec eigval = arma::eig_gen(data_mat);
  // arma::svd_econ(U, s, V, data_mat);
  // arma::mat diagonal_mat = diagmat(s);
  // arma::mat rotation_ele = U * diagonal_mat;
  // arma::mat principal_comps = rotation_ele.submat(1,N_rows,1,num_comps)
  //   * arma::trans(V.submat(1,N_rows,1,num_comps));
  // low_dim_ptr = principal_comps.memptr();
  return 0;
}
