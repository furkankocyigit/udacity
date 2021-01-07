#include <iostream>
void AddFive(int& val,bool& succes){
    val +=5;
    succes =true;

}

int main()
{
    int val = 0;
    bool success = false;
    AddFive(val, success);
    val += 2;

    std::cout << "val = " << val << ", success = " << success << std::endl;
 
    return 0;
}