#include <iostream>

using namespace std;

/* Var 1 
1. Дана последовательность натуральных чисел {Aj}. Найти произведение чисел, 
оканчивающихся цифрой 2 или 4, 
наименьшее из таких чисел и номер этого числа в последовательности.
2. Дано натуральное число N (N<10^9). Найти наибольшую цифру числа N.*/

int main() {
    unsigned int n, min_num, i_min_num = 0, result = 1;
    bool b = true;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        unsigned int num;
        cin >> num;

        if (num % 10 == 4 || num % 10 == 2) {
            while (b) {
                min_num = num;
                i_min_num = i;
                b = false;
            }

            result *= num;
            if (min_num > num) {
                min_num = num;
                i_min_num = i;
            }
        }
    }

    if (b) 
        cout << "Error" << endl;
    else {
        cout << "Result: " << result << endl << 
        "Min_num: " << min_num << endl << 
        "Number min_num: " << i_min_num << endl;
    }


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