// Copyright 2017 Baranov Evgeny

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Baranov_Evgeny_ComplexNumberTest, DISABLED_cant_create_null) {
    // Arrange

    // Act
    ComplexNumber *r1 = nullptr;

    // Assert
    ASSERT_ANY_THROW(ComplexNumber r2(*r1));
}

TEST(Baranov_Evgeny_ComplexNumberTest, setRe_does_not_change_Im) {
    // Arrange
    double re = 11.0;

    // Act
    ComplexNumber r(1, 12);
    r.setRe(re);

    // Assert
    EXPECT_NEAR(11, r.getRe(), 0.001);
    EXPECT_NEAR(12, r.getIm(), 0.001);
}

TEST(Baranov_Evgeny_ComplexNumberTest, setIm_does_not_change_Re) {
    // Arrange
    double im = -1.0;

    // Act
    ComplexNumber r(1, 12);
    r.setIm(im);

    // Assert
    EXPECT_NEAR(1, r.getRe(), 0.001);
    EXPECT_NEAR(-1, r.getIm(), 0.001);
}

TEST(Baranov_Evgeny_ComplexNumberTest, mult_complex_w_conj_eq_sqare_complex) {
    // Arrange
    double re = 2.0;
    double im = -3.0;
    double imconj = 3.0;
    ComplexNumber z(re, im);
    ComplexNumber zconj(re, imconj);

    // Act
    ComplexNumber resconj = z * zconj;
    ComplexNumber res(z.getRe()*z.getRe() + z.getIm()*z.getIm(), 0);

    // Assert
    EXPECT_EQ(res, resconj);
}

TEST(Baranov_Evgeny_ComplexNumberTest, sum_complex_w_conj_eq_real_num) {
    // Arrange
    double re = 2.0;
    double im = -3.0;
    double imconj = 3.0;
    ComplexNumber z(re, im);
    ComplexNumber zconj(re, imconj);

    // Act
    ComplexNumber res = z + zconj;

    // Assert
    EXPECT_NEAR(res.getIm(), 0, 0.001);
}
