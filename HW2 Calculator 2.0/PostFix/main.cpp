// Tyler Harbert

#include <iostream>
#include "../Library/parser.hpp"

using namespace std;

int main()
{
    try {
        // create a parser object
        Parser* parser = new Parser();
        // create an AST using the parser
        Expr* expr = parser->expression();

        // print post fix notation for the expression
        post_fix(expr);
        cout << endl;
    }
    catch (exception& e){
        cout << "Standard exception: " << e.what() << endl;
    }

    return 0;
}
