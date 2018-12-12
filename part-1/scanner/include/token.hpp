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
        std::string temp = "<"+token+", ";
        if (type == RESWORD) {
            temp += "Reserved Word>";
        }
        if (type == ID) {
            temp += "Identifier>";
        }
        if (type == NUM) {
            temp += "Number>";
        }
        if (type == STRING) {
            temp += "String>";
        }
        if (type == SYM) {
            temp += "Symbol>";
        }
        if (type == SPACE) {
            temp += "Space>";
        }
    }
} Pair;

Pair get_token(std::string s);
bool is_valid(std::string s);

#endif