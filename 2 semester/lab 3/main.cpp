#include <iostream>

/*Var 1
Квадрат, расчет площади, периметра и длины диагонали.
*/

class Square {
    public: 
        int length;

        Square(int d_lenght) {
            length = d_lenght;
        }

        int getArea() {
            return length * length;
        }

        int perimeter() {
            return 4 * length;
        }

        int diagonal() {
            return sqrt(2) * length;
        }

        void printInfo(bool detail) {
            std::cout << "Length: " << length << '\n';
        
            if (detail) {
                std::cout << "Area: " << getArea() << '\n';
                std::cout << "Perimeter: " << perimeter() << '\n';
                std::cout << "Diagonal: " << diagonal() << '\n';
            }
        }

    private:
};

int main() {
    Square square1(10);

    square1.printInfo(true);
}