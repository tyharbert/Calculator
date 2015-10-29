// Tyler Harbert

#include "lexer.hpp"

Lexer::Lexer(){
    this->state = (int)lexing_flag;
    this->lookahead = 0;
    this->builder = "";
    this->st = new Symbol_Table();
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
char Lexer::peek(int i){
    return this->input[this->lookahead + i];
}

// this will lex tokens
std::queue<Token> Lexer::lex(){
    Token t = Token();
    
    while(t.symbol->token() != (int)eof_tok) {
        t = this->scan();
        
        // exclude eof token because of errors while parsing
        if (t.symbol->token() != (int)eof_tok)
            this->ts.push(t);
    }
    
    if (this->state == (int)lexer_error_flag)
        throw std::runtime_error("An error occured during lexing");
    
    return this->ts;
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
        case '&': return logical_and();
        case '|': return logical_or();
        
        case 't': return boolean_true();
        case 'f': return boolean_false();
            
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
    if (this->peek(1) == '=')
        this->get();
    
    return symbol();
}

Token Lexer::gt(){
    // this is for >=
    if (this->peek(1) == '=')
        this->get();
    
    return symbol();
}

Token Lexer::lt(){
    // this is for <=
    if (this->peek(1) == '=')
        this->get();
    
    return symbol();
}

Token Lexer::eq(){
    // this is for ==
    if (this->peek(1) == '=')
        this->get();
    
    return symbol();
}

Token Lexer::logical_and(){
    // this is for &&
    if (this->peek(1) == '&')
        this->get();
    
    return symbol();
}

Token Lexer::logical_or(){
    // this is for ||
    if (this->peek(1) == '|')
        this->get();
    
    return symbol();
}

Token Lexer::boolean_true(){
    // this is for true
    if (this->peek(1) == 'r')
        this->get();
    if (this->peek(1) == 'u')
        this->get();
    if (this->peek(1) == 'e')
        this->get();
        
    return symbol();
}

Token Lexer::boolean_false(){
    // this is for true
    if (this->peek(1) == 'a')
        this->get();
    if (this->peek(1) == 'l')
        this->get();
    if (this->peek(1) == 's')
        this->get();
    if (this->peek(1) == 'e')
        this->get();
        
    return symbol();
}

// this function gets a digit
void Lexer::digit(){
    assert(isdigit(this->peek()));
    this->get();
}

// this function parses an integer
Token Lexer::integer(){
    digit();
    while(isdigit(this->peek()))
        digit();
    
    return on_integer();
}

Token Lexer::error(){
    this->state = (int)lexer_error_flag;
    std::cout << "There was an error lexing '" << this->peek() << "'";
    
    // discard
    this->get();
    builder = "";
    
    return Token();
}

Token Lexer::eof(){
    return Token(eof_tok, new Symbol((int)eof_tok));
}

Token Lexer::symbol(){
    this->get();
    return this->on_token();
}

Token Lexer::on_token(){
    Symbol* sym = st->get(this->builder);
    
    // if the symbol is not found in the table throw an error
    if (sym == nullptr){
        std::string msg = "Symbol " + this->builder + " was not found in the symbol table.";
        throw std::runtime_error(msg);
    }
    
    this->builder = "";
    
    return Token(sym->token(), sym);
}

Token Lexer::on_integer(){
  int n = stoi(builder);
  Symbol* sym = st->put<Int_Sym>(builder, integer_tok, n);
  builder = "";
    
  return Token(integer_tok, sym);
}