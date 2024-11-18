// Автор: Степанов В. ИВТ-23

#include "MatrixClass.h"
#include <cstdlib> 
#include <ctime>
#include <algorithm> 
#include <stdexcept>
#include <iostream>
#include <cmath>


// Конструктор (с кол-вом колонок и строк)
Matrix::Matrix(size_t rows, size_t cols){
    if (rows == 0 || cols == 0) {
        throw std::invalid_argument("Размеры матрицы должны быть положительными");
    }
    this->rows = rows;
    this->cols = cols;
    this->data = std::vector<double>(rows * cols, 0.0);
}
// Конструктор (с размером квадратной матрицы)
Matrix::Matrix(size_t size) : rows(size), cols(size), data(size * size, 0.0) {}

Matrix::Matrix(){
    this->rows = 0;
    this->cols = 0;
    this->data = std::vector<double>(0, 0.0);
}

// Получение строки по ее индексу (от 1 до n)
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

// Заполнение матрицы значением value   
void Matrix::fill(double value)
{
    std::fill(data.begin(), data.end(), value);
}

// Получение количества строк и столбцов матрицы
size_t Matrix::getRowscnt() const { return rows; }
size_t Matrix::getColscnt() const { return cols; }

// Вывод матрицы на экран
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
    std::cout << std::endl;
}

// Сохранение матрицы в виде строки
std::string Matrix::savetostring(){
    std::ostringstream oss;
    if (data.size() > 0){
        for (size_t i = 1; i < rows; i++){
            for (size_t j = 1; j <= cols; j++){
                oss << (*this)(i, j) << " ";
            }
        }
    }
    std::cout << "Матрица сохранена в строке!!!" << std::endl;
    return oss.str();
}

// Доступ к элементам
double& Matrix::operator()(size_t i, size_t j)
{
    if (i < 1 || i > rows || j < 1 || j > cols) {
        throw std::out_of_range("Индексы вне диапазона");
    }
    return data[(i - 1) * cols + (j - 1)];
}

// Доступ к элементам (константный)
double Matrix::operator()(size_t i, size_t j) const {
    if (i < 1 || i > rows || j < 1 || j > cols) {
        throw std::out_of_range("Индексы вне диапазона");
    }
    return data[(i - 1) * cols + (j - 1)];
}

// Заполнение матрицы случайными числами
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

// Перегрузка оператора "+" для сложения матриц
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

// Перегрузка оператора "-" для вычитания матриц
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

// Перегрузка оператора "*" для умножения матрицы на скаляр
Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows, cols);
    for (size_t i = 1; i <= rows; ++i) {
        for (size_t j = 1; j <= cols; ++j) {
            result(i, j) = (*this)(i, j) * scalar;
        }
    }
    return result;
}

// Перегрузка оператора "*" для умножения матриц
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
 
 // Перегрузка оператора +=
Matrix Matrix::operator+=(const Matrix& other) {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Размеры матриц не совпадают");
    }
    for (size_t i = 0; i < data.size(); ++i) { 
        data[i] += other.data[i]; 
    }
    return *this; 
}

// Перегрузка оператора -=
Matrix Matrix::operator-=(const Matrix& other) {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Размеры матриц не совпадают");
    }
    for (size_t i = 0; i < data.size(); ++i) { 
        data[i] -= other.data[i]; 
    }
    return *this; 
}

// Перегрузка оператора *= для умножения матрицы на скаляр
Matrix Matrix::operator*=(double scalar) {
    for (size_t i = 1; i < data.size(); i++) {
        data[i] += scalar;
    }
    return *this;
}

// Транспонирование матрицы
Matrix Matrix::transpose() const {
    Matrix result(rows, cols);
    for (size_t i = 1; i <= rows; i++) {
        for (size_t j = 1; j <= cols; j++) {
            result(j, i) = (*this)(i, j);
        }
    }
    return result;
}

// Создание диагональной матрицы
Matrix Matrix::makeDiagonalMatrix() const {
    if (rows != cols) {
        throw std::invalid_argument("Матрица должна быть квадратной");
    }
    Matrix result(rows, cols);
    for (size_t i = 1; i <= rows; i++) {
        for (size_t j = 1; j <= cols; j++) {
            if (i == j) {
                result(i, j) = 1;
            } 
        }
    }
    return result;
}

// Вычисление определителя (методом Гаусса)
double Matrix::determinant() const {
    if (rows != cols) {
        throw std::invalid_argument("Матрица должна быть квадратной для вычисления определителя");
    }

    double det = 1.0;
    Matrix temp = *this;

    for (size_t i = 1; i <= temp.rows; i++){
        size_t pivot = i;
        for (size_t j = i + 1; j <= temp.rows; j++){
            if (std::abs(temp(j, i)) > std::abs(temp(pivot, i))){
                pivot = j;
            }
        }
        if (pivot != i){
            for (size_t j = 1; j <= temp.cols; j++){
                std::swap(temp(i, j), temp(pivot, j));
            }
            det = -det; 
        }
        if (temp(i, i) == 0){
            return 0.0;
        }
        det *= temp(i, i);
        for (size_t j = i + 1; j <= temp.rows; j++){
            double factor = temp(j, i) / temp(i, i);
            for (size_t k = i; k <= temp.cols; k++){
                temp(j, k) -= factor * temp(i, k);
            }
        }
    }
    return det;
}
