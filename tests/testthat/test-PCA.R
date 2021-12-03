library(PCAPackage)
library(testthat)
library(datasets)
context("Principal Component Analysis")

test_that("PCA produces a reasonable result",{
  library(datasets)
  data(iris)
  iris.mat <- as.matrix(iris[,1:4])
  pca.subset <- prcomp(iris.mat)
  num.components <- 2
  principal.components.mat <- pca.subset[["x"]][, 1:num.components]
  data.centered <- scale(iris.mat, center = TRUE, scale = FALSE)
  mine.pca <- PCAPackage::PCA_interface(data.centered,num.components)
  expect_equal(mine.pca, principal.components.mat)
})