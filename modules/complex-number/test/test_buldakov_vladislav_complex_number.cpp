// Copyright 2017 Buldakov Vladislav

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Buldakov_Vladislav_ComplexNumberTest, Can_Create_Default) {
    // Arrange & Act
    ComplexNumber z;

    // Assert
    EXPECT_DOUBLE_EQ(0.0, z.getRe());
    EXPECT_DOUBLE_EQ(0.0, z.getIm());
}

TEST(Buldakov_Vladislav_ComplexNumberTest, Can_Compare) {
    // Arrange & Act
    ComplexNumber z(1.0, -1.0);
    ComplexNumber z_copy(1.0, -1.0);

    // Assert
    ASSERT_TRUE(z_copy == z);
}

TEST(Buldakov_Vladislav_ComplexNumberTest, Can_Create_Object_Copy) {
    // Arrange
    ComplexNumber z(5.0, 16.0);

    // Act
    ComplexNumber z_copy(z);

    // Assert
    ASSERT_TRUE(z_copy == z);
}

TEST(Buldakov_Vladislav_ComplexNumberTest, Can_Sum) {
    // Arrange
    double re = 1.0;
    double im = 2.0;
    ComplexNumber z(re, im);
    ComplexNumber neg_z(-re, -im);

    // Act
    ComplexNumber resut = z + neg_z;

    // Assert
    EXPECT_DOUBLE_EQ(0.0, resut.getRe());
    EXPECT_DOUBLE_EQ(0.0, resut.getIm());
}

TEST(Buldakov_Vladislav_ComplexNumberTest, Can_Multiply) {
    // Arrange
    ComplexNumber x(1.1, -1.4);
    ComplexNumber y(1.4, -1.1);

    // Act
    ComplexNumber resut = x * y;

    // Assert
    EXPECT_DOUBLE_EQ(-0.0, resut.getRe());
    EXPECT_DOUBLE_EQ(-3.17, resut.getIm());
}

TEST(Buldakov_Vladislav_ComplexNumberTest, Can_Divide) {
    // Arrange
    ComplexNumber x(0.5, -1.0);
    ComplexNumber y(-2.0, 4.0);

    // Act
    ComplexNumber resut = x / y;

    // Assert
    EXPECT_DOUBLE_EQ(-0.25, resut.getRe());
    EXPECT_DOUBLE_EQ(0.0, resut.getIm());
}
