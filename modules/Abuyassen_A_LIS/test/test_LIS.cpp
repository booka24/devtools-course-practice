// Copyright 2022 Abuyassen Albara

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include "include/Sequence.h"

TEST(LIS, LIS_create_empty_TEST) {
  int size = 5;
  Sequence seq(size);
  ASSERT_NO_THROW(Sequence seq(size););
}

TEST(LIS, LIS_get_length_Test_TEST) {
  int size = 5;
  Sequence seq(size);
  EXPECT_EQ(seq.GetLength(), size);
}

TEST(LIS, can_set_sequence) {
  int size = 5;
  Sequence seq(size);
  std::vector < int > values = {
    1,
    2,
    3,
    4,
    5
  };
  seq.SetSequence(values);
  ASSERT_TRUE(seq.GetLength() == size);
  ASSERT_EQ(seq[0], values[0]);
  ASSERT_EQ(seq[1], values[1]);
  ASSERT_EQ(seq[2], values[2]);
  ASSERT_EQ(seq[3], values[3]);
}

TEST(LIS, LIS_insert_TEST) {
  int size = 5;
  Sequence seq(size);
  std::vector < int > values = {
    1,
    2,
    3,
    4,
    5
  };
  int value = 6;
  seq.SetSequence(values);
  seq.Insert(value);
  ASSERT_EQ(value, seq[5]);
}

TEST(LIS, LIS_copy_constructor_TEST) {
  int size = 4;
  Sequence seq(size);
  std::vector < int > values = {
    1,
    2,
    3,
    4
  };
  seq.SetSequence(values);
  Sequence copy(seq);
  ASSERT_TRUE(seq.GetLength() == copy.GetLength());
  ASSERT_EQ(seq[0], copy[0]);
  ASSERT_EQ(seq[1], copy[1]);
  ASSERT_EQ(seq[2], copy[2]);
  ASSERT_EQ(seq[3], copy[3]);
}

TEST(LIS, LIS_get_lis_length_TEST) {
  int size = 4;
  Sequence seq(size);
  std::vector < int > values = {
    1,
    2,
    3,
    4
  };
  int LisLength = 4;
  seq.SetSequence(values);
  ASSERT_EQ(seq.GetLISlength(), 4);
}

TEST(LIS, LIS_get_lis_TEST) {
  int size = 5;
  Sequence seq(size);
  std::vector < int > values = {
    1,
    2,
    1,
    3,
    4
  };
  std::vector < int > LIS = {
    1,
    2,
    3,
    4
  };
  seq.SetSequence(values);
  ASSERT_TRUE(seq.LIS() == LIS);
}

TEST(LIS, LIS_returns_first_lis_found_TEST) {
  int size = 5;
  Sequence seq(size);
  std::vector < int > values = {
    1,
    5,
    2,
    3,
    6
  };
  std::vector < int > LIS = {
    1,
    5,
    6
  };
  seq.SetSequence(values);
  ASSERT_TRUE(seq.LIS() == LIS);
}

TEST(LIS, LIS_GetStartingIndex_TEST) {
  int size = 5;
  Sequence seq(size);
  std::vector < int > values = {
    5,
    1,
    2,
    3,
    6
  };
  int expected = 1;
  seq.SetSequence(values);
  ASSERT_TRUE(seq.GetStartingIndex() == expected);
}

TEST(LIS, LIS_returns_one_object_if_no_lis_TEST) {
  int size = 5;
  Sequence seq(size);
  std::vector < int > values(size, 1);
  std::vector < int > LIS(1, 1);
  seq.SetSequence(values);
  ASSERT_TRUE(seq.LIS() == LIS);
}

TEST(LIS_THROWS, LIS_operator_throws_out_of_index_TEST) {
  int size = 5;
  Sequence seq(size);
  std::vector < int > values = {
    1,
    2,
    1,
    3,
    4
  };
  seq.SetSequence(values);
  EXPECT_ANY_THROW(seq[5]);
}

TEST(LIS_THROWS, LIS_GetLISlength_throws_if_empty_TEST) {
  int size = 5;
  Sequence seq(size);
  EXPECT_ANY_THROW(seq.GetLISlength());
}

TEST(LIS_THROWS, LIS_GetStartingIndex_throws_if_empty_TEST) {
  int size = 5;
  Sequence seq(size);
  EXPECT_ANY_THROW(seq.GetStartingIndex());
}
