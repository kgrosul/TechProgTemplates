//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>

TEST(LeapTestCase, 2020) {
  ASSERT_TRUE(IsLeap(2020));
}

TEST(LeapTestCase, 400) {
  ASSERT_TRUE(IsLeap(400));
}

TEST(LeapTestCase, 4) {
  ASSERT_TRUE(IsLeap(4));
}

TEST(LeapTestCase, 600) {
  ASSERT_FALSE(IsLeap(600));
}

TEST(LeapTestCase, 1) {
  ASSERT_FALSE(IsLeap(1));
}

TEST(LeapTestCase, Negative) {
  ASSERT_THROW(IsLeap(-100), std::invalid_argument);
}

TEST(LeapTestCase, Zero) {
  ASSERT_THROW(IsLeap(0), std::invalid_argument);
}
