
# rm(list = ls())


library(FPGrowth)

# Sys.setenv("PKG_CXXFLAGS"="-std=c++11")


a <- "A"
b <- "B"
c <- "C"
d <- "D"
e <- "E"

lst <- list(
              c( a, b ),
              c( a, b),
              c(a),
              c(a,b,c)
              )

test(lst)


