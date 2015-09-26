// Tyler Harbert

#include <iostream>
#include "../Library/parser.hpp"

using namespace std;

int main()
{
    // create a parser class
    Parser* parser = new Parser();
    // create an AST using the parser
    Expr* expression = parser->E();
    // create and evaluator class
    S_Expr sexpr;

    // pass the evaluator class to the
    // root node of the AST's accept function
    expression->accept(sexpr);
    
    cout << endl;

    return 0;
}
