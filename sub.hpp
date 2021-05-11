#pragma once
#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

class Sub : public Base {
private:
    Base*  _lop;
    Base*  _rop;
public:
    Sub(Base* lop, Base* rop) {
        _lop = lop;
        _rop = rop;
    };
    virtual double evaluate() { return _lop->evaluate() - _rop->evaluate(); };
    virtual std::string stringify() {
        std::string res = "(" + _lop->stringify() + "-" +  _rop->stringify() + ")";
	return res;
    };
};

#endif //__SUB_HPP__

