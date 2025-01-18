#include <iostream>
#include <chrono>

/* Var 1
Реализуйте быструю сортировку. Изучите, как она работает. 
Сравните скорость работы с сортировкой обменами. */

const int MAX_SIZE {10000}; 

void swapN(int i, int j, int mas[MAX_SIZE]) { 
    int temp = mas[i]; 
    mas[i] = mas[j]; 
    mas[j] = temp; 
} 

//сортировка обменом 
void swapSort(int n, int mas[MAX_SIZE]) { 
    for (int i = 0; i < n - 1; ++i) { 
        for (int j = i + 1; j < n; ++j) { 
            if (mas[i] > mas[j]) { 
                swapN(i, j, mas); 
            } 
        } 
    } 
} 

//быстрая сортировка 
void quickSort(int start, int end, int mas[]) {
    if (start > end) {
        return;
    }
    int mid = mas[(start + end) / 2];
    int i = start;
    int j = end;

    while (i <= j) {
        while (mas[i] < mid) {
            i++;
        }
        while (mas[j] > mid) {
            j--;
        }
        if (i <= j) {
            swapN(i, j, mas);
            i++;
            j--;
        } 
    }
    quickSort(start, j, mas);
    quickSort(i, end, mas);
} 


int main() {
    int mas[MAX_SIZE];
    int cnt{};

    std::cout << "Enter the length of the array: ";
    std::cin >> cnt;

    std::cout << "Enter the array elements: ";
    for (int i = 0; i < cnt; ++i) {
        std::cin >> mas[i];
    }

    //https://www.techiedelight.com/ru/measure-elapsed-time-program-chrono-library/
    auto start = std::chrono::steady_clock::now();
    quickSort(0, cnt - 1, mas);
    //swapSort(cnt, mas);
    auto end = std::chrono::steady_clock::now();   
    std::cout << "Program opening hours: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns." << '\n';

    for (int i = 0; i < cnt; ++i) { 
        std::cout << mas[i] << " "; 
    } 

    return 0;
}