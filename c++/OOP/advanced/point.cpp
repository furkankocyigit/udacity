#include <cassert>

class Point{

public:
    //Point();
    Point(int x = 0, int y = 0) : x_(x), y_(y){}
    Point operator+(const Point& other){
        Point sum;
        sum.x_ = this->x_ + other.x_;
        sum.y_ = this->y_ + other.y_;
        return sum;
    }
    int x_;
    int y_;

private:
    

};

int main(){
  Point p1(10, 5), p2(2, 4);
  Point p3 = p1 + p2; // An example call to "operator +";
  assert(p3.x_ == p1.x_ + p2.x_);
  assert(p3.y_ == p1.y_ + p2.y_);
}