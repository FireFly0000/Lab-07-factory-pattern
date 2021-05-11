#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"

#include "rand.hpp"

TEST(RandTest, RandEvaluate) {
    Base* test = new Rand();
    EXPECT_GE(test->evaluate(), 0);
    EXPECT_LT(test->evaluate(), 100);

}
TEST(RandTest, RandString) {
    Base* test = new Rand();
    std::string c = test->stringify();		
    EXPECT_EQ(test->stringify(), c);
}


#endif //__RAND_TEST_HPP__
