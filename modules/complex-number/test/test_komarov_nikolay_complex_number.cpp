// Copyright 2017 Komarov Nikolay

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Komarov_Nikolay_Complex_Number_Test, Can_Create_Number) {
    double re = 5.0;
    double im = 7.0;

    ComplexNumber z(re, im);

    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Komarov_Nikolay_Complex_Number_Test, Equality_Of_Numbers) {
    double re1 = 5.0;
    double im1 = 2.0;

    ComplexNumber number1(re1, im1);
    ComplexNumber number2(re1, im1);

    EXPECT_EQ(number1, number2);
}

TEST(Komarov_Nikolay_Complex_Number_Test, Summation_Of_Numbers) {
    double re1 = 5.0;
    double im1 = 2.0;
    double re2 = 3.0;
    double im2 = 6.0;
    double re3 = 8.0;
    double im3 = 8.0;

    ComplexNumber number1(re1, im1);
    ComplexNumber number2(re2, im2);
    ComplexNumber result(re3, im3);

    EXPECT_EQ(number1 + number2, result);
}

TEST(Komarov_Nikolay_Complex_Number_Test, Multiplicity_Of_Numbers) {
    double re1 = 5.0;
    double im1 = 2.0;
    double re2 = 3.0;
    double im2 = 6.0;
    double re3 = 3.0;
    double im3 = 36.0;

    ComplexNumber number1(re1, im1);
    ComplexNumber number2(re2, im2);
    ComplexNumber result(re3, im3);

    EXPECT_EQ(number1 * number2, result);
}

TEST(Komarov_Nikolay_Complex_Number_Test, Getters) {
    double re = 8.4351;
    double im = 0.00547;

    ComplexNumber number(re, im);

    EXPECT_EQ(number.getRe(), re);
    EXPECT_EQ(number.getIm(), im);
}

TEST(Komarov_Nikolay_Complex_Number_Test, Division_Of_Numbers) {
    double re1 = 5.0;
    double im1 = 2.0;
    double re2 = 3.0;
    double im2 = 6.0;
    double re3 = 0.6;
    double im3 = -0.533333;

    ComplexNumber number1(re1, im1);
    ComplexNumber number2(re2, im2);
    ComplexNumber result(re3, im3);

    EXPECT_GT((number1 / number2).getRe(), result.getRe() - 0.00001);
    EXPECT_LT((number1 / number2).getRe(), result.getRe() + 0.00001);
    EXPECT_GT((number1 / number2).getIm(), result.getIm() - 0.00001);
    EXPECT_LT((number1 / number2).getIm(), result.getIm() + 0.00001);
}
