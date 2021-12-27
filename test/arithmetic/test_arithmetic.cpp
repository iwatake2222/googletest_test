/* Copyright 2021 iwatake2222

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
/*** Include ***/
/* for general */
#include <cstdint>
#include <cstdio>
#include <climits>
#include <vector>
#include <array>
#include <string>
#include <stdexcept>

/* GoogleTest */
#include <gtest/gtest.h>

#include "arithmetic.h"

namespace {
#if 0
}    // indent guard
#endif

class TestArithmetic : public testing::Test
{
protected:
    TestArithmetic() {
        // You can do set-up work for each test here.
    }

    ~TestArithmetic() override {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    void SetUp() override {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }
};

TEST_F(TestArithmetic, BasicTest)
{
    EXPECT_TRUE(true);
}

TEST_F(TestArithmetic, Add)
{
    Arithmetic arithmetic;
    EXPECT_EQ(0, arithmetic.Calc('+', 0, 1));
    EXPECT_EQ(1, arithmetic.Calc('+', 0, 1));
    EXPECT_EQ(1, arithmetic.Calc('+', 1, 0));
    EXPECT_EQ(-1, arithmetic.Calc('+', 0, -1));
    EXPECT_EQ(-1, arithmetic.Calc('+', -1, 0));
    EXPECT_EQ(20, arithmetic.Calc('+', 10, 10));
    EXPECT_EQ(30, arithmetic.Calc('+', 10, 20));
    EXPECT_EQ(30, arithmetic.Calc('+', 20, 10));
}
TEST_F(TestArithmetic, Sub)
{
    Arithmetic arithmetic;
    EXPECT_EQ(0, arithmetic.Calc('-', 0, 0));
    EXPECT_EQ(-1, arithmetic.Calc('-', 0, 1));
    EXPECT_EQ(1, arithmetic.Calc('-', 1, 0));
    EXPECT_EQ(1, arithmetic.Calc('-', 0, -1));
    EXPECT_EQ(-1, arithmetic.Calc('-', -1, 0));
    EXPECT_EQ(0, arithmetic.Calc('-', 10, 10));
    EXPECT_EQ(-10, arithmetic.Calc('-', 10, 20));
    EXPECT_EQ(10, arithmetic.Calc('-', 20, 10));
}

TEST_F(TestArithmetic, InvalidOp)
{
    Arithmetic arithmetic;
    EXPECT_THROW(arithmetic.Calc('1', 0, 0), std::invalid_argument);
    EXPECT_THROW(arithmetic.Calc(' ', 0, 0), std::invalid_argument);
    EXPECT_THROW(arithmetic.Calc('?', 0, 0), std::invalid_argument);
}


}
