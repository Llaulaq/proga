#include <iostream>
#include <ctime>

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

    //http://cppstudio.com/post/468/
    unsigned int start_time =  clock();
    quickSort(0, cnt, mas);
    //swapSort(cnt, mas);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    std::cout << "Program opening hours: " << search_time << '\n';

    for (int i = 0; i < cnt; ++i) { 
        std::cout << mas[i] << " "; 
    } 

    return 0;
}