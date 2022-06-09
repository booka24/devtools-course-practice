// Copyright 2022 Abuyassen Albara

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/LIS_finder.h"

int main(int argc, const char** argv) {
    LISFinder app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
