#pragma once

namespace rkh {
    const int MAX_SIZE = 100;

    bool read(int matrix[MAX_SIZE][MAX_SIZE], int& n, int& m);
    void write(int matrix[MAX_SIZE][MAX_SIZE], int n, int m);
    bool identicalColumns(int matrix[MAX_SIZE][MAX_SIZE], int n, int m);
    bool isPrime(int matrix[MAX_SIZE][MAX_SIZE], int n, int m);
    void sortMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n, int m);
}