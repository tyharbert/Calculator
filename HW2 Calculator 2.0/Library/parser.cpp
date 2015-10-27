// getting int and bool value dynamic_cast<Int_Sym*>(t1.symbol)->value

// Tyler Harbert
// code file for the functions of the parser class
// E -> E + F | E - F | F
// F -> F * T | F / T | F % T | T
// T -> D | (E)
// D -> [0-9]

#include <string>
#include "parser.hpp"

    // parser class constructor, gets the users input and initializes look ahead.
    Parser::Parser () {
        la_pos = 0;
        getline(std::cin,input);
        while (isspace(input[la_pos])) {
            la_pos++;
        }
        lookahead = input[la_pos];
    }

    // gets the next look ahead value that is not a whitespace
    // and stops at the last position of the users input
    void Parser::next() {
        do {
            if (la_pos == input.size() - 1)
                break;
            la_pos++;
        } while (isspace(input[la_pos]));
        lookahead = input[la_pos];
    }

    // Implements the following part of the grammar
    // E -> E + F | E - F | F
    Expr* Parser::expression() {
        Expr* e1 = factor();
        while (true){
            if(lookahead == '+'){
                next();
                Expr* e2 = factor();
                e1 = new Add(e1,e2);
            }else if (lookahead == '-') {
                next();
                Expr* e2 = factor();
                e1 = new Sub(e1,e2);
            }else{
                break;
            }
        }
        return e1;
    }

    // Implements the following part of the grammar
    // F -> F * T | F / T | F % T | T
    Expr* Parser::factor() {
        Expr* e1 = term();
        while (true){
            if (lookahead == '*'){
                next();
                Expr* e2 = term();
                e1 = new Mul(e1,e2);
            }else if (lookahead == '/'){
                next();
                Expr* e2 = term();
                e1 = new Div(e1,e2);
            }else if (lookahead == '%'){
                next();
                Expr* e2 = term();
                e1 = new Mod(e1,e2);
            }else {
                break;
            }
        }
        return e1;
    }

    // Implements the following part of the grammar
    // T -> D | (E)
    Expr* Parser::term() {
        while (true){
            switch (lookahead){
                case '0':
                    next(); return new Dig(0);
                case '1':
                    next(); return new Dig(1);
                case '2':
                    next(); return new Dig(2);
                case '3':
                    next(); return new Dig(3);
                case '4':
                    next(); return new Dig(4);
                case '5':
                    next(); return new Dig(5);
                case '6':
                    next(); return new Dig(6);
                case '7':
                    next(); return new Dig(7);
                case '8':
                    next(); return new Dig(8);
                case '9':
                    next(); return new Dig(9);
                case '(':
                {
                    next();
                    Expr* e1 = expression();

                    if (lookahead == ')')
                        next();

                    return e1;
                }
                default:
                {
                    std::string msg = "Syntax Error, ";
                    msg += lookahead;
                    msg += " is not a digit or an open parenthesis.";
                    throw std::runtime_error(msg);
                }
            }
        }
    }
