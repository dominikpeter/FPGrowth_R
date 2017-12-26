#include <cassert>
#include <iostream>
#include <set>
#include <vector>

#include "fptree.hpp"
#include <Rcpp.h>

using namespace Rcpp;


// [[Rcpp::export]]
RcppExport SEXP test(List l)
{
  std::vector<Transaction> transactions;
  StringVector v;
  std::vector<std::string> v_;

  const auto minimum_support_threshold = 2;

  for ( int x = 0; x < l.size(); x++ ) {
    v = l[x];
    v_ = as<std::vector<std::string> >(v);
    Rcout <<  "Iter  = " << v.size() << std::endl;
    transactions.push_back(v_);
    }

  const FPTree fptree{ transactions, minimum_support_threshold };
  const std::set<Pattern> patterns = fptree_growth( fptree );

  Rcout <<  "Patern Size  = " << patterns.size() << std::endl;


  // Iterate over all elements of set
  // using range based for loop
  for (auto elem : patterns)
  {
    for (auto el : elem.first){
      Rcout << el << " , ";
    }
    Rcout << elem.second << " , ";
  }



  return l;

};

