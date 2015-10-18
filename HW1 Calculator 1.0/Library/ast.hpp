// Tyler Harbert
// header file for the class representation of the
// Abstract Syntax Tree.
// e := e1 + e2
//      e1 - e2
//      e1 * e2
//      e1 / e2
//      e1 % e2
//      [0-9]

#ifndef AST_HPP
#define AST_HPP

// forward declarations of AST classes to allow
// for the Visit class to be declared
struct Dig;
struct Add;
struct Sub;
struct Mul;
struct Div;
struct Mod;

// declaration of the visit class that is used to traverse the AST
struct Visit {
    virtual void visit(Dig const* e) = 0;
    virtual void visit(Add const* e) = 0;
    virtual void visit(Sub const* e) = 0;
    virtual void visit(Mul const* e) = 0;
    virtual void visit(Div const* e) = 0;
    virtual void visit(Mod const* e) = 0;
};

// expression class, all nodes of the AST will inherit from this class
struct Expr {
    virtual ~Expr() {}
    virtual void accept(Visit& v) const = 0;
};

// digit class, [0-9]
struct Dig:Expr {
    int value;
    Dig(int value): value(value) {}
    void accept(Visit& v) const { v.visit(this); };
};

// add class, e1 + e2
struct Add:Expr {
    Expr* e1;
    Expr* e2;
    Add(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

// subtract class, e1 - e2
struct Sub:Expr {
    Expr* e1;
    Expr* e2;
    Sub(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

// multiply class, e1 * e2
struct Mul:Expr {
    Expr* e1;
    Expr* e2;
    Mul(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

// divide class, e1 / e2
struct Div:Expr {
    Expr* e1;
    Expr* e2;
    Div(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

// modulus class, e1 % e2
struct Mod:Expr {
    Expr* e1;
    Expr* e2;
    Mod(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

#endif
