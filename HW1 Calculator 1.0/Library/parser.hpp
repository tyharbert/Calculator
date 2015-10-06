// Tyler Harbert
// header file for the calculator parse class
// E -> E + F | E - F | F
// F -> F * T | F / T | F % T | T
// T -> D | (E)
// D -> [0-9]

#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <iostream>
#include "eval.hpp"

// the parser class uses the grammar to produce the Abstract Syntax Tree.
struct Parser {
    // holds the users input
    std::string input;
    // stores the current look ahead character value
    char lookahead;
    // contains the current index of the look ahead within the input
    unsigned int la_pos;

    // parser class constructor
    Parser ();
    // gets the next look ahead value
    void Next();
    
    // E -> E + F | E - F | F
    Expr* E();
    // F -> F * T | F / T | F % T | T
    Expr* F();
    // T -> D | (E)
    Expr* T();
};

#endif
