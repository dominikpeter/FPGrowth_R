
# Sys.setenv("PKG_CXXFLAGS"="-std=c++11")

rm(list = ls())

library(FPGrowth)
library(readxl)
library(dplyr)

df <- read_excel("Data/Online Retail.xlsx") %>% select(InvoiceNo, Description)

create_transactions <- function(df, id, item){
  split.data.frame(df,id) %>%
    lapply("[[",item)
}

trans <- create_transactions(df, df$InvoiceNo, "Description")

sets = FPGrowth(trans, minimum_support = 100)

sets

sets_df <- as.data.frame(sets)




