#include <string>
#include <iostream>
using std::string;
using std::cout;

class Animal{
    public:
    string _name;
    string _color;
    int _age;
    void MakeSoundd(string sound){ cout<<sound<<"\n";}

    protected:
    int abc = 2;

};

class Snake : protected Animal{
    private:
    float _length;
    inline static string const sound{"tsssss"};

    public:
    void MakeSound(){ Animal::MakeSoundd(sound);}
};

class Cat : public Animal{
    private:
    float _height;
    inline static string const sound{"meow!"};
    

    public:
    void MakeSound(){ Animal::MakeSoundd(sound);}
    int returnA(){return abc;}
};

int main(){
    string sound = "aaaa";
    Cat lucy;
    std::cout<<lucy.returnA();
    lucy.MakeSound();
    lucy.MakeSoundd(sound);
    Snake lufy;
    lufy.MakeSound();
}

