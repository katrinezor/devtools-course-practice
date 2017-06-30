// Copyright 2017 Zorina Ekaterina

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "../include/application.h"
#include "../include/symbolic_function.h"

Application::Application() : message_("") {}

void Application::help(const char * appname, const char * message) {
    message_ =
        std::string(message) +
        "This is a derivative application.\n\n" +
        "Please type the expression in the following format:\n\n" +
        "  $ " + appname + " <your expression>\n" +
        "Use 'x' to designate the variable.\n" +
        "All arguments should be double-precision numbers\n" +
        "You can enter expressions with the following operators:\n" +
        "    +    addition,\n" +
        "    -    subtraction,\n" +
        "    *    multiplication,\n" +
        "    /    division,\n" +
        "    exp()    exponent,\n" +
        "    ^    exponentiation,\n" +
        "    sin()    sine,\n" +
        "    cos()    cosine,\n" +
        "    log()    logarithm,\n" +
        "    ( )    left and right brackets,\n";
}

string parseExpression(const char* arg) {
    for (unsigned int i = 0; i < strlen(arg); i++) {
        if (!((arg[i] >= '0' && arg[i] <= '9') || arg[i] == '(' || arg[i] == ')' ||
            arg[i] == '+' || arg[i] == '-' || arg[i] == '*' || arg[i] == '/' || arg[i] == '^' ||
            (arg[i] >= 'a' && arg[i] <='z'))
            throw std::string("ERROR. Wrong expression format.");
    }
    return arg;
}

bool Application::validateNumberOfArguments(int argc, const char ** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    return true;
}

std::string Application::operator()(int argc, const char ** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        expression_ += parseExpression(argv[1]);        
    }
    catch (std::string &str) {
        return str;
    }

    SymbolicFunction express;
    std::ostringstream stream;

    stream << express.Derivative(expression_).ToString();

    message_ = stream.str();
    return message_;
}
