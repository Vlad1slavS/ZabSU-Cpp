#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Matrix
{
private:
    std::vector<double> data;
    size_t rows;
    size_t cols;

public:
    // Конструкторы
    Matrix(size_t rows, size_t cols);
    Matrix(size_t size); // Для создания квадратной матрицы
    Matrix(const std::vector<std::vector<double> > &init);
    // Получение i-й строки и j-й элемента матрицы
    std::vector<double> getRow(size_t row) const;
    void fill(double value);
    size_t getRowscnt() const;
    size_t getColscnt() const;
    void printMatrix() const;
};

Matrix::Matrix(size_t rows, size_t cols)
    : data(rows * cols, 0.0), rows(rows), cols(cols) {}

Matrix::Matrix(size_t size) : data(size * size, 0.0), rows(size), cols(size) {}

std::vector<double> Matrix::getRow(size_t row) const
{
    if (row >= rows)
    {
        throw std::out_of_range("Индекс строки вне диапазона");
    }
    return std::vector<double>(data.begin() + row * cols, data.begin() + (row + 1) * cols);
}

void Matrix::fill(double value)
{
    std::fill(data.begin(), data.end(), value);
}

size_t Matrix::getRowscnt() const
{
    return rows;
}
size_t Matrix::getColscnt() const { return cols; }

void Matrix::printMatrix() const
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << data[i * cols + j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    Matrix square(3);
    cout << "Матрица создана!" << endl;
    square.fill(2.0);
    square.printMatrix();
    square.getRowscnt();
    return 0;
}