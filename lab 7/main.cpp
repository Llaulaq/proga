#include <iostream>
#include <func.hpp>

/* Вариант 1
1. 	Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. 
Если в матрице есть два одинаковых столбца и есть хотя бы один элемент, 
абсолютная величина которого - простое число, упорядочить строки матрицы по неубыванию суммы модулей элементов. */

int main() {
    const int MAX_SIZE = 100;
    int n = 0, m = 0;
    int matrix[MAX_SIZE][MAX_SIZE];

    std::cout << "Enter the number of elements in the row of the matrix: ";
    std::cin >> n;
    std::cout << "Enter the number of elements in the matrix column: ";
    std::cin >> m;

    if (n < 1 || n > MAX_SIZE || 
            m < 1 || m > MAX_SIZE) {
        std::cerr << "Error: The number of items exceeds the allowed maximum." << std::endl;
        return 1;
    }


    rkh::Read(matrix, n, m);
    
    if (rkh::identicalColumns(matrix, n, m) && rkh::isPrime(matrix, n, m)) {

    }

    rkh::Write(matrix, n, m);

    

    return 0;
}