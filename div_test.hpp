#pragma once
#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"
#include <stdexcept>

#include "div.hpp"

TEST(DivTest, EvalTwoPos) {
    Base* a = new Op(8);
    Base* b = new Op(2);
    Base* c = new Div(a, b);
    EXPECT_EQ(c->evaluate(), 4);
}

TEST(DivTest, StringTwoPos) {
    Base* a = new Op(8);
    Base* b = new Op(2);
    Base* c = new Div(a, b);
    EXPECT_EQ(c->stringify(), "(8/2)");
}
TEST(DivTest, EvalTwoNeg) {
    Base* a = new Op(-30);
    Base* b = new Op(-3);
    Base* c = new Div(a, b);
    EXPECT_EQ(c->evaluate(), 10);
}
TEST(DivTest, EvalPosNeg) {
    Base* a = new Op(30);
    Base* b = new Op(-3);
    Base* c = new Div(a, b);
    EXPECT_EQ(c->evaluate(), -10);
}
TEST(DivTest, StringTwoNeg) {
    Base* a = new Op(-10);
    Base* b = new Op(-3);
    Base* c = new Div(a, b);
    EXPECT_EQ(c->stringify(), "(-10/-3)");
}
TEST(DivTest, EvalDecimal) {
    Base* a = new Op(5.205);
    Base* b = new Op(2.5);
    Base* c = new Div(a, b);
    EXPECT_EQ(c->evaluate(), 2.082);
}
TEST(DivTest, StringDecimal) {
    Base* a = new Op(2.505);
    Base* b = new Op(3.505);
    Base* c = new Div(a, b);
    EXPECT_EQ(c->stringify(), "(2.505/3.505)");
}
TEST(DivTest, EvalDivNode) {
    Base* a = new Op(144);
    Base* b = new Op(4);
    Base* c = new Div(a, b);
    Base* d = new Op(6);
    Base* e = new Div(c, d);
    EXPECT_EQ(e->evaluate(), 6);

}
TEST(DivTest, EvalDivMult) {
    Base* a = new Op(120);
    Base* b = new Op(5);
    Base* c = new Div(a, b);
    Base* d = new Op(2);
    Base* e = new Op(4);	
    Base* f = new Mult(d, e);
    Base* g = new Div(c, f);		
    EXPECT_EQ(g->evaluate(), 3);

}
TEST(DivTest, StringDivNode) {
    Base* a = new Op(144);
    Base* b = new Op(4);
    Base* c = new Div(a, b);
    Base* d = new Op(6);
    Base* e = new Div(c, d);
    EXPECT_EQ(e->stringify(), "((144/4)/6)");

}
TEST(DivTest, DivByZero) {
    try{
	Base* a = new Op(5);
	Base* b = new Op(0);
	Base* c = new Div(a,b);
	
	if(b->evaluate() == 0){
	   throw 1;
	}
    }
    catch (int x){
	std::cout << "Division by Zero is invalid, ERROR NUMBER: " << x << std::endl;
    }

}
#endif //__DIV_TEST_HPP__
