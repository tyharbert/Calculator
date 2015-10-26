// Tyler Harbert

#include "lexer.hpp"

Lexer::Lexer(){
    this->lookahead = 0;
    this->builder = "";
    getline(std::cin,this->input);
}

// this function consumes all whitespace characters
void Lexer::consume_whitespace(){
    char c = this->input[this->lookahead];
    
    while(isspace(c)) {
        this->lookahead++;
        c = this->input[this->lookahead];
    }
}

// this function gets the next character and adds it to the builder string
char Lexer::get(){
    char c = this->input[this->lookahead];
    builder = builder + c;
    this->lookahead++;
    
    return c;
}

// this function gets the next character without changing the lookahead
// position or builder string
char Lexer::peek(){
    return this->input[this->lookahead];
}

// this function finds the next token to parse
Token Lexer::scan(){
    this->consume_whitespace();
    
    switch(this->peek()){
        case 0: return eof();
            
        case '(': return lparen();
        case ')': return rparen();
        case '+': return plus();
        case '-': return minus();
        case '*': return star();
        case '/': return slash();
        case '%': return percent();
        case '!': return excl();
        
        case '>': return gt();
        case '<': return lt();
        case '=': return eq();
        case '&': return and();
        case '|': return or();
            
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return integer();
            
        case 't':
        case 'f':
            return boolean();
            
        default:
            return error();
    }
}


// all predefined language symbols

Token Lexer::lparen(){
    return symbol();
}

Token Lexer::rparen(){
    return symbol();
}

Token Lexer::plus(){
    return symbol();
}

Token Lexer::minus(){
    return symbol();
}

Token Lexer::star(){
    return symbol();
}

Token Lexer::slash(){
    return symbol();
}

Token Lexer::percent(){
    return symbol();
}

Token Lexer::excl(){
    // this is for !=
    if (this->peek() == '=')
        this->get();
    
    return symbol();
}

Token Lexer::gt(){
    // this is for >=
    if (this->peek() == '=')
        this->get();
    
    return symbol();
}

Token Lexer::lt(){
    // this is for <=
    if (this->peek() == '=')
        this->get();
    
    return symbol();
}

Token Lexer::eq(){
    // this is for ==
    if (this->peek() == '=')
        this->get();
    
    return symbol();
}

Token Lexer::and(){
    // this is for &&
    if (this->peek() == '&')
        this->get();
    
    return symbol();
}

Token Lexer::or(){
    // this is for ||
    if (this->peek() == '|')
        this->get();
    
    return symbol();
}

Token Lexer::integer(){
    
}

Token Lexer::boolean(){
    
}

Token Lexer::error(){
    
}