  // Copyright 2022 Andrich Maria

#include <gtest/gtest.h>
#include <string>
#include "../include/SortFacility.h"

TEST(Sort_Facility, test_zero) {
Sort s;
const char* input = " ";
char output[128];
ASSERT_NO_THROW(s.shunting_yard(input, output));
}

TEST(Sort_Facility, test_one_argument) {
Sort s;
const char* input = "q";
char output[128];

s.shunting_yard(input, output);

const char* answer = output;

ASSERT_EQ(*answer, *input);
}

TEST(Sort_Facility, test_simple_equation) {
Sort s;
const char* input = "a = b + c1";
const char* expected = "abc1+=";
char output[128];

s.shunting_yard(input, output);

const char* answer = output;

ASSERT_EQ(*answer, *expected);
}

TEST(Sort_Facility, test_equation) {
Sort s;
const char* input = "a = b + c1 * d - f";
const char* expected = "abc1d*+f-=";
char output[128];

s.shunting_yard(input, output);

const char* answer = output;

ASSERT_EQ(*answer, *expected);
}

TEST(Sort_Facility, test_difficult_equation) {
Sort s;
const char* input = "a = D(f - b * c1 + d, !e, g)";
const char* expected = "afbc1*-d+e!gD=";
char output[128];

s.shunting_yard(input, output);

const char* answer = output;
ASSERT_EQ(*answer, *expected);
}
