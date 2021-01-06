#include <iostream>
#include <cassert>
using namespace std;

class node{

    public:
        int data_;       // data
        node* next_;     // pointer  
        node(int x):data_(x),next_(NULL){}
    
};

class LinkedList {    

    public:
        node* head_;
        LinkedList(): head_(NULL){}
        void addAtFront(node* n);   // function to add node at front;
        bool isEmpty();             // function to check wheteher the list is empty
        void addAtEnd(node* n);     // function to add node at the end;
        node* getLastNode();        // function to get last node;
        node* search(int k);        // function to search a value in the list
        node* deleteNode(int x);    // function to delete any node
        void printList();           // function to print the nodes in the list
};

void LinkedList::addAtFront(node* n){
    n->next_ = head_;
    head_ = n;
}

bool LinkedList::isEmpty(){
    if(head_ == NULL ) return true;
    else return false;
}

void LinkedList::addAtEnd(node* n){

    if(head_ == NULL){
        head_ = n;
        n->next_ = NULL;
    }
    else{
        node* ptr = this->getLastNode();
        ptr->next_ = n;
    }    
}
node* LinkedList::search(int k){
    node* ptr = head_;
    while(ptr != NULL){
        if(ptr->data_ == k) 
            return ptr;
        ptr = ptr->next_;
    }
    std::cout<<"\n"<<k<<" is not in the list!!"<<std::endl;
    return NULL;
}
node* LinkedList::deleteNode(int x){

    node* n = search(x);
    node* ptr = head_;
    if(ptr == n){
        head_ = n->next_;
        return n;
    }else
    {
        while(ptr->next_ != n){
            ptr = ptr->next_;
        }
        ptr->next_ = n->next_;
        return n;
    }
}

node* LinkedList::getLastNode(){
    if (!this->isEmpty()){
        node* ptr = head_;
        while(true){
            ptr = ptr->next_;
            if(ptr->next_ == NULL)
            return ptr;
        }
    }else return NULL;
}

void LinkedList::printList(){

    if(!this->isEmpty()){
        node* ptr = head_;
        while(ptr != NULL){
            std::cout<<ptr->data_<<" -> ";
            ptr = ptr->next_;
        }
        std::cout<<"NULL\n";
    }
    else{std::cout<<"List is empty!!"<<std::endl;}

}
int main(){

    LinkedList list;

    node *node1 = new node(5);
    node *node2 = new node(8);
    node *node3 = new node(12);
    node *node4 = new node(15);
    node *node5 = new node(20);
    node *node6 = new node(25);
    
    list.addAtFront(node1);
    list.addAtFront(node2);
    list.addAtFront(node3);
    list.addAtEnd(node4);
   
    list.printList();
    list.addAtFront(node5);
    list.addAtEnd(node6);
    list.printList();

    node* temp = list.search(100);
    assert(temp == NULL );

    list.deleteNode(15);
    list.printList();


    delete[] node1;
    delete[] node2;
    delete[] node3;
    delete[] node4;
    delete[] node5;
    delete[] node6;
    return 0;
}
