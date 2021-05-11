#pragma once
#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base {
private:
    Base* _lop;
    Base* _rop;
public:
    Mult(Base* lop, Base* rop)
    {
        _lop = lop;
        _rop = rop;
    };
    virtual double evaluate() { return _lop->evaluate()*_rop->evaluate(); };
    virtual std::string stringify() {
        std::string res = "(" + _lop->stringify() + "*" +  _rop->stringify() +  ")";
        return res;

    };
};

#endif //__MULT_HPP__


