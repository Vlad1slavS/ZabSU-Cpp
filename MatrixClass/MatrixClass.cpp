#include "MatrixClass.h"
#include <cstdlib> // Для std::srand и std::rand
#include <ctime>
#include <algorithm> // Для std::fill
#include <stdexcept>
#include <iostream>

Matrix::Matrix(size_t rows, size_t cols){
    if (rows == 0 || cols == 0) {
        throw std::invalid_argument("Размеры матрицы должны быть положительными");
    }
    this->rows = rows;
    this->cols = cols;
    this->data = std::vector<double>(rows * cols, 0.0);
}

Matrix::Matrix(size_t size) : rows(size), cols(size), data(size * size, 0.0) {}

std::vector<double> Matrix::getRow(size_t row) const
{
    if (row < 1 || row > rows)
    {
        throw std::out_of_range("Индекс строки вне диапазона");
    }
    std::vector<double> rowData(cols);
    for (size_t j = 1; j <= cols; j++)
    {
        rowData[j - 1] = (*this)(row, j);
    }
    return rowData;
}

void Matrix::fill(double value)
{
    std::fill(data.begin(), data.end(), value);
}

size_t Matrix::getRowscnt() const { return rows; }
size_t Matrix::getColscnt() const { return cols; }

void Matrix::printMatrix() const
{
    for (size_t i = 1; i <= rows; i++)
    {
        for (size_t j = 1; j <= cols; j++)
        {
            std::cout << (*this)(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

double& Matrix::operator()(size_t i, size_t j)
{
    if (i < 1 || i > rows || j < 1 || j > cols) {
        throw std::out_of_range("Индексы вне диапазона");
    }
    return data[(i - 1) * cols + (j - 1)];
}

double Matrix::operator()(size_t i, size_t j) const {
    if (i < 1 || i > rows || j < 1 || j > cols) {
        throw std::out_of_range("Индексы вне диапазона");
    }
    return data[(i - 1) * cols + (j - 1)];
}

void Matrix::fillRand()
{
    static bool first_call = true;
    if (first_call)
    {
        std::srand(static_cast<unsigned int>(std::time(0)));
        first_call = false;
    }
    for (size_t i = 1; i <= rows; ++i)
    {
        for (size_t j = 1; j <= cols; ++j)
        {
            (*this)(i, j) = static_cast<double>(std::rand()) / RAND_MAX;
        }
    }
}

Matrix Matrix::operator+(const Matrix& other) const
{
    if (rows != other.rows || cols != other.cols)
    {
        throw std::invalid_argument("Размеры матриц не совпадают");
    }
    Matrix result(rows, cols);
    for (size_t i = 1; i <= rows; i++)
    {
        for (size_t j = 1; j <= cols; j++)
        {
            result(i, j) = (*this)(i, j) + other(i, j);
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const
{
    if (rows != other.rows || cols != other.cols)
    {
        throw std::invalid_argument("Размеры матриц не совпадают");
    }
    Matrix res(rows, cols);
    for (size_t i = 1; i <= rows; i++)
    {
        for (size_t j = 1; j <= cols; j++)
        {
            res(i, j) = (*this)(i, j) - other(i, j);
        }
    }
    return res;
}

Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows, cols);
    for (size_t i = 1; i <= rows; ++i) {
        for (size_t j = 1; j <= cols; ++j) {
            result(i, j) = (*this)(i, j) * scalar;
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Количество столбцов первой матрицы должно быть равно количеству строк второй матрицы");
    }
    Matrix result(rows, other.cols);
    for (size_t i = 1; i <= rows; i++) {
        for (size_t j = 1; j <= other.cols; j++) {
            double sum = 0.0;
            for (size_t k = 1; k <= cols; k++) {
                sum += (*this)(i, k) * other(k, j);
            }
            result(i, j) = sum;
        }
    }
    return result;
}

Matrix Matrix::transpose() const {
    Matrix result(rows, cols);
    for (size_t i = 1; i <= rows; i++) {
        for (size_t j = 1; j <= cols; j++) {
            result(j, i) = (*this)(i, j);
        }
    }
    return result;
}
