#pragma once
#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"

class Add : public Base {
private:
    Base* _lop;
    Base* _rop;
public:
    Add(Base* lop, Base* rop) {
        _lop = lop;
        _rop = rop;
    };
    virtual double evaluate() { return _lop->evaluate() + _rop->evaluate(); };
    virtual std::string stringify() {
        std::string res = "(" + _lop->stringify() + "+" +  _rop->stringify() +  ")";
	return res;  
    };
};

#endif //__ADD_HPP__



