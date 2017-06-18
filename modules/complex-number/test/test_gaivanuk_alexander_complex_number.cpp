// Copyright 2017 Alexander Gaivanuk

#include <gtest/gtest.h>
#include <limits>

#include "include/complex_number.h"

const double eps = std::numeric_limits<double>::epsilon();

TEST(Gaivanuk_Alexander_ComplexNumberTest, Assign_operator_returns_this) {
    ComplexNumber z1(-324.23, 123.42);
    ComplexNumber z2(24.23, -2.2);

    ComplexNumber &z = (z1 = z2);

    EXPECT_EQ(&z, &z1);
}

TEST(Gaivanuk_Alexander_ComplexNumberTest, Difference_on_equal_numbers) {
    double re = 234.23;
    double im = 324432.243;

    ComplexNumber z1(re, im);
    ComplexNumber z2(re, im);
    ComplexNumber z = z1 - z2;

    EXPECT_EQ(0.0, z.getRe());
    EXPECT_EQ(0.0, z.getIm());
}

TEST(Gaivanuk_Alexander_ComplexNumberTest, Mult_conjuctive_numbers) {
    double re = 34.23;
    double im = -12.44;
    ComplexNumber z1(re, im);
    ComplexNumber z2(re, -im);

    ComplexNumber z = z1 * z2;

    EXPECT_NEAR(re*re + im*im, z.getRe(), eps);
    EXPECT_NEAR(0.0, z.getIm(), eps);
}

TEST(Gaivanuk_Alexander_ComplexNumberTest, Check_assign_operator) {
    ComplexNumber z(12.543, -23.44);

    ComplexNumber z2;
    z = z2;

    EXPECT_EQ(z, z2);
}

TEST(Gaivanuk_Alexander_ComplexNumberTest, Assign_to_itself) {
    double re = -24.435;
    double im = 54.34;
    ComplexNumber z(re, im);

    z = z;
    EXPECT_EQ(z.getRe(), re);
    EXPECT_EQ(z.getIm(), im);
}


TEST(Gaivanuk_Alexander_ComplexNumberTest, Division_by_itself) {
    ComplexNumber z(-3.23, 12.0);

    ComplexNumber z2 = z / z;

    EXPECT_NEAR(1.0, z2.getRe(), eps);
    EXPECT_NEAR(0.0, z2.getIm(), eps);
}

TEST(Gaivanuk_Alexander_ComplexNumberTest, Number_is_not_not_equal_to_itself) {
    ComplexNumber z(-3.23, 12.0);

    EXPECT_FALSE(z != z);
}
