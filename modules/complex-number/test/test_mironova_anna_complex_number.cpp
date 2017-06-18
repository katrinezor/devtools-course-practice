// Copyright 2017 Mironova Anna

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Mironova_Anna_ComplexNumberTest, Can_Get_Imaginary) {
    // Arrange
    double im = 25.0;
    ComplexNumber z(0.0, im);

    // Act
    double actual_im = z.getIm();

    // Assert
    EXPECT_EQ(im, actual_im);
}

TEST(Mironova_Anna_ComplexNumberTest, Can_Multiply_Purely_Imaginary_Complex) {
    // Arrange
    ComplexNumber z1;
    ComplexNumber z2(-3.0, 5.0);
    double im = 1.0;
    z1.setIm(im);

    // Act
    ComplexNumber res = z1*z2;
    ComplexNumber expected_res(-z2.getIm(), z2.getRe());

    // Assert
    EXPECT_EQ(expected_res, res);
}

TEST(Mironova_Anna_ComplexNumberTest, Difference_Zero_and_Complex_Opposite) {
    // Arrange
    ComplexNumber z1;
    ComplexNumber z2(-3.0, 5.0);

    // Act
    ComplexNumber res = z1-z2;
    ComplexNumber expected_res(3.0, -5.0);

    // Assert
    EXPECT_EQ(expected_res, res);
}

TEST(Mironova_Anna_ComplexNumberTest, Complex_Conjugate_Numbers_Not_Equal) {
    // Arrange
    ComplexNumber z1(-1.1, 15.25);
    ComplexNumber z2(-1.1, -15.25);

    // Act & Assert
    EXPECT_TRUE(z1 != z2);
}

TEST(Mironova_Anna_ComplexNumberTest, Check_Commutativity_Of_Addition) {
    // Arrange
    ComplexNumber z1(7.0, 14.0);
    ComplexNumber z2(4.0, -15.0);

    // Act
    ComplexNumber res1 = z1+z2;
    ComplexNumber res2 = z2+z1;

    // Assert
    EXPECT_TRUE(res1 == res2);
}

TEST(Mironova_Anna_ComplexNumberTest, Div_Purely_Im_and_Conjugate_Minus_One) {
    // Arrange
    ComplexNumber z1(0.0, 5.0);
    ComplexNumber z2(0.0, -5.0);

    // Act
    ComplexNumber res = z1/z2;
    ComplexNumber expected_res(-1.0, 0.0);

    // Assert
    EXPECT_EQ(expected_res, res);
}

TEST(Mironova_Anna_ComplexNumberTest, Sum_Complex_and_Conjugate_Two_Real_Part) {
    // Arrange
    ComplexNumber z1(20.0, 5.0);
    ComplexNumber z2(20.0, -5.0);

    // Act
    ComplexNumber res = z1+z2;
    ComplexNumber expected_res(40.0, 0.0);

    // Assert
    EXPECT_EQ(expected_res, res);
}
