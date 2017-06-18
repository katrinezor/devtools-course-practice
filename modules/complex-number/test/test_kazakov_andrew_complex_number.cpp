// Copyright 2017 Kazakov Andrew

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kazakov_Andrew_ComplexNumberTest, Copied_Numbers_Are_Equal) {
    // Arrange
    ComplexNumber z(13.0, 26.0);

    // Act
    ComplexNumber z_copy1 = z;
    ComplexNumber z_copy2 = z;

    // Assert
    EXPECT_EQ(z_copy1, z_copy2);
}

TEST(Kazakov_Andrew_ComplexNumberTest, Can_Create_Chain_Of_Assignments) {
    // Arrange
    ComplexNumber z(10.0, 15.0);
    ComplexNumber z1, z2;

    // Act & Assert
    EXPECT_NO_THROW(z2 = z1 = z);
}

TEST(Kazakov_Andrew_ComplexNumberTest, Adding_Zero_Cant_Change_Number) {
    // Arrange
    ComplexNumber z1(5.0, -3.0);
    ComplexNumber z2(0.0, 0.0);

    // Act
    ComplexNumber z = z1 + z2;

    // Assert
    EXPECT_EQ(z, z1);
}

TEST(Kazakov_Andrew_ComplexNumberTest, Subtracting_Zero_Cant_Change_Number) {
    // Arrange
    ComplexNumber z1(-8.0, 888.0);
    ComplexNumber z2(0.0, 0.0);

    // Act
    ComplexNumber z = z1 - z2;

    // Assert
    EXPECT_EQ(z, z1);
}

TEST(Kazakov_Andrew_ComplexNumberTest, Can_Multiply_Number_By_Itself) {
    // Arrange
    ComplexNumber z(5.0, 7.0);

    // Act
    ComplexNumber zz = z * z;

    // Assert
    ComplexNumber expected_z(-24.0, 70.0);
    EXPECT_EQ(zz, expected_z);
}
