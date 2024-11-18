// Автор: Степанов В. ИВТ-23
// Реализация класса Matrix
// Назначение: Предоставляет методы работы с матрицами, включая операции,
// математические вычисления и вывод данных.

#include "MatrixClass.h"
#include <cstdlib>  // Для генерации случайных чисел
#include <ctime>    // Для инициализации случайного генератора времени
#include <algorithm> // Для использования std::fill и std::swap
#include <stdexcept> // Для обработки исключений
#include <iostream>  // Для вывода данных
#include <cmath>     // Для математических операций

// ===== Конструкторы =====

// Конструктор: инициализирует матрицу заданными строками и столбцами, заполняет нулями
Matrix::Matrix(size_t rows, size_t cols) {
    if (rows == 0 || cols == 0) {
        throw std::invalid_argument("Размеры матрицы должны быть положительными");
    }
    this->rows = rows;
    this->cols = cols;
    this->data = std::vector<double>(rows * cols, 0.0);
}

// Конструктор: создаёт квадратную матрицу указанного размера, заполняет нулями
Matrix::Matrix(size_t size) : rows(size), cols(size), data(size * size, 0.0) {} 

// "rows(size), cols(size), data(size * size, 0.0)" 
// синтаксис используется для инициализации полей класса перед выполнением тела конструктора (обычно для инициализации констант)

// Конструктор по умолчанию: создаёт пустую матрицу
Matrix::Matrix() {
    this->rows = 0;
    this->cols = 0;
    this->data = std::vector<double>(0, 0.0);
}

// ===== Методы доступа =====

// Получение строки матрицы по индексу (от 1 до n)
std::vector<double> Matrix::getRow(size_t row) const {
    if (row < 1 || row > rows) {
        throw std::out_of_range("Индекс строки вне диапазона");
    }
    std::vector<double> rowData(cols);
    for (size_t j = 1; j <= cols; j++) {
        rowData[j - 1] = (*this)(row, j); // *this для доступа к элементам текущего экземпляра матрицы (разыменование)
    }
    return rowData;
}

// Заполнение матрицы заданным значением
void Matrix::fill(double value) {
    std::fill(data.begin(), data.end(), value);
}

// Получение количества строк матрицы
size_t Matrix::getRowscnt() const { return rows; }

// Получение количества столбцов матрицы
size_t Matrix::getColscnt() const { return cols; }


// ===== Вывод и сохранение данных =====


// Вывод матрицы на экран
void Matrix::printMatrix() const {
    for (size_t i = 1; i <= rows; i++) {
        for (size_t j = 1; j <= cols; j++) {
            std::cout << (*this)(i, j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Сохранение матрицы в строковое представление
std::string Matrix::savetostring() {
    std::ostringstream oss;
    if (data.size() > 0) {
        for (size_t i = 1; i <= rows; i++) {
            for (size_t j = 1; j <= cols; j++) {
                oss << (*this)(i, j) << " ";
            }
            oss << "\n";
        }
    }
    return oss.str();
}

// ===== Операции с элементами матрицы =====

// Доступ к элементу матрицы (с возможностью изменения)
double& Matrix::operator()(size_t i, size_t j) {
    if (i < 1 || i > rows || j < 1 || j > cols) {
        throw std::out_of_range("Индексы вне диапазона");
    }
    return data[(i - 1) * cols + (j - 1)];
}

// Доступ к элементу матрицы (только для чтения)
double Matrix::operator()(size_t i, size_t j) const {
    if (i < 1 || i > rows || j < 1 || j > cols) {
        throw std::out_of_range("Индексы вне диапазона");
    }
    return data[(i - 1) * cols + (j - 1)];
}

// Заполнение матрицы случайными числами в диапазоне [0, 1]
void Matrix::fillRand() {
    static bool first_call = true;
    if (first_call) {
        std::srand(static_cast<unsigned int>(std::time(0)));
        first_call = false;
    }
    for (size_t i = 1; i <= rows; ++i) {
        for (size_t j = 1; j <= cols; ++j) {
            (*this)(i, j) = static_cast<double>(std::rand()) / RAND_MAX;
        }
    }
}

// ===== Операции над матрицами =====

// Сложение двух матриц
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Размеры матриц не совпадают");
    }
    Matrix result(rows, cols);
    for (size_t i = 1; i <= rows; i++) {
        for (size_t j = 1; j <= cols; j++) {
            result(i, j) = (*this)(i, j) + other(i, j);
        }
    }
    return result;
}

// Вычитание одной матрицы из другой
Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Размеры матриц не совпадают");
    }
    Matrix result(rows, cols);
    for (size_t i = 1; i <= rows; i++) {
        for (size_t j = 1; j <= cols; j++) {
            result(i, j) = (*this)(i, j) - other(i, j);
        }
    }
    return result;
}

// Умножение матрицы на скаляр
Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows, cols);
    for (size_t i = 1; i <= rows; ++i) {
        for (size_t j = 1; j <= cols; ++j) {
            result(i, j) = (*this)(i, j) * scalar;
        }
    }
    return result;
}

// Умножение двух матриц
Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Количество столбцов первой матрицы должно совпадать с количеством строк второй");
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

// ===== Перегрузка операторов для изменения матриц =====

// Сложение матриц с присваиванием
Matrix Matrix::operator+=(const Matrix& other) {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Размеры матриц не совпадают");
    }
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] += other.data[i];
    }
    return *this;
}

// Вычитание матриц с присваиванием
Matrix Matrix::operator-=(const Matrix& other) {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Размеры матриц не совпадают");
    }
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] -= other.data[i];
    }
    return *this;
}

// Умножение матрицы на скаляр с присваиванием
Matrix Matrix::operator*=(double scalar) {
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] *= scalar;
    }
    return *this;
}

// ===== Дополнительные операции =====

// Транспонирование матрицы
Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
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
        result(i, i) = (*this)(i, i);
    }
    return result;
}

// Вычисление определителя методом Гаусса
double Matrix::determinant() const {
    if (rows != cols) {
        throw std::invalid_argument("Матрица должна быть квадратной для вычисления определителя");
    }
    double det = 1.0; // Инициализация определителя
    Matrix temp = *this; // Создаем копию матрицы для работы

    for (size_t i = 1; i <= temp.rows; i++) {
        // Поиск ведущего элемента в текущем столбце
        size_t pivot = i;
        for (size_t j = i + 1; j <= temp.rows; j++) {
            if (std::abs(temp(j, i)) > std::abs(temp(pivot, i))) {
                pivot = j;
            }
        }
        // Если ведущий элемент найден в другой строке, меняем строки местами
        if (pivot != i) {
            for (size_t j = 1; j <= temp.cols; j++) {
                std::swap(temp(i, j), temp(pivot, j));
            }
            det = -det; // Инвертируем знак определителя
        }
        // Если элемент на диагонали равен нулю, определитель равен нулю
        if (temp(i, i) == 0) {
            return 0.0;
        }
        det *= temp(i, i); // Умножаем определитель на диагональный элемент
        // Приводим остальные строки к треугольному виду
        for (size_t j = i + 1; j <= temp.rows; j++) {
            double factor = temp(j, i) / temp(i, i);
            for (size_t k = i; k <= temp.cols; k++) {
                temp(j, k) -= factor * temp(i, k);
            }
        }
    }
    return det; // Возвращаем вычисленный определитель
}
