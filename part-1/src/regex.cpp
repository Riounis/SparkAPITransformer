#include "regex.hpp"

bool is_letter( char c ) {
    if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' ) {
        return true;
    }
    return false;
}

bool is_digit( char c ) {
    if ( c >= '0' && c <= '9' ) {
        return true;
    }
    return false;
}

bool is_reserved_word( std::string s ) {
    return false;
}

bool is_integer( std::string s ) {
    iterator it = s.begin();
    while ( it != s.end() ) {
        if ( !is_digit( *it ) ) {
            return false;
        }
        it++;
    }
    return true;
}

bool is_double( std::string s ) {
    std::size_t decimal_index = s.find('.');
    if ( decimal_index == std::string::npos ) {
        return false;
    }
    if ( decimal_index + 1 >= s.size() ) {
        return false;
    }
    std::string whole = s.substr(0, decimal_index);
    std::string decimal = s.substr(decimal_index + 1, s.size());
    if ( !is_integer( whole ) || !is_integer( decimal ) ) {
        return false;
    }
    return true;
}

bool is_number( std::string s ) {
    if ( is_double( s ) || is_integer ( s ) ) {
        return true;
    }
    return false;
}

bool is_identifier( std::string s ) {
    iterator it = s.begin();
    if ( !is_letter( *it ) ) {
        return false;
    }
    it++;
    while ( it != s.end() ) {
        if ( !is_letter( *it ) && !is_digit( *it ) ) {
            return false;
        }
        it++;
    }
    return true;
}

bool is_string( std::string s ) {
    if ( s[0] == '"' && s[s.size() - 1] == '"' ) {
        return true;
    }
    return false;
}

bool is_symbol( char c ) {
    if ( !is_digit( c ) && !is_letter( c ) ) {
        return true;
    }
    return false;
}
