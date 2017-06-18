// Copyright 2017 Dryakhlov Dmitry

#ifndef MODULES_HUFFMAN_ALGORITM_INCLUDE_HUFFMAN_APP_H_
#define MODULES_HUFFMAN_ALGORITM_INCLUDE_HUFFMAN_APP_H_

#include <string>
#include <map>
#include <vector>

class HuffmanAlgApp {
 public:
    HuffmanAlgApp();
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
       std::string string_to_encode;
       std::string string_to_decode;
       std::map<char, std::vector<bool> >* table = nullptr;
       } Arguments;
};

#endif  // MODULES_HUFFMAN_ALGORITM_INCLUDE_HUFFMAN_APP_H_
