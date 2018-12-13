#include "replace.hpp"

// replace <sc, identifier> with <spark, identifier>
void replace_sc(std::vector<Pair> *tokens) {
    std::cout << "in replace_sc\n";
    std::vector<Pair>::iterator it = tokens->begin();
    for (it; it != tokens->end(); ++it) {
        if (it->token == "sc") {
            std::cout << "replacing sc with spark\n";
            it->token = "spark";
        }
    }
}

// replace <textFile, identifier> 
// with <read, identifier> <., symbol> <textFile, identifier>
void replace_textfile(std::vector<Pair> *tokens) {
    std::cout << "in replace_textfile\n";
    std::vector<Pair>::iterator it = tokens->begin();
    for (it; it != tokens->end(); ++it) {
    	std::cout << "top of for loop\n";
        if (it->token == "textFile") {
            Pair *read = new Pair;
            read->token = "read";
            read->type = ID;
            Pair *dot = new Pair;
            dot->token = ".";
            dot->type = SYM;
            std::cout << "haven't inserted yet\n";
            tokens->insert(it, *read);
            std::cout << it->token << std::endl;
	    ++it;
            tokens->insert(it, *dot);
	    ++it;
            std::cout << it->token << std::endl;
        }
    }
}

// replace <reduce, identifier> <(, symbol> ... <), symbol>
// with <select, identifier> <(, symbol> <reduceAggregator, identifier> \n 
// <(, symbol> ... <), symbol> <), symbol> <., symbol> <collect, identifier>
// <(, symbol> <), symbol>
void replace_reduce(std::vector<Pair> *tokens) {
    std::cout << "in replace_reduce\n";
    std::vector<Pair>::iterator it = tokens->begin();
    for (it; it != tokens->end(); ++it) {
        
    }
}

// replace <reduceByKey, identifier> <(, symbol> ... <), symbol>
// with <groupByKey, identifier> <_, identifier> <., symbol> <_1, identifier>
// <), symbol> <., symbol> <agg, identifier> <(, symbol> 
// <reduceByKeyAggregator, identifier> <(, symbol> ... <), symbol> <), symbol>
void replace_reducebykey(std::vector<Pair> *tokens) {
    std::cout << "in replace_reducebykey\n";
    std::vector<Pair>::iterator it = tokens->begin();
    for (it; it != tokens->end(); ++it) {
        
    }
}

// replace <sortBy, identifier> <(, symbol> ... <), symbol>
// with <map, identifier> <(, symbol> <row, identifier> <=, symbol> <>, symbol>
// <(, symbol> <(, symbol> ... <), symbol> <(, symbol> <row, identifier>
// <), symbol> <,, symbol> < , space> <row, identifier> <), symbol> <), symbol>
// <., symbol> <orderBy, identifier> <(, symbol> <"_1", string> <), symbol>
// <., symbol> <map, identifier> <(, symbol> <_, identifier> <., symbol>
// <_2, identifier> <), symbol>
void replace_sortby(std::vector<Pair> *tokens) {
    std::cout << "in replace_sortby\n";
    std::vector<Pair>::iterator it = tokens->begin();
    for (it; it != tokens->end(); ++it) {
        
    }
}

