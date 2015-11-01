//Tyler Harbert
// header file for the elaboration procedures for type checking the expression.

#ifndef ELABORATE_HPP
#define ELABORATE_HPP

#include <iostream>
#include "expr.hpp"
#include "type.hpp"

// Elaborate function
// This function uses the visitor pattern to traverse the AST and type check each expression
Type* elaborate(Expr const*);

// Different elaboration functions for each Expr type
Type* elaborate(Bool_Literal_Expr const* e);
Type* elaborate(Int_Literal_Expr const* e);
Type* elaborate(Or_Expr const* e);
Type* elaborate(And_Expr const* e); 
Type* elaborate(Neq_Expr const* e);
Type* elaborate(Eq_Expr const* e);
Type* elaborate(Lt_Expr const* e);
Type* elaborate(Gt_Expr const* e);
Type* elaborate(Lteq_Expr const* e);
Type* elaborate(Gteq_Expr const* e);
Type* elaborate(Add_Expr const* e);
Type* elaborate(Sub_Expr const* e);
Type* elaborate(Mul_Expr const* e);
Type* elaborate(Div_Expr const* e);
Type* elaborate(Mod_Expr const* e);
Type* elaborate(Neg_Expr const* e);
Type* elaborate(Pos_Expr const* e);
Type* elaborate(Not_Expr const* e);

# endif