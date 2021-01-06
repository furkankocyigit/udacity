#include <iostream>
#include <cassert>

class node{
    public:
        int data_;   //data
        node* next_;; //next node
        node(int x): data_(x), next_(NULL){}
};

class Stack{
    public:
        Stack(): top_(NULL){}
        node* top_;
        void push(node* n);
        void pop();
        node* top();
        void print();
};

void Stack::push(node* n){
    if(top_ == NULL){
        top_ = n;
        top_->next_ = NULL;
    }else{
        n->next_ = top_;
        top_ = n;
    }
}
void Stack::pop(){
    if(top_ == NULL)
        std::cout<<"stack is already empty!!"<<std::endl;
    else{
        node* ptr = top_;
        top_ = top_->next_;
        delete(ptr);
    }
}
node* Stack::top(){
    if(top_ == NULL)
        return NULL;
    else
        return top_;
}

void Stack::print(){
    if(top_== NULL)
        std::cout<<"Stack is empty!!"<<std::endl;
    else{
        node* ptr = top_;
        while(ptr !=NULL){
            std::cout<<ptr->data_<<std::endl;
            ptr = ptr->next_;
        }
    }
}

int main(){

    Stack S;
    node *n1 = new node(67);
    node *n2 = new node(42);
    node *n3 = new node(3);

   
    S.push(n1);
    S.push(n2);
    S.push(n3);

    S.print();
    std::cout<<"top node: "<<S.top()->data_<<std::endl;
    std::cout<<"--------"<<std::endl;

    S.pop();
    S.print();
    std::cout<<"top node: "<<S.top()->data_<<std::endl;
    std::cout<<"--------"<<std::endl;
    S.pop();
    S.print();
    std::cout<<"top node: "<<S.top()->data_<<std::endl;
    std::cout<<"--------"<<std::endl;
    S.pop();
    S.print();
    std::cout<<"--------"<<std::endl;

    // delete [] n1;
    // delete [] n2;
    // delete [] n3;   not deleted pointers because they are already cleaned in the pop() function
}