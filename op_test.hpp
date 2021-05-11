#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluatePos) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8); 	
}

TEST(OpTest, OpStringPos) {
    Op* test = new Op(10);
    EXPECT_EQ(test->stringify(), "10");
}

TEST(OpTest, OpEvaluateZero) {
    Op* test = new Op(0);
    EXPECT_EQ(test->evaluate(), 0);
}
TEST(OpTest, OpStringZero) {
    Op* test = new Op(0);
    EXPECT_EQ(test->stringify(), "0");
}
TEST(OpTest, OpEvaluateNeg) {
    Op* test = new Op(-4);
    EXPECT_EQ(test->evaluate(), -4);
}
TEST(OpTest, OpStringNeg) {
    Op* test = new Op(-3.123456);
    EXPECT_EQ(test->stringify(), "-3.123456");
}
TEST(OpTest, OpStringDecimal) {
    Op* test = new Op(12.5005);
    EXPECT_EQ(test->stringify(), "12.5005");
}




#endif //__OP_TEST_HPP__
