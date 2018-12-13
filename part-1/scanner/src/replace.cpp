#include "replace.hpp"

// replace <sc, identifier> with <spark, identifier>
void replace_sc(std::vector<Pair> *tokens) {
    //std::cout << "in replace_sc\n";
    std::vector<Pair>::iterator it = tokens->begin();
    for (it; it != tokens->end(); ++it) {
        if (it->token == "sc") {
            //std::cout << "replacing sc with spark\n";
            it->token = "spark";
        }
    }
}

// replace <textFile, identifier> 
// with <read, identifier> <., symbol> <textFile, identifier>
void replace_textfile(std::vector<Pair> *tokens) {
    //std::cout << "in replace_textfile\n";
    std::vector<Pair>::iterator it = tokens->begin();
    for (it; it != tokens->end(); ++it) {
    	//std::cout << "top of for loop\n";
        if (it->token == "textFile") {
            Pair *read = new Pair;
            read->token = "read";
            read->type = ID;
            Pair *dot = new Pair;
            dot->token = ".";
            dot->type = SYM;
            //std::cout << "haven't inserted yet\n";
            tokens->insert(it, *read);
            //std::cout << it->token << std::endl;
            ++it;
            tokens->insert(it, *dot);
            ++it;
            //std::cout << it->token << std::endl;
        }
    }
}

// replace <reduce, identifier> <(, symbol> ... <), symbol>
// with <select, identifier> <(, symbol> <reduceAggregator, identifier> \n 
// <(, symbol> ... <), symbol> <), symbol> <., symbol> <collect, identifier>
// <(, symbol> <), symbol>
void replace_reduce(std::vector<Pair> *tokens) {
    //std::cout << "in replace_reduce\n";
    std::vector<Pair>::iterator it = tokens->begin();
    bool found = false;
    int count = 0;
    for (it; it != tokens->end(); ++it) {
        if (it->token == "reduce" && !found) {
            it->token = "reduceAggregator";
            // insert select
            Pair *select = new Pair;
            select->token = "select";
            select->type = ID;
            // insert open paren
            Pair *paren = new Pair;
            paren->token = "(";
            paren->type = SYM;
            tokens->insert(it, *select);
            ++it;
            tokens->insert(it, *paren);
            ++it;
            found = true;
            ++it;
        }
        if (found) {
            std::cout << it->token << std::endl;
            if (it->token == "(") {
                count++;
                std::cout << count << std::endl;
            }
            if (it->token == ")") {
                count --;
                std::cout << count << std::endl;
            }
            if (count == 0) {
                // insert after current it
                // <), symbol> <., symbol> <collect, identifier>
                // <(, symbol> <), symbol>
                Pair *close = new Pair;
                close->token = ")";
                close->type = SYM;
                Pair *dot = new Pair;
                dot->token = ".";
                dot->type = SYM;
                Pair *collect = new Pair;
                collect->token = "collect";
                collect->type = ID;
                Pair *open = new Pair;
                open->token = "(";
                open->type = SYM;
                Pair *close2 = new Pair;
                close2->token = ")";
                close2->type = SYM;
                
                tokens->insert(it, *close);
                ++it;
                tokens->insert(it, *close2);
                ++it;
                tokens->insert(it, *dot);
                ++it;
                tokens->insert(it, *collect);
                ++it;
                tokens->insert(it, *open);
                ++it;
                found = false;
            }
        }
    }
}

