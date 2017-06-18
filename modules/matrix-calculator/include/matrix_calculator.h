// Copyright 2017 Israfilov Marat

#ifndef MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_CALCULATOR_H_
#define MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_CALCULATOR_H_

#include <vector>

class MatrixCalculator {
 public:
    explicit MatrixCalculator(int rows = 0, int columns = 0);
    MatrixCalculator(const MatrixCalculator&);
    ~MatrixCalculator();

    MatrixCalculator& operator =(const MatrixCalculator&);
    MatrixCalculator operator +(const MatrixCalculator&) const;
    MatrixCalculator operator -(const MatrixCalculator&) const;
    MatrixCalculator operator *(const MatrixCalculator&) const;

    double Determinant() const;
    void SetMatrix(std::vector<std::vector<double>> &);

    bool operator ==(const MatrixCalculator&) const;
    bool operator !=(const MatrixCalculator&) const;
    bool IsSizesEqual(const MatrixCalculator&) const;

 private:
    std::vector<std::vector<double > > matrix_;
};

#endif  // MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_CALCULATOR_H_
