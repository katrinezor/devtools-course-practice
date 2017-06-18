// Copyright 2017 Gorozhanin Mihail

#include <gtest/gtest.h>

#include "include/complex_number.h"
// Example
TEST(Gorozhanin_Mihail_ComplexNumberTest, Can_Create_Zero) {
  // Arrange
  double re = 0.0;
  double im = 0.0;

  // Act
  ComplexNumber z(re, im);

  // Assert
  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}
// My tests
TEST(Gorozhanin_Mihail_ComplexNumberTest,
  Can_Create_With_Neg_And_Double_Number) {
  double re = -10.0;
  double im = 5.4;
  ComplexNumber z(re, im);
  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Gorozhanin_Mihail_ComplexNumberTest, Can_Multiplication_And_Addition) {
  ComplexNumber z1(5, 10);
  ComplexNumber z2(10, 5);
  ComplexNumber z3(2, 2);
  ComplexNumber z4(4, 4);
  ComplexNumber zRes1 = z1 * z2;
  ComplexNumber zRes2 = z3 * z4;
  EXPECT_EQ(zRes1.getIm()-zRes2.getIm(), 109);
  EXPECT_EQ(zRes1.getRe(), 0);
  EXPECT_EQ(zRes2.getRe(), 0);
}

TEST(Gorozhanin_Mihail_ComplexNumberTest, Validation_For_Completeness) {
  ComplexNumber z1(8, -2);
  ComplexNumber z2(8, 2);
  ComplexNumber zRes = z1*z2;
  EXPECT_EQ(zRes.getRe(), 68);
  EXPECT_EQ(zRes.getIm(), 0);
}
TEST(Gorozhanin_Mihail_ComplexNumberTest, Can_Create_Soever) {
  double re = 5.0;
  double im = -8.0;
  ComplexNumber z1(re, im);
  ComplexNumber z2(5, -8);
  EXPECT_EQ(z1, z2);
  EXPECT_EQ(re, z2.getRe());
  EXPECT_EQ(im, z2.getIm());
}
TEST(Gorozhanin_Mihail_ComplexNumberTest,
  Any_Order_Of_Multiplication_And_Verification_Of_Assignment) {
  double re = 5.0;
  double im = -8.0;
  ComplexNumber z1(re, im);
  ComplexNumber z2 = z1;
  ComplexNumber z_1 = z1*z2;
  ComplexNumber z_2 = z2*z1;
  EXPECT_TRUE(z_1 == z_2);
}
// Delivery date late in connection with the problem in technical terms.
