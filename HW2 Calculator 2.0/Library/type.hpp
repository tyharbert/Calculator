// Tyler Harbert
// header file for types

#ifndef TYPE_HPP
#define TYPE_HPP

struct Type{
    virtual ~Type() {}
};

struct Bool_Type:Type{  
};

struct Int_Type:Type{  
};

inline Bool_Type* get_bool_type(){
    static Bool_Type* b = new Bool_Type();
    return b;
};

inline Int_Type* get_int_type(){
    static Int_Type* i = new Int_Type();
    return i;
};

#endif