// Copyright 2017 Dmitry Dryakhlov

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/huffman_app.h"

int main(int argc, const char** argv) {
    HuffmanAlgApp huffman_alg;
    std::string output = huffman_alg(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
