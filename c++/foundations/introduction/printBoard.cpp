#include <iostream>
#include <vector>


void printBoard(const std::vector<std::vector<int>>& board){
    for(auto vector : board){
        for(auto val : vector){
            std::cout<< val;
        }
        std::cout<<"\n";
    }


}
int main(){

 std::vector<std::vector<int>> board{{0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0, 0},
                            {0, 0, 0, 0, 1, 0}};



printBoard(board);
}