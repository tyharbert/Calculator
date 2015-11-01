// Tyler Harbert
// header file for value class

#ifndef VALUE_HPP
#define VALUE_HPP

#include <iostream>

// Value class
// this can contain an integer or a bool value
class Value{
private:
    enum Value_Type{
        INT,
        BOOL
    };
    
    int _i;
    bool _b;
    Value_Type _t;
public:
    Value() {}
    Value (int i): _i(i), _t(INT) {}
    Value (bool b): _b(b), _t(BOOL) {}
    bool is_bool() const;
    bool is_int() const;
    int type();
    int get_int();
    bool get_bool();
    
    // overloading cout operator
    friend std::ostream& operator<<(std::ostream& os, const Value& v);
    
};

#endif