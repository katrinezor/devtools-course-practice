// Copyright 2017 Kildishev Maxim

#include <gtest/gtest.h>
#include <math.h>

#include "include/complex_number.h"

TEST(Kildishev_Maxim_ComplexNumberTest, MLTPLY_by_selfajoint_is_only_rlpt) {
    ComplexNumber z(1.0, 1.0);
    ComplexNumber z1(1.0, -1.0);
    ComplexNumber res = z * z1;
    EXPECT_DOUBLE_EQ(2.0, res.getRe());
    EXPECT_DOUBLE_EQ(0.0, res.getIm());
}

TEST(Kildishev_Maxim_ComplexNumberTest, Abs_of_selfajoint_digits_are_equal) {
    ComplexNumber z(3.0, 4.0);
    ComplexNumber z1(3.0, -4.0);
    double abs_z = sqrt(z.getRe() * z.getRe() + z.getIm() * z.getIm());
    double abs_z1 = sqrt(z1.getRe()*z1.getRe() + z1.getIm() * z1.getIm());
    EXPECT_TRUE(abs_z == abs_z1);
}

TEST(Kildishev_Maxim_ComplexNumberTest, Multyply_by_zero_is_zero) {
    ComplexNumber z(1.1, 1.1);
    ComplexNumber expected(0.0, 0.0);
    EXPECT_DOUBLE_EQ(expected.getRe(), (z = z * expected).getRe());
    EXPECT_DOUBLE_EQ(expected.getIm(), (z = z* expected).getIm());
}

TEST(Kildishev_Maxim_ComplexNumberTest, Copy_is_equal_orig) {
    ComplexNumber z(1.1, 1.1);
    ComplexNumber z1(z);
    EXPECT_TRUE(z1.getRe() == z.getRe());
    EXPECT_TRUE(z1.getIm() == z.getIm());
}

TEST(Kildishev_Maxim_ComplexNumberTest, Sum_works_with_floatingpoint_numbers) {
    ComplexNumber z(1.1, 1.0);
    ComplexNumber z1(2.0, 2.1);
    ComplexNumber z2 = z + z1;
    EXPECT_DOUBLE_EQ(3.1, z2.getRe());
    EXPECT_DOUBLE_EQ(3.1, z2.getIm());
}
