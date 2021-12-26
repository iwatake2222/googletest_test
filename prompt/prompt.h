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
#ifndef PROMPT_H_
#define PROMPT_H_

/*** Include ***/
/* for general */
#include <cstdint>
#include <cstdio>
#include <vector>
#include <array>
#include <string>

#include "i_prompt.h"

class Prompt : public IPrompt
{
public:
    Prompt();
    virtual ~Prompt() override;

    virtual void Input(char& op, int32_t& a, int32_t& b) override;
    virtual void Output(char op, int32_t a, int32_t b, int32_t ans) override;
};

#endif
