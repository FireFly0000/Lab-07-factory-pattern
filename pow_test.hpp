#pragma once
#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "div.hpp"


TEST(PowTest, EvalTwoPos) {
    Base* a = new Op(3);
    Base* b = new Op(2);
    Base* c = new Pow(a, b);
    EXPECT_EQ(c->evaluate(), 9);
}
TEST(PowTest, StringTwoPos) {
    Base* a = new Op(8);
    Base* b = new Op(2);
    Base* c = new Pow(a, b);
    EXPECT_EQ(c->stringify(), "(8**2)");
}
TEST(PowTest, EvalPowNeg) {
    Base* a = new Op(2);
    Base* b = new Op(-1);
    Base* c = new Pow(a, b);
    EXPECT_EQ(c->evaluate(), 0.5);
}
TEST(PowTest, EvalPowZero) {
    Base* a = new Op(2);
    Base* b = new Op(0);
    Base* c = new Pow(a, b);
    EXPECT_EQ(c->evaluate(), 1);
}
TEST(PowTest, EvalPowDecimal) {
    Base* a = new Op(16);
    Base* b = new Op(0.5);
    Base* c = new Pow(a, b);
    EXPECT_EQ(c->evaluate(), 4);
}
TEST(PowTest, EvenRootNegBase) {
    try{
	Base* a = new Op(-4);
	Base* b = new Op(0.5);
	Base* c = new Pow(a, b);
	if (a->evaluate() < 0 && b->evaluate() > -1 && b->evaluate() <1){
		throw 2;
  	}
    }
    catch(int x){
	std::cout << "Even root of negative number is invalid, NUMBER ERROR: " << x << std::endl;
    }  			 
}



#endif //__POW_TEST_HPP__
