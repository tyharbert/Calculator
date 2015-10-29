// Tyler Harbert

#include <iostream>
#include "../Library/lexer.hpp"
#include "../Library/parser.hpp"

using namespace std;

int main()
{
    try {
        // create a lexer object
        Lexer* l = new Lexer();
        // lex the input string into a token stream
        queue<Token> ts = l->lex();
        // create a parser object, pass it the token stream
        Parser* p = new Parser(ts);
        // call the expr() function to parse the token stream
        Expr* expression = p->expr();
        cout << "made it to the end";

    }
    catch (exception& e){
        cout << "Standard exception: " << e.what() << endl;
    }

    return 0;
}
