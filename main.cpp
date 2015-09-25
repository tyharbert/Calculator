// Tyler Harbert

#include <iostream>
#include "parser.hpp"

using namespace std;

int main()
{
    // create a parser class
    Parser* parser = new Parser();
    // create an AST using the parser
    Expr* expression = parser->E();
    // create and evaluator class
    PostFix pfix;

    // pass the evaluator class to the
    // root node of the AST's accept function
    expression->accept(pfix);

    return 0;
}
