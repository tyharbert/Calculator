// Tyler Harbert
// header file for the lexer class

#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <iostream>
#include <cassert>
#include "token.hpp"
#include "symbol.hpp"

// Lexer state flag definitions
enum Lexer_States {
    lexing_flag,
    lexer_error_flag
};

struct Lexer {
    // holds the user's input
    std::string input;
    // hold's the current token
    std::string builder;
    // contains the current index of the begining and end of a token
    unsigned int lookahead;
    // symbol table
    Symbol_Table* st;
    // token stream
    TokenStream ts;
    // this contains the state of the lexer
    int state;

    // lexer class constructor
    Lexer();
    
    // get and peek functions
    void consume_whitespace();
    char get();
    char peek(int = 0);
    void digit();
    
    TokenStream lex();
    
    // Token returning parsing functions
    Token scan();
    Token lparen();
    Token rparen();
    Token plus();
    Token minus();
    Token star();
    Token slash();
    Token percent();
    Token excl();
    Token gt();
    Token lt();
    Token eq();
    Token logical_and();
    Token logical_or();
    Token boolean_true();
    Token boolean_false();
    Token integer();
    Token error();
    Token eof();
    
    // all predefined language symbols
    Token symbol();
    // called at the end of parsing an integer
    Token on_integer();
    // called at the end of parsing a predefined symbol
    Token on_token();
};

#endif