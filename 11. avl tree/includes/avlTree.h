#ifndef AVL_TREE
#define AVL_TREE

#include <iostream>

struct Node
{
    int data;
    int height;
    Node* lChild;
    Node* rChild;
};

class avlTree
{
private:
    Node* root = nullptr;

    void deleteTree(Node* p);
    void inOrder(Node* p);
    int nodeHeight(Node* p);
    int balanceFactor(Node* p);
    Node* rotationLL(Node* p);
    Node* rotationRR(Node* p);
    Node* rotationLR(Node* p);
    Node* rotationRL(Node* p);
    Node* getPredecessor(Node* p);
    Node* getSuccessor(Node* p);

public:
    avlTree();
    ~avlTree();
    void inOrder();
    void setRoot(Node* p);
    Node* getRoot();
    Node* rInsert(Node* p, int key);
    Node* deleteNode(Node* p, int key);
};

#endif