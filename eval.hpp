// Tyler Harbert

#ifndef EVAL_HPP
#define EVAL_HPP

#include "ast.hpp"

struct Eval:Visit {
    Eval () {
        result = 0;
    }

    int result;

    void visit(Dig const* e) { result = e->value; };
    void visit(Add const* e) { e->e1->accept(*this); int temp1 = result; e->e2->accept(*this); result = temp1 + result; };
    void visit(Sub const* e) { e->e1->accept(*this); int temp1 = result; e->e2->accept(*this); result = temp1 - result; };
    void visit(Mul const* e) { e->e1->accept(*this); int temp1 = result; e->e2->accept(*this); result = temp1 * result; };
    void visit(Div const* e) { e->e1->accept(*this); int temp1 = result; e->e2->accept(*this); result = temp1 / result; };
    void visit(Mod const* e) { e->e1->accept(*this); int temp1 = result; e->e2->accept(*this); result = temp1 % result; };
};

# endif