// replace <reduceByKey, identifier> <(, symbol> ... <), symbol>
// with <groupByKey, identifier> <_, identifier> <., symbol> <_1, identifier>
// <), symbol> <., symbol> <agg, identifier> <(, symbol> 
// <reduceByKeyAggregator, identifier> <(, symbol> ... <), symbol> <), symbol>
void replace_reducebykey(std::vector<Pair> *tokens) {
    //std::cout << "in replace_reducebykey\n";
    std::vector<Pair>::iterator it = tokens->begin();
    bool found = false;
    int count = 0;
    for (it; it != tokens->end(); ++it) {
        if (it->token == "reduceByKey" && !found) {
            it->token = "reduceByKeyAggregator";
            // insert groupByKey
            Pair *group = new Pair;
            group->token = "groupByKey";
            group->type = ID;
            // insert (
            Pair *open = new Pair;
        open->token = "(";
        open->type = SYM;
            // insert _
            Pair *und = new Pair;
            und->token = "_";
            und->type = ID;
            // insert .
            Pair *dot = new Pair;
            dot->token = ".";
            dot->type = SYM;
            // insert _1
            Pair *un1 = new Pair;
            un1->token = "_1";
            un1->type = ID;
            // insert )
            Pair *clos = new Pair;
            clos->token = ")";
            clos->type = SYM;
            // insert .
            Pair *dot2 = new Pair;
            dot2->token = ".";
            dot2->type = SYM;
            // insert agg
            Pair *agg = new Pair;
            agg->token = "agg";
            agg->type = ID;
            // insert
            Pair *clos2 = new Pair;
            clos2->token = ")";
            clos2->type = SYM;
            tokens->insert(it, *group);
            ++it;
            tokens->insert(it, *open);
            ++it;
            tokens->insert(it, *und);
            ++it;
            tokens->insert(it, *dot);
            ++it;
            tokens->insert(it, *un1);
            ++it;
            tokens->insert(it, *clos);
            ++it;
            tokens->insert(it, *dot2);
            ++it;
            tokens->insert(it, *agg);
            ++it;
            tokens->insert(it, *clos2);
            ++it;
            found = true;
            ++it;
        }
        if (found) {
            std::cout << it->token << std::endl;
            if (it->token == "(") {
                count++;
                std::cout << count << std::endl;
            }
            if (it->token == ")") {
                count --;
                std::cout << count << std::endl;
            }
            if (count == 0) {
                // insert after current it
                // <), symbol> <., symbol> <collect, identifier>
                // <(, symbol> <), symbol>
                Pair *close = new Pair;
                close->token = ")";
                close->type = SYM;
                
                tokens->insert(it, *close);
                ++it;
                found = false;
            }
        }
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
    //std::cout << "in replace_sortby\n";
    std::vector<Pair>::iterator it = tokens->begin();
    bool found = false;
    int count = 0;
    for (it; it != tokens->end(); ++it) {
        if (it->token == "sortBy" && !found) {
            ++it;
            Pair *paren = new Pair;
            paren->token = "(";
            paren->type = SYM;
            tokens->insert(it, *paren);
            Pair *map = new Pair;
            map->token = "map";
            map->type = ID;
            Pair *op = new Pair;
            op->token = "(";
            op->type = SYM;
            Pair *row = new Pair;
            row->token = "row";
            row->type = ID;
            Pair *eq = new Pair;
            eq->token = "=";
            eq->type = SYM;
            Pair *arr = new Pair;
            arr->token = ">";
            arr->type = SYM;
            
            tokens->insert(it, *map);
            ++it;
            tokens->insert(it, *op);
            ++it;
            tokens->insert(it, *row);
            ++it;
            tokens->insert(it, *eq);
            ++it;
            tokens->insert(it, *arr);
            ++it;
            
        }
        if (found) {
            std::cout << it->token << std::endl;
            if (it->token == "(") {
                count++;
                std::cout << count << std::endl;
            }
            if (it->token == ")") {
                count --;
                std::cout << count << std::endl;
            }
            if (count == 0) {
                // insert after current it
                // <), symbol> <., symbol> <collect, identifier>
                // <(, symbol> <), symbol>
                Pair *ope = new Pair;
                Pair *r1 = new Pair;
                Pair *clo = new Pair;
                Pair *comm = new Pair;
                Pair *spc = new Pair;
                Pair *r2 = new Pair;
                Pair *close = new Pair;
                close->token = ")";
                close->type = SYM;
                Pair *close2 = new Pair;
                close2->token = ")";
                close2->type = SYM;
                Pair *dot = new Pair;
                dot->token = ".";
                dot->type = SYM;
                Pair *orderBy = new Pair;
                orderBy->token = "orderBy";
                orderBy->type = ID;
                Pair *open = new Pair;
                open->token = "(";
                open->type = SYM;
                Pair *str = new Pair;
                str->token = "\"_1\"";
                str->type = STRING;
                Pair *close3 = new Pair;
                close3->token = ")";
                close3->type = SYM;
                Pair *dot2 = new Pair;
                dot2->token = ".";
                dot2->type = SYM;
                Pair *map2 = new Pair;
                map2->token = "map";
                map2->type = ID;
                Pair *parenopen = new Pair;
                parenopen->token = "(";
                parenopen->type = SYM;
                Pair *und2 = new Pair;
                und2->token = "_";
                und2->type = ID;
                Pair *dot3 = new Pair;
                dot3->token = ".";
                dot3->type = SYM;
                Pair *under2 = new Pair;
                under2->token = "_2";
                under2->type = ID;
                
                tokens->insert(it, *ope);
                ++it;
                tokens->insert(it, *r1);
                ++it;
                tokens->insert(it, *clo);
                ++it;
                tokens->insert(it, *comm);
                ++it;
                tokens->insert(it, *spc);
                ++it;
                tokens->insert(it, *r2);
                ++it;
                tokens->insert(it, *close);
                ++it;
                tokens->insert(it, *close2);
                ++it;
                tokens->insert(it, *dot);
                ++it;
                tokens->insert(it, *orderBy);
                ++it;
                found = false;
                tokens->insert(it, *open);
                ++it;
                tokens->insert(it, *str);
                ++it;
                tokens->insert(it, *close3);
                ++it;
                tokens->insert(it, *dot2);
                ++it;
                tokens->insert(it, *map2);
                ++it;
                tokens->insert(it, *parenopen);
                ++it;
                tokens->insert(it, *und2);
                ++it;
                tokens->insert(it, *dot3);
                ++it;
                tokens->insert(it, *under2);
                ++it;
            }
        }
    }
}

