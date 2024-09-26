#include <iostream>
#include <cmath>

class Shape {
public:
  
    Shape() {}


    double calculateArea(double base, double height) {
        return 0.5 * base * height;
    }


    double calculateArea(double length, double width) {
        return length * width;
    }

    double calculateArea(double radius) {
        return M_PI * radius * radius;
    }
};

int main() {
    Shape myShape;

   
    double triangleArea = myShape.calculateArea(5.0, 3.0);
    double rectangleArea = myShape.calculateArea(4.0, 6.0);
    double circleArea = myShape.calculateArea(2.5);

    std::cout << "Triangle area: " << triangleArea << std::endl;
    std::cout << "Rectangle area: " << rectangleArea << std::endl;
    std::cout << "Circle area: " << circleArea << std::endl;

    return 0;
}

