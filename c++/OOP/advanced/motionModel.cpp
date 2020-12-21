#include <cassert>
#include <iostream>
#include <cmath>

#define PI 3.14159

class VehicleModel{
    public:
        virtual void Move(double v, double theta) = 0;
};

class ParticleModel : public VehicleModel{
    public:
        void Move(double v, double theta) override{
            _theta += theta;
            _x += v * cos(_theta);
            _y += v * cos(_theta); 
        }

    
        double _x{0};
        double _y{0};
        double _theta{0};

};

class BicycleModel : public ParticleModel{

    public:
        void Move(double v, double theta) override {
            _theta += v/ _L * tan(theta);
            _x += v * cos(_theta);
            _y += v * cos(_theta); 
        }

        double _x{0};
        double _y{0};
        double _theta{0};
        double _L = 1;


};

int main() {
  // Test function overriding
  ParticleModel particle;
  BicycleModel bicycle;
  particle.Move(10, PI / 9);
  bicycle.Move(10, PI / 9);
  assert(particle._x != bicycle._x);
  assert(particle._y != bicycle._y);
  assert(particle._theta != bicycle._theta);
}