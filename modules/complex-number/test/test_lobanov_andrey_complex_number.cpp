// Copyright 2017 Lobanov Andrey
#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Lobanov_Andrey_ComplexNumberTest, Add__Complex_And_Comparing__Result) {
  ComplexNumber z1(5.0, 4.0);
  ComplexNumber z2(2.0, -7.0);
  ComplexNumber z3(10.0, 1.0);
  ComplexNumber z4(-3.0, -4.0);
  ComplexNumber z_1 = z1 + z2;
  ComplexNumber z_2 = z3 + z4;
  EXPECT_TRUE(z_1 == z_2);
}

TEST(Lobanov_Andrey_ComplexNumberTest, Subtract_Complex_And_Comparing_Result) {
  ComplexNumber z1(12.0, 8.0);
  ComplexNumber z2(-6.0, -15.0);
  ComplexNumber z3(11.0, 7.0);
  ComplexNumber z4(-7.0, -16.0);
  ComplexNumber z_1 = z1 - z3;
  ComplexNumber z_2 = z2 - z4;
  EXPECT_TRUE(z_1 == z_2);
}

TEST(Lobanov_Andrey_ComplexNumberTest, Multiplication_With_Permutation) {
  double r = 5.0;
  double im = -5.0;
  ComplexNumber z1(r, im);
  ComplexNumber z2(r, im);
  ComplexNumber z_1 = z1 * z2;
  ComplexNumber z_2 = z2 * z1;
  EXPECT_EQ(z_1, z_2);
}

TEST(Lobanov_Andrey_ComplexNumberTest, Set_Works_Correctly) {
  ComplexNumber z;
  double r = 25.0;
  double im = 29.0;
  ComplexNumber z1(r, im);
  z.setRe(r);
  z.setIm(im);
  EXPECT_EQ(z, z1);
}

TEST(Lobanov_Andrey_ComplexNumberTest, Division_With_Opposite_And_Compare) {
  double r = 11.0;
  double im = 23.0;
  ComplexNumber z1(r, im);
  ComplexNumber z2(-r, -im);
  ComplexNumber z_1 = z1 / z1;
  ComplexNumber z_2 = z2 / z2;
  bool result = (z_1 == z_2);
  EXPECT_TRUE(result);
}
