// Copyright 2017 Vladimir Kalinin

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Vladimir_Kalinin_ComplexNumberTest, Number_Equal_To_Itself) {
  // Arrange
  ComplexNumber z(0, 0);

  // Act Assert
  EXPECT_TRUE(z == z);
}

TEST(Vladimir_Kalinin_ComplexNumberTest, Multiplication_Of_Conjugate_Is_Real) {
  // Arrange
  ComplexNumber z1(3, 2);
  ComplexNumber z2(3, -2);

  // Act
  ComplexNumber z = z1 * z2;

  // Assert
  EXPECT_EQ(z.getIm(), 0);
}

TEST(Vladimir_Kalinin_ComplexNumberTest, Throw_When_Divide_Zero) {
  // Arrange
  ComplexNumber z1(1, 2);
  ComplexNumber z2(0, 0);

  // Act Assert
  EXPECT_ANY_THROW({ z1 / z2; });
}


TEST(Vladimir_Kalinin_ComplexNumberTest, Multiplication_Of_Zeros_is_Zero) {
  // Arrange
  ComplexNumber z1(0, 0);

  // Act
  ComplexNumber z = z1 * z1;

  // Assert
  ComplexNumber expected_z(0, 0);
  EXPECT_EQ(z, expected_z);
}

TEST(Vladimir_Kalinin_ComplexNumberTest, Can_Appropriate_Element_To_Itself) {
  // Arrange
  ComplexNumber z1(5, 25);
  ComplexNumber z2(z1);

  // Act
  z1 = z1;

  // Assert
  EXPECT_TRUE(z1 == z2);
}
