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
//Value eval(Expr const*);
void print(Expr const*);

struct Value{
    enum Value_Type{
        INT,
        BOOL
    };
    
    int i;
    bool b;
    Value_Type t;   
};

# endif
