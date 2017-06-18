// Copyright 2016 Kursakov Evgeny

#include "include/fraction.h"
#include "include/fraction_calculator.h"

#include <string>
#include <sstream>
#include <stdexcept>

Fraction parseFraction(const std::string &arg);
int parseInt(const std::string &arg);
char parseOperation(const std::string &arg);

FractionCalculator::FractionCalculator() : message_("") { }

std::string FractionCalculator::operator()(int argc, const char **argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    Fraction fraction1;
    Fraction fraction2;
    char operation;

    try {
        fraction1 = parseFraction(argv[1]);
        operation = parseOperation(argv[2]);
        fraction2 = parseFraction(argv[3]);
    } catch (std::invalid_argument& e) {
        return e.what();
    }

    Fraction result;
    try {
        switch (operation) {
            case '+':
                result = fraction1 + fraction2;
                break;
            case '-':
                result = fraction1 - fraction2;
                break;
            case '*':
                result = fraction1 * fraction2;
                break;
            case '/':
                result = fraction1 / fraction2;
                break;
        }
    } catch (std::invalid_argument& e) {
        return e.what();
    }

    std::ostringstream stream;
    stream << result.getNum() << "/" << result.getDenom();

    message_ = stream.str();

    return message_;
}

bool FractionCalculator::validateNumberOfArguments(int argc,
                                                   const char **argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}

void FractionCalculator::help(const char *appName, const char *message) {
    message_ =
        std::string(message) +
            "This is a fraction calculator application.\n\n" +
            "Arguments should be provided in the following format:\n" +

            " $ " + appName + " <frac1>" +
            " <operation> <frac2> \n" +

            "Where <operation> is one of '+', '-', '*', '/' " +
            "and where <frac*> is integer or pair of integer separated by '/'.";
}

Fraction parseFraction(const std::string &arg) {
    size_t separatorPos = arg.find('/');

    if (separatorPos == std::string::npos) {
        return Fraction(parseInt(arg), 1);
    }

    return Fraction(parseInt(arg.substr(0, separatorPos)),
                    parseInt(arg.substr(separatorPos + 1)));
}

int parseInt(const std::string &arg) {
    char *end;
    int value = static_cast<int>(strtol(arg.c_str(), &end, 10));

    if (end[0]) {
        throw std::invalid_argument("Wrong number format!");
    }

    return value;
}

char parseOperation(const std::string &arg) {
    char op;
    if (arg == "+") {
        op = '+';
    } else if (arg == "-") {
        op = '-';
    } else if (arg == "*") {
        op = '*';
    } else if (arg == "/") {
        op = '/';
    } else {
        throw std::invalid_argument("Wrong operation format!");
    }
    return op;
}
