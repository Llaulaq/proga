#include <func.hpp>
#include <iostream>

const int MAX_SIZE { 100 };

namespace rkh {
    
    bool read(int matrix[MAX_SIZE][MAX_SIZE], int& n, int& m) {
        std::cout << "Enter the number of elements in the row of the matrix: ";
        std::cin >> n;
        std::cout << "Enter the number of elements in the matrix column: ";
        std::cin >> m;

        if (n < 1 || n > MAX_SIZE || 
            m < 1 || m > MAX_SIZE) {
            std::cerr << "Error: The number of items exceeds the allowed maximum." << '\n';
            return false;
        }

        std::cout << "Enter the sequence elements: ";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cin >> matrix[i][j];
            } 
        }
        return true;
    }


    void write(int matrix[MAX_SIZE][MAX_SIZE], int n, int m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << '\n';
        }
    }


    bool identicalColumns(int matrix[MAX_SIZE][MAX_SIZE], int n, int m) {
        for (int i = 0; i < n; ++i) {
            bool flag = true;
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j - 1] == matrix[i][j]) {
                    continue;
                }
                flag = false;
                break;
            }
            if (flag) {
                return flag;
            }
        }
        return false;
    }


    bool isPrime(int matrix[MAX_SIZE][MAX_SIZE], int n, int m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int matrix_ij = abs(matrix[i][j]);
                bool isPrimeNum = true;

                for (int d = 2; d <= sqrt(matrix_ij) + 1; ++d) {
                    if(matrix_ij % d != 0) {
                        continue;                     
                    }
                    isPrimeNum = false;
                    break;
                }

                if (isPrimeNum) {
                    return isPrimeNum;
                }
            }
        }
        return false;
    }

    void sortMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n, int m) {
        for (int i = 0; i < n - 1; ++i) {
            for (int k = i + 1; k < n; ++k) {
                int sum1 = 0, sum2 = 0;
                for (int j = 0; j < m; ++j) {
                    sum1 += abs(matrix[i][j]);
                    sum2 += abs(matrix[k][j]);      
                }
                if (sum1 > sum2) {
                    for (int j = 0; j < m; ++j) {
                        std::swap(matrix[i][j], matrix[k][j]);
                    }
                }
            }
        }
    }
}