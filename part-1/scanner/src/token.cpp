#include "token.hpp"

Pair get_token(std::string s) {
    Pair *ret = new Pair;
    ret->token = s;
    if (is_reserved_word(s)) {
        ret->type = RESWORD;
    }
    if (is_identifier(s)) {
        ret->type = ID;
    }
    if (is_number(s)) {
        ret->type = NUM;
    }
    if (is_string(s)) {
        ret->type = STRING;
    }
    if (is_symbol(s)) {
        ret->type = SYM;
    }
    if (is_space(s)) {
        ret->type = SPACE;
    }
    return *ret;
}

bool is_valid(std::string s) {
    if (is_reserved_word(s)) {
        return true;
    }
    if (is_identifier(s)) {
        return true;
    }
    if (is_number(s)) {
        return true;
    }
    if (is_string(s)) {
        return true;
    }
    if (is_symbol(s)) {
        return true;
    }
    if (is_space(s)) {
        return true;
    }
    return false;
}
