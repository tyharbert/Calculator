// Tyler Harbert

#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "symbol.hpp"

// Token kinds
enum Token_Kind
{
    error_tok = -2,
    eof_tok = -1,
    lparen_tok,//0
    rparen_tok,//1
    plus_tok,//2
    minus_tok,//3
    star_tok,//4
    slash_tok,//5
    percent_tok,//6
    excl_tok,//7
    gt_tok,//8
    lt_tok,//9
    gteq_tok,//10
    lteq_tok,//11
    eq_tok,//12
    noteq_tok,//13
    logical_and_tok,//14
    logical_or_tok,//15
    integer_tok,//16
    boolean_tok//17
};

// Token class
struct Token {
    int token_kind; 
    Symbol* symbol;
    
    explicit operator bool() const;
    
    Token(int tk, Symbol* s): token_kind(tk), symbol(s) {}
    Token(): token_kind((int)error_tok), symbol(new Symbol((int)error_tok)) {}
};

// This must be added to allow the match_if function
// to evaluate to false only if an error token is returned
inline Token::operator bool() const
{
  return token_kind != (int)error_tok;
}

#endif