// Copyright 2017 Israfilov Marat

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Israfilov_Marat_ComplexNumberTest, Difference_Equal_Numbers_Gives_Zero) {
    // Arrange
    ComplexNumber z(1.2, 3.4);
    ComplexNumber z1(z);
    ComplexNumber z2;

    // Act
    z2 = z - z1;

    // Assert
    ComplexNumber expected_z(0.0, 0.0);

    EXPECT_EQ(z2, expected_z);
}

TEST(Israfilov_Marat_ComplexNumberTest, Add_With_Zero_Does_Not_Change_Number) {
    // Arrange
    ComplexNumber z(1.2, 3.4);
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2;

    // Act
    z2 = z + z1;

    // Assert
    EXPECT_EQ(z2, z);
}

TEST(Israfilov_Marat_ComplexNumberTest, Multiplication_With_Zero_Gives_Zero) {
    // Arrange
    ComplexNumber z(1.2, 3.4);
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2;

    // Act
    z2 = z * z1;

    // Assert
    ComplexNumber expected_z(0.0, 0.0);

    EXPECT_EQ(z2, expected_z);
}

TEST(Israfilov_Marat_ComplexNumberTest, Diff_With_Zero_Does_Not_Change_Number) {
    // Arrange
    ComplexNumber z(1.2, 3.4);
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2;

    // Act
    z2 = z - z1;

    // Assert
    EXPECT_EQ(z2, z);
}

TEST(Israfilov_Marat_ComplexNumberTest, Division_Zero_By_Number_Gives_Zero) {
    // Arrange
    ComplexNumber z(1.2, 3.4);
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2;

    // Act
    z2 = z1 / z;

    // Assert
    ComplexNumber expected_z(0.0, 0.0);

    EXPECT_EQ(z2, expected_z);
}
