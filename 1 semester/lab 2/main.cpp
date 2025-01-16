#include <iostream>

using namespace std;
/* Написать программу, которая на 
вход получает 3 целых числа A, B, C – стороны треугольника. 
Рассчитать площадь треугольника по формуле Герона.*/
int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b > c && a + c > b && b + c > a) {
        double p = (a + b + c) * 1.0 / 2;
        cout << "S = " << sqrt(p * (p - a)*(p - b) * (p - c));
    } else {
        cout << "Error";
    }

    return 0;
}