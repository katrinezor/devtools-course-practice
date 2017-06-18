// Copyright 2017 Povelikin Rostislav

#include <gtest/gtest.h>
#include <complex>

#include "include/complex_number.h"


class Povelikin_Rostislav_ComplexNumberTest : public ::testing::Test {
 protected:
    double im = 213.123;
    double re = -312.31;
    ComplexNumber complexNumber;

    void SetUp() {
        complexNumber.setIm(im);
        complexNumber.setRe(re);
    }
};

TEST_F(Povelikin_Rostislav_ComplexNumberTest, square_number) {
    complexNumber = complexNumber * complexNumber;

    EXPECT_DOUBLE_EQ(re * re - im * im, complexNumber.getRe());
    EXPECT_DOUBLE_EQ(re * im + re * im, complexNumber.getIm());
}

TEST_F(Povelikin_Rostislav_ComplexNumberTest, sum_with_zero) {
    complexNumber = complexNumber + ComplexNumber();

    EXPECT_DOUBLE_EQ(re, complexNumber.getRe());
    EXPECT_DOUBLE_EQ(im, complexNumber.getIm());
}

TEST_F(Povelikin_Rostislav_ComplexNumberTest, sum_of_conjugate_is_0) {
    ComplexNumber conjucate(complexNumber);
    conjucate.setIm(complexNumber.getIm()*(-1));

    EXPECT_DOUBLE_EQ(0, (complexNumber + conjucate).getIm());
}

TEST_F(Povelikin_Rostislav_ComplexNumberTest, abs) {
    std::complex<double> stdComplexNumber(complexNumber.getIm(),
        complexNumber.getRe());

    double absolute = std::sqrt(complexNumber.getIm()*complexNumber.getIm() +
        complexNumber.getRe()*complexNumber.getRe());

    EXPECT_DOUBLE_EQ(std::abs(stdComplexNumber), absolute);
}

TEST(Povelikin_Rostislav_ComplexNumberTest_NoF, destruction_of_array) {
    ComplexNumber* complexNumber = new ComplexNumber[10];
    EXPECT_NO_THROW(delete [] complexNumber);
}
