
#pragma once
#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "div.hpp"

TEST(SubTest, EvalTwoPos) {
    Base* a = new Op(8);
    Base* b = new Op(2);
    Base* c = new Sub(a, b);
    EXPECT_EQ(c->evaluate(), 6);
}
TEST(SubTest, StringTwoPos) {
    Base* a = new Op(8);
    Base* b = new Op(2);
    Base* c = new Sub(a, b);
    EXPECT_EQ(c->stringify(), "(8-2)");
}
TEST(SubTest, EvalTwoNeg) {
    Base* a = new Op(-10);
    Base* b = new Op(-3);
    Base* c = new Sub(a, b);
    EXPECT_EQ(c->evaluate(), -7);
}
TEST(SubTest, EvalPosNeg) {
    Base* a = new Op(10);
    Base* b = new Op(-3);
    Base* c = new Sub(a, b);
    EXPECT_EQ(c->evaluate(), 13);
}
TEST(SubTest, StringTwoNeg) {
    Base* a = new Op(-10);
    Base* b = new Op(-3);
    Base* c = new Sub(a, b);
    EXPECT_EQ(c->stringify(), "(-10--3)");
}
TEST(SubTest, EvalDecimal) {
    Base* a = new Op(2.505);
    Base* b = new Op(3.505);
    Base* c = new Sub(a, b);
    EXPECT_EQ(c->evaluate(), -1);
}
TEST(SubTest, StringDecimal) {
    Base* a = new Op(2.505);
    Base* b = new Op(3.505);
    Base* c = new Sub(a, b);
    EXPECT_EQ(c->stringify(), "(2.505-3.505)");
}
TEST(SubTest, EvalMultNode) {
    Base* a = new Op(4);
    Base* b = new Op(5);
    Base* c = new Mult(a, b);
    Base* d = new Op(6);
    Base* e = new Sub(c, d);
    EXPECT_EQ(e->evaluate(), 14);

}
TEST(SubTest, EvalDivPowSub) {
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
TEST(SubTest, StringDivPowSub) {
    Base* a = new Op(4);
    Base* b = new Op(2);
    Base* c = new Div(a, b);
    Base* d = new Op(6);
    Base* e = new Op(3);
    Base* f = new Sub(d, e);
    Base* g = new Pow(f,c);
    Base* h = new Op(1);
    Base* m = new Sub(g, h);
    EXPECT_EQ(m->stringify(), "(((6-3)**(4/2))-1)");
}

#endif //__SUB_TEST_HPP__

