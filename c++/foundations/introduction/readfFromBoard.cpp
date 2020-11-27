#include <iostream>
#include <vector>
#include <fstream>

void readBoardFile(const char* myPath){

    std::fstream myfile(myPath);
    if(myfile){
        std::string line;
        while(getline(myfile,line)){
            std::cout<<line;
            std::cout<<"\n";
        }
    }else{
        std::cout<<"couldnt read the file"<<std::endl;
    }
    
}

void printBoard(const std::vector<std::vector<int>>& board){
    for(auto vector : board){
        for(auto val : vector){
            std::cout<< val;
        }
        std::cout<<"\n";
    }


}
int main(){

    const char* myPath = "./1.board";

    readBoardFile(myPath);
 

}