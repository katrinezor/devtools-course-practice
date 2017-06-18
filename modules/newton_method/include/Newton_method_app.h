// Copyright 2017 Buldakov Vlad

#ifndef MODULES_NEWTON_METHOD_INCLUDE_NEWTON_METHOD_APP_H_
#define MODULES_NEWTON_METHOD_INCLUDE_NEWTON_METHOD_APP_H_

#include <string>

class NewtonMethodApp {
 public:
    NewtonMethodApp();
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double* polynom_coef;
        int polynom_size;
    } Arguments;
};

#endif  // MODULES_NEWTON_METHOD_INCLUDE_NEWTON_METHOD_APP_H_
