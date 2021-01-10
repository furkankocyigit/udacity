#include <stdlib.h>
#include <iostream>


class MyMovableClass{

private: 
    int _size;
    int* _data;

public:
    MyMovableClass(size_t size){    //constructor
        _size = size;
        _data = new int[_size];
        std::cout << "CREATING instance of MyMovableClass at " << this << " allocated with size = " << _size*sizeof(int)  << " bytes" << std::endl;
    }
    ~MyMovableClass(){      //destructor
        std::cout<<"DELETING instance of MyMovableClass at "<<this<<std::endl;
        delete[] this->_data;
    }

    MyMovableClass(const MyMovableClass& source){   //copy constructor
        this->_size = source._size;
        this->_data = new int[this->_size];
        *this->_data = *source._data;
        std::cout << "COPYING content of instance " << &source << " to instance " << this << std::endl;
    }

    MyMovableClass(MyMovableClass &&source) // 4 : move constructor
    {
        std::cout << "MOVING (c’tor) instance " << &source << " to instance " << this << std::endl;
        _data = source._data;
        _size = source._size;
        source._data = nullptr;
        source._size = 0;
    }

    MyMovableClass& operator=(const MyMovableClass& source){
        std::cout << "ASSIGNING content of instance " << &source << " to instance " << this << std::endl;
        if(this == &source)
            return *this;
        delete[] this->_data;
        this->_size = source._size;
        this->_data = new int[this->_size];
        *this->_data = *source._data;
        return *this;
    }

    MyMovableClass& operator=(MyMovableClass &&source){
        std::cout << "MOVING (assign) instance " << &source << " to instance " << this << std::endl;
        if(this == &source)
            return *this;
        delete [] this->_data;
        this->_size = source._size;
        this->_data = source._data;
        source._size = 0;
        source._data = nullptr;
        
        return *this;
    }

};

void useObject(MyMovableClass obj){
    std::cout<<"using object "<<&obj<<std::endl;
}
int main(){

    // //Example 1
    // MyMovableClass obj1(100),obj2(200);  // constructor
    // MyMovableClass obj3(obj1);      // copy constructor
    // MyMovableClass obj4 = obj1;     // copy constructor
    // obj4 = obj2;        //coppy assignment operator

    // //Example 2
    // MyMovableClass obj1(100); // constructor
    // obj1 = MyMovableClass(200); // move assignment operator
    // MyMovableClass obj2 = MyMovableClass(300); // move constructor

    //Example 3
    MyMovableClass obj1(100);   //constructor
    useObject(std::move(obj1));
    
    return 0;
}