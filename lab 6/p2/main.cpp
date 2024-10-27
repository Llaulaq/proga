#include <iostream>

/* Вариант 1
2. Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000). 
Упорядочить последовательность по неубыванию первой цифры числа, 
числа с одинаковыми первыми цифрами дополнительно упорядочить по неубыванию суммы цифр числа, 
числа с одинаковыми первыми цифрами и одинаковыми суммами цифр дополнительно упорядочить по неубыванию самого числа.*/

int main() {
    const int MAX_SIZE = 10000;
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

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int firstI = sequence[i];
            int sumI = 0;
            while (firstI > 9) {
                sumI += firstI % 10;
                firstI /= 10;
            }
            sumI += firstI;

            int firstJ = sequence[j];
            int sumJ = 0;
            while (firstJ > 9) {
                sumJ += firstJ % 10;
                firstJ /= 10;
            }
            sumJ += firstJ;

            if ((firstI > firstJ) || 
                (firstI == firstJ && sumI > sumJ) || 
                    (firstI == firstJ && sumI == sumJ && sequence[i] > sequence[j])) {
                        std::swap(sequence[i], sequence[j]);
            }      
        }
    }

    std::cout << "Result: ";
    for (int i = 0; i < n; ++i) {
        std::cout << sequence[i] << " ";
    }
        

    return 0;
}