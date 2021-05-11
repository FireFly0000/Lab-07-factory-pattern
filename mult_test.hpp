#pragma once
#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"
#include "add.hpp"

TEST(MultTest, EvalTwoPos) {
    Base* a = new Op(8);
    Base* b = new Op(2);
    Base* c = new Mult(a, b);		
    EXPECT_EQ(c->evaluate(), 16);
}

TEST(MultTest, StringTwoPos) {
    Base* a = new Op(8);
    Base* b = new Op(2);
    Base* c = new Mult(a, b);
    EXPECT_EQ(c->stringify(), "(8*2)");
}
TEST(MultTest, EvalTwoNeg) {
    Base* a = new Op(-10);
    Base* b = new Op(-3);
    Base* c = new Mult(a, b);
    EXPECT_EQ(c->evaluate(), 30);
}
TEST(MultTest, EvalPosNeg) {
    Base* a = new Op(10);
    Base* b = new Op(-3);
    Base* c = new Mult(a, b);
    EXPECT_EQ(c->evaluate(), -30);
}
TEST(MultTest, StringTwoNeg) {
    Base* a = new Op(-10);
    Base* b = new Op(-3);
    Base* c = new Mult(a, b);
    EXPECT_EQ(c->stringify(), "(-10*-3)");
}
TEST(MultTest, EvalDecimal) {
    Base* a = new Op(2.505);
    Base* b = new Op(3.505);
    Base* c = new Mult(a, b);
    EXPECT_EQ(c->evaluate(), 8.780025);
}
TEST(MultTest, StringDecimal) {
    Base* a = new Op(2.505);
    Base* b = new Op(3.505);
    Base* c = new Mult(a, b);
    EXPECT_EQ(c->stringify(), "(2.505*3.505)");
}
TEST(MultTest, EvalMultNode) {		
    Base* a = new Op(4);
    Base* b = new Op(5);
    Base* c = new Add(a, b);
    Base* d = new Op(6);
    Base* e = new Mult(c, d);		
    EXPECT_EQ(e->evaluate(), 54);

}
TEST(MultTest, StringMultNode) {
    Base* a = new Op(4);
    Base* b = new Op(5);
    Base* c = new Mult(a, b);
    Base* d = new Op(6);
    Base* e = new Mult(c, d);
    EXPECT_EQ(e->stringify(), "((4*5)*6)");

}





#endif //__MULT_TEST_HPP__

