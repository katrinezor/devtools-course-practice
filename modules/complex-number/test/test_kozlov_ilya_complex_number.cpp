// Copyright 2017 Kozlov Ilya

#include <gtest/gtest.h>

#include "include/complex_number.h"


TEST(Kozlov_Ilya_ComplexNumberTest, Multiplicate_With_One) {
    const int a = 10;
    const int b = 15;

    ComplexNumber C1(a, b);
    ComplexNumber C2(1, 0);

    EXPECT_EQ((C1*C2), C1);
}

TEST(Kozlov_Ilya_ComplexNumberTest, DISABLED_Existence_Of_Private_Number) {
    const double az = 5.0;
    const double bz = 6.0;

    ComplexNumber z1(10.0, 3.0);
    ComplexNumber z2(11.0, 6.0);
    ComplexNumber z(az, bz);

    bool res = ((z1 * z == z2) && (z == z2 / z1));

    ASSERT_TRUE(res);
}

TEST(Kozlov_Ilya_ComplexNumberTest, Divide_And_Multiplicate_Complex) {
    ComplexNumber z(10, 10);

    EXPECT_EQ(z*z / z, z);
}

TEST(Kozlov_Ilya_ComplexNumberTest, SetRe_SetIm_Is_Working_Correctly) {
    const int az = 10;
    const int bz = 15;

    ComplexNumber z1(az, bz);
    ComplexNumber z2(1, 1);

    z2.setRe(az);
    z2.setIm(bz);

    EXPECT_EQ(z1, z2);
}

TEST(Kozlov_Ilya_ComplexNumberTest, Try_To_GetRe_In_SetRe) {
    const int az = 10;

    ComplexNumber z(az, 1);

    ASSERT_NO_THROW(z.setRe(z.getRe()));
}

TEST(Kozlov_Ilya_ComplexNumberTest, Compare_Get_In_Set_With_Avarage) {
    const int az = 10;
    const int bz = 15;

    ComplexNumber z(az, bz);
    ComplexNumber zCheck(az, bz);

    z.setRe(z.getRe());
    z.setIm(z.getIm());

    EXPECT_EQ(z, zCheck);
}
