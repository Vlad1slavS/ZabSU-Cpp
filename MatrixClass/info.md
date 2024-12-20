# Документация класса `Matrix`

## Заголовочные файлы

- _MatrixClass.h_: содержит объявление класса `Matrix`.
- `<cstdlib>` и `<ctime>`: используются для генерации случайных чисел.
- `<algorithm>`: используется для работы с алгоритмами стандартной библиотеки C++.
- `<stdexcept>`: используется для обработки и генерации исключений.
- `<iostream>`: используется для ввода и вывода.
- `<cmath>`: для математических операций.

## Описание класса `Matrix`

Класс реализует матрицу с различными функциональными возможностями, такими как создание, доступ к элементам, операции сложения, вычитания и умножения.

### Конструкторы

- _`Matrix(size_t rows, size_t cols)`_: создает матрицу с заданным числом строк и столбцов. Выбрасывает исключение `std::invalid_argument`, если размеры матрицы равны нулю.
- _`Matrix(size_t size)`_: создает квадратную матрицу размером `size x size`.
- _`Matrix()`_: создает пустую 0-ую матрицу.

### Методы

- _`getRow(size_t row) const`_: возвращает строку с индексом `row`. Выбрасывает исключение `std::out_of_range`, если индекс строки вне диапазона.
- _`fill(double value)`_: заполняет матрицу значением `value` с использованием `std::fill`.
- _`getRowscnt() const`_: возвращает количество строк в матрице.
- _`getColscnt() const`_: возвращает количество столбцов в матрице.
- _`printMatrix() const`_: выводит матрицу в стандартный вывод.
- _`operator()(size_t i, size_t j)`_: возвращает ссылку на элемент матрицы с индексами `i` и `j` (с поддержкой изменения). Выбрасывает исключение `std::out_of_range`, если индексы вне диапазона.
- _`operator()(size_t i, size_t j) const`_: возвращает значение элемента матрицы с индексами `i` и `j` (константная версия).
- _`fillRand()`_: заполняет матрицу случайными числами. Использует `std::srand` и `std::rand`.
- _`determinant()` вычисляет определитель (методом Гаусса)_
- _`transpose()` возвращает транспонированную матрицу_
- `makeDiagonalMatrix()` создает диагональную матрицу_


### Перегрузка операторов

- `operator()` Доступ к элемнту по i,j индексам
- _`operator+(const Matrix& other) const`_: перегрузка оператора `+` для сложения двух матриц. Выбрасывает исключение `std::invalid_argument`, если размеры матриц не совпадают.
- _`operator-(const Matrix& other) const`_: перегрузка оператора `-` для вычитания одной матрицы из другой. Выбрасывает исключение `std::invalid_argument`, если размеры матриц не совпадают.
- _`operator*(double scalar) const`*: перегрузка оператора `\*` для умножения матрицы на скаляр.
- `operator*(const Matrix& other) const` умножение матрицы на другую
- `operator+=(const Matrix& other)` упрощеная версия сложения матриц
- `operator-=(const Matrix& other)` упрощеная версия вычитания матриц
- `operator*=(double scalar)` упрощеная версия умножения матрицы на скаляр


## Исключения

- _`std::invalid_argument`_: выбрасывается при ошибочных параметрах конструктора или несоответствии размеров матриц при операциях.
- _`std::out_of_range`_: выбрасывается при попытке доступа к элементу по неверным индексам.

## Использование

Для использования класса необходимо создать объект `Matrix`, передав необходимые параметры в один из конструкторов, и выполнять доступные операции согласно предоставленным методам и перегруженным операторам.
