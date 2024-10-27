#include <iostream>

/* Вариант 1
1. 	Дана последовательность натуральных чисел {aj}j=1...n (n<=10000). Если в последовательности 
есть хотя бы одно число, начинающееся цифрой 1, упорядочить последовательность по неубыванию.*/

int main() {
    const int MAX_SIZE = 10000;
    int n = 0;
    int sequence[MAX_SIZE];

    std::cout << "Enter the number of items in the sequence:" << std::endl;
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

    //для сортировки расчесткой
    float foot = n - 1; 
    float factor = 1.25; 
    
    for (int i = 0; i < n; i++) {
        bool check = false;

        int first_num = sequence[i];
        while (first_num > 9) {
            first_num /= 10;
        }
        
        //сортировка расчеткой(https://ru.wikipedia.org/wiki/Сортировка_расчёской)
        if (first_num == 1) {
            check = true; 
            while (foot >= 1) {
                for (int j = 0; j < n; j++) {
                    if ((static_cast<int>(foot) + j) > n - 1) {
                        break;
                    }

                    if (sequence[j] > sequence[j + static_cast<int>(foot)]) {
                        std::swap(sequence[j], sequence[static_cast<int>(foot) + j]);
                    }
                }
                foot = foot / factor; 
            }
        }

        if (check) break;    
    }

    std::cout << "Result: ";
    for (int i = 0; i < n; ++i) {
        std::cout << sequence[i] << " ";
    }
        

    return 0;
}