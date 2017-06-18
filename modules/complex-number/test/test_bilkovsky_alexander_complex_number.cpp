// Copyright 2017 Bilkovsky Alexander

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Bilkovsky_Alexander_ComplexNumberTest, copied_has_another_adress_1) {
    double re = 15.0;
    double im = 10.0;
    ComplexNumber z(re, im), z1(z);
    z1 = z1 + z1;
    EXPECT_EQ(z == z1, false);
}
TEST(Bilkovsky_Alexander_ComplexNumberTest, copied_has_another_adress_2) {
    double re = 15.0;
    double im = 10.0;
    ComplexNumber z(re, im), z1;
    z1 = z;
    z1 = z1 + z1;
    EXPECT_EQ(z == z1, false);
}
TEST(Bilkovsky_Alexander_ComplexNumberTest, more_adding) {
    double re = 2.0;
    double im = 1.0;
    ComplexNumber z(re, im), z1;
    z1 = z + z + z + z + z;
    EXPECT_EQ(z1.getRe(), 10);
    EXPECT_EQ(z1.getIm(), 5);
}
TEST(Bilkovsky_Alexander_ComplexNumberTest, several_operations_in_one_line) {
    double re = 2.0;
    double im = 1.0;
    ComplexNumber z(re, im), z1;
    z1 = z + z - z - z + z + z;
    EXPECT_EQ(z1.getRe(), 4);
    EXPECT_EQ(z1.getIm(), 2);
}
TEST(Bilkovsky_Alexander_ComplexNumberTest, Multiplication_by_zero) {
    double re = 2.0;
    double im = 1.0;
    ComplexNumber z(re, im), z1;
    z = z * z1;
    EXPECT_EQ(z1.getRe(), 0);
    EXPECT_EQ(z1.getIm(), 0);
}
