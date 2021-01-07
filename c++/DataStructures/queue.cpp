#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node* next;
        node(int x):data(x),next(NULL){}
};

class Queue{
    public:
        node *front;
        node *back;
        Queue():back(NULL),front(NULL){}
        void enqueue(node* n);
        void dequeue();
        void print();
};

void Queue::enqueue(node* n){
    if(front == NULL){
        front = n;
        back = n;
    }else{
        back->next = n;
        back = n;
    }
}

void Queue::dequeue(){
    if(front == NULL) return;

    node* n = front;
    front = n->next;

    if(front == NULL)
        back = NULL;
    
    delete n;
}

void Queue::print(){
    if(front != NULL){
        node *ptr = front;
        while(ptr != NULL){
            cout<<ptr->data<<" -> ";
            ptr = ptr->next;
        }
        std::cout<<std::endl;
    }else cout<<"queue is empty!!"<<endl;
}

int main(){
    Queue Q;

    node *n1 = new node(7);
    node *n2 = new node(78);
    node *n3 = new node(11);

    Q.print();
    cout<<"----------------------"<<endl;

    Q.enqueue(n1);
    Q.enqueue(n2);
    Q.print();
    cout<<"----------------------"<<endl;
    Q.enqueue(n3);
    Q.print();
    cout<<"----------------------"<<endl;

    Q.dequeue();
    Q.print();
    cout<<"----------------------"<<endl;

    Q.dequeue();
    Q.print();
    cout<<"----------------------"<<endl;

 
    delete [] n3;

    return 0;
}