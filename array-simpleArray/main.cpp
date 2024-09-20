#include <iostream>                    // для std::cin и std::cout
#include <cmath>                       // для std::sin и std::abs
#include "modules/SimpleArrayModule.h" // для функций ввода и вычисления
using namespace std;                   // для использования пространства имен std
using namespace SimpleArrayModule;     // для использования пространства имен SimpleArrayModule

// Главная функция программы вычисления синуса модуля суммы элементов массива "а"
int main()
{
    // Ввод натурального числа n
    int n = inputNaturalNumber();

    // Ввод массива действительных чисел
    double *a = inputRealNumbers(n);

    // Вычисление суммы элементов массива
    double sum = calculateSum(a, n);

    // Вычисление результата
    double result = calculateResult(sum);

    // Вывод результата
    displayResult(result);

    // Освобождение памяти, выделенной под динамический массив
    delete[] a;

    return 0; // Завершение программы
}
