#include <iostream>

using namespace std;

/* Var 1 
1. Ввести натуральные числа A, B и C. Если A кратно B и B больше C, то вывести A/B+C, если A кратно B и B меньше C, то вывести A/B-C, в остальных случаях вывести (A+B)*C.
2. Ввести натуральное число N, обозначающее номер месяца в году. Используя оператор switch вывести названия всех месяцев года. Предусмотреть обработку ошибочного ввода N.
3. Переменная x может принимать 2 значения: -1 и 1. Если -1, то вывести в консоль “Negative number”, если положительное - “Positive number”. Предложить вариант программы и объяснить свой выбор.
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

    int n;
    cout << "Enter n: ";
    cin >> n;

    switch (n) {
    case 1: cout << "January" << endl; break;
    case 2: cout << "February" << endl; break;
    case 3: cout << "March" << endl; break;
    case 4: cout << "April" << endl; break;
    case 5: cout << "May" << endl; break;
    case 6: cout << "June" << endl; break;
    case 7: cout << "July" << endl; break;
    case 8: cout << "August" << endl; break;
    case 9: cout << "September" << endl; break;
    case 10: cout << "October" << endl; break;
    case 11: cout << "November" << endl; break;
    case 12: cout << "December" << endl; break;
    default: cout << "Error" << endl; break;
    }

    char x;
    cout << "Enter x: ";
    cin >> x;

    cout << (x == 1 ? "Positive number" : x == -1 ? "Negative number" : "Error") << endl;
    
    return 0;
}