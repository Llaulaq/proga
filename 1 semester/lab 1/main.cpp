#include <iostream>
#include <limits>

using namespace std;

int main() {

    cout << "char: " << sizeof(char) << " byte, min: -127, max: 128" << endl;
    cout << "unsigned char: " << sizeof(unsigned char) << " byte, min: 0, max: 255" << endl;    
    cout << "bool: " << sizeof(bool) << " byte, min: " << numeric_limits<bool>::min() << ", max: " << numeric_limits<bool>::max() << endl;                 
    cout << "short int: " << sizeof(short int) << " byte, min: " << numeric_limits<short int>::min() << ", max: " << numeric_limits<short int>::max() << endl;       
    cout << "int: " << sizeof(int) << " byte, min: " << numeric_limits<int>::min() << ", max: " << numeric_limits<int>::max() << endl;
    cout << "unsigned int: " << sizeof(unsigned int) << " byte, min: " << numeric_limits<unsigned int>::min() << ", max: " << numeric_limits<unsigned int>::max() << endl;               
    cout << "long int: " << sizeof(long int) << " byte, min: " << numeric_limits<long int>::min() << ", max: " << numeric_limits<long int>::max() << endl;      
    cout << "unsigned long int: " << sizeof(unsigned long int) << " byte, min: " << numeric_limits<unsigned long int>::min() << ", max: " << numeric_limits<unsigned long int>::max() << endl;           
    cout << "long long int: " << sizeof(long long) << " byte, min: " << numeric_limits<long long>::min() << ", max: " << numeric_limits<long long>::max() << endl;   
    cout << "float: " << sizeof(float) << " byte, min: " << numeric_limits<float>::min() << ", max: " << numeric_limits<float>::max() << endl;               
    cout << "double: " << sizeof(double) << " byte, min: " << numeric_limits<double>::min() << ", max: " << numeric_limits<double>::max() << endl;             
    cout << "long double: " << sizeof(long double) << " byte, min: " << numeric_limits<long double>::min() << ", max: " << numeric_limits<long double>::max() << endl << endl;

    cout << "int: 5 + 2 = " << 5 + 2 << endl;
    cout << "int: 5 - 2 = " << 5 - 2 << endl;
    cout << "int: 5 * 2 = " << 5 * 2 << endl;
    cout << "int: 5 / 2 = " << 5 / 2 << endl;
    cout << "int: 5 % 2 = " << 5 % 2 << endl << endl;

    cout << "float: 3.1 + 3.2 = " << 3.1 + 3.2 << endl;
    cout << "float: 3.1 - 3.2 = " << 3.1 - 3.2 << endl;
    cout << "float: 3.1 * 3.2 = " << 3.1 * 3.2 << endl;
    cout << "float: 3.1 / 3.2 = " << 3.1 / 3.2 << endl << endl;

    return 0;
}