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
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stdexcept>

#include "i_arithmetic.h"
#include "i_prompt.h"

#include "calculator.h"

/*** Macro ***/

/*** Setting ***/

/*** Global variable ***/

/*** Function ***/
Calculator::Calculator(std::unique_ptr<IArithmetic> arithmetic, std::unique_ptr<IPrompt> prompt)
{
    m_arithmetic = std::move(arithmetic);
    m_prompt = std::move(prompt);
}

Calculator::~Calculator()
{
    // do nothing
}

void Calculator::Run()
{
    char op;
    int32_t a = 0;
    int32_t b = 0;
    m_prompt->Input(op, a, b);

    int32_t ans = 0;
    try {
        ans = m_arithmetic->Calc(op, a, b);
    } catch (std::exception& e) {
        std::cout << e.what();
        return;
    }
    m_prompt->Output(op, a, b, ans);
}
