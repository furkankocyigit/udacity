#include <iostream>
#include <memory>

// void f(object*);  // a
// void f(object&);  // b
// void f(std::unique_ptr<object>);  // c
// void f(std::unique_ptr<object>&); // d
// void f(std::shared_ptr<object>);  // e
// void f(std::shared_ptr<object>&); // f

class MyClass{
    private:
        int _member;
    public:
        
        MyClass(int val) : _member(val) {}
        void printVal(){ std::cout<<", managed object "<<this<<" with val = "<< _member<<std::endl; }
};

void f(std::unique_ptr<MyClass>& ptr){
    std::cout<<"unique_ptr "<<&ptr;
    ptr->printVal();
}
void f(std::shared_ptr<MyClass>& ptr){
    std::cout<<"shared_ptr (ref_cnt = "<<ptr.use_count()<<") "<<&ptr;
    ptr->printVal();
}

int main(){

    // unique pointer transfer
    std::unique_ptr<MyClass> uniquePtr = std::make_unique<MyClass>(23);
    std::cout<<"unique_ptr "<<&uniquePtr;
    uniquePtr->printVal();

    //f(std::move(uniquePtr));
    f(uniquePtr);
    // std::cout<<"adress of uniquePtr "<<&uniquePtr<<" , "<<"with value "<<uniquePtr->_member<<std::endl;
    if(uniquePtr){
        std::cout<<"pointer is still valid"<<std::endl;
        uniquePtr->printVal();
    }


    // Shared pointer transfer
    std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>(23);
    std::cout<<"shared_ptr (ref_cnt = "<<sharedPtr.use_count()<<") "<<&sharedPtr;
    sharedPtr->printVal();

    f(sharedPtr);

    std::cout<<"shared_ptr (ref_cnt = "<<sharedPtr.use_count()<<") "<<&sharedPtr;
    sharedPtr->printVal();
    

    return 0;
}