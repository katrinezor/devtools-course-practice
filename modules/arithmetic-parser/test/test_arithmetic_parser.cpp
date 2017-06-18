// Copyright 2017 Alexander Gaivanuk

#include <gtest/gtest.h>

#include <stdlib.h>
#include <math.h>
#include <string>

#include "include/arithmetic_parser.h"

using std::string;

class ArithmeticParserTest : public ::testing::Test {
 protected:
    ArithmeticParser parser;
};

TEST_F(ArithmeticParserTest, Can_parse_simple_expressions) {
    string s1 = "1 + 2";
    string s2 = "x - 1";
    string s3 = "3.1 * 3";
    string s4 = "x / 2.0";
    string s5 = "x ^ 2.0";

    EXPECT_TRUE(parser.Parse(s1));
    EXPECT_TRUE(parser.Parse(s2));
    EXPECT_TRUE(parser.Parse(s3));
    EXPECT_TRUE(parser.Parse(s4));
}

TEST_F(ArithmeticParserTest, Can_parse_mixed_expressions) {
    string s1 = "1 + (2 * x)";
    string s2 = "(1 - x) - (x + 21.3)";
    string s3 = "3.1/1 * 3^(1 + x)";

    EXPECT_TRUE(parser.Parse(s1));
    EXPECT_TRUE(parser.Parse(s2));
    EXPECT_TRUE(parser.Parse(s3));
}

TEST_F(ArithmeticParserTest, Can_parse_expressions_with_omitted_mult) {
    string s1 = "2x";
    string s2 = "23x + 11 / (3(2+3x))";
    string s3 = "3.1 - 3^2 * 3(1 + 2.0x)";

    EXPECT_TRUE(parser.Parse(s1));
    EXPECT_TRUE(parser.Parse(s2));
    EXPECT_TRUE(parser.Parse(s3));
}

TEST_F(ArithmeticParserTest, Can_parse_expressions_with_unary_minus) {
    string s1 = "-2x";
    string s2 = "23.1x + -11";
    string s3 = "-1 - (-2)";
    string s4 = "-(1 * -(-2x))";

    EXPECT_TRUE(parser.Parse(s1));
    EXPECT_TRUE(parser.Parse(s2));
    EXPECT_TRUE(parser.Parse(s3));
    EXPECT_TRUE(parser.Parse(s4));
}

TEST_F(ArithmeticParserTest, Can_parse_expressions_with_functions) {
    string s1 = "(cos(x)^2 + sin(x)^2)";
    string s2 = "tg(1.0) / ctg(1/x)";
    string s3 = "arcsin(-arccos(x+2*arctg(2x)))";
    string s4 = "-ln(2(lg(-3x / 2)))";
    string s5 = "-abs(-x + 2)^2";

    EXPECT_TRUE(parser.Parse(s1));
    EXPECT_TRUE(parser.Parse(s2));
    EXPECT_TRUE(parser.Parse(s3));
    EXPECT_TRUE(parser.Parse(s4));
    EXPECT_TRUE(parser.Parse(s5));
}

TEST_F(ArithmeticParserTest, Can_parse_expressions_with_whitespaces) {
    string s = "1   \t + 2\f\r / x * cos (\t\n1.0/-x)";

    EXPECT_TRUE(parser.Parse(s));
}

TEST_F(ArithmeticParserTest, Cant_parse_aborted_expressions) {
    string s1 = "-2x +";
    string s2 = "x /";
    string s3 = "-1 - (-2";
    string s4 = "-1.";

    EXPECT_FALSE(parser.Parse(s1));
    EXPECT_FALSE(parser.Parse(s2));
    EXPECT_FALSE(parser.Parse(s3));
    EXPECT_FALSE(parser.Parse(s4));
}

TEST_F(ArithmeticParserTest, Cant_parse_wrong_parenthesis_order) {
    string s1 = "(x)+(1/2)/((1+2)";
    string s2 = "x / 4 + (2))";

    EXPECT_FALSE(parser.Parse(s1));
    EXPECT_FALSE(parser.Parse(s2));
}

TEST_F(ArithmeticParserTest, Cant_parse_non_alphanum) {
    string s1 = "^+1";
    string s2 = "$/x+1";

    EXPECT_NO_THROW(parser.Parse(s1));
    EXPECT_NO_THROW(parser.Parse(s2));
    EXPECT_FALSE(parser.Parse(s1));
    EXPECT_FALSE(parser.Parse(s2));
}

