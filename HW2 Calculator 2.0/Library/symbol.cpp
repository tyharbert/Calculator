// Tyler Harbert
// code file for symbol.

#include "symbol.hpp"
#include "token.hpp"

// this returns the spelling
std::string Symbol::spelling() const{
    return *this->str;
}

// this returns the token kind
int Symbol::token() const{
    return this->token_kind;
}

// This will auto insert all of the default language tokens
Symbol_Table::Symbol_Table(){
    this->put<Symbol>("(", lparen_tok);
    this->put<Symbol>(")", rparen_tok);
    this->put<Symbol>("+", plus_tok);
    this->put<Symbol>("-", minus_tok);
    this->put<Symbol>("*", star_tok);
    this->put<Symbol>("/", slash_tok);
    this->put<Symbol>("%", percent_tok);
    this->put<Symbol>("!", excl_tok);
    this->put<Symbol>(">", gt_tok);
    this->put<Symbol>("<", lt_tok);
    this->put<Symbol>(">=", gteq_tok);
    this->put<Symbol>("<=", lteq_tok);
    this->put<Symbol>("==", eq_tok);
    this->put<Symbol>("!=", noteq_tok);
    this->put<Symbol>("&&", logical_and_tok);
    this->put<Symbol>("||", logical_or_tok);
    this->put<Bool_Sym>("true", boolean_tok, true);
    this->put<Bool_Sym>("false", boolean_tok, false);
}

// This function attempts a find and returns the symbol if it's found otherwise it returns a nullptr
Symbol* Symbol_Table::get(std::string const& s) const
{
  auto iter = this->map.find(s);
  if (iter != map.end())
    return iter->second;
  else
    return nullptr;
}