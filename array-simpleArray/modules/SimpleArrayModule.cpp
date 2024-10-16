#include <iostream>            // для ввода-вывода
#include "SimpleArrayModule.h" // для функций ввода и вычисления
#include <vector>              // для std::vector

using namespace std; // для использования пространства имен std

// Функция для ввода натурального числа
namespace SimpleArrayModule
{
    // Функция для ввода натурального числа
    int inputNaturalNumber()
    {
        int n;
        cout << "Введите натуральное число n: ";
        cin >> n;

        // Проверка на положительность
        while (n <= 0)
        {
            cout << "Ошибка: n должно быть натуральным числом. Повторите ввод: ";
            cin >> n;
        }

        return n;
    }

    // Функция для вывода результата
    void displayResult(double result)
    {
        cout << "Результат: sin|a1 + a2 + ... + an| (в рад.) = " << result << endl;
    }

}
