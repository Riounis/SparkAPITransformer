#include <string.h>

#ifndef REGEX_HPP
#define REGEX_HPP

/*
 * Checks whether the character is a letter by verifying it is
 * either a lowercase or uppercase letter, or an underscore.
 *
 * @return whether the character is a letter
 * @param c
 */
bool is_letter(char c);

/*
 * Checks whether the character is a digit by verifying it is
 * between 0 and 9 (inclusive).
 *
 * @return whether the character is a digit
 * @param c
 */
bool is_digit(char c);

/*
 * Checks whether the string is a reserved word in the language.
 *
 * @return whether the string is a reserved word
 * @param s
 */
bool is_reserved_word( std::string s );

/*
 * Checks whether the string is an integer by verifying it is
 * composed of digits.
 *
 * @return whether the string is an integer
 * @param s
 */
bool is_integer(std::string s);

/*
 * Checks whether the string is a double by verifying it is
 * composed of an integer, a decimal point then another integer.
 *
 * @return whether the string is a double precision number
 * @param s
 */
bool is_double(std::string s);

/*
 * Checks whether the string is a number by verifying it is
 * either an integer or a double precision number.
 *
 * @return whether the string is a number
 * @param s
 */
bool is_number(std::string s);

/*
 * Checks whether the string is an identifier by verifying that it
 * begins with a letter and contains only letters and digits.
 *
 * @return whether the string is an identifier
 * @param s
 */
bool is_identifier(std::string s);

/*
 * Checks whether the string is a string by verifying that it
 * begins and ends with a double quotation mark.
 *
 * @return whether the string is a string
 * @param s
 */
bool is_string(std::string s);

/*
 * Checks whether the character is a symbol by verifying it is
 * not a letter or digit.
 *
 * @return whether the character is a symbol
 * @param c
 */
bool is_symbol(char c);

#endif
