
# Sys.setenv("PKG_CXXFLAGS"="-std=c++11")

rm(list = ls())

library(FPGrowth)
library(readxl)
library(dplyr)

df <- read_excel("Data/Online Retail.xlsx") %>% select(InvoiceNo, Description)


trans <- create_transactions(df, df$InvoiceNo, "Description")

sets = FPGrowth(trans, minimum_support = 100)

sets

sets_df <- as.data.frame(sets)




