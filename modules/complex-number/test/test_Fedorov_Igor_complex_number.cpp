// Copyright 2017 Fedorov Igor

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Igor_Fedorov_ComplexNumberTest, Cant_divide_by_Zero) {
    double r = 15.023;
    double i = 97.193;
    ComplexNumber a(r, i);
    ComplexNumber b(r, i);
    ComplexNumber c = a - b;
    ComplexNumber d;
    EXPECT_ANY_THROW(d = c / d);
}
TEST(Igor_Fedorov_ComplexNumberTest, can_divide_by_1) {
    double r = 123;
    double i = 123;
    ComplexNumber a(1, 0);
    ComplexNumber b(r, i);
    ComplexNumber c = a / b;
    ComplexNumber d(r / (r*r + i*i), -i / (r*r + i*i));
    EXPECT_EQ(c, d);
}
TEST(Igor_Fedorov_ComplexNumberTest, get_work_ok) {
    double r1 = 1.123;
    double i1 = 12.23;
    double r2 = 123.4;
    double i2 = 1234.0;
    ComplexNumber a(r1, i1);
    ComplexNumber b(r2, i2);
    ComplexNumber c = a * b;
    ComplexNumber d(c.getRe(), c.getIm());
    EXPECT_EQ(c , d);
}
TEST(Igor_Fedorov_ComplexNumberTest, set_work_ok) {
    double r = 1.234;
    double i = 12.34;
    ComplexNumber a(r, i);
    ComplexNumber d;
    d.setRe(r);
    d.setIm(i);
    EXPECT_EQ(a, d);
}
TEST(Igor_Fedorov_ComplexNumberTest, correct_multilication) {
    double r = 1.0;
    double i = 0.0;
    ComplexNumber c(i, r);
    ComplexNumber result(-r, i);
    ComplexNumber cc = c * c;
    EXPECT_EQ(result, cc);
}
