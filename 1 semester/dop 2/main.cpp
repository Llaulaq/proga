#include <iostream>

/*
Посчитайте количество всех возможных счастливых трамвайных билетиков. 
Номер билета содержит 6 цифр.
*/

int main() {
    int count { 0 };
    for (int i = 1; i <= 999'999; ++i) {
        int sum1 { 0 };
        int sum2 { 0 };
        int num  { i };
        int sh   { 0 }; 

        /*for (int j = 100'000; j >= 1; j /= 10) {
            if (j >= 1000) {
                sum1 += (i / j) % 10;
            }
            else {
                sum2 += (i / j) % 10;
            }
        }*/


       while (num != 0) {
            int x = num % 10;
            sh++;
            if (sh >= 4) 
                sum1 += x;

            else 
                sum2 += x;
            
            num /= 10;
        }

        if (sum1 == sum2) {
            count++;
        }
    }

    std::cout << count << '\n';

    return 0;
}