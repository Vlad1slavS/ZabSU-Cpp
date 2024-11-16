#include "MatrixClass.h"
#include <cstdlib> // Для std::srand и std::rand
#include <ctime>
#include <algorithm> // Для std::fill

Matrix::Matrix(size_t rows, size_t cols){
    if (rows > 0) {
        this->rows = rows;
        this->cols = cols;
        this->data = std::vector<double>(rows * cols, 0.0);
    }
}

Matrix::Matrix(size_t size) {
    if (rows > 0) {
        this->rows = size;
        this->cols = size;
        this->data = std::vector<double>(size * size, 0.0);
    }
}


std::vector<double> Matrix::getRow(size_t row) const
{
    if (row < 1 || row > rows)
    {
        throw std::out_of_range("Индекс строки вне диапазона");
    }
    return std::vector<double>(data.begin() + (row - 1) * cols, data.begin() + row * cols);
}

void Matrix::fill(double value)
{
    std::fill(data.begin(), data.end(), value);
}

size_t Matrix::getRowscnt() const { return rows; }
size_t Matrix::getColscnt() const { return cols; }

void Matrix::printMatrix() const
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cout << data[i * cols + j] << " ";
        }
        std::cout << std::endl;
    }
}

double& Matrix::operator()(size_t i, size_t j)
{
    if (i < 1 || i > rows || j < 1 || j > cols)
    {
        throw std::out_of_range("Индексы вне диапазона");
    }
    return data[(i - 1) * cols + (j - 1)];
}

void Matrix::fillRand()
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    for (size_t i = 0; i < data.size(); ++i)
    {
        data[i] = static_cast<double>(std::rand()) / RAND_MAX;
    }
}

Matrix Matrix::operator+(const Matrix& other) const
{
    if (rows != other.rows || cols != other.cols)
    {
        throw std::invalid_argument("Размеры матриц не совпадают");
    }
    Matrix result(rows, cols);
    for (size_t i = 0; i < data.size(); i++)
    {
        result.data[i] = data[i] + other.data[i];
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
    for (int i = 0; i < data.size(); i++) {
        res.data[i] = data[i] - other.data[i];
    }
    return res;
}
