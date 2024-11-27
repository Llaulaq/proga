#include <iostream>

using namespace std;

/* Var 1 
1. Ввести натуральные числа A, B и C. Если A кратно B и B больше C, то вывести A/B+C, 
если A кратно B и B меньше C, то вывести A/B-C, в остальных случаях вывести (A+B)*C.
*/

int main() {
    int a, b, c;
    cout << "Enter a, b, c: ";
    cin >> a >> b >> c;

    if (a < 1 || b < 1 || c < 1) {
        cout << "Error" << endl;
    } else {
        if ((a % b == 0) && b > c) {
            cout << a / b + c << endl;
        } else if ((a % b == 0) && b < c) {
            cout << a / b - c << endl;
        } else {
            cout << (a + b) * c << endl;
        }
    }

    return 0;
}