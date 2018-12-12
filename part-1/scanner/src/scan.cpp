#include "scan.hpp"

std::vector<Pair> scan(std::string s) {
    //std::cout << "in scan\n";
    std::vector<Pair> tokens;
    std::string::iterator it = s.begin();
    std::string current_token;
    for (it; it != s.end(); ++it) {
        std::cout << current_token << " | " << *it << std::endl;
        if (*it == EOF) {
            //std::cout << "hit end of file\n";
            return tokens;
        }
        if (is_valid(current_token + *it)) {
            current_token += *it;
            //std::cout << "valid token " << current_token << std::endl;
        } else {
            std::cout << "encountered token " << get_token(current_token).to_string() << std::endl;
            tokens.push_back(get_token(current_token));
            //std::cout << "added token to list\n";
            current_token = *it;
            //std::cout << "set current token to " << current_token << std::endl;
        }
        //std::cout << "end of loop" << std::endl;
    }
    //std::cout << "out of loop\n";
    return tokens;
}
