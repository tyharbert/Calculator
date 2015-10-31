//Tyler Harbert
// code file for the evaluation procedures for evaluating the expression,
// printing the s-expression and printing the post fix notation.

#include "elaborate.hpp"

// Evaluation function
// This function uses the visitor pattern to traverse the AST andevaluate the expression
Type* elaborate(Expr const* e){
    
    struct V: Visit {
        Type* result;
        
        void visit(Bool_Literal_Expr const* e) { result = elaborate(e); }
        void visit(Int_Literal_Expr const* e) { result = elaborate(e); }
        void visit(Or_Expr const* e) { result = elaborate(e); }
        void visit(And_Expr const* e) { result = elaborate(e); }
        void visit(Neq_Expr const* e) { result = elaborate(e); }
        void visit(Eq_Expr const* e) { result = elaborate(e); }
        void visit(Lt_Expr const* e) { result = elaborate(e); }
        void visit(Gt_Expr const* e) { result = elaborate(e); }
        void visit(Lteq_Expr const* e) { result = elaborate(e); }
        void visit(Gteq_Expr const* e) { result = elaborate(e); }
        void visit(Add_Expr const* e) { result = elaborate(e); }
        void visit(Sub_Expr const* e) { result = elaborate(e); }
        void visit(Mul_Expr const* e) { result = elaborate(e); }
        void visit(Div_Expr const* e) { result = elaborate(e); }
        void visit(Mod_Expr const* e) { result = elaborate(e); }
        void visit(Neg_Expr const* e) { result = elaborate(e); }
        void visit(Pos_Expr const* e) { result = elaborate(e); }
        void visit(Not_Expr const* e) { result = elaborate(e); }
    };
    
    V v;
    e->accept(v);
    return v.result;
}

Type* elaborate(Bool_Literal_Expr const* e){
    return get_bool_type();
}

Type* elaborate(Int_Literal_Expr const* e){
    return get_int_type();
}

Type* elaborate(Or_Expr const* e){
    Type* ref = get_bool_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == ref)
        if (t2 == ref)
            return ref;
    
    throw std::runtime_error("|| type error.");
}

Type* elaborate(And_Expr const* e){
    Type* ref = get_bool_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == ref)
        if (t2 == ref)
            return ref;
    
    throw std::runtime_error("&& type error.");
}

Type* elaborate(Neq_Expr const* e){
    Type* ref1 = get_bool_type();
    Type* ref2 = get_int_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == ref1)
        if (t2 == ref1)
            return ref1;
    
    if (t1 == ref2)
        if (t2 == ref2)
            return ref2;
    
    throw std::runtime_error("!= type error.");
}

Type* elaborate(Eq_Expr const* e){
    Type* ref1 = get_bool_type();
    Type* ref2 = get_int_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == ref1)
        if (t2 == ref1)
            return ref1;
    
    if (t1 == ref2)
        if (t2 == ref2)
            return ref2;
    
    throw std::runtime_error("== type error.");
}

Type* elaborate(Lt_Expr const* e){
    Type* ref = get_int_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == ref)
        if (t2 == ref)
            return ref;
    
    throw std::runtime_error("< type error.");
}

Type* elaborate(Gt_Expr const* e){
    Type* ref = get_int_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == ref)
        if (t2 == ref)
            return ref;
    
    throw std::runtime_error("> type error.");
}

Type* elaborate(Lteq_Expr const* e){
    Type* ref = get_int_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == ref)
        if (t2 == ref)
            return ref;
    
    throw std::runtime_error("<= type error.");
}

Type* elaborate(Gteq_Expr const* e){
    Type* ref = get_int_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == ref)
        if (t2 == ref)
            return ref;
    
    throw std::runtime_error(">= type error.");
}

Type* elaborate(Add_Expr const* e){
    Type* ref = get_int_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == ref)
        if (t2 == ref)
            return ref;
    
    throw std::runtime_error("add type error.");
}

Type* elaborate(Sub_Expr const* e){
    Type* ref = get_int_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == ref)
        if (t2 == ref)
            return ref;
    
    throw std::runtime_error("subtract type error.");
}

Type* elaborate(Mul_Expr const* e){
    Type* ref = get_int_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == ref)
        if (t2 == ref)
            return ref;
    
    throw std::runtime_error("* type error.");
}

Type* elaborate(Div_Expr const* e){
    Type* ref = get_int_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == ref)
        if (t2 == ref)
            return ref;
    
    throw std::runtime_error("/ type error.");
}

Type* elaborate(Mod_Expr const* e){
    Type* ref = get_int_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == ref)
        if (t2 == ref)
            return ref;
    
    throw std::runtime_error("% type error.");
}

Type* elaborate(Neg_Expr const* e){
    Type* ref = get_bool_type();
    Type* t = elaborate(e->ex);
    
    if (t == ref)
        return ref;
    
    throw std::runtime_error("! type error.");
}

Type* elaborate(Pos_Expr const* e){
    Type* ref = get_int_type();
    Type* t = elaborate(e->ex);
    
    if (t == ref)
        return ref;
    
    throw std::runtime_error("negative type error.");
}

Type* elaborate(Not_Expr const* e){
    Type* ref = get_int_type();
    Type* t = elaborate(e->ex);
    
    if (t == ref)
        return ref;
    
    throw std::runtime_error("positive type error.");
}