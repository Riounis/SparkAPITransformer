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
    //std::cout << "in is_valid" << std::endl;
    if (is_reserved_word(s)) {
        //std::cout << "reserved word" << std::endl;
        return true;
    }
    //std::cout << "not reserved word" << std::endl;
    if (is_identifier(s)) {
        //std::cout << "identifier" << std::endl;
        return true;
    }
    //std::cout << "not identifier" << std::endl;
    if (is_number(s)) {
        //std::cout << "number" << std::endl;
        return true;
    }
    //std::cout << "not number" << std::endl;
    if (is_string(s)) {
        //std::cout << "string" << std::endl;
        return true;
    }
    //std::cout << "not string" << std::endl;
    if (is_symbol(s)) {
        //std::cout << "symbol" << std::endl;
        return true;
    }
    //std::cout << "not symbol" << std::endl;
    if (is_space(s)) {
        //std::cout << "space" << std::endl;
        return true;
    }
    //std::cout << "not space" << std::endl;
    return false;
}
