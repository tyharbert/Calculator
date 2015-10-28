// Tyler Harbert

#include <iostream>
#include "../Library/comp_lib.hpp"

using namespace std;

int main()
{
    try {
        Lexer* l = new Lexer();
        TokenStream ts = l->lex();
        
        Token t;
        do {
            t = ts.get();
            cout << t.symbol->spelling() << endl;
        }while(t.symbol->token() != (int)eof_tok);
        
    }
    catch (exception& e){
        cout << "Standard exception: " << e.what() << endl;
    }

    return 0;
}
