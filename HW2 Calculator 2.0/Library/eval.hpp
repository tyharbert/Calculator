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

# endif
