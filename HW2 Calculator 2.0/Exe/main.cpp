// Tyler Harbert

#include <iostream>
#include "../Library/comp_lib.hpp"

using namespace std;

int main()
{
    try {
        Lexer* l = new Lexer();
        
//        auto t = l->st->get("(");
//        cout << t->token() << *t->spelling() << endl;
        
    }
    catch (exception& e){
        cout << "Standard exception: " << e.what() << endl;
    }

    return 0;
}
