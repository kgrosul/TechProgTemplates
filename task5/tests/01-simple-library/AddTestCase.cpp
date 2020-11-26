//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"

TEST(AddTestCase, SimpleTest) {
  ASSERT_EQ(2 + 2, Add(2, 2));
}

TEST(AddTestCase, ZeroTest) {
  ASSERT_EQ(2 + 0, Add(2, 0));
}

TEST(AddTestCase, NegativeTest) {
  ASSERT_EQ(2 + -2, Add(2, -2));
}