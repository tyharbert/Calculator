// Tyler Harbert

#include <iostream>
#include "../Library/comp_lib.hpp"

using namespace std;

int main()
{
    try {
        Lexer* l = new Lexer();
        
        auto t1 = l->scan();
        cout << *t1.symbol->spelling() << endl;
        
//        cout << dynamic_cast<Int_Sym*>(t1.symbol)->value + 4 << endl;
        
    }
    catch (exception& e){
        cout << "Standard exception: " << e.what() << endl;
    }

    return 0;
}
