#include <cassert>
#include <iostream>

class Square{

    private:
    friend class Rectangle;
    float _side;

    public:
    
    Square(float side){ 
        if(side > 0) _side = side;
        else throw std::invalid_argument("side cannot be negative!!");}
    
};

class Rectangle{
    
    private:
    float _width;
    float _height;

    public:
    Rectangle(const Square& square){
        _width = square._side;
        _height = square._side;
    };
    float getArea(){
        return _width * _height;
    }



};



// Define class Square as friend of Rectangle

// Add public constructor to Square, initialize side
    // Add friend class Rectangle

    // Add private attribute side

// Define class Rectangle
    // Add public function to Rectangle: Area()
    
    // Add private attributes width, height;

// Define a Rectangle constructor that takes a Square

// Define Area() to compute area of Rectangle

// Update main() to pass the tests

int main(){

    Square square(4);
    Rectangle rectangle(square);

    assert(rectangle.getArea() - 16 <0.5);
}