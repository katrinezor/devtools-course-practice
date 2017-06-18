// Copyright 2017 Dryakhlov Dmitry

#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <vector>

#include "include/huffman_app.h"
#include "include/huffman.h"

HuffmanAlgApp::HuffmanAlgApp() : message_("") {}

void HuffmanAlgApp::Help(const char* appname, const char* message) {
     message_ = std::string(message) +
        "This is a huffman algoritm application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        "  $ " + appname + ", 'encode' , " + "<string to encode>" +
        ", or \n" +
        "  $ " + appname + ", 'encode_and_decode' , " + "<string to encode>";
}

bool HuffmanAlgApp::ValidateNumberOfArguments(int argc, const char** argv) {
    Arguments args;
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc == 2) {
        Help(argv[0], "ERROR: Should be more than 1 arguments\n\n");
        return false;
    } else if (argc > 3) {
        Help(argv[0], "ERROR: Should be less than 3 arguments\n\n");
        return false;
    }
    return true;
}

std::string HuffmanAlgApp::operator()(int argc, const char** argv) {
    Arguments args;
    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }
    if (argv[1] != std::string("encode") &&
        (argv[1] != std::string("encode_and_decode"))) {
        message_ = "command is uncorrect";
        return message_;
    }


    std::ostringstream stream;
    args.string_to_encode = argv[2];
    args.table = new std::map< char, std::vector<bool >>;
    std::string result;
    Huffman huff;
    if (argv[1] == std::string("encode")) {
        args.string_to_decode = huff.Encode(args.string_to_encode, args.table);
        stream << args.string_to_decode;
    } else if (argv[1] == std::string("encode_and_decode")) {
        args.string_to_decode = huff.Encode(args.string_to_encode, args.table);
        result = huff.Decode(args.string_to_decode, *args.table);
        stream << result;
        }
    delete args.table;
    message_ = stream.str();
    return message_;
}
