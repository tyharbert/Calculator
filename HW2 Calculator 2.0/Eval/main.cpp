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

        // print result
        cout << eval(expr) << endl << endl;
    }
    catch (exception& e){
        cout << "Standard exception: " << e.what() << endl;
    }

    return 0;
}
