// TEMP
// getting int and bool value dynamic_cast<Int_Sym*>(t1.symbol)->value

//        Token t;
//        do {
//            t = ts.get();
//            cout << t.symbol->spelling() << endl;
//        }while(t.symbol->token() != (int)eof_tok);
//        

// Tyler Harbert
/*
code file for the functions of the parser class
 
primary-expr -> literal | ( expr )

unary-expr -> - unary-expr
            | + unary-expr
            | ! unary-expr
            | primary-expr

multiplicative-expr -> multiplicative-expr * unary-expr
            | multiplicative-expr / unary-expr
            | multiplicative-expr % unary-expr
            | unary-expr
            
additive-expr -> additive-expr + multiplicative-expr
            | additive-expr - multiplicative-expr
            | multiplicative-expr

ordering-expr -> ordering-expr '<' additive-expr
            | ordering-expr '>' additive-expr
            | ordering-expr '<=' additive-expr
            | ordering-expr '>=' additive-expr
            | additive-expr

equality-expr -> equality-expr '==' ordering-expr
            | equality-expr '!=' ordering-expr
            | ordering-expr

logical-and-expr -> logical-and-expr '&&' ordering-expr
            | ordering-expr

logical-or-expr -> logical-or-expr '||' logical-and-expr
            | logical-and-expr

expr -> logical-or-expr
*/

#include <string>
#include "parser.hpp"

    // parser class constructor, gets the users input and initializes look ahead.
    Parser::Parser (std::vector<Token> ts) {
        this->ts = ts;
    }

    bool Parser::match_if(Token_Kind tk) {
        if (this->ts.back().symbol->token() == (int)tk){
            this->ts.pop_back();
            return true;
        }
        else
            return false;
    }

    /*
    primary-expr -> literal | ( expr )
    */
    Expr* Parser::primary_expr() {
        Expr* e1;
//        while (true){
//            if(lookahead == '+'){
//                next();
//                Expr* e2 = factor();
//                e1 = new Add(e1,e2);
//            }else if (lookahead == '-') {
//                next();
//                Expr* e2 = factor();
//                e1 = new Sub(e1,e2);
//            }else{
//                break;
//            }
//        }
        return e1;
    }
