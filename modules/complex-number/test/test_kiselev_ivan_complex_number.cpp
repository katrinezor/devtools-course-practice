// Copyright 2017 Kiselev Ivan
#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kiselev_Complex_Number_Test, Simple_Test) {
ComplexNumber first(2.0, 3.0);
ComplexNumber second(2.0, 3.0);
EXPECT_TRUE(first == second);
}

TEST(Kiselev_Complex_Number_Test, Add_Test) {
ComplexNumber first(3.0, 2.5);
ComplexNumber second(2.0, 3.0);
ComplexNumber result(1.0, -0.5);
EXPECT_TRUE(result == first - second);
}

TEST(Kiselev_Complex_Number_Test, Multiplication_Test) {
ComplexNumber first(3.0, 2.0);
ComplexNumber second(2.0, 3.0);
ComplexNumber result(0, 13.0);
EXPECT_TRUE(result == first * second);
}

TEST(Kiselev_Complex_Number_Test, Division_Test) {
ComplexNumber first(2.0, 2.0);
ComplexNumber second(2.0, 2.0);
ComplexNumber result(1.0, 0.0);
EXPECT_TRUE(result == first / second);
}
