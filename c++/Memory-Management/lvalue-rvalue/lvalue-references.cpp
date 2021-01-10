#include <iostream>

void myFunction(int &val){
    ++val;
}


int main(){

    int i = 1;
    int &j = i;
    ++i;
    ++j;
    std::cout<<"i = "<<i<<", j = "<<j<<std::endl;

    int k = 1;
    myFunction(k);
    std::cout<<"k = "<<k<<std::endl;
}