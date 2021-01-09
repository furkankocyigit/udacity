#include<iostream>
using namespace std;


class AdjacencyMatrix{

    private:
        int n_;
        int **adj;
    public:
        AdjacencyMatrix(int n);
        void addEdge(int orig, int dest);
        void removeEdge(int orig,int dest);
        void display();
};

AdjacencyMatrix::AdjacencyMatrix(int n){
    this->n_ = n;
    adj = new int*[n];
    for(int k = 0; k < this->n_; k++){
        adj[k] = new int[n];
        for(int j = 0; j < this->n_; j++){
            adj[k][j] = 0;
        }
    }
}

void AdjacencyMatrix::addEdge(int orig, int dest){
    if(orig > this->n_ || dest > this->n_ || orig < 1 || dest < 1 ){
        cout<<"Trying to add an invalid edge";
        cout<<"("<<orig<<","<<dest<<")"<<endl;
    }else
    {
        adj[orig - 1][dest - 1] = 1;
    }
    
}

void AdjacencyMatrix::removeEdge(int orig, int dest){
    if(orig > this->n_ || dest > this->n_ || orig < 1 || dest < 1 ){
        cout<<"Trying to remove an invalid edge";
        cout<<"("<<orig<<","<<dest<<")"<<endl;
    }else
    {
        adj[orig - 1][dest - 1] = 0;
    }
    
}

void AdjacencyMatrix::display(){
    for(int i = 0; i < this->n_; i++){
        for(int j = 0; j < this->n_; j++){
            cout<<adj[i][j]<<" "; 
        }
        cout<<endl;
    }

}

int main(){

    AdjacencyMatrix M(5);

    M.addEdge(2,5);
    M.addEdge(1,5);
    M.addEdge(5,1);
    M.addEdge(3,3);
    M.display();
    cout<<"-----------------"<<endl;
    M.removeEdge(1,5);
    M.display();
  

    return 0;
}