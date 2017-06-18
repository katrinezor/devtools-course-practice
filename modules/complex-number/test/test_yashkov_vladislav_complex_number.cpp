// Copyright 2017 Yashkov Vladislav

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Yashkov_Vladislav_ComplexNumberTest, Can_Set_Negative_Real) {
  ComplexNumber z(-1, 1);
  EXPECT_EQ(-1, z.getRe());
}

TEST(Yashkov_Vladislav_ComplexNumberTest, Can_Set_Negative_Imaginary) {
  ComplexNumber z(1, -1);
  EXPECT_EQ(-1, z.getIm());
}

TEST(Yashkov_Vladislav_ComplexNumberTest, First_Parm_Is_Real) {
  ComplexNumber z(1, 2);
  EXPECT_EQ(1, z.getRe());
}

TEST(Yashkov_Vladislav_ComplexNumberTest, Second_Parm_Is_Imaginary) {
  ComplexNumber z(1, 2);
  EXPECT_EQ(2, z.getIm());
}

TEST(Yashkov_Vladislav_ComplexNumberTest, If_Not_Equal_Imaginary_Not_Equal) {
  ComplexNumber z1(1, 2);
  ComplexNumber z2(1, 3);
  EXPECT_TRUE(z1 != z2);
}
