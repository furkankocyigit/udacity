#include <stdlib.h>
#include<iostream>

class MyMovableClass{

private:
    int _size;
    int* _data;

public:
    MyMovableClass(size_t size){
        _size = size;
        _data = new int[_size];
        std::cout<<"CREATING instance of MyMovableClass at "<<this<<" allocated with size = "<<_size * sizeof(int)<< " bytes"<<std::endl;
    }

    MyMovableClass(const MyMovableClass& source){
        this->_size = source._size;
        this->_data = new int[this->_size];
        *this->_data = *source._data;
        std::cout<<"COPYING content of instance "<<&source<<" to instance "<<this<<std::endl;

    }

    MyMovableClass& operator=(const MyMovableClass& source){
        std::cout << "ASSIGNING content of instance " << &source << " to instance " << this << std::endl;
        if(this == &source)
            return *this;
        delete[] this->_data;      
        this->_size = source._size;
        this->_data = new int[this->_size];
        *this->_data =*source._data;
        return *this;   
    }
    ~MyMovableClass(){
        std::cout<<"DELETING instance of MyMovableClass at "<<this<<std::endl;
        delete [] this->_data;
    }
};


int main(){
    MyMovableClass obj1(10);        // regular constructor
    MyMovableClass obj2(obj1);      // copy constructor
    obj2 = obj1;
    //MyMovableClass obj3 = obj1;
}