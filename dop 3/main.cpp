#include <iostream>

/* Var 1
Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000). 
Удалить из последовательности простые числа и продублировать составные числа, 
сумма цифр которых равна 15.
*/

const int MAX_SIZE { 10000 };


bool read(int& cnt, int sequence[MAX_SIZE]) { 
    std::cout << "Enter the number of items in the sequence: ";
    std::cin >> cnt;

    if (cnt < 1 || cnt > MAX_SIZE) {
        std::cerr << "Error: The number of items exceeds the allowed maximum." << std::endl;
        return false;
    }

    std::cout << "Enter the sequence elements: ";
    for (int i = 0; i < cnt; ++i) {
        std::cin >> sequence[i];
        if (sequence[i] > MAX_SIZE) {
            std::cerr << "Error: The element exceeds the allowed value.";
            return true;
        }
    }
}



int main() {
    int cnt { 0 };
    int sequence[MAX_SIZE];

    if (!read(cnt, sequence)) {
        return -1;
    }


    return 0;
}