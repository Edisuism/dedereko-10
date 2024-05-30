// Copyright 2022 The Dawn & Tint Authors
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived from
//    this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

////////////////////////////////////////////////////////////////////////////////
// File generated by 'tools/src/cmd/gen' using the template:
//   src/tint/lang/core/texel_format_test.cc.tmpl
//
// To regenerate run: './tools/run gen'
//
//                       Do not modify this file directly
////////////////////////////////////////////////////////////////////////////////

#include "src/tint/lang/core/texel_format.h"

#include <gtest/gtest.h>

#include <string>

#include "src/tint/utils/text/string.h"

namespace tint::core {
namespace {

namespace parse_print_tests {

struct Case {
    const char* string;
    TexelFormat value;
};

inline std::ostream& operator<<(std::ostream& out, Case c) {
    return out << "'" << std::string(c.string) << "'";
}

static constexpr Case kValidCases[] = {
    {"bgra8unorm", TexelFormat::kBgra8Unorm},   {"r32float", TexelFormat::kR32Float},
    {"r32sint", TexelFormat::kR32Sint},         {"r32uint", TexelFormat::kR32Uint},
    {"rg32float", TexelFormat::kRg32Float},     {"rg32sint", TexelFormat::kRg32Sint},
    {"rg32uint", TexelFormat::kRg32Uint},       {"rgba16float", TexelFormat::kRgba16Float},
    {"rgba16sint", TexelFormat::kRgba16Sint},   {"rgba16uint", TexelFormat::kRgba16Uint},
    {"rgba32float", TexelFormat::kRgba32Float}, {"rgba32sint", TexelFormat::kRgba32Sint},
    {"rgba32uint", TexelFormat::kRgba32Uint},   {"rgba8sint", TexelFormat::kRgba8Sint},
    {"rgba8snorm", TexelFormat::kRgba8Snorm},   {"rgba8uint", TexelFormat::kRgba8Uint},
    {"rgba8unorm", TexelFormat::kRgba8Unorm},
};

static constexpr Case kInvalidCases[] = {
    {"bgraunccrm", TexelFormat::kUndefined},      {"blranr3", TexelFormat::kUndefined},
    {"bVra8unorm", TexelFormat::kUndefined},      {"132float", TexelFormat::kUndefined},
    {"32Jlqqat", TexelFormat::kUndefined},        {"ll3277loat", TexelFormat::kUndefined},
    {"ppqq2snHH", TexelFormat::kUndefined},       {"r3cv", TexelFormat::kUndefined},
    {"b2siGt", TexelFormat::kUndefined},          {"r32uiivt", TexelFormat::kUndefined},
    {"8WW2uint", TexelFormat::kUndefined},        {"rxxuint", TexelFormat::kUndefined},
    {"rX2flggat", TexelFormat::kUndefined},       {"rg3XVut", TexelFormat::kUndefined},
    {"3g32float", TexelFormat::kUndefined},       {"rg3Esint", TexelFormat::kUndefined},
    {"PP32TTint", TexelFormat::kUndefined},       {"xxg32ddnt", TexelFormat::kUndefined},
    {"44g32uint", TexelFormat::kUndefined},       {"rSS32uinVV", TexelFormat::kUndefined},
    {"R322Rint", TexelFormat::kUndefined},        {"rgba16fF9a", TexelFormat::kUndefined},
    {"rgba16floa", TexelFormat::kUndefined},      {"rOObVR16floH", TexelFormat::kUndefined},
    {"ryba1sint", TexelFormat::kUndefined},       {"r77ba1nnsllrrt", TexelFormat::kUndefined},
    {"rgb4006sint", TexelFormat::kUndefined},     {"rb1uioot", TexelFormat::kUndefined},
    {"rga1uzznt", TexelFormat::kUndefined},       {"r11b1uppiit", TexelFormat::kUndefined},
    {"rgba32fXXoat", TexelFormat::kUndefined},    {"rgbII99355float", TexelFormat::kUndefined},
    {"rgbaa32fSSrHHYt", TexelFormat::kUndefined}, {"rbkk2Hit", TexelFormat::kUndefined},
    {"jgba3sgRR", TexelFormat::kUndefined},       {"rgbab2si", TexelFormat::kUndefined},
    {"rgba32jint", TexelFormat::kUndefined},      {"rba32uint", TexelFormat::kUndefined},
    {"rgba2uqn", TexelFormat::kUndefined},        {"rbaNNsint", TexelFormat::kUndefined},
    {"rga8invv", TexelFormat::kUndefined},        {"gba8sQQnt", TexelFormat::kUndefined},
    {"rgbsnrrff", TexelFormat::kUndefined},       {"rgba8snojm", TexelFormat::kUndefined},
    {"NNgba8sww2m", TexelFormat::kUndefined},     {"rgba8uit", TexelFormat::kUndefined},
    {"rrgba8uint", TexelFormat::kUndefined},      {"rgba8uiGt", TexelFormat::kUndefined},
    {"rgba8unFFrm", TexelFormat::kUndefined},     {"g8unErm", TexelFormat::kUndefined},
    {"rgb8urrorm", TexelFormat::kUndefined},
};

using TexelFormatParseTest = testing::TestWithParam<Case>;

TEST_P(TexelFormatParseTest, Parse) {
    const char* string = GetParam().string;
    TexelFormat expect = GetParam().value;
    EXPECT_EQ(expect, ParseTexelFormat(string));
}

INSTANTIATE_TEST_SUITE_P(ValidCases, TexelFormatParseTest, testing::ValuesIn(kValidCases));
INSTANTIATE_TEST_SUITE_P(InvalidCases, TexelFormatParseTest, testing::ValuesIn(kInvalidCases));

using TexelFormatPrintTest = testing::TestWithParam<Case>;

TEST_P(TexelFormatPrintTest, Print) {
    TexelFormat value = GetParam().value;
    const char* expect = GetParam().string;
    EXPECT_EQ(expect, ToString(value));
}

INSTANTIATE_TEST_SUITE_P(ValidCases, TexelFormatPrintTest, testing::ValuesIn(kValidCases));

}  // namespace parse_print_tests

}  // namespace
}  // namespace tint::core
