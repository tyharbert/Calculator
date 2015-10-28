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
    
    Token(int tk, Symbol* s): token_kind(tk), symbol(s) {}
};

// List Node Class
struct Node {
    Token data;
    Node* next;
    
    Node(Token, Node*);
};

// Linked list Class
class TokenStream {
private:
    Node* head;
    Node* tail;
    Node* current;

public:
    ~TokenStream();
    TokenStream();
    TokenStream(Token);
    void add_t(Token);
    void add_h(Token);
    Node* peek();
    Token get(bool = false);
    int length;
    
};

#endif