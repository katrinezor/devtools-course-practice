// Copyright 2017 Korniakov Kirill

#include <gtest/gtest.h>
#include <limits>
#include <string>
#include "include/complex_number.h"

TEST(Bevzuk_Semen_ComplexNumberTest, Can_assigning_yourself) {
    // Arrange
    double re = 1.1;
    double im = 2.2;

    // Act
    ComplexNumber z(re, im);
    z = z;

    // Assert
    EXPECT_DOUBLE_EQ(re, z.getRe());
    EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(Bevzuk_Semen_ComplexNumberTest, Can_not_division_by_number_less_eps) {
    // Arrange
    const double eps = std::numeric_limits<double>::epsilon()/2.0;
    ComplexNumber z1(eps, 0.0);
    ComplexNumber z2(1.1, 1.0);

    // Act & Assert
    EXPECT_THROW(z2 / z1, std::string);
}

TEST(Bevzuk_Semen_ComplexNumberTest, Can_division_by_number_more_eps) {
    // Arrange
    const double eps = std::numeric_limits<double>::epsilon() * 2.0;
    ComplexNumber z1(eps, 0);
    ComplexNumber z2(1.0, 0);
    ComplexNumber result(1.0 / eps, 0);

    // Act & Assert
    EXPECT_EQ(z2 / z1, result);
}

TEST(Bevzuk_Semen_ComplexNumberTest, Sum_number_and_conjugate_is_real_number) {
    // Arrange
    // z1 = a+ib; z2 = a-ib; => z1+z2 = 2a;
    ComplexNumber z1(5, 3);
    ComplexNumber z2(5, -3);
    ComplexNumber result(10, 0);

    // Act & Assert
    EXPECT_EQ(z1+z2, result);
}

TEST(Bevzuk_Semen_ComplexNumberTest,
    Multiplication_by_conjugate_corresponds_property_of_complex_number) {
    // Arrange
    // z1 = a+ib; z2 = a-ib; => z1*z2 = a^2+b^2;
    ComplexNumber z1(2, -1);
    ComplexNumber z2(2, 1);
    ComplexNumber result(5, 0);

    // Act & Assert
    EXPECT_EQ(z1*z2, result);
}

TEST(Bevzuk_Semen_ComplexNumberTest, Difference_with_itself_is_zero) {
    // Arrange
    ComplexNumber z(4.0, 2.0);
    ComplexNumber z1;
    ComplexNumber result(0, 0);

    // Act
    z1 = z - z;

    // Assert
    EXPECT_EQ(z1, result);
}
