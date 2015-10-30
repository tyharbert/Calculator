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
    Parser::Parser (TokenStream ts) {
        this->ts = ts;
    }

    // this returns the Token on match or an error Token
    // the bool() of Token is overloaded to evaluate
    // to false only if the Token returned is an error token
    Token Parser::match_if(Token_Kind tk) {
        if (ts.eos())
            return Token();
        
        if (this->ts.peek().symbol->token() == (int)tk){
            return ts.get();
        }
        else {
            Token t = Token(error_tok, new Symbol((int)error_tok));
            return t;
        }
    }

    // this pops the token out of the vector on a match
    // and returns an error if it doesnt match
    Token Parser::match(Token_Kind tk) {
        if (ts.eos())
            return Token();
        
        if (this->ts.peek().symbol->token() == (int)tk){
            return ts.get();
        }
        
        throw std::runtime_error("Match failed for " + ts.peek().symbol->spelling() );
    }

    /*
    primary-expr -> literal | ( expr )
    */
    Expr* Parser::primary_expr() {
        if (Token t = match_if(boolean_tok))
            return new Bool_Literal_Expr(t.symbol);

        else if (Token t = match_if(integer_tok))
            return new Int_Literal_Expr(t.symbol);

        else if (match_if(lparen_tok)) {
            Expr* e = expr();
            match(rparen_tok);
            return e;
        }
        
        throw std::runtime_error("Unexpected primary expression.");
    }

    /*
    unary-expr -> - unary-expr
                | + unary-expr
                | ! unary-expr
                | primary-expr
    */
    Expr* Parser::unary_expr() {
        if(this->match_if(minus_tok)){
            Expr* e = unary_expr();
            return new Neg_Expr(e);

        }else if(this->match_if(plus_tok)){
            Expr* e = unary_expr();
            return new Pos_Expr(e);

        }else if(this->match_if(excl_tok)){
            Expr* e = unary_expr();
            return new Not_Expr(e);

        }else{
            return primary_expr();
        }
    }
    
    /*
    multiplicative-expr -> multiplicative-expr * unary-expr
                | multiplicative-expr / unary-expr
                | multiplicative-expr % unary-expr
                | unary-expr
     */
    Expr* Parser::multiplicative_expr() {
        Expr* e1 = unary_expr();
        while (true){
            if(this->match_if(star_tok)){
                Expr* e2 = unary_expr();
                e1 = new Mul_Expr(e1,e2);
                
            }else if(this->match_if(slash_tok)){
                Expr* e2 = unary_expr();
                e1 = new Div_Expr(e1,e2);
                
            }else if(this->match_if(percent_tok)){
                Expr* e2 = unary_expr();
                e1 = new Mod_Expr(e1,e2);
                
            }else{
                break;
            }
        }

        return e1;
    }
    
    /*           
    additive-expr -> additive-expr + multiplicative-expr
                | additive-expr - multiplicative-expr
                | multiplicative-expr
    */
    Expr* Parser::additive_expr() {
        Expr* e1 = multiplicative_expr();
        while (true){
            if(this->match_if(plus_tok)){
                Expr* e2 = multiplicative_expr();
                e1 = new Add_Expr(e1,e2);
                
            }else if(this->match_if(minus_tok)){
                Expr* e2 = multiplicative_expr();
                e1 = new Sub_Expr(e1,e2);
                
            }else{
                break;
            }
        }

        return e1;
    }
    
    /*
    ordering-expr -> ordering-expr '<' additive-expr
                | ordering-expr '>' additive-expr
                | ordering-expr '<=' additive-expr
                | ordering-expr '>=' additive-expr
                | additive-expr
    */
    Expr* Parser::ordering_expr() {
        Expr* e1 = additive_expr();
        while (true){
            if(this->match_if(lt_tok)){
                Expr* e2 = additive_expr();
                e1 = new Lt_Expr(e1,e2);
                
            }else if(this->match_if(gt_tok)){
                Expr* e2 = additive_expr();
                e1 = new Gt_Expr(e1,e2);
                
            }else if(this->match_if(lteq_tok)){
                Expr* e2 = additive_expr();
                e1 = new Lteq_Expr(e1,e2);
                
            }else if(this->match_if(gteq_tok)){
                Expr* e2 = additive_expr();
                e1 = new Gteq_Expr(e1,e2);
                
            }else{
                break;
            }
        }

        return e1;
    }
    
    /*
    equality-expr -> equality-expr '==' ordering-expr
                | equality-expr '!=' ordering-expr
                | ordering-expr
    */
    Expr* Parser::equality_expr() {
        Expr* e1 = ordering_expr();
        while (true){
            if(this->match_if(eq_tok)){
                Expr* e2 = ordering_expr();
                e1 = new Eq_Expr(e1,e2);
                
            }else if(this->match_if(noteq_tok)){
                Expr* e2 = ordering_expr();
                e1 = new Neq_Expr(e1,e2);
                
            }else{
                break;
            }
        }

        return e1;
    }
    
    /*
    logical-and-expr -> logical-and-expr '&&' ordering-expr
                | ordering-expr
    */
    Expr* Parser::logical_and_expr() {
        Expr* e1 = ordering_expr();
        while (true){
            if(this->match_if(logical_and_tok)){
                Expr* e2 = ordering_expr();
                e1 = new And_Expr(e1,e2);
                
            }else{
                break;
            }
        }

        return e1;
    }
    
    /*
    logical-or-expr -> logical-or-expr '||' logical-and-expr
                | logical-and-expr
    */
    Expr* Parser::logical_or_expr() {
        Expr* e1 = logical_and_expr();
        while (true){
            if(this->match_if(logical_or_tok)){
                Expr* e2 = logical_and_expr();
                e1 = new Or_Expr(e1,e2);
                
            }else{
                break;
            }
        }

        return e1;
    }
    
    /*
    expr -> logical-or-expr
    */
    Expr* Parser::expr() {
        return logical_or_expr();
    }