#include <cassert>
#include <iostream>
#include <set>
#include <vector>

#include "fptree.hpp"
#include <Rcpp.h>

using namespace Rcpp;
// [[Rcpp::plugins(cpp11)]]



// [[Rcpp::export]]
RcppExport SEXP FPGrowth_(List l, double minimum_support)
{
  std::vector<Transaction> transactions;
  std::vector<std::string> v;

  // fill in transactions

  for ( int x = 0; x < l.size(); x++ ) {
    v = as<std::vector<std::string> >(l[x]);
    transactions.push_back(v);
    }

  const double minimum_support_threshold = minimum_support;
  const FPTree fptree{ transactions, minimum_support_threshold};
  const std::set<Pattern> patterns = fptree_growth( fptree );

  std::vector<std::string> sets;
  std::string s = "{";
  std::vector<double> values;

  for (auto elem : patterns)
  {
    for (std::set<std::string>::iterator it=elem.first.begin(); it!=elem.first.end(); ++it){
      if (std::next(it) == elem.first.end()){
        s += *it;
      } else {
        s += *it + " -> ";
      }
    }
    s += "}";

    sets.push_back(s);
    values.push_back(elem.second);

    s = "{";
  }

  List L = List::create(Named("Sets") = sets,
                        Named("Support") = values);
  return L;
};

