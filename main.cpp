#include <iostream>
#include "func.h"

// https://github.com/b2050330/lab1

//Вариант 2
/* Из входного потока вводится прямоугольная сильно разреженная матрица вещественных чисел [aij],
 * i = 1, …, m, j = 1, …, n.  Значения m и n заранее не известны и вводятся из входного потока.
Сформировать новую матрицу, упорядочив строки исходной матрицы по возрастанию (если a11 <= 0)
 или убыванию (если a11 > 0) элементов первого столбца.
Исходную и полученную матрицы вывести в выходной поток с необходимыми комментариями. */

using namespace func;

int main() {
    struct Line *ln = nullptr;
    int str_num, collum_num;


    ln = input(str_num, collum_num);
    if (!ln) {
        std::cout << "incorrect data" << std::endl;
        return 1;
    }

    output("Sourced matrix", ln, str_num, collum_num);
    ln = sort(ln, str_num, collum_num);
    output("Sorted matrix", ln, str_num, collum_num);
    erase(ln, str_num);
    return 0;
}
