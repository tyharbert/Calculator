// Tyler Harbert
// header file for the evaluation procedures for evaluating the expression,
// printing the s-expression and printing the post fix notation.

#ifndef EVAL_HPP
#define EVAL_HPP

#include "ast.hpp"
#include <iostream>

// Evaluation class
// This class uses the visitor pattern to traverse from the root node to the
// digit nodes to get the digit values. Within the operator classes the result
// must be saved into a temporary integer after the first except so that it is not
// overwritten by the value of the next.
struct Eval:Visit {
    Eval () {
        result = 0;
    }

    int result;

    void visit(Dig const* e) { result = e->value; };
    void visit(Add const* e) { e->e1->accept(*this); int temp = result; e->e2->accept(*this); result = temp + result; };
    void visit(Sub const* e) { e->e1->accept(*this); int temp = result; e->e2->accept(*this); result = temp - result; };
    void visit(Mul const* e) { e->e1->accept(*this); int temp = result; e->e2->accept(*this); result = temp * result; };
    void visit(Div const* e) { e->e1->accept(*this); int temp = result; e->e2->accept(*this); result = temp / result; };
    void visit(Mod const* e) { e->e1->accept(*this); int temp = result; e->e2->accept(*this); result = temp % result; };
};

// S-Expression Class
// This class uses the visitor pattern to visit each node of the AST. The operator is printed before the digits
// in each of the operator classes.
struct S_Expr:Visit {
    void visit(Dig const* e) { std::cout << e->value << " "; };
    void visit(Add const* e) { std::cout << "(+ "; e->e1->accept(*this); e->e2->accept(*this); std::cout << "\b) "; };
    void visit(Sub const* e) { std::cout << "(- "; e->e1->accept(*this); e->e2->accept(*this); std::cout << "\b) "; };
    void visit(Mul const* e) { std::cout << "(* "; e->e1->accept(*this); e->e2->accept(*this); std::cout << "\b) "; };
    void visit(Div const* e) { std::cout << "(/ "; e->e1->accept(*this); e->e2->accept(*this); std::cout << "\b) "; };
    void visit(Mod const* e) { std::cout << "(% "; e->e1->accept(*this); e->e2->accept(*this); std::cout << "\b) "; };
};

// Postfix Class
// This class uses the visitor pattern to visit each node in the AST. The operator is printed after the digits
// in each of the operator classes.
struct PostFix:Visit {
    void visit(Dig const* e) { std::cout << e->value << " "; };
    void visit(Add const* e) { std::cout << "("; e->e1->accept(*this); e->e2->accept(*this); std::cout << "+)"; };
    void visit(Sub const* e) { std::cout << "("; e->e1->accept(*this); e->e2->accept(*this); std::cout << "-)"; };
    void visit(Mul const* e) { std::cout << "("; e->e1->accept(*this); e->e2->accept(*this); std::cout << "*)"; };
    void visit(Div const* e) { std::cout << "("; e->e1->accept(*this); e->e2->accept(*this); std::cout << "/)"; };
    void visit(Mod const* e) { std::cout << "("; e->e1->accept(*this); e->e2->accept(*this); std::cout << "%)"; };
};

# endif
