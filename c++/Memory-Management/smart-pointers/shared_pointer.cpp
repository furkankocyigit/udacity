#include <iostream>
#include <memory>

class MyClass{
public:
    std::shared_ptr<MyClass> _member;
    ~MyClass(){ std::cout<<"Destructor of MyClass called"<<std::endl;}
};

int main(){

    std::shared_ptr<int> shared1(new int);
    std::cout<<"shared1 pointer count = "<<shared1.use_count()<<std::endl;
    {
        std::shared_ptr<int> shared2 = shared1;
        std::cout<<"shared1 pointer count = "<<shared1.use_count()<<std::endl;
    }
    std::cout<<"shared1 pointer count = "<<shared1.use_count()<<std::endl;
    std::cout<<"************************************** "<<std::endl;
    std::shared_ptr<MyClass> shared(new MyClass);
    std::cout<<"shared pointer count = "<<shared.use_count()<<std::endl;

    shared.reset(new MyClass);
    std::cout<<"shared pointer count = "<<shared.use_count()<<std::endl;
    std::cout<<"************************************** "<<std::endl;

    std::shared_ptr<MyClass> myClass1(new MyClass);
    std::shared_ptr<MyClass> myClass2(new MyClass);

    myClass1->_member = myClass2;       //causes memory leak. run valgrind to see it
    myClass2->_member = myClass1;       //causes memory leak. run valgrind to see it


    return 0;
}