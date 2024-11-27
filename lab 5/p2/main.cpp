#include <iostream>

using namespace std;

/* Var 1 
2. Дано натуральное число N (N<10^9). Найти наибольшую цифру числа N.*/

int main() {
    int x, max_x = 0;
    cin >> x;

    while (x > 0) {
        int digit = x % 10;
        if (max_x < digit) 
            max_x = digit;
        x /= 10;
    }

    cout << "Max: " << max_x << endl;

    return 0;
}