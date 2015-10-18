// Tyler Harbert
// header file for the evaluation procedures for evaluating the expression,
// printing the s-expression and printing the post fix notation.

#ifndef EVAL_HPP
#define EVAL_HPP

#include "ast.hpp"

// throw an exception if the integer is a zero
int validate_divide_0(int);

// Evaluation function
// This function uses the visitor pattern to traverse the AST and evaluate the expression
int eval(Expr const*);

// S-Expression Class
// This function uses the visitor pattern to traverse the AST and print the expression as an s expression
void s_expr(Expr const*);

// Postfix Class
// This function uses the visitor pattern to traverse the AST and print the expression in post fix notation
void post_fix(Expr const*);

# endif
