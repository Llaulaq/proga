#pragma once

namespace rkh {
    const int MAX_SIZE = 100;

    void Read(int matrix[MAX_SIZE][MAX_SIZE], int n, int m);
    void Write(int matrix[MAX_SIZE][MAX_SIZE], int n, int m);
    bool identicalColumns(int matrix[MAX_SIZE][MAX_SIZE], int n, int m);
    bool isPrime(int matrix[MAX_SIZE][MAX_SIZE], int n, int m);
}