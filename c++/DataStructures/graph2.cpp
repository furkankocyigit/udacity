#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *link;
        Node(int value): data(value), link(NULL){}
};

class vertexList{
    public:
        Node *head;
};

class Graph{
    public:
        int v;
        vertexList *vl;
        
        Graph(int n);
        void addEdge(int src, int dest);
        void print();
};

Graph::Graph(int n){
    this->v = n;
    this->vl = new vertexList[this->v];
    for(int i = 0; i < this->v; i++)
        this->vl[i].head = NULL;
}

void Graph::addEdge(int src, int dest){

    Node* n = new Node(dest);
    n->link = this->vl[src].head;
    this->vl[src].head = n;
    n = new Node(src);
    n->link = this->vl[dest].head;
    this->vl[dest].head = n;
}

void Graph::print(){
    for(int i = 0; i<this->v; i++){
        Node* temp = this->vl[i].head;
        cout<<"\n Adjacency list of vertex "<<i<<"\n head";
        while(temp){
            cout<<" -> "<<temp->data;
            temp = temp->link;
        }
        cout<<endl;
    }
}


int main(){
    Graph G(5);

    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(2,3);

    G.print();
}