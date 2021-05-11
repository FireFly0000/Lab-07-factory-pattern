#pragma once
#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"

class Div : public Base {
private:
    Base* _lop;
    Base* _rop;
public:
    Div(Base* lop, Base* rop)
    {
        _lop = lop;
        _rop = rop;
    };
    virtual double evaluate() { return _lop->evaluate() / _rop->evaluate(); };
    virtual std::string stringify() {
        std::string res = "(" + _lop->stringify() + "/" +  _rop->stringify() +  ")";
        return res;

    };
};

#endif //__DIV_HPP__


