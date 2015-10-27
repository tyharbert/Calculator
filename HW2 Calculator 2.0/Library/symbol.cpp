// Tyler Harbert

#include <string>
#include <typeinfo>
#include "symbol.hpp"
#include "token.hpp"

// this returns the spelling
std::string const* Symbol::spelling() const{
    return this->str;
}

// this returns the token kind
int Symbol::token() const{
    return this->token_kind;
}

// This will auto insert all of the default language tokens
Symbol_Table::Symbol_Table(){
    this->put("(", new Symbol((int)lparen_tok));
    this->put(")", new Symbol((int)rparen_tok));
    this->put("+", new Symbol((int)plus_tok));
    this->put("-", new Symbol((int)minus_tok));
    this->put("*", new Symbol((int)star_tok));
    this->put("/", new Symbol((int)slash_tok));
    this->put("%", new Symbol((int)percent_tok));
    this->put("!", new Symbol((int)excl_tok));
    this->put(">", new Symbol((int)gt_tok));
    this->put("<", new Symbol((int)lt_tok));
    this->put(">=", new Symbol((int)gteq_tok));
    this->put("<=", new Symbol((int)lteq_tok));
    this->put("==", new Symbol((int)eq_tok));
    this->put("!=", new Symbol((int)noteq_tok));
    this->put("&&", new Symbol((int)logical_and_tok));
    this->put("||", new Symbol((int)logical_or_tok));
}

// This function will attempt to insert a symbol.  If the symbol already exists
// then we must check if it is being reassigned to a different type
void Symbol_Table::put(std::string const& s, Symbol* sym){
    // attempt insert
    auto x = this->map.insert(std::make_pair(s, sym));
    // get inserted object or existing one with the same key
    auto iter = x.first;
    
    // insert success
    if(x.second){
        // set the symbol's string to the key
        iter->second->str = &iter->first;
    }
    // check if the type of the symbol was beign reassigned
    else{
        if(typeid(sym) != typeid(*iter->second))
            throw std::runtime_error("Lexical symbol redefinition.");
    }
}

// This function attempts a find and returns the symbol if it's found otherwise it returns a nullptr
Symbol const* Symbol_Table::get(std::string const& s) const
{
  auto iter = this->map.find(s);
  if (iter != map.end())
    return iter->second;
  else
    return nullptr;
}