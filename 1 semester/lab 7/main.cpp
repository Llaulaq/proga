#include <iostream>
#include <func.hpp>

/* Var 1
1. 	Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. 
Если в матрице есть два одинаковых столбца и есть хотя бы один элемент, 
абсолютная величина которого - простое число, упорядочить строки матрицы по неубыванию суммы модулей элементов. */

int main() {
    const int MAX_SIZE { 100 };
    int n { 0 };
    int m { 0 };
    int matrix[MAX_SIZE][MAX_SIZE];

    if (!rkh::read(matrix, n, m)) {
        return -1;
    }

    
    if (rkh::identicalColumns(matrix, n, m) && rkh::isPrime(matrix, n, m)) {
        rkh::sortMatrix(matrix, n, m);
    }


    rkh::write(matrix, n, m);

    return 0;
}