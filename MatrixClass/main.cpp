#include <iostream>
#include "MatrixClass.h"

using namespace std;

int main()
{
    try
    {
        // Создание матрицы 3x3 и заполнение единицами
        Matrix A(3);
        A.fill(1);
        // Создание матрицы 3x3 и заполнение случайными числами
        Matrix B(3);
        B.fill(3);
        // Сумма матриц
        Matrix C = A + B;
        // Вычитание матриц
        Matrix D = B - A;
        // Умножение на скаляр
        Matrix E = A * 2;
        // Умножение матриц
        Matrix F = A * B;  
        // Транспонирование матрицы
        Matrix G(3);
        G.fillRand();
        G.transpose();
        // Создание диагональной матрицы
        Matrix Z(4);
        Z.makeDiagonalMatrix();
        // Вычисление определителя матрицы
        Matrix H(3);
        H.fillRand();
        // += -= *=
        Matrix I(3);
        I.fill(2);
        I.printMatrix();
        I += A;
        I.printMatrix();
        I -= A;
        I.printMatrix();
        // Метод получения доступа к строке по ее индексу
        std::vector<double> arr = A.getRow(2);
        for (double i : arr){
            cout << arr[i] << " ";
        }

    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
