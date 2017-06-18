// Copyright 2017 Vasin Stanislav

#include <gtest/gtest.h>

#include "include/complex_number.h"


TEST(Vasin_Stanislav_ComplexNumberTest, imaginary_i_pow_2) {
    // Arrange
    ComplexNumber i(0.0, 1.0);

    // Act
    ComplexNumber i_pow_2 = i * i;

    // Assert
    EXPECT_TRUE((i_pow_2.getRe() == -1.0) && (i_pow_2.getIm() == 0.0));
}

TEST(Vasin_Stanislav_ComplexNumberTest, imaginary_i_pow_3) {
    // Arrange
    ComplexNumber i(0.0, 1.0);

    // Act
    ComplexNumber i_pow_3 = i * i * i;

    // Assert
    EXPECT_TRUE((i_pow_3.getRe() == 0.0) && (i_pow_3.getIm() == -1.0));
}

TEST(Vasin_Stanislav_ComplexNumberTest, imaginary_i_pow_4) {
    // Arrange
    ComplexNumber i(0.0, 1.0);

    // Act
    ComplexNumber i_pow_4 = i * i * i * i;

    // Assert
    EXPECT_TRUE((i_pow_4.getRe() == 1.0) && (i_pow_4.getIm() == 0.0));
}

TEST(Vasin_Stanislav_ComplexNumberTest, mull_by_the_complex_conjugate) {
    // Arrange
    ComplexNumber A(2.3, 15.0);
    ComplexNumber B(2.3, -15.0);

    // Act
    ComplexNumber C = A * B;

    // Assert
    double res = 2.3 * 2.3 + 15.0 * 15.0;
    EXPECT_TRUE((C.getRe() == res) && (C.getIm() == 0.0));
}

TEST(Vasin_Stanislav_ComplexNumberTest, error_add_small_and_large_numbers) {
    // Arrange
    ComplexNumber A(1e+11, 1e+11);
    ComplexNumber B(1e-11, 1e-11);

    // Act
    ComplexNumber C = A + B;

    // Assert
    EXPECT_TRUE((A.getRe() == C.getRe()) && (A.getRe() == C.getRe()));
}

TEST(Vasin_Stanislav_ComplexNumberTest, default_constructor) {
    // Arrange

    // Act
    ComplexNumber A;

    // Assert
    EXPECT_TRUE((0.0 == A.getIm()) && (0.0 == A.getRe()));
}

TEST(Vasin_Stanislav_ComplexNumberTest, copy_constructor) {
    // Arrange
    ComplexNumber A(1.0, 23.1);

    // Act
    ComplexNumber B(A);

    // Assert
    EXPECT_TRUE((A.getIm() == B.getIm()) && (A.getRe() == B.getRe()));
}
