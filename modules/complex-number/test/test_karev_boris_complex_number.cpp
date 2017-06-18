// Copyright 2017 Karev Boris

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Karev_Boris_ComplexNumberTest, Can_add_opposite) {
    double re = 8.9;
    double im = 5.4;

    ComplexNumber z(re, im);
    ComplexNumber z2(-re, -im);
    z = z + z2;

    EXPECT_EQ(0.0, z.getRe());
    EXPECT_EQ(0.0, z.getIm());
}

TEST(Karev_Boris_ComplexNumberTest, Can_create_via_copy_constructor) {
    ComplexNumber z(8.9, 5.4);
    ComplexNumber z2(z);

    EXPECT_EQ(z, z2);
}

TEST(Karev_Boris_ComplexNumberTest, Commutativity_add) {
    ComplexNumber z(1.0, 5.0);
    ComplexNumber z2(5.0, 1.0);
    ComplexNumber z3(z + z2);
    z = z2 + z;

    EXPECT_EQ(z, z3);
}

TEST(Karev_Boris_ComplexNumberTest, Commutativity_multiplication) {
    ComplexNumber z(1.0, 5.0);
    ComplexNumber z2(5.0, 1.0);
    ComplexNumber z3(z*z2);
    z = z2*z;

    EXPECT_EQ(z, z3);
}

TEST(Karev_Boris_ComplexNumberTest, Associativity_add) {
    ComplexNumber z(1.0, 5.0);
    ComplexNumber z2(5.0, 1.0);
    ComplexNumber z3(10.0, 10.0);
    ComplexNumber z4((z + z2) + z3);
    z = z + (z2 + z3);

    EXPECT_EQ(z, z4);
}

TEST(Karev_Boris_ComplexNumberTest, Associativity_multiplication) {
    ComplexNumber z(1.0, 5.0);
    ComplexNumber z2(5.0, 1.0);
    ComplexNumber z3(10.0, 10.0);
    ComplexNumber z4((z*z2)*z3);
    z = z*(z2*z3);

    EXPECT_EQ(z, z4);
}
