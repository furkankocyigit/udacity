#include <stdio.h> 
#include <stdlib.h>

struct MyStruct {
    int i; 
    double d; 
    char a[5];
};
  
int main() 
{ 
    int *p = (int*)malloc(sizeof(int)*3);
    p[0] = 1; p[1] = 2; p[2] = 3; p[3] = 4;
    printf("address=%p, value=%d\n", p, p[3]);

    MyStruct *ptr = (MyStruct*)calloc(4,sizeof(MyStruct));
    ptr[0].i = 1; ptr[0].d = 3.14159; ptr[0].a[0] = 'a';

    return 0; 
}