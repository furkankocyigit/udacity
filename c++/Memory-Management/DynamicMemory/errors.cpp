#include <iostream>
#include <string.h>


// void factorial(int* p, int size){
//     for(int i = 0; i<size;i++){
//         int factorial = 1;
//         for(int j = p[i]; j>0;j--){
//             factorial *= j;
//         }
//         std::cout<<"factorial of "<<p[i]<<": "<<factorial<<std::endl;
//     }
// }

// void soru_4(){
//     int arr[10],size;
//     size = sizeof(arr)/sizeof(int);
//     for(int i = 0; i<size;i++){
//         std::cout<<"Enter the element "<<i+1<<": ";
//         std::cin>>arr[i];
//     }
//     std::cout<<"\n\nArray{ ";
//     for(int i = 0; i<size;i++){
//         std::cout<<arr[i]<<" ";
//     }
//     std::cout<<"}\n\n";
//     factorial(arr,size);
// }

int main(){
    // char str[5];
    // strcpy(str,"BufferOverRun");
    // printf("%s",str);

    //soru_4();

    char *pStr=new char[25];
    //delete[] pStr;
    

    // strcpy(pStr, "Invalid Access");
    // for(int i = 0;i<25;i++){
    //     std::cout<<pStr[i];
    // }
    delete[] pStr;

    int *pInt = new int[10];
    delete[] pInt;

    return 0;
    
    
}