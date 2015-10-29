//Tyler Harbert
// code file for the evaluation procedures for evaluating the expression,
// printing the s-expression and printing the post fix notation.

#include <iostream>
#include "eval.hpp"

// throw an exception if the integer is a zero
int validate_divide_0(int i){
    if (i == 0)
        throw std::runtime_error("Divide by 0 error.");
    
    return i;
}

// Evaluation function
// This function uses the visitor pattern to traverse the AST andevaluate the expression
int eval(Expr const* e){
    
//    struct V: Visit {
//        int result;
//        void visit(Dig const* e) { result = e->value; };
//        void visit(Add const* e) { result = eval(e->e1) + eval(e->e2); };
//        void visit(Sub const* e) { result = eval(e->e1) - eval(e->e2);  };
//        void visit(Mul const* e) { result = eval(e->e1) * eval(e->e2);  };
//        void visit(Div const* e) { result = eval(e->e1) / validate_divide_0(eval(e->e2));  };
//        void visit(Mod const* e) { result = eval(e->e1) % eval(e->e2);  };
//    };
//    
//    V v;
//    e->accept(v);
    return 0;//v.result;
}