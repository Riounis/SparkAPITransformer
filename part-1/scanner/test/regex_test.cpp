#include "regex.hpp"

#define PASS 1
#define FAIL 0

/************************ IS LETTER TEST ***************************/
bool is_letter_test() {
    bool fail = false;
    cout << "is_letter tests:\n";
    if ( is_letter_boundary_test() ) {
        cout << "Passed Boundary Value Test for function: is_letter\n";
    } else { 
        cout << "Failed Boundary Value Test for function: is_letter\n";
        fail = true;
    }
    if ( is_letter_average_test() ) {
        cout << "Passed Average Value Test for function: is_letter\n";
    } else {
        cout << "Failed Average Value Test for function: is_letter\n";
        fail = true;
    }
    if ( fail ) {
        return FAIL;
    }
    cout << "All tests for function is_letter passed!\n";
    return PASS;
}

bool is_letter_boundary_test() {
    if ( !is_letter('a') || !is_letter('A') || !is_letter('z') ||
        !is_letter('Z') || !is_letter('_') ) {
        return FAIL;
    }
    if ( is_letter('a' - 1) || is_letter('A' + 1) ||
        is_letter('z' - 1) || is_letter('Z' + 1) ||
        is_letter('_' - 1) || is_letter('_' + 1) ) {
        return FAIL;
    }
    return PASS;
}

bool is_letter_average_test() {
    if ( !is_letter('m') || !is_letter('P') || is_letter('%') ||
        is_letter('^') || is_letter('}') ) {
        return FAIL;
    }
    return PASS:
}

/************************ IS DIGIT TEST ****************************/
bool is_digit_test() {
    bool fail = false;
    cout << "is_digit tests:\n";
    if ( is_digit_boundary_test() ) {
        cout << "Passed Boundary Value Test for function: is_digit\n";
    } else { 
        cout << "Failed Boundary Value Test for function: is_digit\n";
        fail = true;
    }
    if ( is_digit_average_test() ) {
        cout << "Passed Average Value Test for function: is_digit\n";
    } else {
        cout << "Failed Average Value Test for function: is_digit\n";
        fail = true;
    }
    if ( fail ) {
        return FAIL;
    }
    cout << "All tests for function is_digit passed!\n";
    return PASS;
}

bool is_digit_boundary_test() {
    if ( !is_digit('0') || !is_digit('9') ) {
        return FAIL;
    }
    if ( is_digit('0' - 1) || is_digit('9' + 1) ) {
        return FAIL;
    }
    return PASS;
}

bool is_digit_average_test() {
    if ( !is_digit('5') || is_digit('+') || is_digit('a') ) {
        return FAIL;
    }
    return PASS;
}

/******************** IS RESERVED WORD TEST ************************/
bool is_reserved_word_test() {
    cout << "is_reserved_word tests:\n";
    cout << "Not yet implemented\n";
    return PASS;
}

/*********************** IS INTEGER TEST ***************************/
bool is_integer_test() {
    cout << "is_integer tests:\n";
    cout << "Not yet implemented\n";
    return PASS;
}

/************************ IS DOUBLE TEST ***************************/
bool is_double_test() {
    cout << "is_double tests:\n";
    cout << "Not yet implemented\n";
    return PASS;
}

/************************ IS NUMBER TEST ***************************/
bool is_number_test() {
    cout << "is_number tests:\n";
    cout << "Not yet implemented\n";
    return PASS;
}

/********************** IS IDENTIFIER TEST *************************/
bool is_identifier_test() {
    cout << "is_identifier tests:\n";
    cout << "Not yet implemented\n";
    return PASS;
}

/************************ IS STRING TEST ***************************/
bool is_string_test() {
    cout << "is_string tests:\n";
    cout << "Not yet implemented\n";
    return PASS;
}

/************************ IS SYMBOL TEST ***************************/
bool is_symbol_test() {
    cout << "is_symbol tests:\n";
    cout << "Not yet implemented\n";
    return PASS;
}
