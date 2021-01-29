#include <iostream>
#include <memory>


class Node {
    public:
        int _data;
        Node* _left;
        Node* _right;
        Node(int data){
            this->_data = data;
            this->_left = NULL;
            this->_right =NULL;
        }
};

class BinaryTree{
    private:
        Node root;
    public:
        BinaryTree(){}
        void print();
        void add(int data);
        void del(Node node);

};

int main(){
    
}