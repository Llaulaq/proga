#include <iostream>

/*
Var 1
Вам дано число N (1<=N<=19). Рассчитать факториал числа N рекурсивно.
*/

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}


int main() {
    int n{};
    std::cout << "Enter N: " << '\n';
    std::cin >> n;

    if (!(n >=1 && n <= 19)) {
        std::cerr << "The number N is out of range.";
        return -1;
    }
    
    std::cout << factorial(n) << '\n';

    return 0;
}