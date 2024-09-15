// mean_calculator.cpp
#include <cmath>             // Подключаем библиотеку для математических операций
#include "mean_calculator.h" // Подключаем заголовочный файл

// Функция для вычисления среднего арифметического
double arithmeticMean(double a, double b)
{
    return (a + b) / 2;
}

// Функция для вычисления среднего геометрического по формуле (sqrt(n,x1*x2x3*xn))
double geometricMean(double a, double b)
{
    return sqrt(abs(a) * abs(b));
}
