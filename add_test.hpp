#pragma once
#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "div.hpp"

TEST(AddTest, EvalTwoPos) {
    Base* a = new Op(8);
    Base* b = new Op(2);
    Base* c = new Add(a, b);
    EXPECT_EQ(c->evaluate(), 10);
}

TEST(AddTest, StringTwoPos) {
    Base* a = new Op(8);
    Base* b = new Op(2);
    Base* c = new Add(a, b);
    EXPECT_EQ(c->stringify(), "(8+2)");
}
TEST(AddTest, EvalTwoNeg) {
    Base* a = new Op(-10);
    Base* b = new Op(-3);
    Base* c = new Add(a, b);
    EXPECT_EQ(c->evaluate(), -13);
}
TEST(AddTest, EvalPosNeg) {
    Base* a = new Op(10);
    Base* b = new Op(-3);
    Base* c = new Add(a, b);
    EXPECT_EQ(c->evaluate(), 7);
}
TEST(AddTest, StringTwoNeg) {
    Base* a = new Op(-10);
    Base* b = new Op(-3);
    Base* c = new Add(a, b);
    EXPECT_EQ(c->stringify(), "(-10+-3)");
}
TEST(AddTest, EvalDecimal) {
    Base* a = new Op(2.505);
    Base* b = new Op(3.505);
    Base* c = new Add(a, b);
    EXPECT_EQ(c->evaluate(), 6.01);
}
TEST(AddTest, StringDecimal) {
    Base* a = new Op(2.505);
    Base* b = new Op(3.505);
    Base* c = new Add(a, b);
    EXPECT_EQ(c->stringify(), "(2.505+3.505)");
}
TEST(AddTest, EvalMultNode) {
    Base* a = new Op(4);
    Base* b = new Op(5);
    Base* c = new Mult(a, b);
    Base* d = new Op(6);
    Base* e = new Add(c, d);
    EXPECT_EQ(e->evaluate(), 26);

}
TEST(AddTest, EvalDivPowSub) {
    Base* a = new Op(4);
    Base* b = new Op(2);
    Base* c = new Div(a, b);
    Base* d = new Op(6);
    Base* e = new Op(3);	
    Base* f = new Sub(d, e);
    Base* g = new Pow(f,c);
    Base* h = new Op(1);
    Base* m = new Add(g, h); 
    EXPECT_EQ(m->evaluate(), 10);
}
TEST(AddTest, StringDivPowSub) {
    Base* a = new Op(4);
    Base* b = new Op(2);
    Base* c = new Div(a, b);
    Base* d = new Op(6);
    Base* e = new Op(3);
    Base* f = new Sub(d, e);
    Base* g = new Pow(f,c);
    Base* h = new Op(1);
    Base* m = new Add(g, h);
    EXPECT_EQ(m->stringify(), "(((6-3)**(4/2))+1)");
}

#endif //__ADD_TEST_HPP__

