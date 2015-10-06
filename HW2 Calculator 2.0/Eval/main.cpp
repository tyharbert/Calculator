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
    // create an evaluator object
    Eval eval;

    // pass the evaluator object to the
    // root node of the AST's accept function
    expression->accept(eval);

    // print result
    cout << eval.result << endl << endl;

    return 0;
}
