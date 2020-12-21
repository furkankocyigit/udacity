#include <string>
#include <iostream>
#include <cmath>
#include <cassert>

#define pi 3.14159

class LineSegment{
    
    public:

    LineSegment(float length) : length_(length){}
    float getLength() const {return length_;}
    void setLength(float l){ if (l>0) length_ = l;}

    private:
    float length_;

};

class Circle{

    private:
    LineSegment& _radius;
    float _cArea;
    bool _calculateArea{true};

    public:
    Circle(LineSegment& radius) : _radius(radius){
        if(_radius.getLength() <= 0){
            throw std::invalid_argument("Invalid Input: radius must be greater than 0");
        }
        
    }

    void setRadius(float r){
        if(r <= 0){
            throw std::invalid_argument("Invalid Input: radius must be greater than 0");
        }else {
            _radius.setLength(r);
            _calculateArea = true;
        }
    }
    float getArea(){
        if(_calculateArea){
            _cArea = pi * pow(_radius.getLength(),2);
            _calculateArea = false;
        }
        return _cArea;
    };
    
   
};
int main(){
    LineSegment radius(3);
    Circle circle(radius);

    assert(int(circle.getArea()) == 28);

}