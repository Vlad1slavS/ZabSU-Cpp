// Автор: Степанов Владислав ИВТ-23

#include <iostream>                                  // Подключаем библиотеку для ввода-вывода
#include <cmath>                                     // Подключаем библиотеку для математических операций
#include <cstdlib>                                   // Подключаем библиотеку для функций работы со строками
#include "modules/mean_calculator/mean_calculator.h" // Подключаем заголовочный файл модуля
#include <cassert>                                   // Подключаем библиотеку для использования assert

using namespace std; // Используем пространство имен std

// Функция для вывода справки по использованию программы
void showHelp()
{
    cout << "Использование: ./mean_calculator <число1> <число2>" << endl;
    cout << "Или просто запустите программу без аргументов для ввода параметров вручную." << endl;
    cout << "Опции:" << endl;
    cout << "help, --help    Показать это сообщение." << endl;
}

// Функция для автоматического тестирования
void runTests()
{
    // Тесты для arithmeticMean
    assert(arithmeticMean(2, 4) == 3);  // Обычный случай: (2 + 4) / 2 = 3
    assert(arithmeticMean(-2, 2) == 0); // Смешанные знаки: (-2 + 2) / 2 = 0
    assert(arithmeticMean(0, 0) == 0);  // Крайний случай: (0 + 0) / 2 = 0

    // Тесты для geometricMean
    assert(geometricMean(4, 16) == 8);  // Обычный случай: sqrt(4 * 16) = 8
    assert(geometricMean(-4, 16) == 8); // Крайний случай: sqrt(abs(-4) * 16) = 8
    assert(geometricMean(0, 10) == 0);  // Крайний случай: sqrt(0 * 10) = 0
}

// Основная функция программы
int main(int argc, char *argv[])
{
    runTests(); // Запуск тестов. Если тесты не пройдут, программа завершится.

        // Обработка аргументов командной строки
    if (argc == 2 && (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "--help") == 0))
    {
        showHelp(); // Показываем справку
        return 0;   // Завершение программы
    }

    double a, b; // Объявляем переменные для хранения введённых чисел

    // Если аргументы не переданы, запрашиваем данные у пользователя
    if (argc != 3)
    {
        cout << "Введите первое число: ";
        cin >> a; // Считываем первое число
        cout << "Введите второе число: ";
        cin >> b; // Считываем второе число
    }
    else
    {
        // Преобразуем аргументы командной строки в числа
        a = atof(argv[1]); // Преобразуем первый аргумент в double
        b = atof(argv[2]); // Преобразуем второй аргумент в double
    }

    // Вычисляем и выводим средние
    cout << "Среднее арифметическое: " << round(arithmeticMean(a, b) * 100) / 100 << endl;
    cout << "Среднее геометрическое: " << round(geometricMean(a, b) * 100) / 100 << endl;

    return 0; // Завершение программы
}