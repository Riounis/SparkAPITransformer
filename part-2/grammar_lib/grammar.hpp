#ifndef GRAMMAR_HPP
#define GRAMMAR_HPP

/*
 *
 *
 * @param 
 * @return
 */
bool is_program();

/*
 *
 *
 * @param 
 * @return
 */
bool is_map_ops();

/*
 *
 *
 * @param 
 * @return
 */
bool is_udf();

/*
 *
 *
 * @param 
 * @return
 */
bool is_expression();

/*
 *
 *
 * @param 
 * @return
 */
bool is_simple_expr();

/*
 *
 *
 * @param 
 * @return
 */
bool is_tuple_expr();

/*
 *
 *
 * @param 
 * @return
 */
bool is_complex_expr();

/*
 *
 *
 * @param 
 * @return
 */
bool is_assign_expr();

/*
 *
 *
 * @param 
 * @return
 */
bool is_pure_expr();

/*
 *
 *
 * @param 
 * @return
 */
bool is_comp_expr();

/*
 *
 *
 * @param 
 * @return
 */
bool is_op();

/*
 * Returns whether the token is a comparison operator
 *
 * @param 
 * @return
 */
bool is_comp();

#endif