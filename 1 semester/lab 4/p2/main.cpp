#include <iostream>

using namespace std;

/* Var 1 
2. Ввести натуральное число N, обозначающее номер месяца в году. 
Используя оператор switch вывести названия всех месяцев года. Предусмотреть обработку ошибочного ввода N.
 */

int main() {
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

    return 0;
}