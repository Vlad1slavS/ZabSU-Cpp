// Автор: Степанов В. ИВТ-23

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <stdexcept>
#include <iostream>
#include <string>
#include <sstream>

// Класс Matrix представляет матрицу с базовыми операциями линейной алгебры.
class Matrix
{
private:
    // Вектор для хранения элементов матрицы в линейном представлении
    std::vector<double> data;
    // Количество строк в матрице
    size_t rows;
    // Количество столбцов в матрице
    size_t cols;

public:
    // Конструктор: создает матрицу заданного размера (строки и столбцы)
    Matrix(size_t rows, size_t cols);
    // Конструктор: создает пустую матрицу (0x0)
    Matrix();
    // Конструктор: создает квадратную матрицу заданного размера
    Matrix(size_t size);

    // Возвращает вектор, представляющий строку матрицы с заданным индексом
    std::vector<double> getRow(size_t row) const;

    // Заполняет матрицу заданным значением
    void fill(double value);

    // Возвращает количество строк в матрице
    size_t getRowscnt() const;

    // Возвращает количество столбцов в матрице
    size_t getColscnt() const;

    // Выводит содержание матрицы в консоль
    void printMatrix() const;

    // Возвращает ссылку на элемент матрицы в позиции i, j (для использования в качестве lvalue)
    double& operator()(size_t i, size_t j);
    // Возвращает копию элемента матрицы в позиции i, j (для использования в качестве rvalue)
    double operator()(size_t i, size_t j) const;

    // Заполняет матрицу случайными значениями (например, для тестирования)
    void fillRand();

    // Возвращает новую матрицу, являющуюся результатом сложения данной матрицы с другой
    Matrix operator+(const Matrix& other) const;

    // Возвращает новую матрицу, являющуюся результатом вычитания другой матрицы из данной
    Matrix operator-(const Matrix& other) const;

    // Возвращает новую матрицу, умноженную на заданный скаляр
    Matrix operator*(double scalar) const;

    // Возвращает новую матрицу, являющуюся результатом умножения данной матрицы на другую
    Matrix operator*(const Matrix& other) const;

    // Возвращает транспонированную матрицу
    Matrix transpose() const;

    // Создает и возвращает диагональную матрицу, созданную на основе данной
    Matrix makeDiagonalMatrix() const;

    // Вычисляет определитель матрицы методом Гаусса и возвращает его
    double determinant() const;

    // Перегрузка операторов для изменения текущей матрицы в результате арифметических операций
    Matrix operator-=(const Matrix& other);
    Matrix operator+=(const Matrix& other);
    Matrix operator*=(double scalar);

    // Сохраняет матрицу в виде строки, пригодной для вывода или записи
    std::string savetostring();
};

#endif // MATRIX_H
