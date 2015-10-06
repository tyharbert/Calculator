// Tyler Harbert

#include <iostream>
#include "../Library/parser.hpp"

using namespace std;

int main()
{
    // create a parser object
    Parser* parser = new Parser();
    // create an AST using the parser
    Expr* expression = parser->E();
    // create an s-expression object
    S_Expr sexpr;

    // pass the s-expression object to the
    // root node of the AST's accept function
    expression->accept(sexpr);
    
    cout << endl;

    return 0;
}
