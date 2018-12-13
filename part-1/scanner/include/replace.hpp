#ifndef REPLACE_HPP
#define REPLACE_HPP

#include "scan.hpp"

// replace <sc, identifier> with <spark, identifier>
void replace_sc(std::vector<Pair> *tokens);

// replace <textFile, identifier> 
// with <read, identifier> <., symbol> <textFile, identifier>
void replace_textfile(std::vector<Pair> *tokens);

// replace <reduce, identifier> <(, symbol> ... <), symbol>
// with <select, identifier> <(, symbol> <reduceAggregator, identifier> \n 
// <(, symbol> ... <), symbol> <), symbol> <., symbol> <collect, identifier>
// <(, symbol> <), symbol>
void replace_reduce(std::vector<Pair> *tokens);

// replace <reduceByKey, identifier> <(, symbol> ... <), symbol>
// with <groupByKey, identifier> <_, identifier> <., symbol> <_1, identifier>
// <), symbol> <., symbol> <agg, identifier> <(, symbol> 
// <reduceByKeyAggregator, identifier> <(, symbol> ... <), symbol> <), symbol>
void replace_reducebykey(std::vector<Pair> *tokens);

// replace <sortBy, identifier> <(, symbol> ... <), symbol>
// with <map, identifier> <(, symbol> <row, identifier> <=, symbol> <>, symbol>
// <(, symbol> <(, symbol> ... <), symbol> <(, symbol> <row, identifier>
// <), symbol> <,, symbol> < , space> <row, identifier> <), symbol> <), symbol>
// <., symbol> <orderBy, identifier> <(, symbol> <"_1", string> <), symbol>
// <., symbol> <map, identifier> <(, symbol> <_, identifier> <., symbol>
// <_2, identifier> <), symbol>
void replace_sortby(std::vector<Pair> *tokens);

#endif
