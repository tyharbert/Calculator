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
    // create a post fix object
    PostFix pfix;

    // pass the post fix object to the
    // root node of the AST's accept function
    expression->accept(pfix);
    
    cout << endl;

    return 0;
}
