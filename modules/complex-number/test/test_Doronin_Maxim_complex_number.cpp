// Copyright 2017 Doronin Maxim

#include <gtest/gtest.h>
#include <limits>
#include <cmath>

#include "include/complex_number.h"

TEST(Doronin_Maxim_ComplexNumberTest, Default_constructor_set_zeros) {
    ComplexNumber z;

    EXPECT_EQ(0.0, z.getRe());
    EXPECT_EQ(0.0, z.getIm());
}

TEST(Doronin_Maxim_ComplexNumberTest, Can_create_via_copying_constructor) {
    ComplexNumber z(13.3, -17.8);

    ComplexNumber zCopy(z);

    EXPECT_EQ(z, zCopy);
}

TEST(Doronin_Maxim_ComplexNumberTest, Setting_real_doesnt_change_imaginary) {
    const double Re = 13.3;
    const double Im = -17.8;
    const double newRe = 15.5;
    ComplexNumber z(Re, Im);

    z.setRe(newRe);

    EXPECT_EQ(z.getIm(), Im);
}

TEST(Doronin_Maxim_ComplexNumberTest, Setting_imaginary_doesnt_change_real) {
    const double Re = 13.3;
    const double Im = -17.8;
    const double newIm = 21.3;
    ComplexNumber z(Re, Im);

    z.setIm(newIm);

    EXPECT_EQ(z.getRe(), Re);
}

TEST(Doronin_Maxim_ComplexNumberTest, Equal_method_return_false_if_notequal) {
    ComplexNumber z1(13.3, -17.8);
    ComplexNumber z2(10.3, 17.8);

    ASSERT_FALSE(z1 == z2);
}

TEST(Doronin_Maxim_ComplexNumberTest, NotEqual_method_return_false_if_equal) {
    ComplexNumber z1(13.3, -17.8);
    ComplexNumber z2(13.3, -17.8);

    ASSERT_FALSE(z1 != z2);
}

TEST(Doronin_Maxim_ComplexNumberTest, getRe_is_const_method) {
    const double Re = 13.3;
    const double Im = -17.8;
    ComplexNumber z(Re, Im);
    ComplexNumber expected_z(z);

    z.getRe();

    EXPECT_EQ(expected_z, z);
}

TEST(Doronin_Maxim_ComplexNumberTest, getIm_is_const_method) {
    const double Re = 13.3;
    const double Im = -17.8;
    ComplexNumber z(Re, Im);
    ComplexNumber expected_z(z);

    z.getIm();

    EXPECT_EQ(expected_z, z);
}

TEST(Doronin_Maxim_ComplexNumberTest, assignment_to_itself) {
    const double Re = 13.3;
    const double Im = -17.8;
    ComplexNumber z(Re, Im);

    ASSERT_NO_FATAL_FAILURE(z = z);
}

TEST(Doronin_Maxim_ComplexNumberTest, DISABLED_Can_divide_large_nums) {
    const double x = sqrt(std::numeric_limits<double>::max());
    ComplexNumber z1(x, x);
    ComplexNumber z2(x, x);

    ASSERT_NO_THROW(z1 / z2);
}

TEST(Doronin_Maxim_ComplexNumberTest, DISABLED_Divide_large_nums_correctly) {
    const double x = sqrt(std::numeric_limits<double>::max());
    ComplexNumber z1(x, x);
    ComplexNumber z2(x, x);
    ComplexNumber expected(1.0, 0);

    EXPECT_EQ(expected, z1 / z2);
}

TEST(Doronin_Maxim_ComplexNumberTest, DISABLED_Copy_from_nullptr) {
    ComplexNumber *z1 = nullptr;
    ASSERT_ANY_THROW(ComplexNumber z2(*z1););
}


