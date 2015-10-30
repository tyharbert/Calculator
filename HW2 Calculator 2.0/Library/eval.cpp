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
//auto eval(Expr const* e){
//    
//    struct V: Visit {
//        auto result;
//        
//        void visit(Bool_Literal_Expr const* e) { result = dynamic_cast<Bool_Sym*>(e->sym)->value; }
//        void visit(Int_Literal_Expr const* e) { result = dynamic_cast<Int_Sym*>(e->sym)->value; }
//        void visit(Or_Expr const* e) { eval(e->e1) || eval(e->e2); }
//        void visit(And_Expr const* e) { eval(e->e1) && eval(e->e2); }
//        void visit(Neq_Expr const* e) { eval(e->e1) != eval(e->e2); }
//        void visit(Eq_Expr const* e) { eval(e->e1) == eval(e->e2); }
//        void visit(Lt_Expr const* e) { eval(e->e1) < eval(e->e2); }
//        void visit(Gt_Expr const* e) { eval(e->e1) > eval(e->e2); }
//        void visit(Lteq_Expr const* e) { eval(e->e1) <= eval(e->e2); }
//        void visit(Gteq_Expr const* e) { eval(e->e1) >= eval(e->e2); }
//        void visit(Add_Expr const* e) { eval(e->e1) && eval(e->e2); }
//        void visit(Sub_Expr const* e) { eval(e->e1) - eval(e->e2); }
//        void visit(Mul_Expr const* e) { eval(e->e1) * eval(e->e2); }
//        void visit(Div_Expr const* e) { eval(e->e1) / validate_divide_0(eval(e->e2)); }
//        void visit(Mod_Expr const* e) { eval(e->e1) % eval(e->e2); }
//        void visit(Neg_Expr const* e) { !eval(e->e); }
//        void visit(Pos_Expr const* e) { eval(e->e); }
//        void visit(Not_Expr const* e) { -eval(e->e); }
//    };
//    
//    V v;
//    e->accept(v);
//    return v.result;
//}

void print(Expr const* e){
    
    struct V: Visit {
        
        void visit(Bool_Literal_Expr const* e) { std::cout << dynamic_cast<Bool_Sym*>(e->sym)->value; }
        void visit(Int_Literal_Expr const* e) { std::cout << dynamic_cast<Int_Sym*>(e->sym)->value; }
        void visit(Or_Expr const* e) {  print(e->e1); std::cout << " || "; print(e->e2); }
        void visit(And_Expr const* e) { print(e->e1); std::cout << " && "; print(e->e2); }
        void visit(Neq_Expr const* e) { print(e->e1); std::cout << " != "; print(e->e2); }
        void visit(Eq_Expr const* e) { print(e->e1); std::cout << " == "; print(e->e2); }
        void visit(Lt_Expr const* e) { print(e->e1); std::cout << " < "; print(e->e2); }
        void visit(Gt_Expr const* e) { print(e->e1); std::cout << " > "; print(e->e2); }
        void visit(Lteq_Expr const* e) { print(e->e1); std::cout << " <= "; print(e->e2); }
        void visit(Gteq_Expr const* e) { print(e->e1); std::cout << " >= "; print(e->e2); }
        void visit(Add_Expr const* e) { print(e->e1); std::cout << " + "; print(e->e2); }
        void visit(Sub_Expr const* e) { print(e->e1); std::cout << " - "; print(e->e2); }
        void visit(Mul_Expr const* e) { print(e->e1); std::cout << " * "; print(e->e2); }
        void visit(Div_Expr const* e) { print(e->e1); std::cout << " / "; print(e->e2); }
        void visit(Mod_Expr const* e) { print(e->e1); std::cout << " % "; print(e->e2); }
        void visit(Neg_Expr const* e) {  std::cout << "!"; print(e->ex);}
        void visit(Pos_Expr const* e) {  std::cout << "+"; print(e->ex);}
        void visit(Not_Expr const* e) {  std::cout << "-"; print(e->ex);}
    };
    
    V v;
    e->accept(v);
}