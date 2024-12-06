#include <iostream>
#include <math.h>
#include <iomanip>
/*
Вам даны координаты центров и радиусы двух кругов: x1, y1, r1, x2, y2, r2. 
Все значения целочисленные. Гарантируется, что оба круга полностью помещаются в квадрат размерами 1000х1000. 
Круги могут не пересекаться, касаться друг друга в одной точке и пересекаться.
Найдите суммарную площадь двух кругов с точностью до 10^-3. Площадь пересечения кругов учитывается 1 раз.
*/

int main() {
    int x1 {};
    int y1 {};
    int r1 {};
    int x2 {};
    int y2 {};
    int r2 {};

    std::cout << "Enter the values: " << '\n';
    std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    double p { 0 };
    double pi { 2*acos(0.0) };
    double s { 0 };
    double alpha { 0 };
    double beta { 0 };

    //the distance between the centers of the circles
    p = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    //the areas of both circles
    s = pi * (r1*r1 + r2*r2);

    if ((r1 + r2) >= ceil(p)) {
        if (r1 >= ceil(p)) {
            s = pi * r1*r1;
        }
        else if (r2 >= ceil(p)) {
            s = pi * r2*r2;
        }
        else {
            //formula
            alpha = acos((r1*r1 + p*p - r2*r2) / (2 * r1 * p)) * 2;
            beta = acos((r2*r2 + p*p - r1*r1) / (2 * r2 * p)) * 2;
            s -= 0.5 * beta * r2*r2 - 0.5 * r2*r2 * sin(beta);
            s -= 0.5 * alpha * r1*r1 - 0.5 * r1*r1 * sin(alpha);
        }
        
    }

    std::cout << "The area of two circles: ";
    std::cout << std::fixed << std::setprecision(3) << s << '\n';

    return 0;
}