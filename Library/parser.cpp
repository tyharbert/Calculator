// Tyler Harbert
// code file for the functions of the parser class
// E -> E + F | E - F | F
// F -> F * T | F / T | F % T | T
// T -> D | (E)
// D -> [0-9]

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
    void Parser::Next() {
        do {
            if (la_pos == input.size() - 1)
                break;
            la_pos++;
        } while (isspace(input[la_pos]));
        lookahead = input[la_pos];
    }

    // Implements the following part of the grammar
    // E -> E + F | E - F | F
    Expr* Parser::E() {
        Expr* e1 = F();
        while (true){
            if(lookahead == '+'){
                Next();
                Expr* e2 = F();
                e1 = new Add(e1,e2);
            }else if (lookahead == '-') {
                Next();
                Expr* e2 = F();
                e1 = new Sub(e1,e2);
            }else{
                break;
            }
        }
        return e1;
    }

    // Implements the following part of the grammar
    // F -> F * T | F / T | F % T | T
    Expr* Parser::F() {
        Expr* e1 = T();
        while (true){
            if (lookahead == '*'){
                Next();
                Expr* e2 = T();
                e1 = new Mul(e1,e2);
            }else if (lookahead == '/'){
                Next();
                Expr* e2 = T();
                e1 = new Div(e1,e2);
            }else if (lookahead == '%'){
                Next();
                Expr* e2 = T();
                e1 = new Mod(e1,e2);
            }else {
                break;
            }
        }
        return e1;
    }

    // Implements the following part of the grammar
    // T -> D | (E)
    Expr* Parser::T() {
        while (true){
            if (lookahead == '0') { Next(); return new Dig(0);}
            else if (lookahead == '1') { Next(); return new Dig(1);}
            else if (lookahead == '2') { Next(); return new Dig(2);}
            else if (lookahead == '3') { Next(); return new Dig(3);}
            else if (lookahead == '4') { Next(); return new Dig(4);}
            else if (lookahead == '5') { Next(); return new Dig(5);}
            else if (lookahead == '6') { Next(); return new Dig(6);}
            else if (lookahead == '7') { Next(); return new Dig(7);}
            else if (lookahead == '8') { Next(); return new Dig(8);}
            else if (lookahead == '9') { Next(); return new Dig(9);}
            else if (lookahead == '(') {
                Next();
                Expr* e1 = E();

                if (lookahead == ')')
                    Next();

                return e1;
            }
            else{
                std::cout << "Error.";
            }
        }
    }
