// Copyright 2017 Buldakov Vlad

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/Newton_method_app.h"

int main(int argc, const char** argv) {
    NewtonMethodApp nma;
    std::string output = nma(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
