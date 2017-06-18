// Copyright 2016 Nesterov Alexander

#include <gtest/gtest.h>
#include <functional>

#include "include/complex_number.h"

typedef std::function<ComplexNumber(int, ComplexNumber)> functor;

TEST(Nesterov_Alexander_ComplexNumberTest,
     Can_Repeatedly_Rewrite_Values_Of_Complex_Numbers) {
    // Arrange
    const int STEPS = 1000;

    // Act
    ComplexNumber z;
    for (int i = 0; i < STEPS; i++) {
        z.setRe(z.getRe() + 1);
        z.setIm(z.getIm() - 1);
    }

    // Assert
    ComplexNumber expected_z(1000, -1000);
    EXPECT_EQ(expected_z, z);
}

TEST(Nesterov_Alexander_ComplexNumberTest,
     Can_Division_Different_Methods) {
    // Arrange
    const double re_z = 3.256;
    const double im_z = 25.123;
    const ComplexNumber z(re_z, im_z);
    const double re_w = 42.856;
    const double im_w = 6.357;
    const ComplexNumber w(re_w, im_w);
    const ComplexNumber conjugate_w(re_w, -im_w);

    // Act
    double norme_w = w.getRe()*w.getRe() + w.getIm()*w.getIm();
    ComplexNumber res1 = (z * conjugate_w) / (w * conjugate_w);
    ComplexNumber res2((z * conjugate_w).getRe() / norme_w,
        (z * conjugate_w).getIm() / norme_w);

    // Assert
    ComplexNumber expected_division = z / w;
    EXPECT_EQ(expected_division, res1);
    EXPECT_EQ(expected_division, res2);
}

TEST(Nesterov_Alexander_ComplexNumberTest,
     Can_Use_Property_Conjugacy) {
    // Arrange
    const int STEPS = 1000;
    const double re = 1 + 1e-5;
    const double im = 1e-5;
    const ComplexNumber z(re, im);
    const ComplexNumber conjugate_z(re, -im);

    // Act
    ComplexNumber res(1.0, 0.0);
    for (int i = 0; i < STEPS; i++)
        res = res * z;
    res.setIm(-res.getIm());

    // Assert
    ComplexNumber expected_conjugacy(1.0, 0.0);
    for (int i = 0; i < STEPS; i++)
        expected_conjugacy = expected_conjugacy * conjugate_z;
    EXPECT_EQ(expected_conjugacy, res);
}

TEST(Nesterov_Alexander_ComplexNumberTest,
     Can_Receive_The_Real_Number) {
    // Arrange
    const int STEPS = 1000;
    const double re = 5e-7;
    const double im = 3e-7;
    const ComplexNumber z(re, im);
    const ComplexNumber conjugate_z(re, -im);

    // Act
    ComplexNumber res(1.0, 0.0);
    for (int i = 0; i < STEPS; i++) {
        res = res * (z +  z * conjugate_z + conjugate_z);
    }

    // Assert
    EXPECT_DOUBLE_EQ(0.0, res.getIm());
}

TEST(Nesterov_Alexander_ComplexNumberTest,
     Can_Use_Repeated_Enclosure_Constructors) {
    // Arrange
    const double re = 3.68;
    const double im = 2.09;
    const ComplexNumber z(re, im);

    // Act
    functor foo = [&foo](int k, ComplexNumber y) -> ComplexNumber {
        if (k != 1) {
            ComplexNumber temp(foo(k - 1, y));
            return temp;
        }
        return y;
    };
    ComplexNumber res(foo(1000, z));

    // Assert
    EXPECT_EQ(z, res);
}
