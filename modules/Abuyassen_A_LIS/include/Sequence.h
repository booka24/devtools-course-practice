// Copyright 2022 Abuyassen Albara

#ifndef MODULES_ABUYASSEN_A_LIS_INCLUDE_SEQUENCE_H_
#define MODULES_ABUYASSEN_A_LIS_INCLUDE_SEQUENCE_H_

#include <vector>

class Sequence {
 public:
    explicit Sequence(int size);
    Sequence(const Sequence &a);
    int GetStartingIndex() const;
    std::vector<int> LIS();
    int GetLength() const;
    int GetLISlength() const;
    void SetSequence(const std::vector<int>& a);
    void Insert(int a);
    int operator[](int index);
 private:
    std::vector<int> Seq;
    int length;
};

#endif  // MODULES_ABUYASSEN_A_LIS_INCLUDE_SEQUENCE_H_
