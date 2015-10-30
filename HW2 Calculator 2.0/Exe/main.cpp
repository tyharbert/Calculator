// Tyler Harbert

#include <iostream>
#include "../Library/lexer.hpp"
#include "../Library/parser.hpp"
#include "../Library/eval.hpp"
#include "../Library/value.hpp"

using namespace std;

int main()
{
    try {
        // create a lexer object
        Lexer* l = new Lexer();
        // lex the input string into a token stream
        TokenStream ts = l->lex();
        // create a parser object, pass it the token stream
        Parser* p = new Parser(ts);
        // call the expr() function to parse the token stream
        Expr* ast = p->expr();
        
        print(ast);
        cout << endl;

    }
    catch (exception& e){
        cout << "Standard exception: " << e.what() << endl;
    }

    return 0;
}
