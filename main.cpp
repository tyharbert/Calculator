#include <iostream>
#include "parser.hpp"

using namespace std;

int main()
{
    Parser* parser = new Parser();
    Expr* expression = parser->E();
    Eval eval;

    expression->accept(eval);
    cout << eval.result;

    return 0;
}
