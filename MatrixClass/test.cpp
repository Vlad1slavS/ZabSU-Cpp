#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>  // Для форматированного вывода
#include <cstdlib>  // Для генерации случайных чисел
#include <ctime>    // Для инициализации генератора случайных чисел

class Matrix {
private:
    std::vector<double> data;
    size_t rows;
    size_t cols;

public:
    // Конструкторы
    Matrix(size_t rows, size_t cols);
    Matrix(size_t size);  // Для создания квадратной матрицы
    Matrix(const std::vector<std::vector<double> >& init);

    // Доступ к элементам
    double& operator()(size_t i, size_t j);
    double operator()(size_t i, size_t j) const;

    // Доступ к строкам
    std::vector<double> getRow(size_t row) const;

    // Заполнение матрицы
    void fill(double value);
    void randomFill(double min = 0.0, double max = 1.0);

    // Операторы сложения и вычитания
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;

    // Операторы присваивания с арифметическими действиями
    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);

    // Умножение на число
    Matrix operator*(double scalar) const;
    Matrix& operator*=(double scalar);

    // Умножение матрицы на матрицу
    Matrix operator*(const Matrix& other) const;

    // Транспонирование
    Matrix transpose() const;

    // Создание диагональной матрицы
    static Matrix diagonal(const std::vector<double>& diagElements);

    // Вычисление определителя (только для квадратных матриц)
    double determinant() const;

    // Вычисление обратной матрицы (только для квадратных матриц)
    Matrix inverse() const;

    // Применение функции к элементам матрицы
    typedef double (*FunctionType)(double);
    void applyFunction(FunctionType func);

    // Вывод матрицы
    void print() const;

    // Получение размеров матрицы
    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    // Проверка возможности выполнения операции
    void checkBounds(size_t i, size_t j) const;
    void checkSameSize(const Matrix& other) const;
    void checkMultiplicable(const Matrix& other) const;
    void checkSquare() const;
};

// Реализация методов класса Matrix

// Конструктор матрицы размера rows x cols с инициализацией нулями
Matrix::Matrix(size_t rows, size_t cols)
    : data(rows * cols, 0.0), rows(rows), cols(cols) {}

// Конструктор квадратной матрицы размера size x size
Matrix::Matrix(size_t size)
    : data(size * size, 0.0), rows(size), cols(size) {}

// Конструктор инициализации от вложенного вектора
Matrix::Matrix(const std::vector<std::vector<double> >& init) {
    rows = init.size();
    if (rows == 0) {
        cols = 0;
    } else {
        cols = init[0].size();
    }
    data.reserve(rows * cols);
    for (size_t idx = 0; idx < init.size(); ++idx) {
        const std::vector<double>& row = init[idx];
        if (row.size() != cols) {
            throw std::invalid_argument("Все строки должны быть одинаковой длины");
        }
        data.insert(data.end(), row.begin(), row.end());
    }
}

// Доступ к элементам (неконстантный)
double& Matrix::operator()(size_t i, size_t j) {
    checkBounds(i, j);
    return data[i * cols + j];
}

// Доступ к элементам (константный)
double Matrix::operator()(size_t i, size_t j) const {
    checkBounds(i, j);
    return data[i * cols + j];
}

// Получение строки матрицы
std::vector<double> Matrix::getRow(size_t row) const {
    if (row >= rows) {
        throw std::out_of_range("Индекс строки вне диапазона");
    }
    return std::vector<double>(data.begin() + row * cols, data.begin() + (row + 1) * cols);
}

// Заполнение матрицы одним значением
void Matrix::fill(double value) {
    std::fill(data.begin(), data.end(), value);
}

// Заполнение матрицы случайными числами
void Matrix::randomFill(double min, double max) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    for (size_t i = 0; i < data.size(); ++i) {
        double rand_val = min + static_cast<double>(std::rand()) / RAND_MAX * (max - min);
        data[i] = rand_val;
    }
}

