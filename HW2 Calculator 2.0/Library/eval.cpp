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
    
    struct V: Visit {
        int result;
        void visit(Dig const* e) { result = e->value; };
        void visit(Add const* e) { result = eval(e->e1) + eval(e->e2); };
        void visit(Sub const* e) { result = eval(e->e1) - eval(e->e2);  };
        void visit(Mul const* e) { result = eval(e->e1) * eval(e->e2);  };
        void visit(Div const* e) { result = eval(e->e1) / validate_divide_0(eval(e->e2));  };
        void visit(Mod const* e) { result = eval(e->e1) % eval(e->e2);  };
    };
    
    V v;
    e->accept(v);
    return v.result;
}

// S-Expression Class
// This function uses the visitor pattern to traverse the AST and print the expression as an s expression
void s_expr(Expr const* e){
    
    struct V: Visit {
        int result;
        void visit(Dig const* e) { std::cout << e->value << " "; };
        void visit(Add const* e) { std::cout << "(+ "; s_expr(e->e1); s_expr(e->e2); std::cout << "\b)"; };
        void visit(Sub const* e) { std::cout << "(- "; s_expr(e->e1); s_expr(e->e2); std::cout << "\b)";  };
        void visit(Mul const* e) { std::cout << "(* "; s_expr(e->e1); s_expr(e->e2); std::cout << "\b)";  };
        void visit(Div const* e) { std::cout << "(/ "; s_expr(e->e1); s_expr(e->e2); std::cout << "\b)";  };
        void visit(Mod const* e) { std::cout << "(% "; s_expr(e->e1); s_expr(e->e2); std::cout << "\b)";  };
    };;
    
    V v;
    e->accept(v);
}

// Postfix Class
// This function uses the visitor pattern to traverse the AST and print the expression in post fix notation
void post_fix(Expr const* e){
    
    struct V: Visit {
        int result;
        void visit(Dig const* e) { std::cout << e->value << " "; };
        void visit(Add const* e) { post_fix(e->e1); post_fix(e->e2); std::cout << "+";  };
        void visit(Sub const* e) { post_fix(e->e1); post_fix(e->e2); std::cout << "-";  };
        void visit(Mul const* e) { post_fix(e->e1); post_fix(e->e2); std::cout << "*";  };
        void visit(Div const* e) { post_fix(e->e1); post_fix(e->e2); std::cout << "/";  };
        void visit(Mod const* e) { post_fix(e->e1); post_fix(e->e2); std::cout << "%";  };
    };
    
    V v;
    e->accept(v);
}