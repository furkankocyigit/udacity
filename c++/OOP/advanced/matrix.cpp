#include <cassert>
#include <vector>

class Matrix{

public:
    Matrix(int rows, int columns) : rows_(rows), columns_(columns), values_(rows * columns) {}

    int& operator()(int row , int column){
        return values_[row * columns_ + column];
    }
    int operator()(int row,int column) const {
        return values_[row * columns_ + column];
    }
    Matrix operator+(Matrix m){
        Matrix sum(rows_,columns_);
        for(int i = 0; i< this->columns_*this->rows_; i++){
            sum.values_[i] = this->values_[i] + m.values_[i];
        }
        return sum;
    }
private:
    int rows_;
    int columns_;
    std::vector<int> values_;

};

int main(){

    Matrix matrix1(2,2);
    Matrix matrix2(2,2);
    Matrix matrix3(2,2);
    matrix1(0,0) = 0;
    matrix1(0,1) = 1;
    matrix1(1,0) = 2;
    matrix1(1,1) = 3;
    matrix2(0,0) = 6;
    matrix2(0,1) = 7;
    matrix2(1,0) = 8;
    matrix2(1,1) = 9;

    matrix3 = matrix1 + matrix2;


    assert(matrix1(0,0) == 0);
    assert(matrix3(1,1) == 12);
    assert(matrix3(0,1) == 8);
}