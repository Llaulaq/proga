#include <iostream> 
 
const int MAX_SIZE = 10000; 
 
 
void swapN(int i, int j, int mat[MAX_SIZE]) { 
    int temp = mat[i]; 
    mat[i] = mat[j]; 
    mat[j] = temp; 
} 
 
 
//сортировка обменом 
void swapSort(int n, int mat[MAX_SIZE]) { 
    for (int i = 0; i < n - 1; ++i) { 
        for (int j = i + 1; j < n; ++j) { 
            if (mat[i] > mat[j]) { 
                swapN(i, j, mat); 
            } 
        } 
    } 
} 
 
 
//сортировка пузырьком 
void bubbleSort(int n, int mat[MAX_SIZE]) { 
    for (int i = 0; i < n; ++i) { 
        bool flag = true; 
        for (int j = 0; j < n - i + 1; ++j) { 
            if (mat[j] > mat[j + 1]) { 
                swapN(j, j + 1, mat); 
                bool flag = false; 
            } 
        } 
        if (flag) { 
            break; 
        } 
    } 
} 
 
 
//сортировка Шелла 
void shellSort(int n, int mat[MAX_SIZE]) { 
    for (int step = n / 2; step > 0; step /= 2) { 
        for (int i = step; i < n; ++i) { 
            for (int j = i - step; j >= 0 && mat[j] > mat[j + step]; j -= step) { 
                swapN(j, j + 1, mat); 
            } 
 
        } 
    } 
} 
 
 
 
//быстрая сортировка 
void quickSort(int n, int mat[]) { 
 
} 
 
 
 
//сортировка слиянием 
 
 
//сортировка посчётом 
void countingSort(int n, int mat[MAX_SIZE]) { 
    int tmp_mat[MAX_SIZE]{}; 
    for (int i = 0; i < n; ++i) { 
        tmp_mat[mat[i]]++; 
    } 
 
    int k = 0; 
    for (int i = 0; i < n; ++i) { 
        while (tmp_mat[i] > 0) { 
            mat[k] = i; 
            k++; 
            tmp_mat[i]--; 
        } 
    } 
 
} 
 
 
//сортировка кучей 
void heapSort(int n, int mat[MAX_SIZE]) { 
 
} 
 
 
 
 
int main() { 
    int mat[5]{ 93, -86, 457, 5, -9 }; 
 
    shellSort(5, mat); 
 
    for (int i = 0; i < 5; ++i) { 
        std::cout << mat[i] << " "; 
    } 
 
    return 0; 
}
