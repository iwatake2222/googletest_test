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
#include <memory>
#include <vector>
#include <string>

#include "arithmetic.h"
#include "prompt.h"
#include "calculator.h"

/*** Macro ***/

/*** Setting ***/

/*** Global variable ***/

/*** Function ***/
int main(int argc, char* argv[])
{
    Calculator calc(std::make_unique<Arithmetic>(), std::make_unique<Prompt>());
    calc.Run();

    /* Cause security warning */
    // char buffer[1];
    // buffer[3] = 1;

    return 0;
}
