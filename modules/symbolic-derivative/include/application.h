// Copyright 2017 Zorina Ekaterina

#ifndef MODULES_SYMBOLIC_DERIVATIVE_INCLUDE_APPLICATION_H_
#define MODULES_SYMBOLIC_DERIVATIVE_INCLUDE_APPLICATION_H_

#include <string.h>

class Application {
public:
    Application();
    std::string operator()(int argc, const char** argv);
private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    std::string expression_;
};

#endif  // MODULES_SYMBOLIC_DERIVATIVE_INCLUDE_APPLICATION_H_