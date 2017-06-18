// Copyright 2017 Grachev Vlad

#include <gtest/gtest.h>

#include "include/complex_number.h"

class Grachev_Vlad_ComplexNumberTest : public ::testing::Test {
 protected:
    double epsilon = 0.001;
};

TEST_F(Grachev_Vlad_ComplexNumberTest, Copied_Number_Has_Its_Own_Mem) {
    ComplexNumber z1(2.0, 4.0);
    ComplexNumber z2(z1);

    z1.setRe(-2.0);
    z1.setIm(-4.0);

    EXPECT_NE(z1, z2);
}

TEST_F(Grachev_Vlad_ComplexNumberTest, Can_Assign_Number_To_Itself) {
    ComplexNumber z1(1.0, 2.0);

    ASSERT_NO_THROW(z1 = z1);
}

TEST_F(Grachev_Vlad_ComplexNumberTest, Addition_Doesnt_Change_Arguments) {
    ComplexNumber z1(2.0, 4.0), z2(-3.0, -5.0);

    ComplexNumber old_z1(z1), old_z2(z2);
    z1 + z2;

    EXPECT_EQ(z1, old_z1);
    EXPECT_EQ(z2, old_z2);
}

TEST_F(Grachev_Vlad_ComplexNumberTest, Division_Of_Equal_Numbers_Returns_One) {
    ComplexNumber z1(5.1, 6.1), z2(z1);

    ComplexNumber res_z = z1 / z2;

    EXPECT_NEAR(res_z.getRe(), 1.0, Grachev_Vlad_ComplexNumberTest::epsilon);
    EXPECT_NEAR(res_z.getIm(), 0.0, Grachev_Vlad_ComplexNumberTest::epsilon);
}

TEST_F(Grachev_Vlad_ComplexNumberTest, Can_Combine_Operations_On_Numbers) {
    ComplexNumber z1(19.0, 4.0), z2(-3.0, -7.0), z3(2.0, -3.0);

    ComplexNumber res_z = z1 * z2 + z1 / z3 - z2;

    ComplexNumber expected_res(-24.0, -133.0);
    EXPECT_EQ(res_z, expected_res);
}