// Оператор сложения матриц
Matrix Matrix::operator+(const Matrix& other) const {
    checkSameSize(other);
    Matrix result(rows, cols);
    for (size_t i = 0; i < data.size(); ++i) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

// Оператор вычитания матриц
Matrix Matrix::operator-(const Matrix& other) const {
    checkSameSize(other);
    Matrix result(rows, cols);
    for (size_t i = 0; i < data.size(); ++i) {
        result.data[i] = data[i] - other.data[i];
    }
    return result;
}

// Оператор +=
Matrix& Matrix::operator+=(const Matrix& other) {
    checkSameSize(other);
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] += other.data[i];
    }
    return *this;
}

// Оператор -=
Matrix& Matrix::operator-=(const Matrix& other) {
    checkSameSize(other);
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] -= other.data[i];
    }
    return *this;
}

// Умножение на число
Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows, cols);
    for (size_t i = 0; i < data.size(); ++i) {
        result.data[i] = data[i] * scalar;
    }
    return result;
}

// Оператор *= с числом
Matrix& Matrix::operator*=(double scalar) {
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] *= scalar;
    }
    return *this;
}

// Умножение матрицы на матрицу
Matrix Matrix::operator*(const Matrix& other) const {
    checkMultiplicable(other);
    Matrix result(rows, other.cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < other.cols; ++j) {
            double sum = 0.0;
            for (size_t k = 0; k < cols; ++k) {
                sum += (*this)(i, k) * other(k, j);
            }
            result(i, j) = sum;
        }
    }
    return result;
}

// Транспонирование матрицы
Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result(j, i) = (*this)(i, j);
        }
    }
    return result;
}

// Создание диагональной матрицы
Matrix Matrix::diagonal(const std::vector<double>& diagElements) {
    size_t size = diagElements.size();
    Matrix result(size, size);
    for (size_t i = 0; i < size; ++i) {
        result(i, i) = diagElements[i];
    }
    return result;
}

// Вычисление определителя (методом Гаусса)
double Matrix::determinant() const {
    checkSquare();
    Matrix temp(*this);
    double det = 1.0;
    const double EPS = 1E-9;
    for (size_t i = 0; i < rows; ++i) {
        size_t pivot = i;
        for (size_t j = i + 1; j < rows; ++j) {
            if (std::abs(temp(j, i)) > std::abs(temp(pivot, i))) {
                pivot = j;
            }
        }
        if (std::abs(temp(pivot, i)) < EPS) {
            return 0.0;
        }
        if (i != pivot) {
            for (size_t j = 0; j < cols; ++j) {
                std::swap(temp(i, j), temp(pivot, j));
            }
            det = -det;
        }
        det *= temp(i, i);
        for (size_t j = i + 1; j < rows; ++j) {
            double factor = temp(j, i) / temp(i, i);
            for (size_t k = i; k < cols; ++k) {
                temp(j, k) -= factor * temp(i, k);
            }
        }
    }
    return det;
}

// Вычисление обратной матрицы (метод Гаусса-Жордана)
Matrix Matrix::inverse() const {
    checkSquare();
    size_t n = rows;
    Matrix temp(n, 2 * n);

    // Инициализация расширенной матрицы
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            temp(i, j) = (*this)(i, j);
        }
        temp(i, n + i) = 1.0;
    }

    const double EPS = 1E-9;

    // Прямой ход
    for (size_t i = 0; i < n; ++i) {
        size_t pivot = i;
        for (size_t j = i + 1; j < n; ++j) {
            if (std::abs(temp(j, i)) > std::abs(temp(pivot, i))) {
                pivot = j;
            }
        }
        if (std::abs(temp(pivot, i)) < EPS) {
            throw std::runtime_error("Матрица вырожденная, обратной нет.");
        }
        if (i != pivot) {
            for (size_t j = 0; j < 2 * n; ++j) {
                std::swap(temp(i, j), temp(pivot, j));
            }
        }
        double div = temp(i, i);
        for (size_t j = 0; j < 2 * n; ++j) {
            temp(i, j) /= div;
        }
        for (size_t j = 0; j < n; ++j) {
            if (j != i && std::abs(temp(j, i)) > EPS) {
                double factor = temp(j, i);
                for (size_t k = 0; k < 2 * n; ++k) {
                    temp(j, k) -= factor * temp(i, k);
                }
            }
        }
    }

    // Извлечение обратной матрицы
    Matrix inv(n, n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            inv(i, j) = temp(i, n + j);
        }
    }
    return inv;
}

