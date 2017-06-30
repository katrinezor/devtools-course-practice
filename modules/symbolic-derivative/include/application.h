// Copyright 2017 Zorina Ekaterina

#ifndef MODULES_SYMBOLIC_DERIVATIVE_INCLUDE_APPLICATION_H_
#define MODULES_SYMBOLIC_DERIVATIVE_INCLUDE_APPLICATION_H_

#include <string>

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);
 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        std::string expression_;
        std::string variable_;
    } Arguments;
};


#endif  // MODULES_SYMBOLIC_DERIVATIVE_INCLUDE_APPLICATION_H_
