
# Sys.setenv("PKG_CXXFLAGS"="-std=c++11")

rm(list = ls())

library(FPGrowth)
library(readxl)
library(dplyr)
library(stringr)

# df <- read_excel("Data/Online Retail.xlsx") %>%
#   select(InvoiceNo, Description)
#
# trans <- create_transactions(df, df$InvoiceNo, "Description")
#
# save(trans, file="Data/trans.Rdata")

load("Data/trans.Rdata")

sets <- FPGrowth(trans, minimum_support = .8)
sets['n_rules'] <- lapply(sets['Sets'], function(x) str_count(x, "->"))


sets_df <- as_data_frame(sets)

sets_df %>% filter(n_rules > 0) %>% View()


