// Copyright 2017 Zorina Ekaterina

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "../include/application.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    // system("pause");
    return 0;
}
