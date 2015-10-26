// Tyler Harbert

#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <iostream>
#include <cassert>
#include "token.hpp"

struct Lexer {
    // holds the user's input
    std::string input;
    // hold's the current token
    std::string builder;
    // contains the current index of the begining and end of a token
    unsigned int lookahead;

    // lexer class constructor
    Lexer();
    
    // get and peek functions
    void consume_whitespace();
    char get();
    char peek();
    void digit();
    
    // Token returning parsing functions
    Token scan();
    Token lparen();
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
    Token and();
    Token or();
    Token integer();
    Token boolean();
    Token error();
    
    // all predefined language symbols
    Token symbol();
    // called at the end of parsing an integer
    Token on_integer();
    // called at the end of parsing a predefined symbol
    Token on_token();
};

#endif