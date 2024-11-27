#include <iostream>
#include <string>
#include <fstream>

//Var 1
/* Дано целое число типа int, выведите на экран содержимое каждого из его байтов, 
используя знания по указателям. Дайте обоснование полученному результату. 
*/


int main() {
    int a{};
    std::cin >> a;

    unsigned char * p = (unsigned char *) &a;

    for (int i = 0; i < sizeof(a); ++i) {
        int b { *(p + i) };
        std::cout << std::hex << b << " ";
    }

    return 0;
}
