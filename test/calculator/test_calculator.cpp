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
#include <vector>
#include <array>
#include <string>
#include <memory>
#include <stdexcept>

/* GoogleTest */
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "i_arithmetic.h"
#include "i_prompt.h"
#include "calculator.h"

namespace {
#if 0
}    // indent guard
#endif


class MockArithmetic : public IArithmetic {
public:
    MOCK_METHOD3(Calc, int32_t(char op, int32_t a, int32_t b));
};

class MockPrompt : public IPrompt {
public:
    void Input(char& op, int32_t& a, int32_t& b) {
        op = m_preset_op;
        a = m_preset_a;
        b = m_preset_b;
    }
    MOCK_METHOD4(Output, void(char op, int32_t a, int32_t b, int32_t ans));

    void SetPresetValue(char op, int32_t a, int32_t b)
    {
        m_preset_op = op;
        m_preset_a = a;
        m_preset_b = b;
    }

private:
    char m_preset_op;
    int32_t m_preset_a;
    int32_t m_preset_b;
};

class TestCalculator : public testing::Test
{
protected:
    TestCalculator() {
        // You can do set-up work for each test here.
    }

    ~TestCalculator() override {
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

TEST_F(TestCalculator, BasicTest)
{
    EXPECT_TRUE(true);
}

TEST_F(TestCalculator, Add)
{
    std::unique_ptr<MockPrompt> prompt = std::make_unique<MockPrompt>();
    prompt->SetPresetValue('+', 1, 2);
    std::unique_ptr<MockArithmetic> arithmetic = std::make_unique<MockArithmetic>();
    
    EXPECT_CALL(*arithmetic, Calc('+', 1, 2))
        .WillOnce(testing::Return(3));
    EXPECT_CALL(*prompt, Output('+', 1, 2, 3));

    Calculator calc(std::move(arithmetic), std::move(prompt));
    calc.Run();
}

TEST_F(TestCalculator, Sub)
{
    std::unique_ptr<MockPrompt> prompt = std::make_unique<MockPrompt>();
    prompt->SetPresetValue('-', 1, 2);
    std::unique_ptr<MockArithmetic> arithmetic = std::make_unique<MockArithmetic>();

    EXPECT_CALL(*arithmetic, Calc('-', 1, 2))
        .WillOnce(testing::Return(-1));
    EXPECT_CALL(*prompt, Output('-', 1, 2, -1));

    Calculator calc(std::move(arithmetic), std::move(prompt));
    calc.Run();
}

}
