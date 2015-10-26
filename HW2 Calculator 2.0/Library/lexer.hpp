// Tyler Harbert

#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <iostream>
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
    
    // Token returning parsing functions
    Token scan();
    
};

#endif