
#pragma once
#ifndef __MOCK_TEST_HPP__
#define __MOCK_TEST_HPP__

#include "gtest/gtest.h"

#include "SevenTimesThreeMock.hpp"
#include "add.hpp"

TEST(MockTest, EvalTest) {
    Base* a = new SevenTimesThreeMock();
    EXPECT_EQ(a->evaluate(), 21);
}

TEST(MockTest, StringTest) {
    Base* a = new SevenTimesThreeMock();
    EXPECT_EQ(a->stringify(), "(7*3)");
}
#endif //__MOCK_TEST_HPP__


