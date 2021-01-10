#include <iostream>

class SharedCopy{

private:
    int* _myInt;
    static int _count;

public:
    SharedCopy(int val);
    ~SharedCopy();
    SharedCopy(SharedCopy& source);
};

int SharedCopy::_count = 0;

SharedCopy::SharedCopy(int val){
    _myInt = (int*) malloc(sizeof(int));
    *_myInt = val;
    this->_count++;
    std::cout<<"resource allocated at adress -> "<< _myInt<< std::endl;
}

SharedCopy::~SharedCopy(){
    this->_count--;
    if(this->_count == 0){
        free(_myInt);
        std::cout<<"resource freed at adress -> "<<_myInt<<std::endl;
    }else std::cout<<"instance at adress -> "<<this<<" goes out of scope with _count = "<<_count<<std::endl;
}

SharedCopy::SharedCopy(SharedCopy& source){
    _myInt = source._myInt;
    ++_count;
    std::cout<<_count<<" is instances with handless to adress "<<_myInt<<" with _myInt = "<<*_myInt<<std::endl;
}


int main(){
    SharedCopy source(42);
    SharedCopy dest1(source);
    SharedCopy dest2(source);
    SharedCopy dest3(source);
    
}