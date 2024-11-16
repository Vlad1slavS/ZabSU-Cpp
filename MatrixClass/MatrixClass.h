#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <stdexcept>
#include <iostream>

class Matrix
{
private:
    std::vector<double> data;
    size_t rows;
    size_t cols;

public:
    // Конструкторы
    Matrix(size_t rows, size_t cols);
    Matrix(size_t size);
    Matrix(const std::vector<std::vector<double> >& init);
    // Метод получения строки по индексу
    std::vector<double> getRow(size_t row) const;
    // Метод заполнения матрицы
    void fill(double value);
    // Метод получения количества строк
    size_t getRowscnt() const;
    // Метод получения количества столбцов
    size_t getColscnt() const;
    // Метод вывода матрицы
    void printMatrix() const;
    // Метод получения доступа к элементу i-й строки и j-го столбца
    double& operator()(size_t i, size_t j);
    // Метод заполнения матрицы случайными числами
    void fillRand();
    // Оператор сложения матриц
    Matrix operator+(const Matrix& other) const;
    // Оператор вычитания матриц
    Matrix operator-(const Matrix& other) const;
    // Оператор умножения матрицы на число
    Matrix operator*(double scalar) const;
};

#endif // MATRIX_H
