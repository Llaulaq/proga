#include <iostream>

using namespace std;

/* Var 1 
Установить i-ый бит числа х (0<x<10^9) в 1. */

int main() {
    unsigned int x;
    int i;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter i: ";
    cin >> i;

    cout << (x | (1 << i)) << endl;

    return 0;
}