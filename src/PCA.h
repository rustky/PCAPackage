/* -*- compile-command: "R CMD INSTALL .." -*- */

#define ERROR_TOO_MANY_COMPONENTS 1

int PCA(
  const double * data_ptr,
  const int N_rows,
  const int N_cols,
  const int num_comps,
  double * low_dim_ptr
);