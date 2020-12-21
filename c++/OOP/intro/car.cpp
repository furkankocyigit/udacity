#include <iostream>
#include <cstring>
#include <string>
#include <cassert>

class Car {

    float horsePower_, weight_;
    char*  brand_;
 public:
    Car(){};
    ~Car(){};
    // accessor
    float& getHorsePower(){return horsePower_;}
    float& getWeight(){return weight_;};
    std::string getBrand() const{
        std::string strBrand;
        //strBrand = brand_.c_str();
        // for( int i = 0; brand_[i] != '\n'; i++){
        //     strBrand[i] = brand_[i];
        // }
        return brand_;
    }
    
    //mutators
    void setHoursePower(const float hp){ horsePower_ = hp;};
    void setWeight(const float weight){ weight_ = weight;}
    void setBrand(std::string brandName){
        brand_ = new char[brandName.length() + 1];
        strcpy(brand_, brandName.c_str());
        }

};


int main(){
    
    Car ferrari;
    ferrari.setBrand("ferrari");
    ferrari.setHoursePower(105.5);
    ferrari.setWeight(1600);
    std::cout<<"brand : "<<ferrari.getBrand()<<std::endl;
    std::cout<<"hp    : "<<ferrari.getHorsePower()<<std::endl;
    std::cout<<"weight: "<<ferrari.getWeight()<<std::endl;
    // assert(ferrari.getBrand() == "ferrari");


}