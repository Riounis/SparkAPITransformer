#include "scan.hpp"

std::vector<Pair> scan(std::string s) {
    std::vector<Pair> tokens;
    std::string::iterator it = s.begin();
    std::string current_token;
    for (it; it != s.end(); ++it) {
        if (*it == 'eof') {
            return tokens;
        }
        if (is_valid(current_token + *it)) {
            current_token += *it;
        } else {
            tokens.push_back(get_token(current_token));
            current_token = *it;
        }
    }
    return tokens;
}
