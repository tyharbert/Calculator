
Student: Tyler Harbert

## Evaluation

Does not compile without renaming "AST.hpp" to "ast.hpp". Beware
of case insensitive file systems.

Exits after evaluating a single command.

There should be no parens in postfix output.


## Comments

Single letter function names are not generally consisered good
style.


In your parser, use a switch() instead of the ifs to match
characters.


Instead of explicitly calling accept() in your visitors, use a
separate function to handle that for you. For example, here's how
I would define eval.


int eval(Expr const* e)
{
  struct V : Visitor
  {
    int r;
    void visit(Integer const* e) { r = e->value; }
    void visit(Add const* e) { r = eval(e->left()) + eval(e->right()); }
    // ...
  };

  V v;
  e->accept(v);
  return v.r;
}


## Grade

5 / 5
