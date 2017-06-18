// Copyright 2017 Israfilov Marat

#include <gtest/gtest.h>
#include <vector>
#include "include/matrix_calculator.h"

TEST(MatrixCalculatorTest, cant_create_matrix_with_negativ_sizes) {
    EXPECT_ANY_THROW(MatrixCalculator matrix(-1, -1));
}

TEST(MatrixCalculatorTest, copied_matrix_is_equal_to_source_one) {
    std::vector<std::vector<double>> tmp(3, std::vector<double>(3, 2));
    MatrixCalculator m1;
    m1.SetMatrix(tmp);

    MatrixCalculator m2(m1);

    EXPECT_EQ(m1, m2);
}

TEST(MatrixCalculatorTest, copied_matrix_has_its_own_memory) {
    std::vector<std::vector<double>> v1(3, std::vector<double>(3, 2));
    std::vector<std::vector<double>> v2(3, std::vector<double>(3, 7));

    MatrixCalculator m1;
    m1.SetMatrix(v1);
    MatrixCalculator m2(m1);
    m2.SetMatrix(v2);

    EXPECT_NE(m1, m2);
}

TEST(MatrixCalculatorTest, assign_operator_change_matrix_size) {
    std::vector<std::vector<double>> v1(3, std::vector<double>(3, 2));
    std::vector<std::vector<double>> v2(4, std::vector<double>(4, 2));

    MatrixCalculator m1, m2;
    m1.SetMatrix(v1);
    m2.SetMatrix(v2);
    m1 = m2;

    EXPECT_EQ(m1, m2);
}

TEST(MatrixCalculatorTest, can_add_matrices_with_equal_size) {
    std::vector<std::vector<double>> v1(3, std::vector<double>(3, 2));

    MatrixCalculator m1, m2, m3;
    m1.SetMatrix(v1);
    m2.SetMatrix(v1);
    m3 = m1 + m2;

    EXPECT_EQ(m3, m1 + m2);
}

TEST(MatrixCalculatorTest, cant_add_matrices_with_not_equal_size) {
    std::vector<std::vector<double>> v1(3, std::vector<double>(3, 2));
    std::vector<std::vector<double>> v2(4, std::vector<double>(4, 2));

    MatrixCalculator m1, m2;
    m1.SetMatrix(v1);
    m2.SetMatrix(v2);

    EXPECT_ANY_THROW(m1 + m2);
}

TEST(MatrixCalculatorTest, can_subtract_matrices_with_equal_size) {
    std::vector<std::vector<double>> v1(3, std::vector<double>(3, 2));

    MatrixCalculator m1, m2, m3;
    m1.SetMatrix(v1);
    m2.SetMatrix(v1);
    m3 = m1 - m2;

    EXPECT_EQ(m3, m1 - m2);
}

TEST(MatrixCalculatorTest, cant_subtract_matrices_with_not_equal_size) {
    std::vector<std::vector<double>> v1(3, std::vector<double>(3, 2));
    std::vector<std::vector<double>> v2(4, std::vector<double>(4, 2));

    MatrixCalculator m1, m2;
    m1.SetMatrix(v1);
    m2.SetMatrix(v2);

    EXPECT_ANY_THROW(m1 - m2);
}

TEST(MatrixCalculatorTest, can_mult_matrices_with_correct_size) {
    std::vector<std::vector<double>> v1(3, std::vector<double>(3, 2));

    MatrixCalculator m1, m2, m3;
    m1.SetMatrix(v1);
    m2.SetMatrix(v1);
    m3 = m1 * m2;

    EXPECT_EQ(m3, m1 * m2);
}

TEST(MatrixCalculatorTest, cant_mult_matrices_with_incorrect_size) {
    std::vector<std::vector<double>> v1(3, std::vector<double>(3, 2));
    std::vector<std::vector<double>> v2(4, std::vector<double>(3, 2));

    MatrixCalculator m1, m2, m3;
    m1.SetMatrix(v1);
    m2.SetMatrix(v2);

    EXPECT_ANY_THROW(m1 * m2);
}

TEST(MatrixCalculatorTest, determinant_is_calculated_correctry) {
    std::vector<std::vector<double>> v1 = {
        { 1.0, 2.0, 5.0 },
        { 3.0, 2.0, 5.0 },
        { 5.0, 3.0, 1.0 } };
    double expected = 26.0;

    MatrixCalculator m1;
    m1.SetMatrix(v1);

    EXPECT_EQ(m1.Determinant(), expected);
}


TEST(MatrixCalculatorTest, cant_calc_determinant_in_rect_matrix) {
    std::vector<std::vector<double>> v1 = {
        { 1.0, 2.0, 5.0, 3.0 },
        { 3.0, 2.0, 5.0, 2.0 },
        { 5.0, 3.0, 1.0, 4.0 } };

    MatrixCalculator m1;
    m1.SetMatrix(v1);

    EXPECT_ANY_THROW(m1.Determinant());
}

TEST(MatrixCalculatorTest, matrix_determinant_with_zero_elem) {
    std::vector<std::vector<double>> v1 = {
        { 0.0, 2.0, 5.0 },
        { 3.0, 2.0, 5.0 },
        { 5.0, 3.0, 1.0 } };
    double expected = 39.0;

    MatrixCalculator m1;
    m1.SetMatrix(v1);

    EXPECT_EQ(m1.Determinant(), expected);
}

TEST(MatrixCalculatorTest, matrix_determinant_with_zero_row) {
    std::vector<std::vector<double>> v1 = {
        { 1.0, 2.0, 5.0 },
        { 0.0, 0.0, 0.0 },
        { 5.0, 3.0, 1.0 } };
    double expected = 0.0;

    MatrixCalculator m1;
    m1.SetMatrix(v1);

    EXPECT_EQ(m1.Determinant(), expected);
}

TEST(MatrixCalculatorTest, size_comp_is_correctly) {
    std::vector<std::vector<double>> v1(3, std::vector<double>(3, 2));
    std::vector<std::vector<double>> v2(4, std::vector<double>(3, 2));

    MatrixCalculator m1, m2;
    m1.SetMatrix(v1);
    m2.SetMatrix(v2);

    EXPECT_FALSE(m1.IsSizesEqual(m2));
}

TEST(MatrixCalculatorTest, set_matrix_works_correctly) {
    std::vector<std::vector<double>> v1(3);
    for (size_t i = 0; i < v1.size(); ++i) {
        v1[i] = std::vector<double>(i+1);
    }

    MatrixCalculator m1;

    EXPECT_ANY_THROW(m1.SetMatrix(v1));
}
