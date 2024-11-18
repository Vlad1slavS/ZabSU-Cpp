// Автор: Степанов В. ИВТ-23

#include <iostream>
#include "MatrixClass.h"
#include <cassert>

using namespace std;

int main()
{
    // Тест нулевой матрицы
    {
        Matrix m3;
        assert(m3.getRowscnt() == 0);
        assert(m3.getColscnt() == 0);
    }
    // Тест кадратной матрицы
    {
        Matrix m2(3);  // 3x3 
        assert(m2.getRowscnt() == 3);
        assert(m2.getColscnt() == 3);
    }
    // Тест метода заполнения матрицы
    {
        Matrix m6(2, 3);
        m6.fill(1.0);
        auto row = m6.getRow(1);
        assert(row.size() == 3);
        assert(row[0] == 1.0);
    }
    // Тест метода суммирования матриц
    {
        Matrix m7(2, 2), m8(2, 2);
        m7.fill(2.0);
        m8.fill(3.0);
        Matrix res = m7 + m8;
        for (size_t i = 1; i <= 2; i++) {
            for (size_t j = 1; j <= 2; j++) {
                assert(res(i, j) == 5.0);
            }
        }
    }
    // Тест метода умножения матрицы на скаляр
    {
        Matrix m11(2, 2);
        m11.fill(2.0);
        Matrix res3 = m11 * 3.0;
        for (size_t i = 1; i <= 2; i++) {
            for (size_t j = 1; j <= 2; j++) {
                assert(res3(i, j) == 6.0);
            }
        }
    }
    // Тест метода случанйого заполнения матрицы (на диапозон разброса значения)
    {
        Matrix m12(2, 2);
        m12.fillRand();
        assert(m12(1, 1) >= 0.0 && m12(1, 1) <= 1.0);
    }

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
        std::cout << std::endl;
        // Сохранение матрицы в строку
        I.savetostring();
        Matrix T(4,5);
        T.fill(2);
        T.printMatrix();
        Matrix X = T * A;
        X.printMatrix();


    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
