#include <iostream>
#include <memory>



class Node {
    int _data;
    public:
        std::shared_ptr<Node> _left;
        std::shared_ptr<Node> _right;
        int getData(){return _data;}
        void setData(int data){ _data = data;}
        Node(int data){
            setData(data);
            this->_left = NULL;
            this->_right =NULL;
        }
};


class BinaryTree{
    private:
        std::shared_ptr<Node> _root;
    public:
        BinaryTree(){
            _root = nullptr;
        }
        void print();
        std::shared_ptr<Node> getRoot(){return _root;}
        void insert(int data);
        void del(Node node);
        void printTree(std::shared_ptr<Node> root,int space = 0, int t = 0, int COUNT = 3);

};

void BinaryTree::insert(int value){
    
    if(!this->_root){
        //this->_root->setData(value);
        this->_root = std::make_shared<Node>(value);
        }
    else{
        std::shared_ptr<Node>tempPtr= nullptr;
        auto x = getRoot();
        while(x != nullptr){
            tempPtr = x;
            if(tempPtr->getData() < value){
                x = x->_left;
            }
            else{
                x = x->_right;
            }
        }
        if(value < tempPtr->getData())
            tempPtr->_left = std::make_shared<Node>(value);
        else    
            tempPtr->_right = std::make_shared<Node>(value);
    }
}

void BinaryTree::printTree(std::shared_ptr<Node> root, int space, int t, int COUNT ){
    
    if(!root) return;
    space += COUNT;
    printTree(root->_right,space,1);
    
    for(int i = COUNT; i < space; i++){
        std::cout<<" ";
    }
    if(t == 1){   //Right Node
        std::cout<<"/ "<<root->getData()<<std::endl;
    }
    else if(t == 2){    //Left Node
        std::cout<<"\\ "<<root->getData()<<std::endl;
    }
    else{   //root
        std::cout<<root->getData()<<std::endl;
    }
    printTree(root->_left,space,2);

}

void print(std::shared_ptr<Node> root, int space = 0, int t = 0, int COUNT = 3){
    
    if(!root) return;
    space += COUNT;
    print(root->_right,space,1);
    
    for(int i = COUNT; i < space; i++){
        std::cout<<" ";
    }
    if(t == 1){   //Right Node
        std::cout<<"/ "<<root->getData()<<std::endl;
    }
    else if(t == 2){    //Left Node
        std::cout<<"\\ "<<root->getData()<<std::endl;
    }
    else{   //root
        std::cout<<root->getData()<<std::endl;
    }
    print(root->_left,space,2);

}

int main(){
    
    std::shared_ptr<Node> binaryTreeRoot = std::make_shared<Node>(10);
    binaryTreeRoot->_left = std::make_shared<Node>(5);
    binaryTreeRoot->_right = std::make_shared<Node>(15);
    binaryTreeRoot->_left->_left = std::make_shared<Node>(100);
    print(binaryTreeRoot);

    std::cout<<"=========================================="<<std::endl;

    BinaryTree binaryTree;
    binaryTree.insert(10);
    binaryTree.insert(5);
    binaryTree.insert(15);
    binaryTree.insert(100);

    binaryTree.printTree(binaryTree.getRoot());
}