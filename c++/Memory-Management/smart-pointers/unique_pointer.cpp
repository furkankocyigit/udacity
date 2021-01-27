#include <iostream>
#include <memory>
#include <string>

void RawPointer(){
    int *raw = new (int);   //create raw pointer on the heap
    *raw = 1;   //assign a value
    std::cout<<"*raw = "<<*raw<<std::endl;
    delete raw; //delete resource again
    std::cout<<"*raw = "<<*raw<<std::endl;
};

void UniquePointer(){
    std::unique_ptr<int> unique(new int); // create unique pointer on the stack
    *unique = 2;        // assign a value
    std::cout<<"*unique = "<<*unique<<std::endl;
    //delete is not necessary
}

class MyClass{
private:
    std::string _text;
public:
    MyClass(){};
    MyClass(std::string text) {_text = text;}
    ~MyClass(){std::cout<<_text<<" destroyed"<<std::endl;}
    void setText(std::string text){ _text = text;}
};
void test(std::unique_ptr<MyClass> myclass){

}

int main(){
    RawPointer();
    UniquePointer();

    //create unique pointer to properietary class
    std::unique_ptr<MyClass> myClass1(new MyClass());
    std::unique_ptr<MyClass> myClass2(new MyClass("String 2"));

  

    //call member function using "->"
    myClass1->setText("String 1");

    //use dereferencing operator
    *myClass1 = *myClass2;

    //use the .get() function to retrieve a raw pointer to the object
    std::cout<<"Objects have stack adresses "<<myClass1.get()<<" and "<<myClass2.get()<<std::endl;

    return 0;
}