// Copyright 2017 Vinogradova Ekaterina

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Vinogradova_Ekaterina_ComplexNumberTest, Commutativity_Of_Addition) {
    // Arrange
    ComplexNumber z1(10.0, 15.0);
    ComplexNumber z2(14.0, 20.0);

    // Act & Assert
    EXPECT_EQ(z1 + z2, z2 + z1);
}

TEST(Vinogradova_Ekaterina_ComplexNumberTest, Commutativity_Of_Mult) {
    // Arrange
    ComplexNumber z1(10.0, 15.0);
    ComplexNumber z2(14.0, 20.0);

    // Act & Assert
    EXPECT_EQ(z1 * z2, z2 * z1);
}

TEST(Vinogradova_Ekaterina_ComplexNumberTest, Associativity_Of_Addition) {
    // Arrange
    ComplexNumber z1(15.0, 10.0);
    ComplexNumber z2(14.0, 20.0);
    ComplexNumber z3(8.0, 11.0);

    // Act
    ComplexNumber left_z = (z1 + z2) + z3;
    ComplexNumber right_z = z1 + (z2 + z3);

    // Assert
    EXPECT_EQ(left_z, right_z);
}

TEST(Vinogradova_Ekaterina_ComplexNumberTest, Associativity_Of_Mult) {
    // Arrange
    ComplexNumber z1(15.0, 10.0);
    ComplexNumber z2(14.0, 20.0);
    ComplexNumber z3(8.0, 11.0);

    // Act
    ComplexNumber left_z = (z1 * z2) * z3;
    ComplexNumber right_z = z1 * (z2 * z3);

    // Assert
    EXPECT_EQ(left_z, right_z);
}

TEST(Vinogradova_Ekaterina_ComplexNumberTest, Distributivity) {
    // Arrange
    ComplexNumber z1(15.0, 10.0);
    ComplexNumber z2(14.0, 20.0);
    ComplexNumber z3(8.0, 11.0);

    // Act
    ComplexNumber left_z = z1 * (z2 + z3);
    ComplexNumber right_z = z1 * z2 + z1 * z3;

    // Assert
    EXPECT_EQ(left_z, right_z);
}

TEST(Vinogradova_Ekaterina_ComplexNumberTest, Imaginary_Squared_Is_Minus_One) {
    // Arrange
    ComplexNumber z(0.0, 1.0);

    // Act
    ComplexNumber res_z = z * z;

    // Assert
    ComplexNumber exp_z(-1.0, 0.0);
    EXPECT_EQ(exp_z, res_z);
}

TEST(Vinogradova_Ekaterina_ComplexNumberTest, Mult_Of_Conjugate_Give_Zero_Im) {
    // Arrange
    ComplexNumber z1(5.0, 12.0);
    ComplexNumber z2(5.0, -12.0);

    // Act
    ComplexNumber res_z = z1 * z2;

    // Assert
    EXPECT_EQ(0.0, res_z.getIm());
}
