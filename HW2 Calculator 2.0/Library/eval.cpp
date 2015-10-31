//Tyler Harbert
// code file for the evaluation procedures for evaluating the expression,
// printing the s-expression and printing the post fix notation.

#include "eval.hpp"

// Evaluation function
// This function uses the visitor pattern to traverse the AST andevaluate the expression
Value eval(Expr const* e){
    
    struct V: Visit {
        Value result;
        
        void visit(Bool_Literal_Expr const* e) { result = eval(e); }
        void visit(Int_Literal_Expr const* e) { result = eval(e); }
        void visit(Or_Expr const* e) { result = eval(e); }
        void visit(And_Expr const* e) { result = eval(e); }
        void visit(Neq_Expr const* e) { result = eval(e); }
        void visit(Eq_Expr const* e) { result = eval(e); }
        void visit(Lt_Expr const* e) { result = eval(e); }
        void visit(Gt_Expr const* e) { result = eval(e); }
        void visit(Lteq_Expr const* e) { result = eval(e); }
        void visit(Gteq_Expr const* e) { result = eval(e); }
        void visit(Add_Expr const* e) { result = eval(e); }
        void visit(Sub_Expr const* e) { result = eval(e); }
        void visit(Mul_Expr const* e) { result = eval(e); }
        void visit(Div_Expr const* e) { result = eval(e); }
        void visit(Mod_Expr const* e) { result = eval(e); }
        void visit(Neg_Expr const* e) { result = eval(e); }
        void visit(Pos_Expr const* e) { result = eval(e); }
        void visit(Not_Expr const* e) { result = eval(e); }
    };
    
    V v;
    e->accept(v);
    return v.result;
}

Value eval(Bool_Literal_Expr const* e){
    return dynamic_cast<Bool_Sym*>(e->sym)->value;
}

Value eval(Int_Literal_Expr const* e){
    return dynamic_cast<Int_Sym*>(e->sym)->value;
}

Value eval(Or_Expr const* e){
    Value v1 = eval(e->e1);
    Value v2 = eval(e->e2);
    return v1.get_bool() || v2.get_bool();
}

Value eval(And_Expr const* e){
    Value v1 = eval(e->e1);
    Value v2 = eval(e->e2);
    return v1.get_bool() && v2.get_bool();
}

Value eval(Neq_Expr const* e){
    Value v1 = eval(e->e1);
    Value v2 = eval(e->e2);
    
    if (v1.type() == v2.type()){
        if (v1.is_bool())
            return v1.get_bool() != v2.get_bool();
        else
            return v1.get_int() != v2.get_int();
    }
    
    throw std::runtime_error("cannont compare different types.");
}

Value eval(Eq_Expr const* e){
    Value v1 = eval(e->e1);
    Value v2 = eval(e->e2);
    
    if (v1.type() == v2.type()){
        if (v1.is_bool())
            return v1.get_bool() == v2.get_bool();
        else
            return v1.get_int() == v2.get_int();
    }
    
    throw std::runtime_error("cannont compare different types.");
}

Value eval(Lt_Expr const* e){
    Value v1 = eval(e->e1);
    Value v2 = eval(e->e2);
    return v1.get_int() < v2.get_int();
}

Value eval(Gt_Expr const* e){
    Value v1 = eval(e->e1);
    Value v2 = eval(e->e2);
    return v1.get_int() > v2.get_int();
}

Value eval(Lteq_Expr const* e){
    Value v1 = eval(e->e1);
    Value v2 = eval(e->e2);
    return v1.get_int() <= v2.get_int();
}

Value eval(Gteq_Expr const* e){
    Value v1 = eval(e->e1);
    Value v2 = eval(e->e2);
    return v1.get_int() >= v2.get_int();
}

Value eval(Add_Expr const* e){
    Value v1 = eval(e->e1);
    Value v2 = eval(e->e2);
    return v1.get_int() + v2.get_int();
}

Value eval(Sub_Expr const* e){
    Value v1 = eval(e->e1);
    Value v2 = eval(e->e2);
    return v1.get_int() - v2.get_int();
}

Value eval(Mul_Expr const* e){
    Value v1 = eval(e->e1);
    Value v2 = eval(e->e2);
    return v1.get_int() * v2.get_int();
}

Value eval(Div_Expr const* e){
    Value v1 = eval(e->e1);
    Value v2 = eval(e->e2);
    
    if (v2.get_int() == 0)
        throw std::runtime_error("Divide by 0 error.");
    
    return v1.get_int() / v2.get_int();
}

Value eval(Mod_Expr const* e){
    Value v1 = eval(e->e1);
    Value v2 = eval(e->e2);
    return v1.get_int() % v2.get_int();
}

Value eval(Neg_Expr const* e){
    Value v = eval(e->ex);
    return !v.get_bool();
}

Value eval(Pos_Expr const* e){
    Value v = eval(e->ex);
    return +v.get_int();
}

Value eval(Not_Expr const* e){
    Value v = eval(e->ex);
    return -v.get_int();
}


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
    std::cout << std::endl;
}