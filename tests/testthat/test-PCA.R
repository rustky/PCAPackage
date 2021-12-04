library(PCAPackage)
library(testthat)
library(datasets)
context("Principal Component Analysis")

test_that("PCA produces a reasonable result",{
  library(datasets)
  data(iris)
  iris.mat <- as.matrix(iris[,1:4])
  num.components <- 2
  data.centered <- scale(iris.mat, center = TRUE, scale = FALSE)
  pca.subset <- prcomp(data.centered)
  some.directions <-
    pca.subset$rotation[, 1:num.components]
  some.components <- pca.subset$x[, 1:num.components]
  pc.reconstruction <- some.components %*% t(some.directions)
  mine.pca <- PCAPackage::PCA_interface(data.centered,num.components)
  built_in_error = sum((pc.reconstruction-data.centered)^2)
  mine_error = sum((mine.pca-data.centered)^2)
  expect_equal(mine_error,built_in_error)
})