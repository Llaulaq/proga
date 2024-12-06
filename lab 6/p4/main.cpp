#include <iostream>

/* Вариант 1
Сначала введите последовательность. Затем удалите и продублируйте элементы. 
Затем выведите полученную последовательность (каждый элемент по одному разу). 
Используйте в программе только один массив.

4. Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000). 
Удалить из последовательности числа, содержащие цифру 7, но не содержащие цифру 6, 
а среди оставшихся продублировать простые числа.*/

int main() {
    const int MAX_SIZE = 20000;
    int n = 0;
    int sequence[MAX_SIZE];

    std::cout << "Enter the number of items in the sequence: ";
    std::cin >> n;

    if (n < 1 || n > MAX_SIZE) {
        std::cerr << "Error: The number of items exceeds the allowed maximum." << std::endl;
        return 1;
    }

    std::cout << "Enter the sequence elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> sequence[i];
        if (sequence[i] > MAX_SIZE) {
            std::cerr << "Error: The element exceeds the allowed value.";
            return 1;
        }
    }

    // удаление
    for (int i = 0; i < n; ++i) {
        int num_sq = sequence[i];
        bool flag7 = false, flag6 = false;

        while (num_sq != 0) {
            int x = num_sq % 10;
            if (x == 7) {
                flag7 = true;
            }
            if (x == 6) {
                flag6 = true;
            }
            num_sq /= 10;
        }

        if (flag7 && !flag6) {
            for(int j = i; j< n - 1; ++j) {
                sequence[j] = sequence[j + 1];
            } 
            i--;
            n--;
        } 
    }

    // дублирование
     for(int i = 0; i < n; ++i) {
        bool isPrime = true;
        if (sequence[i] == 1) isPrime = false;
        for(int d = 2; d <= sqrt(sequence[i]); ++d) {
            if (sequence[i] % d == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) {
            for(int j = n; j > i; --j) {
                sequence[j] = sequence[j - 1];
            } 
            i++;
            n++;     
        }
    }

    std::cout << "Result: ";
    for (int i = 0; i < n; ++i) {
        std::cout << sequence[i] << " ";
    }
        
    return 0;
}