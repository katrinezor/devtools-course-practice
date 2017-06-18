// Copyright 2017 Dmitrichev Nikita

#include "gtest/gtest.h"

#include "include/complex_number.h"

class Dmitrichev_Nikita_ComplexNumberTest : public ::testing::Test {
 protected:
    virtual void SetUp() {
        CN = new ComplexNumber[N];

        for (int i = 0; i < N; ++i) {
            CN[i].setRe(i + 1);
            CN[i].setIm(i + 1);
        }
    }
    virtual void TearDown() {
        delete[] CN;
    }
    const int N = 3;
    ComplexNumber* CN;
};

TEST_F(Dmitrichev_Nikita_ComplexNumberTest, can_add_up_many_complex_numbers) {
    // Arrange
    ComplexNumber z;

    // Act
    z = CN[0] + CN[1] + CN[2];

    // Assert
    ComplexNumber expected_z(6, 6);
    EXPECT_EQ(expected_z, z);
}

TEST_F(Dmitrichev_Nikita_ComplexNumberTest, copied_com_num_has_its_own_mem) {
    // Act
    ComplexNumber z(CN[0]);

    // Assert
    EXPECT_NE(&z, &CN[0]);
}

TEST_F(Dmitrichev_Nikita_ComplexNumberTest, can_assign_many_complex_numbers) {
    // Act
    CN[0] = CN[1] = CN[2];

    // Assert
    ComplexNumber expected_z(3, 3);
    EXPECT_EQ(expected_z, CN[0]);
    EXPECT_EQ(expected_z, CN[1]);
    EXPECT_EQ(expected_z, CN[2]);
}

TEST_F(Dmitrichev_Nikita_ComplexNumberTest, can_mult_many_complex_numbers) {
    // Arrange
    ComplexNumber z;

    // Act
    z = CN[0] * CN[1] * CN[2];

    // Assert
    ComplexNumber expected_z(-12, 12);
    EXPECT_EQ(expected_z, z);
}

TEST_F(Dmitrichev_Nikita_ComplexNumberTest, addition_is_associative) {
    // Arrange
    ComplexNumber z1, z2, z3;

    // Act
    z1 = (CN[0] + CN[1]) + CN[2];
    z2 = CN[0] + (CN[1] + CN[2]);
    z3 = (CN[0] + CN[2]) + CN[1];

    // Assert
    EXPECT_EQ(z1, z2);
    EXPECT_EQ(z1, z3);
    EXPECT_EQ(z2, z3);
}

TEST_F(Dmitrichev_Nikita_ComplexNumberTest, can_do_add_dif_mult_div_together) {
    // Arrange
    ComplexNumber z;

    // Act
    z = CN[0] + CN[1] - CN[2] * CN[0] / CN[1];

    // Assert
    ComplexNumber expected_z(1.5, 1.5);
    EXPECT_EQ(expected_z, z);
}
