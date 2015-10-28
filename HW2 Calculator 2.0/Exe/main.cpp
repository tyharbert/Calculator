// Tyler Harbert

#include <iostream>
#include "../Library/comp_lib.hpp"

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
        
        if (p->match_if(eq_tok))
            cout << "true";
        else
            cout << "false";

    }
    catch (exception& e){
        cout << "Standard exception: " << e.what() << endl;
    }

    return 0;
}
