#include <stdlib.h>
#include <iostream>

class MyClass {
    private:
        int* _number;

    public:
        MyClass(){
            std::cout<<"Allocate memory\n";
            _number = (int*)malloc(sizeof(int));
        }
        ~MyClass(){
            std::cout<<"Delete memory\n";
            free(_number);
        }
        void setNumber(int number){
            *_number = number;
            std::cout<<"Number: "<<*_number<<std::endl;
        }
};

int main(){
    // MyClass *myClass = (MyClass*)malloc(sizeof(MyClass));
    // myClass->setNumber(43); //EXC_BAD_ACCES
    // free(myClass);

    MyClass *newMyClass = new MyClass();
    newMyClass->setNumber(43); //works as expected

    delete newMyClass;
    bool flag = true;
}