#include "MatrixClass.h"
#include <cstdlib> // Для std::srand и std::rand
#include <ctime>
#include <algorithm> // Для std::fill

Matrix::Matrix(size_t rows, size_t cols)
    : data(rows * cols, 0.0), rows(rows), cols(cols) {}

Matrix::Matrix(size_t size)
    : data(size * size, 0.0), rows(size), cols(size) {}


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
