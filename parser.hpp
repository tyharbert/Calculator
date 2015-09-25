// Tyler Harbert

#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <iostream>
#include "eval.hpp"

// the parser class is used to evaluate the
// user input into the abstract syntax tree format.
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
    // expression node parse function
    Expr* E();
    // factor node parse function
    Expr* F();
    // term node parse function
    Expr* T();
};

#endif
