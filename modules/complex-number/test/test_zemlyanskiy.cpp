// Copyright 2017 Zemlyanskiy Nikita
#include <gtest/gtest.h>
#include <string>
#include "include/complex_number.h"
TEST(Zemlyanskiy_TEST, Can_Subtract_Numbers) {
    ComplexNumber s1(5.2, 3.9);
    ComplexNumber s2(3.8, 4.5);
    ComplexNumber s = s1 - s2;
    EXPECT_EQ(s1 - s2, s);
}
TEST(Zemlyanskiy_TEST, Can_Get_Real_Value) {
    ComplexNumber p(2.2, 0.0);
    ASSERT_NO_THROW(p.getRe());
}
TEST(Zemlyanskiy_TEST, Can_Get_Imaginary_Value) {
    ComplexNumber z(0.0, 2.2);
    ASSERT_NO_THROW(z.getIm());
}
TEST(Zemlyanskiy_TEST, Can_Not_Divide_By_Zero) {
    ComplexNumber r1(6.0, 9.0);
    ComplexNumber r2(0.0, 0.0);
    EXPECT_THROW(r1 / r2, std::string);
}
TEST(Zemlyanskiy_TEST, Can_Multiply_Numbers) {
    ComplexNumber x1(2.2, 2.2);
    ComplexNumber x2(4.4, 4.4);
    ComplexNumber x = x1*x2;
    EXPECT_EQ(x1*x2, x);
}
TEST(Zemlyanskiy_TEST, Can_Set_Real_Value) {
    ComplexNumber z;
    double re = 4.2;
    ASSERT_NO_THROW(z.setRe(re));
}
TEST(Zemlyanskiy_TEST, Can_Set_Imaginary_Value) {
    ComplexNumber z;
    double im = 4.2;
    ASSERT_NO_THROW(z.setRe(im));
}
