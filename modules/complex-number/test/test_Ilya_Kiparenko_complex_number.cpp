// Copyright 2017 Ilya Kiparenko

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Ilya_Kiparenko_ComplexNumberTest, Cant_Divide_Zero) {
    // Arrange
    ComplexNumber z1(1, 2);
    ComplexNumber z2(0, 0);

    // Act Assert
    EXPECT_ANY_THROW({ z1 / z2; });
}

TEST(Ilya_Kiparenko_ComplexNumberTest, Multiplication_Of_Imaginary_Is_Real) {
    // Arrange
    ComplexNumber z1(0, 2);
    ComplexNumber z2(0, -3);

    // Act
    ComplexNumber z = z1 * z2;

    // Assert
    EXPECT_EQ(z.getIm(), 0);
}

TEST(Ilya_Kiparenko_ComplexNumberTest, Sum_Of_Opposite_Is_Zero) {
    // Arrange
    ComplexNumber z1(1, 2);
    ComplexNumber z2(-1, -2);

    // Act
    ComplexNumber z = z1 + z2;

    // Assert
    ComplexNumber expected_z(0, 0);
    EXPECT_EQ(z, expected_z);
}

TEST(Ilya_Kiparenko_ComplexNumberTest, Sum_Of_Zeros_is_Zero) {
    // Arrange
    ComplexNumber z1(0, 0);

    // Act
    ComplexNumber z = z1 + z1;

    // Assert
    ComplexNumber expected_z(0, 0);
    EXPECT_EQ(z, expected_z);
}

TEST(Ilya_Kiparenko_ComplexNumberTest, Copy_Equal_Original) {
    // Arrange
    ComplexNumber z1(1, 2);
    ComplexNumber z2(z1);

    // Assert
    EXPECT_TRUE(z1 == z2);
}
