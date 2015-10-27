// Tyler Harbert

#ifndef SYMBOL_HPP
#define SYMBOL_HPP

#include <string>
#include <iostream>
#include <typeinfo>
#include <unordered_map>

// Symbol Class
class Symbol {
    friend class Symbol_Table;
    
private:
    std::string const* str;
    int token_kind;
    
public:
    virtual ~Symbol() {}
    Symbol(int tk): token_kind(tk) {}
    std::string const* spelling() const;
    int token() const;
};

struct Int_Sym:Symbol{
    int value;
    
    Int_Sym(int tk, int v): Symbol(tk), value(v) {}
};

struct Bool_Sym:Symbol{
    bool value;

    Bool_Sym(int tk, bool v): Symbol(tk), value(v) {}
};

class Symbol_Table {
private:
    std::unordered_map<std::string,Symbol*> map;

public:
    virtual ~Symbol_Table() {}
    Symbol_Table();
    template<typename T, typename... Args>
    Symbol* put(std::string const&, Args&&...);
    Symbol* get(std::string const&) const;
};

// Including this template definition to the header file because the compiler needs to see the full definition
// http://stackoverflow.com/questions/12905292/template-build-error-undefined-symbols-for-architecture-x86-64

// This function will attempt to insert a symbol.  If the symbol already exists
// then we must check if it is being reassigned to a different type
template<typename T, typename... Args>
Symbol* Symbol_Table::put(std::string const& s, Args&&... args){
    // attempt insert
    auto x = this->map.insert(std::make_pair(s, nullptr));
    // get inserted object or existing one with the same key
    auto iter = x.first;
    
    // insert success
    if(x.second){
        // set the symbols to the correct symbol class
        iter->second = new T(std::forward<Args>(args)...);
        // set the symbol's string to the key
        iter->second->str = &iter->first;
    }
    // check if the type of the symbol was beign reassigned
    else{
        if(typeid(T) != typeid(*iter->second))
            throw std::runtime_error("Lexical symbol redefinition.");
    }
    
    return iter->second;
}

#endif