#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
    int *p = (int*)malloc(sizeof(int)); 
    int *p2 = p;

    free(p); // OK
    *p = 3;
    std::cout<<"p: "<<*p<<std::endl;
    free(p2); // ERROR

    return 0;
}