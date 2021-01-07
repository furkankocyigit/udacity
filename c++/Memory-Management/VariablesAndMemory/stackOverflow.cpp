#include <iostream>

int id = 0;

void MyRecursiveFunc(int &i){
    int j = 0;
    printf("%d: stack bottom : %p, current : %p\n",id++, &i, &j);
    MyRecursiveFunc(i);
}

int main(){
    int i = 0;
    MyRecursiveFunc(i);

    return 0;

}