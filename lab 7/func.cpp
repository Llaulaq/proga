#include <func.hpp>
#include <iostream>

const int MAX_SIZE = 100;

namespace rkh {
    
    void Read(int matrix[MAX_SIZE][MAX_SIZE], int n, int m) {
        std::cout << "Enter the sequence elements: ";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cin >> matrix[i][j];
            } 
        }
    }


    void Write(int matrix[MAX_SIZE][MAX_SIZE], int n, int m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
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

    void bubbleSort(int matrix[MAX_SIZE][MAX_SIZE], int n, int m) {
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                int sum1 = 0, sum2 = 0;
                for (int t = 0; t < m; ++t) {
                    sum1 += abs(matrix[i][t]);
                    sum2 += abs(matrix[j][t]);      
                }

                if (sum1 > sum2) {
                    for (int t = 0; t < m; ++t) {
                        std::swap(matrix[i][t], matrix[j][t]);
                    }
                } 
            }
        }
    }
}