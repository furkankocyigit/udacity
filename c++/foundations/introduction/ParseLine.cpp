#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

enum class State{ kEmpty, kObstacle};

vector<State> ParseLine(string& line){

    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while(sline>>n>>c && c == ','){
        if(n == 1)
            row.push_back(State::kObstacle);
        else if(n == 0)
            row.push_back(State::kEmpty);
    }
    return row;
}


vector<vector<State>> readBoardFile(const char* myPath){

    std::fstream myfile(myPath);
    vector<State> row;
    vector<vector<State>> board;

    if(myfile){
        std::string line;
        
        while(getline(myfile,line)){
            row.clear();
            // std::cout<<line;
            // std::cout<<"\n";
            row = ParseLine(line);
            board.push_back(row);
            
        }
    }else{
        std::cout<<"couldnt read the file"<<std::endl;
    }
    return board;
    
}
string CellString(const State& cell){
    switch (cell)
    {
    case State::kObstacle : return "⛰️   ";    
    default:return "0   ";
    }
}

void printBoard(const vector<vector<State>>& board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}

//#include "test.cpp"
int main(){

    const char* myPath = "./1.board";
    auto board = readBoardFile(myPath);
    printBoard(board);
    //TestParseLine();
 

}