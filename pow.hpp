#pragma once
#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <cmath> // for pow

class Pow : public Base {
private:
    Base* _lop;
    Base* _rop;
public:
    
    Pow(Base* lop, Base* rop)
    {
        _lop = lop;
        _rop = rop;
    };
    virtual double evaluate() { return pow(_lop->evaluate(), _rop->evaluate()); };
    virtual std::string stringify() {
        std::string res = "(" + _lop->stringify() + "**" +  _rop->stringify() +  ")";
        return res;
     };
};

#endif //__POW_HPP__
