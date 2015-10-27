// Tyler Harbert

#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "symbol.hpp"

// Token kinds
enum Token_Kind
{
    error_tok = -2,
    eof_tok = -1,
    lparen_tok,
    rparen_tok,
    plus_tok,
    minus_tok,
    star_tok,
    slash_tok,
    percent_tok,
    excl_tok,
    gt_tok,
    lt_tok,
    gteq_tok,
    lteq_tok,
    eq_tok,
    noteq_tok,
    logical_and_tok,
    logical_or_tok,
    integer_tok,
    boolean_tok
};

// Token class
struct Token {
    int token_kind; 
    Symbol* symbol;
    
    Token(int tk, Symbol* s): token_kind(tk), symbol(s) {}
};

#endif