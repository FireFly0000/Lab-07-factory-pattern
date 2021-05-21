#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include "gtest/gtest.h"
#include "mult.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "op.hpp"
#include "factory.hpp"

TEST(FactoryTest, AddingValues) { 
	Factory test;
	char *args[] = {"2", "+", "2"};
	Base *op = test.parse(args, 3);
	EXPECT_DOUBLE_EQ(op->evaluate(), 4);
}   

TEST(FactoryTest, AddingAndSubtracting) {
        Factory test;
        char *args[] = {"10", "-", "2", "+", "3","-","4"};
        Base *op = test.parse(args, 7);
        EXPECT_DOUBLE_EQ(op->evaluate(), 7);
}

TEST(FactoryTest, MultandDiv) {
        Factory test;
        char *args[] = {"5", "*", "10","/","25","/","2"};
        Base *op = test.parse(args, 7);
        EXPECT_DOUBLE_EQ(op->evaluate(), 1);
}

TEST(FactoryTest, Pow) {
        Factory test;
        char *args[] = {"3", "*","*", "3"};
        Base *op = test.parse(args, 4);
        EXPECT_DOUBLE_EQ(op->evaluate(), 27);
}

TEST(FactoryTest, AllOperators) {
        Factory test;
        char *args[] = {"10", "+", "5","*","2","/","15","*","*","3","-","4"};
        Base *op = test.parse(args, 12);
        EXPECT_DOUBLE_EQ(op->evaluate(), 4);
}

TEST(FactoryTest, InvalidInput) {
	Factory test;
	char *args[] = {"10", "x", "4"};
        Base *op = test.parse(args, 3);
        EXPECT_TRUE(op == nullptr);
}

TEST(FactoryTest, DoubleMultandDiv) {
    Factory test;
    char* args[] = { "7.8", "*", "-3.2", "/", "2.0" };
    Base* op = test.parse(args, 5);
    EXPECT_DOUBLE_EQ(op->eavluate(), -12.48);
}

TEST(FactoryTest, MultiplyingTwoNeg) {
    Factory test;
    char* args[] = { "-9.0", "*", "-2.0"};
    Base* op = test.parse(args, 3);
    EXPECT_DOUBLE_EQ(op->eavluate(), 18);
}

#endif