TEST_F(ArithmeticParserTest, Cant_parse_unknown_function) {
    string s = "pancake(x)";

    EXPECT_FALSE(parser.Parse(s));
}

TEST_F(ArithmeticParserTest, Can_eval_expressions_without_x) {
    string s1 = "2*(2+2)";
    string s2 = "3 / 1 + 5^3";
    string s3 = "3.43 * (1+2) + 5/3";

    double e1 = 8;
    double e2 = 128;
    double e3 = 3.43 * (1 + 2) + 5.0 / 3.0;
    double a1, a2, a3;

    parser.Parse(s1);
    parser.Evaluate(&a1);
    parser.Parse(s2);
    parser.Evaluate(&a2);
    parser.Parse(s3);
    parser.Evaluate(&a3);

    EXPECT_DOUBLE_EQ(e1, a1);
    EXPECT_DOUBLE_EQ(e2, a2);
    EXPECT_DOUBLE_EQ(e3, a3);
}

TEST_F(ArithmeticParserTest, Can_eval_expressions_with_x) {
    string s1 = "x / (1 + 3.0x)";
    string s2 = "1 + x*2 / x^3";
    string s3 = "3.3 * (x - 1) / 2x / 2";
    double x = 0.234;

    double e1 = [](double x) { return x / (1 + 3.0*x); }(x);
    double e2 = [](double x) { return 1 + x * 2 / (x*x*x); }(x);
    double e3 = [](double x) { return 3.3 * (x - 1.0) / (2.0*x) / 2.0; }(x);
    double a1, a2, a3;

    parser.Parse(s1);
    parser.Evaluate(x, &a1);
    parser.Parse(s2);
    parser.Evaluate(x, &a2);
    parser.Parse(s3);
    parser.Evaluate(x, &a3);

    EXPECT_DOUBLE_EQ(e1, a1);
    EXPECT_DOUBLE_EQ(e2, a2);
    EXPECT_DOUBLE_EQ(e3, a3);
}

TEST_F(ArithmeticParserTest, Can_eval_expressions_with_functions) {
    string s1 = "cos(x)^2 + sin(x)^2";
    string s2 = "tg(x) * ctg(x) + x / 2";
    string s3 = "sin(x) + arcsin(0.2)";
    string s4 = "arccos(0.2) * sin(x/3)";
    string s5 = "arctg(0.01) - tg(x+3)+1";
    string s6 = "lg(x*ln(2.72))";
    string s7 = "-abs(x)/x";
    double x = 435.343;

    double e1 = 1.0;
    double e2 = [](double x) { return 1 + x / 2; }(x);
    double e3 = [](double x) { return sin(x) + asin(0.2); }(x);
    double e4 = [](double x) { return acos(0.2) * sin(x / 3); }(x);
    double e5 = [](double x) { return atan(0.01) - tan(x + 3) + 1; }(x);
    double e6 = [](double x) { return log(x*log(2.72)) / log(10); }(x);
    double e7 = [](double x) { return -fabs(x) / x; }(x);
    double a1, a2, a3, a4, a5, a6, a7;

    parser.Parse(s1);
    parser.Evaluate(x, &a1);
    parser.Parse(s2);
    parser.Evaluate(x, &a2);
    parser.Parse(s3);
    parser.Evaluate(x, &a3);
    parser.Parse(s4);
    parser.Evaluate(x, &a4);
    parser.Parse(s5);
    parser.Evaluate(x, &a5);
    parser.Parse(s6);
    parser.Evaluate(x, &a6);
    parser.Parse(s7);
    parser.Evaluate(x, &a7);

    EXPECT_DOUBLE_EQ(e1, a1);
    EXPECT_DOUBLE_EQ(e2, a2);
    EXPECT_DOUBLE_EQ(e3, a3);
    EXPECT_DOUBLE_EQ(e4, a4);
    EXPECT_DOUBLE_EQ(e5, a5);
    EXPECT_DOUBLE_EQ(e6, a6);
    EXPECT_DOUBLE_EQ(e7, a7);
}

TEST_F(ArithmeticParserTest, Evaluate_returns_zero_on_error) {
    double a;
    bool success;

    parser.Parse("(");
    success = parser.Evaluate(0.424, &a);

    EXPECT_FALSE(success);
}
