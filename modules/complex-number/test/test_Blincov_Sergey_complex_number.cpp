// Copyright 2017 Blincov Sergey


#include <gtest/gtest.h>
#include <math.h>

#include "include/complex_number.h"

TEST(Blincov_Sergey_ComplexNumberTest, DevideOnZero) {
    ComplexNumber z1(3, 3);
    ComplexNumber z2(0, 0);
    EXPECT_ANY_THROW({ z1 / z2; });
}

TEST(Blincov_Sergey_ComplexNumberTest, MultiplyZeroOnZero) {
    ComplexNumber z1(7.5, 7.5);
    ComplexNumber expected(0.0, 0.0);
    EXPECT_DOUBLE_EQ(expected.getRe(), (z1 = z1 * expected).getRe());
    EXPECT_DOUBLE_EQ(expected.getIm(), (z1 = z1* expected).getIm());
}

TEST(Blincov_Sergey_ComplexNumberTest, EqualsAbsOfReverseDigits) {
    ComplexNumber z1(5.0, 1.0);
    ComplexNumber z2(5.0, -1.0);
    double abs_z1 = sqrt(z1.getRe() * z1.getRe() + z1.getIm() * z1.getIm());
    double abs_z2 = sqrt(z2.getRe()*z2.getRe() + z2.getIm() * z2.getIm());
    EXPECT_TRUE(abs_z1 == abs_z2);
}

TEST(Blincov_Sergey_ComplexNumberTest, SummaryFloatingNumbers) {
    ComplexNumber z1(3.2, 3.4);
    ComplexNumber z2(3.4, 3.2);
    ComplexNumber summary = z1 + z2;
    EXPECT_DOUBLE_EQ(6.6, summary.getRe());
    EXPECT_DOUBLE_EQ(6.6, summary.getIm());
}

TEST(Blincov_Sergey_ComplexNumberTest, MakeACopyOfComplexNumberObject) {
    ComplexNumber z1(7.7, 4.4);
    ComplexNumber z2(z1);
    EXPECT_TRUE(z2.getRe() == z1.getRe());
    EXPECT_TRUE(z2.getIm() == z1.getIm());
}
