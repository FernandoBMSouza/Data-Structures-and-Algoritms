#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

struct Node
{
    Node* lchild;
    int data;
    Node* rchild;
};

class binarySearchTree
{
private:
    Node* root;
    void deleteTree(Node* node);
public:
    binarySearchTree();
    ~binarySearchTree();
    void insert(int key);
    void inorder(Node* p);
    void setRoot(Node* p);
    int getHeight(Node* p);
    Node* getRoot();
    Node* search(int key);
    Node* rInsert(Node* p, int key);
    Node* deleteNode(Node* p, int key);
    Node* inorderPredecessor(Node* p);
    Node* inorderSuccessor(Node* p);
};

#endif