#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include <iostream>
#include "regex.hpp"

#define RESWORD 1
#define ID      2
#define NUM     3
#define STRING  4
#define SYM     5
#define SPACE   6

typedef struct {
    int type;
    std::string token;
    std::string to_string() {
        //std::cout << "in to_string\n";
        //std::cout << token << std::endl;
        std::string temp = "<"+token+", ";
        if (type == RESWORD) {
            //std::cout << "reserved word\n";
            temp += "Reserved Word>";
        }
        if (type == ID) {
            //std::cout << "identifier\n";
            temp += "Identifier>";
        }
        if (type == NUM) {
            //std::cout << "number\n";
            temp += "Number>";
        }
        if (type == STRING) {
            //std::cout << "string\n";
            temp += "String>";
        }
        if (type == SYM) {
            //std::cout << "symbol\n";
            temp += "Symbol>";
        }
        if (type == SPACE) {
            //std::cout << "space\n";
            temp += "Space>";
        }
        return temp;
    }
} Pair;

Pair get_token(std::string s);
bool is_valid(std::string s);

#endif