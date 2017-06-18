// Copyright 2017 Israfilov Marat

#include "include/matrix_calculator.h"
#include <iostream>
#include <vector>

bool MatrixCalculator::operator ==(const MatrixCalculator& p) const {
    return this->matrix_ == p.matrix_;
}

bool MatrixCalculator::operator !=(const MatrixCalculator& p) const {
    return this->matrix_ != p.matrix_;
}

bool MatrixCalculator::IsSizesEqual(const MatrixCalculator& p) const {
    bool result = false;

    if ((this->matrix_.size() == p.matrix_.size()) &&
        (this->matrix_[0].size() == p.matrix_[0].size())) {
        result = true;
    }

    return result;
}

MatrixCalculator::MatrixCalculator(int rows, int columns) {
    if (rows < 0 || columns < 0) {
        throw "Invalid arguments";
    }

    matrix_ = std::vector<std::vector<double > >(rows,
              std::vector<double>(columns, 0.0));
}

MatrixCalculator::MatrixCalculator(const MatrixCalculator& p) {
    matrix_ = p.matrix_;
}

MatrixCalculator::~MatrixCalculator() {}

MatrixCalculator& MatrixCalculator::operator =(const MatrixCalculator& p) {
    if (!(*this == p)) {
        matrix_ = p.matrix_;
    }

    return *this;
}

MatrixCalculator MatrixCalculator::operator +(const MatrixCalculator& p) const {
    MatrixCalculator result(*this);

    if (!IsSizesEqual(p)) {
        throw "Invalid sizes";
    }

    for (size_t i = 0; i < this->matrix_.size(); ++i) {
        for (size_t j = 0; j < this->matrix_[i].size(); ++j) {
            result.matrix_[i][j] = this->matrix_[i][j] + p.matrix_[i][j];
        }
    }

    return result;
}

MatrixCalculator MatrixCalculator::operator -(const MatrixCalculator& p) const {
    MatrixCalculator result(*this);

    if (!IsSizesEqual(p)) {
        throw "Invalid sizes";
    }

    for (size_t i = 0; i < this->matrix_.size(); ++i) {
        for (size_t j = 0; j < this->matrix_[i].size(); ++j) {
            result.matrix_[i][j] = this->matrix_[i][j] - p.matrix_[i][j];
        }
    }

    return result;
}

MatrixCalculator MatrixCalculator::operator *(const MatrixCalculator& p) const {
    if (this->matrix_[0].size() != p.matrix_.size()) {
        throw "Invalid sizes";
    }

    MatrixCalculator result(this->matrix_.size(), p.matrix_[0].size());

    for (size_t i = 0; i < result.matrix_.size(); ++i) {
        for (size_t j = 0; j < result.matrix_[i].size(); ++j) {
            for (size_t k = 0; k < p.matrix_.size(); ++k) {
                result.matrix_[i][j] += this->matrix_[i][k] * p.matrix_[k][j];
            }
        }
    }

    return result;
}

double MatrixCalculator::Determinant() const {
    if (matrix_.size() != matrix_[0].size()) {
        throw "Invalid sizes";
    }

    double tmp, det = 1;
    MatrixCalculator temp(*this);
    size_t matrix_size = temp.matrix_.size();

    for (size_t i = 0; i < matrix_size; ++i) {
        size_t t = i + 1;
        while ((temp.matrix_[i][i] == 0) && (t < matrix_size)) {
            if (temp.matrix_[t][i] != 0) {
                temp.matrix_[i].swap(temp.matrix_[t]);
                det *= -1;
            }
            ++t;
        }
        if (temp.matrix_[i][i] == 0) {
            det = 0;
            break;
        }
        for (size_t j = i + 1; j < matrix_size; ++j) {
            tmp = temp.matrix_[j][i] / temp.matrix_[i][i];
            for (size_t k = i; k < temp.matrix_.size(); k++) {
                temp.matrix_[j][k] -= temp.matrix_[i][k] * tmp;
            }
        }
        det *= temp.matrix_[i][i];
    }
    return det;
}

void MatrixCalculator::SetMatrix(std::vector<std::vector<double>> &input) {
    if (this->matrix_ != input) {
        for (size_t i = 1; i < input.size(); ++i) {
            if (input[i - 1].size() != input[i].size()) {
                throw "Invalid matrix";
            }
        }

        matrix_ = input;
    }
}
