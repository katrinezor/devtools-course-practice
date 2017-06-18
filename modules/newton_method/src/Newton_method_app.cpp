// Copyright 2017 Buldakov Vlad

#include "include/Newton_method_app.h"
#include "include/Newton_method.h"

#include <stdio.h>
#include <string>
#include <sstream>

NewtonMethodApp::NewtonMethodApp() : message_("") {}

void NewtonMethodApp::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a newton method application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <polynom size> " +
          "<polynom coefficients>\n\n" +

          "Where polynom size is integer number (1 or more)"+
          "and coefficients are double-precision numbers.\n\n";
}

bool NewtonMethodApp::ValidateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc == 2) {
        Help(argv[0], "ERROR: Should be more than 2 arguments\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string NewtonMethodApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.polynom_coef = NULL;
        args.polynom_size = static_cast<int>(parseDouble(argv[1]));
        if (argc > 2 && args.polynom_size != argc-2) {
            throw std::string(
                "Number of coefficients not equal polynom size!");
        }
        args.polynom_coef = new double[args.polynom_size];
        for ( int i = 2; i < argc; i++ ) {
            args.polynom_coef[i-2] = parseDouble(argv[i]);
        }
    }
    catch(std::string& str) {
        return str;
    }

    std::ostringstream stream;

    NewtonMethod nm;

    try {
        double root = nm.NewtonMethodPolynom(args.polynom_size,
            args.polynom_coef);
        stream << "Root = " << root;
    }
    catch(std::string& str) {
        delete args.polynom_coef;
        return str;
    }

    delete args.polynom_coef;

    message_ = stream.str();

    return message_;
}
