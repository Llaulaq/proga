#include <iostream>

using namespace std;

/* Var 1 
1. Дана последовательность натуральных чисел {Aj}. Найти произведение чисел, 
оканчивающихся цифрой 2 или 4, 
наименьшее из таких чисел и номер этого числа в последовательности.
*/

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

    return 0;
}