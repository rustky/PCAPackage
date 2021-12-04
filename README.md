# PCAPackage
# Installation
remotes::install_github("rustky/PCAPackage")
# Examples
Compute Principal Component Analysis
```
library(datasets)
data(iris)
iris.mat <- as.matrix(iris[,1:4])
num.components <- 2
data.centered <- scale(iris.mat, center = TRUE, scale = FALSE)
mine.pca <- PCAPackage::PCA_interface(data.centered,num.components)
```
<!-- badges: start -->
[![R-CMD-check](https://github.com/rustky/PCAPackage/workflows/R-CMD-check/badge.svg)](https://github.com/rustky/PCAPackage/actions)
<!-- badges: end -->