// Применение функции к элементам матрицы
void Matrix::applyFunction(FunctionType func) {
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] = func(data[i]);
    }
}

// Вывод матрицы
void Matrix::print() const {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            std::cout << std::setw(8) << (*this)(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

// Проверка границ
void Matrix::checkBounds(size_t i, size_t j) const {
    if (i >= rows || j >= cols) {
        throw std::out_of_range("Индексы вне диапазона");
    }
}

// Проверка одинакового размера матриц
void Matrix::checkSameSize(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Матрицы должны быть одинакового размера");
    }
}

// Проверка возможности умножения матриц
void Matrix::checkMultiplicable(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Количество столбцов первой матрицы должно быть равно количеству строк второй матрицы");
    }
}

// Проверка на квадратную матрицу
void Matrix::checkSquare() const {
    if (rows != cols) {
        throw std::invalid_argument("Матрица должна быть квадратной");
    }
}

// Функция для использования в applyFunction
double square(double val) {
    return val * val;
}

// Пример использования класса
int main() {
    try {
        // Создание матрицы 3x3 и заполнение случайными числами
        Matrix A(3, 3);
        A.randomFill(1.0, 10.0);
        std::cout << "Матрица A:" << std::endl;
        A.print();

        // Создание матрицы 3x3 и заполнение числом 5
        Matrix B(3, 3);
        B.fill(5.0);
        std::cout << "\nМатрица B:" << std::endl;
        B.print();

        // Сложение матриц
        Matrix C = A + B;
        std::cout << "\nA + B:" << std::endl;
        C.print();

        // Вычитание матриц
        Matrix D = A - B;
        std::cout << "\nA - B:" << std::endl;
        D.print();

        // Умножение матрицы на число
        Matrix E = A * 2.0;
        std::cout << "\nA * 2.0:" << std::endl;
        E.print();

        // Транспонирование матрицы
        Matrix At = A.transpose();
        std::cout << "\nТранспонированная матрица A:" << std::endl;
        At.print();

        // Создание диагональной матрицы
        double diagArray[] = {1.0, 2.0, 3.0};
        std::vector<double> diagElements(diagArray, diagArray + 3);
        Matrix F = Matrix::diagonal(diagElements);
        std::cout << "\nДиагональная матрица F:" << std::endl;
        F.print();

        // Вычисление определителя
        double detA = A.determinant();
        std::cout << "\nОпределитель матрицы A: " << detA << std::endl;

        // Вычисление обратной матрицы
        Matrix A_inv = A.inverse();
        std::cout << "\nОбратная матрица A:" << std::endl;
        A_inv.print();

        // Проверка решения системы линейных уравнений
        // Решим систему Ax = b, где b - вектор столбец
        double b_array[] = {1.0, 2.0, 3.0};
        Matrix b_matrix(3, 1);
        for (size_t i = 0; i < 3; ++i) {
            b_matrix(i, 0) = b_array[i];
        }

        Matrix x = A_inv * b_matrix;
        std::cout << "\nРешение системы Ax = b:" << std::endl;
        x.print();

        // Применение функции к элементам матрицы
        A.applyFunction(square);
        std::cout << "\nМатрица A после возведения элементов в квадрат:" << std::endl;
        A.print();

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
