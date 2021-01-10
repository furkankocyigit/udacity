#include <iostream>

// void myFunction(int & lval){
//     std::cout<<"inside lvalue function val = "<<lval<<std::endl;
// }

void myFunction(int && rval){
    std::cout<<"inside rvalue function val = "<<rval<<std::endl;
}


int main(){

    int x = 42;
    myFunction(std::move(x));
    myFunction(42);

    int y = 23;
    myFunction(x+y);

    int i = 1;
    int j = 2;
    int k = i + j;
    int &&l = i + j;

    std::cout<<"k = "<<k<<", l = "<<l<<std::endl;



}