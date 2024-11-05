#include <iostream>
#include <limits>

/* Вариант 1
3. Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). 
Найти строку, сумма элементов которой наиболее близка к 0, и заменить все элементы этой строки числом 0.*/

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

    std::cout << "Enter the sequence elements: " << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
            if (matrix[i][j] > MAX_SIZE) {
                std::cerr << "Error: The element exceeds the allowed value.";
                return 1;
        }
        }
        
    }

    int sum_min = std::numeric_limits<int>::max();
    int minI = 0;

    for (int i = 0; i < n; ++i) {
        int sumI = 0;
        for (int j = i + 1; j < m; ++j) {
            sumI += matrix[i][j];
        }

        if (abs(sumI) < sum_min) {
            minI = i;
        }
    }

    for (int j = 0; j < m; ++j) {
        matrix[minI][j] = 0;
    }


    std::cout << "Result: " << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
        
    return 0;
}