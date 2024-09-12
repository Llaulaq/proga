#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    cout << "char 8 bit -128 ... 127" << endl;
    cout << "unsigned char 8 bit 0 ... 256" << endl; 
    cout << "int 16 bit -32_768 ... 32_367" << endl; 
    cout << "unsigned int 16 bit 0 ... 65_535" << endl; 
    cout << "long int 32 bit -2_147_483_648 ... 2_147_483_676" << endl; 
    cout << "unsigned long int 32 bit 0 ... 4_294_967_295" << endl; 
    cout << "float 32 bit +-3.4 * 10**-38 ... +-3.4 * 10**38" << endl; 
    cout << "double 64 bit +-1.7 * 10**-308 ... +-1.7 * 10**308" << endl; 
    cout << "long double 80 bit +-3.4 * 10**-4932 ... +-1.1 * 10**4932" << endl; 
    cout << "bool 8 bit true, false" << endl; 

    return 0;
}