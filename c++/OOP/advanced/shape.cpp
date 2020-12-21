#include <iostream>
#include <cassert>
#include <stdexcept>
#include <cmath>

#define PI 3.14159
class Shape{
    public:
        Shape(){};
        virtual double Area() const = 0;
        virtual double Perimeter() const = 0;
};
// TODO: Define Rectangle to inherit publicly from Shape
class Rectangle : public Shape{
    public:
    // TODO: Declare public constructor
        Rectangle(double w, double h): _width(w), _height(h){
            if(_width <= 0 || _height <=0 )
                throw std::invalid_argument("edges cannot be negative!");
        };
    // TODO: Override virtual base class functions Area() and Perimeter()
    double Area() const {return _width * _height;}
    double Perimeter() const { return 2 * (_width + _height);}
    // TODO: Declare private attributes width and height
    private:
        double _width;
        double _height;
};
// TODO: Define Circle to inherit from Shape
class Circle : public Shape{
    public:
        // TODO: Declare public constructor
        Circle(float radius) : _radius(radius){
            if(_radius <=0 )
                throw std::invalid_argument("radius cannot be negative!");
        }
        // TODO: Override virtual base class functions Area() and Perimeter()
        double Area() const { return PI * pow(_radius,2); }
        double Perimeter() const { return 2 * PI * _radius;}

    private:
        // TODO: Declare private member variable radius
        float _radius;
};

// Test in main()
int main() {
  double epsilon = 0.1; // useful for floating point equality

  // Test circle
  Circle circle(12.31);
  assert(abs(circle.Perimeter() - 77.35) < epsilon);
  assert(abs(circle.Area() - 476.06) < epsilon);

  // Test rectangle
  Rectangle rectangle(10, 6);
  assert(rectangle.Perimeter() == 32);
  assert(rectangle.Area() == 60);
}