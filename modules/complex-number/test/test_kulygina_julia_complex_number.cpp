// Copyright 2017 Kulygina Julia
#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kulygina_Julia_ComplexNumberTest, Can_create_complex_number) {
    double re = 1.0;
    double im = -1.0;
    ComplexNumber z(re, im);
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Kulygina_Julia_ComplexNumberTest, Can_set_complex_number) {
    ComplexNumber z(10.0, 10.0);
    ComplexNumber z2(1.0, 0.0);
    z.setRe(z2.getRe());
    z.setIm(-1.0);
    EXPECT_TRUE(z2 != z);
}

TEST(Kulygina_Julia_ComplexNumberTest, Correct_add_operation) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(z1);
    ComplexNumber tmp(2.0, 4.0);
    ComplexNumber zres;
    zres = z1+z2;
    EXPECT_EQ(tmp, zres);
}

TEST(Kulygina_Julia_ComplexNumberTest, Correct_definition_operation) {
    ComplexNumber z(1.0, 2.0);
    ComplexNumber zres(0.0, 0.0);
    zres = z;
    EXPECT_TRUE(z == zres);
}

TEST(Kulygina_Julia_ComplexNumberTest, Correct_divided_zero) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(0.0, 0.0);
    ASSERT_ANY_THROW(z1/z2);
}

TEST(Kulygina_Julia_ComplexNumberTest, Correct_divide_operation) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(1.0, -1.0);
    double tmp = (z1.getRe() / z2.getRe());
    EXPECT_FALSE((z1/z2).getRe() == tmp);
}

TEST(Kulygina_Julia_ComplexNumberTest, Can_divide) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(1.0, 0.0);
    ComplexNumber tmp = z1 / z2;
    EXPECT_EQ(z1, tmp);
}
