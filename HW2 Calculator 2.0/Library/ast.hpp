// Tyler Harbert
/*
 header file for the class representation of the
 Abstract Syntax Tree.
 
 e := e1 || e2
      e1 && e2
      e1 != e2
      e1 == e2
      e1 < e2
      e1 > e2
      e1 <= e2
      e1 >= e2
      e1 + e2
      e1 - e2
      e1 * e2
      e1 / e2
      e1 % e2
      - e
      + e
      ! e
      Z (integers)
      B (booleans)
*/

#ifndef AST_HPP
#define AST_HPP

#include "symbol.hpp"

// forward declarations of AST classes to allow
// for the Visit class to be declared
struct Literal_Expr;
struct Or_Expr;
struct And_Expr;
struct Neq_Expr;
struct Eq_Expr;
struct Lt_Expr;
struct Gt_Expr;
struct Lteq_Expr;
struct Gteq_Expr;
struct Add_Expr;
struct Sub_Expr;
struct Mul_Expr;
struct Div_Expr;
struct Mod_Expr;
struct Neg_Expr;
struct Pos_Expr;
struct Not_Expr;

// declaration of the visit class that is used to traverse the AST
struct Visit {
    virtual void visit(Literal_Expr const* e) = 0;
    virtual void visit(Or_Expr const* e) = 0;
    virtual void visit(And_Expr const* e) = 0;
    virtual void visit(Neq_Expr const* e) = 0;
    virtual void visit(Eq_Expr const* e) = 0;
    virtual void visit(Lt_Expr const* e) = 0;
    virtual void visit(Gt_Expr const* e) = 0;
    virtual void visit(Lteq_Expr const* e) = 0;
    virtual void visit(Gteq_Expr const* e) = 0;
    virtual void visit(Add_Expr const* e) = 0;
    virtual void visit(Sub_Expr const* e) = 0;
    virtual void visit(Mul_Expr const* e) = 0;
    virtual void visit(Div_Expr const* e) = 0;
    virtual void visit(Mod_Expr const* e) = 0;
    virtual void visit(Neg_Expr const* e) = 0;
    virtual void visit(Pos_Expr const* e) = 0;
    virtual void visit(Not_Expr const* e) = 0;
};

// expression class, all nodes of the AST will inherit from this class
struct Expr {
    virtual ~Expr() {}
    virtual void accept(Visit& v) const = 0;
};

// literal class, Z (integers) and B (booleans)
struct Literal_Expr:Expr {
    Symbol* sym;
    Literal_Expr(Symbol* s): sym(s) {}
    void accept(Visit& v) const { v.visit(this); };
};

// OR class, e1 || e2
struct Or_Expr:Expr {
    Expr* e1;
    Expr* e2;
    Or_Expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

// AND class, e1 && e2
struct And_Expr:Expr {
    Expr* e1;
    Expr* e2;
    And_Expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

// Not equivalent class, e1 != e2
struct Neq_Expr:Expr {
    Expr* e1;
    Expr* e2;
    Neq_Expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

// Equivalent class, e1 == e2
struct Eq_Expr:Expr {
    Expr* e1;
    Expr* e2;
    Eq_Expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

// Less than class, e1 < e2
struct Lt_Expr:Expr {
    Expr* e1;
    Expr* e2;
    Lt_Expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

// Greater than class, e1 > e2
struct Gt_Expr:Expr {
    Expr* e1;
    Expr* e2;
    Gt_Expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

// Less than or equivalent class, e1 <= e2
struct Lteq_Expr:Expr {
    Expr* e1;
    Expr* e2;
    Lteq_Expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

// Greater than or equivalent class, e1 >= e2
struct Gteq_Expr:Expr {
    Expr* e1;
    Expr* e2;
    Gteq_Expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

// Add class, e1 + e2
struct Add_Expr:Expr {
    Expr* e1;
    Expr* e2;
    Add_Expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

// Sub class, e1 - e2
struct Sub_Expr:Expr {
    Expr* e1;
    Expr* e2;
    Sub_Expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

// Multiply class, e1 * e2
struct Mul_Expr:Expr {
    Expr* e1;
    Expr* e2;
    Mul_Expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

// Divide class, e1 / e2
struct Div_Expr:Expr {
    Expr* e1;
    Expr* e2;
    Div_Expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

// Mod class, e1 % e2
struct Mod_Expr:Expr {
    Expr* e1;
    Expr* e2;
    Mod_Expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

// Negative class, - e
struct Neg_Expr:Expr {
    Expr* ex;
    Neg_Expr(Expr* e) : ex(e) {}
    void accept(Visit& v) const { v.visit(this); };
};

// Positive class, + e
struct Pos_Expr:Expr {
    Expr* ex;
    Pos_Expr(Expr* e) : ex(e) {}
    void accept(Visit& v) const { v.visit(this); };
};

// NOT class, ! e
struct Not_Expr:Expr {
    Expr* ex;
    Not_Expr(Expr* e) : ex(e) {}
    void accept(Visit& v) const { v.visit(this); };
};

#endif
