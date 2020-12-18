#include <iostream>

#include <cassert>
#include <iostream>

// // Define a simple structure
// class Birthday{
// public:
// Birthday(int d, int m, int y);
// int Day(){return day;}
// // void Day(int d){
// //     if(d>=1 && d<=31) day = d;
// //}
// int Month(){return month;}
// // void Month(int m){
// //     if(m>=1 && m<=12) month = m;
// int Year(){return year;}
// //void Year(int y){year = y;}




// private:
// int const day;
// int const month;
// int const year;

// };
// Birthday::Birthday(int d, int m, int y): day(d), month(m),year(y) {}
class A {
    public:
        A(int a, double b, char c) : attr1(a), attr2(b), attr3(c)
        {
            std::cout<<"A constructor"<<"\n";
        }
        void print() const
        {
            std::cout<<"A: "<<attr1<<" "<<attr2<<" "<<attr3<<"\n";
        }
    private:
        int attr1;
        double attr2;
        char attr3;
};

class B {
    public:
        B(int num, int a, double b, char c) : number(num), attr(a, b, c) 
        {
            std::cout<<"B constructor"<<"\n";
        }
        void print() const 
        {
            std::cout<<"B: "<<number<<" ";
            attr.print();
        }
    private:
        int number;
        A attr;
};



// Define a main function to instantiate and tes
int main(){
    

    //TODO: İnitialize date to August 29, 1981
    // Birthday date(29,8,1981);

    // //TEST
    // assert(date.Day() == 29);
    // assert(date.Month() == 8);
    // assert(date.Year() == 1981);

    // //print the data in the structure
    // std::cout<<date.Day()<<"/"<<date.Month()<<"/"<<date.Year()<<"\n";
    B obj(23, 2, 2.3, 'X');
    obj.print();
}