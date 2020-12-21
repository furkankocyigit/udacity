#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iostream>



class Sphere{

    public:
    //static float Volume(float r){ return 4.0/3.0 * PI * pow(r,3);}
    Sphere(float r);
    float Volume() const { return volume_; }
    float Radius() const { return radius_; }
    void Radius(float r);

    private:
    float radius_;
    float volume_;
    static float constexpr PI {3.14159};
};

Sphere::Sphere(float r){
    if(r >= 0){ 
        this->radius_ = r;
        this->volume_ = 4.0/3.0 * PI * pow(radius_,3);
    }
    else throw std::invalid_argument("invalid radius");
}
void Sphere::Radius(float r){
    if(r >= 0){ 
        this->radius_ = r;
        this->volume_ = 4.0/3.0 * PI * pow(radius_,3);
    }
    else throw std::invalid_argument("invalid radius");
}

class Foo {
 public:
  static int count;
  Foo() { Foo::count += 1; }
};

int Foo::count{0};

int main(){

    //assert(abs(Sphere::Volume(5)-523.6)<1);

    Sphere sphere(5);
    assert(sphere.Radius() == 5);
    std::cout<<"volume: "<< sphere.Volume() <<std::endl;
    assert(abs(sphere.Volume() - 523.6) < 1);

    sphere.Radius(3);
    assert(sphere.Radius() == 3);
    std::cout<<"volume: "<< sphere.Volume() <<std::endl;
    assert(abs(sphere.Volume() - 113.1) < 1);

    bool caught{false};
    try{
        sphere.Radius(-1);
    }catch(...){
        caught = true;
    }
    assert(caught);

    Foo f{};
    assert(Foo::count == 1);



}