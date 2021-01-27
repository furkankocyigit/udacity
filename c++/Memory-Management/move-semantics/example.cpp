#include <iostream>
#include <string>

class Shape{

    protected:
        std::string _name;
        int _side1,_side2,_side3,_side4;
    public:
        Shape(){};
        virtual ~Shape(){};
        //virtual void setEdges() = 0;

};

class Rectangle : public Shape{
    public: 
        Rectangle(int a, int b){
            setEdges(a,b);
        }
        ~Rectangle(){}
        void setEdges(int a, int b){
            _side1 = _side2 = a;
            _side3 = _side4 = b;
        }
        int getEdge1(){return this->_side1;}
        int getEdge2(){return this->_side3;}

};

class Math{
    public:
        Math(){}
    float calculatePerimeter(Rectangle* rectangle);
    float calculateArea(Rectangle* rectangle);

};

float Math::calculateArea(Rectangle* rectangle){
    return rectangle->getEdge1() * rectangle->getEdge2();
}
float Math::calculatePerimeter(Rectangle* rectangle){
    return 2 * (rectangle->getEdge1() + rectangle->getEdge2());
}

class Display{
    public:
    int choice;
    int side1,side2,side3,side4;
    
    Display(){
        std::cout<<"1- Triangle\n";
        std::cout<<"2- Right Triangle\n";
        std::cout<<"3- Rectangle\n";
        std::cout<<"4- Square\n";
        std::cout<<"5- Exit\n";
        std::cout<<"Please choose the shape that you want to evaluate: ";
        std::cin>>choice;
        
        switch(choice){
            case 1:
                break;
            case 2:
                break;
            case 3:{
                std::cout<<"Please enter side1: ";
                std::cin>>this->side1;
                std::cout<<"Please enter side2: ";
                std::cin>>this->side2;
                
                Rectangle *rectangleSample = new Rectangle(this->side1,this->side2);
                Math mathObject;

                std::cout<<"Area of the rectangle: "<<mathObject.calculateArea(rectangleSample)<<std::endl;
                std::cout<<"Perimeter of the rectangle: "<<mathObject.calculatePerimeter(rectangleSample)<<std::endl;
                delete rectangleSample;
                break;
                }
                
            case 4:
                break;
            case 5:
                break;

        }
        //std::cout<<"name: "<<name<<std::endl;


    }

};


int main(){
    Display displayObject;

}