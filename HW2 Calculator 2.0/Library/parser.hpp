// Tyler Harbert
/*
 header file for the calculator parse class
 
primary-expr -> literal | ( expr )

unary-expr -> - unary-expr
            | + unary-expr
            | ! unary-expr
            | primary-expr

multiplicative-expr -> multiplicative-expr * unary-expr
            | multiplicative-expr / unary-expr
            | multiplicative-expr % unary-expr
            | unary-expr
            
additive-expr -> additive-expr + multiplicative-expr
            | additive-expr - multiplicative-expr
            | multiplicative-expr

ordering-expr -> ordering-expr '<' additive-expr
            | ordering-expr '>' additive-expr
            | ordering-expr '<=' additive-expr
            | ordering-expr '>=' additive-expr
            | additive-expr

equality-expr -> equality-expr '==' ordering-expr
            | equality-expr '!=' ordering-expr
            | ordering-expr

logical-and-expr -> logical-and-expr '&&' equality-expr
            | equality-expr

logical-or-expr -> logical-or-expr '||' logical-and-expr
            | logical-and-expr

expr -> logical-or-expr
*/

#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <iostream>
#include "expr.hpp"
#include "token.hpp"

// the parser class uses the grammar to produce the Abstract Syntax Tree.
struct Parser {
    // holds the token stream
    TokenStream ts;

    // parser class constructor
    Parser (TokenStream);
    
    // this returns true or false for a match
    // and pops the token out of the vector on a match
    Token match_if(Token_Kind);
    
    // this pops the token out of the vector on a match
    // and returns an error if it doesnt match
    Token match(Token_Kind);
    
    // fuction to print the token attempting to be matched
    void debug_print();
    
    /*
    primary-expr -> literal | ( expr )
    */
    Expr* primary_expr();
    
    /*
    unary-expr -> - unary-expr
                | + unary-expr
                | ! unary-expr
                | primary-expr
    */
    Expr* unary_expr();
    
    /*
    multiplicative-expr -> multiplicative-expr * unary-expr
                | multiplicative-expr / unary-expr
                | multiplicative-expr % unary-expr
                | unary-expr
     */
    Expr* multiplicative_expr();
    
    /*           
    additive-expr -> additive-expr + multiplicative-expr
                | additive-expr - multiplicative-expr
                | multiplicative-expr
    */
    Expr* additive_expr();
    
    /*
    ordering-expr -> ordering-expr '<' additive-expr
                | ordering-expr '>' additive-expr
                | ordering-expr '<=' additive-expr
                | ordering-expr '>=' additive-expr
                | additive-expr
    */
    Expr* ordering_expr();
    
    /*
    equality-expr -> equality-expr '==' ordering-expr
                | equality-expr '!=' ordering-expr
                | ordering-expr
    */
    Expr* equality_expr();
    
    /*
    logical-and-expr -> logical-and-expr '&&' equality-expr
                | equality-expr
    */
    Expr* logical_and_expr();
    
    /*
    logical-or-expr -> logical-or-expr '||' logical-and-expr
                | logical-and-expr
    */
    Expr* logical_or_expr();
    
    /*
    expr -> logical-or-expr
    */
    Expr* expr();
};

#endif
