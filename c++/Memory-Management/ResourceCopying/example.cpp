#include <iostream>

class MyClass{
    private:
        int *_myInt;
    
    public:
        MyClass(){
            _myInt = (int*) malloc(sizeof(int));
        }
        ~MyClass(){
            free(_myInt);
        }
        void printOwnAdress(){std::cout<<"Own adress on the stack -> "<<this<<std::endl;}
        void printMemberAdress(){std::cout<<"Managing memory block on the heap at ->  "<<_myInt<<std::endl;}
};

int main(){
    MyClass myClass1;       // instantiate object 1
    myClass1.printOwnAdress();
    myClass1.printMemberAdress();

    MyClass myClass2(myClass1);     //copy constructor
    myClass2.printOwnAdress();
    myClass2.printMemberAdress();
}