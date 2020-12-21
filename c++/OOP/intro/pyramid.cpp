#include <cassert>
#include <stdexcept>

class Pyramid{
    public:
    Pyramid(int length, int width, int height);
    int Length() const {return length_;}
    int Width() const {return width_;}
    int Height() const {return height_;}
    bool Length(int length);
    bool Width(int width);
    bool Height(int Height);
    float Volume(){return (length_* width_ * height_) / 3.0;};
    void assignDimension(int& dimension, int value);

    private:
    int length_;
    int width_;
    int height_;
};
Pyramid::Pyramid(int length, int width, int height){
    assignDimension(this->length_,length);
    assignDimension(this->width_,width);
    assignDimension(this->height_,height);
}
bool Valid(int value){
    if(value>0) return true;
    else{
        return false;
    }
}
void Pyramid::assignDimension( int& dimension, int value){
    if(Valid(value)) dimension = value;
    else throw  std::invalid_argument( "invalid dimension");
}


// Pyramid::Pyramid(int length, int width, int height){
//     if(!Length(length)) throw "length is not valid";
//     if(!Width(width)) throw "width is not valid";
//     if(!Height(height)) throw "height is not valid";
   
// }

// bool Pyramid::Length(int length){
//     if(length > 0){
//         length_ = length;
//         return true;
//     }else
//     {
//         return false;
//     }    
// }
// bool Pyramid::Width(int width){
//     if(width > 0){
//         width_ = width;
//         return true;
//     }else
//     {
//         return false;
//     }    
// }
// bool Pyramid::Height(int height){
//     if(height > 0){
//         height_ = height;
//         return true;
//     }else
//     {
//         return false;
//     }    
// }

int main(){
    Pyramid pyramid(-4,5,6);
    assert(pyramid.Length() == 4);
    assert(pyramid.Width() == 5);
    assert(pyramid.Height() == 6);
    assert(pyramid.Volume() == 40);

}