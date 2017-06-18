// Copyright 2017 Kabalova Anna

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kabalova_Anna_ComplexNumberTest, Sum_Complex_Number) {
    double re1 = 0.1;
    double im1 = 0.2;

    double re2 = 0.2;
    double im2 = 0.3;

    double re3 = 0.3;
    double im3 = 0.5;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber Sum(re3, im3);

    EXPECT_EQ(Sum, z1+z2);
}

TEST(Kabalova_Anna_ComplexNumberTest, Difference_Complex_Number) {
    double re1 = 0.1;
    double im1 = 0.2;

    double re2 = 0.2;
    double im2 = 0.3;

    double re3 = 0.1;
    double im3 = 0.1;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber Dif(re3, im3);

    EXPECT_EQ(Dif, z2 - z1);
}

TEST(Kabalova_Anna_ComplexNumberTest, Multiplication_Complex_Number) {
    double re1 = 1.0;
    double im1 = 2.0;

    double re2 = 1.0;
    double im2 = -2.0;

    double re3 = 5.0;
    double im3 = 0.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber Mult(re3, im3);

    EXPECT_EQ(Mult, z1 * z2);
}

TEST(Kabalova_Anna_ComplexNumberTest, Test_Copy_Constructor) {
    double re1 = 1.0;
    double im1 = 2.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(z1);

    EXPECT_EQ(z1, z2);
}

TEST(Kabalova_Anna_ComplexNumberTest, Test_Assignment_Operator) {
    double re1 = 1.0;
    double im1 = 2.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber Assigment;
    Assigment = z1;

    EXPECT_EQ(z1, Assigment);
}
