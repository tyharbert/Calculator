// Tyler Harbert

#ifndef AST_HPP
#define AST_HPP

struct Exp;
struct Dig;
struct Add;
struct Sub;
struct Mul;
struct Div;
struct Mod;

struct Visit {
    virtual void visit(Dig const* e) = 0;
    virtual void visit(Add const* e) = 0;
    virtual void visit(Sub const* e) = 0;
    virtual void visit(Mul const* e) = 0;
    virtual void visit(Div const* e) = 0;
    virtual void visit(Mod const* e) = 0;
};

struct Expr {
    virtual ~Expr() {}
    virtual void accept(Visit& v) const = 0;
};

struct Dig:Expr {
    int value;
    Dig(int value): value(value) {}
    void accept(Visit& v) const { v.visit(this); };
};

struct Add:Expr {
    Expr* e1;
    Expr* e2;
    Add(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

struct Sub:Expr {
    Expr* e1;
    Expr* e2;
    Sub(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

struct Mul:Expr {
    Expr* e1;
    Expr* e2;
    Mul(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

struct Div:Expr {
    Expr* e1;
    Expr* e2;
    Div(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

struct Mod:Expr {
    Expr* e1;
    Expr* e2;
    Mod(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
    void accept(Visit& v) const { v.visit(this); };
};

#endif
