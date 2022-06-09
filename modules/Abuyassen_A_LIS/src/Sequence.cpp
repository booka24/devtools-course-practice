// Copyright 2022 Abuyassen Albara

#include <algorithm>
#include <vector>
#include "include/Sequence.h"

Sequence::Sequence(int size) {
  length = size;
  Seq = std::vector < int > ();
  Seq.reserve(size);
}

Sequence::Sequence(const Sequence & a) {
  length = a.length;
  Seq = a.Seq;
}

int Sequence::GetStartingIndex() const {
  if (Seq.empty())
    throw("Sequence is empty Sequence::GetStartingIndex");
  std::vector < int > lengthes(Seq.size(), 1);
  for (auto i = Seq.size() - 1;
  i != (std::vector < int > ::size_type) - 1; i--) {
    for (size_t j = i + 1; j < Seq.size(); j++)
      if (Seq[i] < Seq[j]) {
        int v = 1 + lengthes[j];
        lengthes[i] = std::max(lengthes[i], v);
      }
  }
  return std::max_element(lengthes.begin(), lengthes.end()) - lengthes.begin();
}

std::vector < int > Sequence::LIS() {
  int starting_inx = GetStartingIndex();
  std::vector < int > result;
  result.push_back(Seq[starting_inx]);
  for (size_t i = starting_inx + 1; i < Seq.size(); i++) {
    if (Seq[i] > result.back())
      result.push_back(Seq[i]);
  }
  return result;
}

int Sequence::GetLength() const {
  return length;
}

int Sequence::GetLISlength() const {
  if (Seq.empty())
    throw("Sequence is empty Sequence::GetLISlength");
  std::vector < int > lengthes(Seq.size(), 1);
  for (auto i = Seq.size() - 1;
  i != (std::vector < int > ::size_type) - 1; i--) {
    for (size_t j = i + 1; j < Seq.size(); j++)
      if (Seq[i] < Seq[j]) {
        int v = 1 + lengthes[j];
        lengthes[i] = std::max(lengthes[i], v);
      }
  }
  return *std::max_element(lengthes.begin(), lengthes.end());
}

void Sequence::SetSequence(const std::vector < int > & a) {
  Seq = a;
  length = static_cast < int > (a.size());
}

void Sequence::Insert(int a) {
  Seq.push_back(a);
  length++;
}

int Sequence::operator[](int index) {
  if (Seq.empty())
    throw("Sequence is empty Sequence::operator[]");
  else if (index < 0 || index >= length)
    throw("index out of range Sequence::operator[]");
  return Seq[index];
}
