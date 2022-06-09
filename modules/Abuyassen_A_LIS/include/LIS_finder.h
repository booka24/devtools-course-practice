// Copyright 2022 Abuyassen Albaraa

#ifndef MODULES_ABUYASSEN_A_LIS_INCLUDE_LIS_FINDER_H_
#define MODULES_ABUYASSEN_A_LIS_INCLUDE_LIS_FINDER_H_

#include <string>

class LISFinder {
 public:
    LISFinder();
    std::string operator()(int argc, const char** argv);
 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
};

#endif  // MODULES_ABUYASSEN_A_LIS_INCLUDE_LIS_FINDER_H_

