#include <iostream>

/* Var 1
Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000). 
Удалить из последовательности простые числа и продублировать составные числа, 
сумма цифр которых равна 15.
*/

const int MAX_SIZE { 20000 };


bool read(int& cnt, int sequence[MAX_SIZE]) { 
    std::cout << "Enter the number of items in the sequence: ";
    std::cin >> cnt;

    if (cnt < 1 || cnt > MAX_SIZE) {
        std::cerr << "Error: The number of items exceeds the allowed maximum." << std::endl;
        return false;
    }

    std::cout << "Enter the sequence elements: ";
    for (int i = 0; i < cnt; ++i) {
        std::cin >> sequence[i];
        if (sequence[i] > MAX_SIZE) {
            std::cerr << "Error: The element exceeds the allowed value.";
            return true;
        }
    }
}


bool isPrime(int num) {
    if (num == 1) return false;
    for(int d = 2; d <= sqrt(num); ++d) {
        if(num % d == 0) {
            return false;
        }
    }
    return true;
}


void deleteSequenceNum(int& cnt, int sequence[MAX_SIZE]) {
    for (int i = 0; i < cnt; ++i) {
        if (isPrime(sequence[i])) {
            for(int j = i; j < cnt - 1; ++j) {
                sequence[j] = sequence[j + 1];
            } 
            i--;
            cnt--;
        } 
    }
}


bool sum15(int num) {
    int sum { 0 };
    while (num != 0) {
        int x = num % 10;
        sum += x;
        num /= 10;
    }
    return sum == 15;
}


void duplicateSequenceNum(int& cnt, int sequence[MAX_SIZE]) {
    for (int i = 0; i < cnt; ++i) {
        if (sum15(sequence[i])) {
            for(int j = cnt; j > i; --j) {
                sequence[j] = sequence[j - 1];
            } 
            i++;
            cnt++; 
        }    
    }
}
    

void write(int cnt, int sequence[MAX_SIZE]) {
    std::cout << "Result: ";
    for (int i = 0; i < cnt; ++i) {
        std::cout << sequence[i] << " ";
    }
}


int main() {
    int cnt { 0 };
    int sequence[MAX_SIZE];

    if (!read(cnt, sequence)) {
        return -1;
    }
    
    deleteSequenceNum(cnt, sequence);
    duplicateSequenceNum(cnt, sequence);

    write(cnt, sequence);

    return 0;
}