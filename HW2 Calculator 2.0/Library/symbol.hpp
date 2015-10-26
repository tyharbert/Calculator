// Tyler Harbert

#ifndef SYMBOL_HPP
#define SYMBOL_HPP

#include <string>
#include <unordered_map>

// Symbol Class
class Symbol {
    friend class Symbol_Table;
    
private:
    std::string const* str;
    int token_kind;
public:
    virtual ~Symbol();
    Symbol(int tk): token_kind(tk) {}
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
    virtual ~Symbol_Table();
    void put(std::string const&, Symbol*);
    Symbol const* get(std::string const&) const;
};

#endif