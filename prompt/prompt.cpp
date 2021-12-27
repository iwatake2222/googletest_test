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
#include <iostream>

#include "prompt.h"

/*** Macro ***/

/*** Setting ***/

/*** Global variable ***/

/*** Function ***/
Prompt::Prompt()
{
    // do nothing
}

Prompt::~Prompt()
{
    // do nothing
}

void Prompt::Input(char& op, int32_t& a, int32_t& b)
{
    std::cout << ">";
    std::cin >> op >> a >> b;
}
#include <cstring>
void Prompt::Output(char op, int32_t a, int32_t b, int32_t ans)
{
    std::cout << std::to_string(a) + " " + op + " " + std::to_string(b) + " = " + std::to_string(ans);

    scanf("%d %d", &a);
    char buffer[1];
    memset(buffer, 0, 2);
}
