#include <iostream>

using namespace std;

/* Var 1 
3. Переменная x может принимать 2 значения: -1 и 1. Если -1, то вывести в консоль “Negative number”, 
если положительное - “Positive number”. Предложить вариант программы и объяснить свой выбор.
*/

int main() {
    char x;
    cout << "Enter x: ";
    cin >> x;

    cout << (x == 1 ? "Positive number" : x == -1 ? "Negative number" : "Error") << endl;
    
    return 0;
}