#include "avlTree.h"

avlTree::avlTree()
{
    root = nullptr;
}

avlTree::~avlTree()
{
    deleteTree(root);
    root = nullptr;
}

void avlTree::deleteTree(Node* p)
{
    if(p)
    {
        deleteTree(p->lChild);
        deleteTree(p->rChild);
        delete p;
    }
}

void avlTree::setRoot(Node* p)
{
    root = p;
}

Node* avlTree::getRoot() { return root; }

Node* avlTree::rInsert(Node* p, int key)
{
    if(p == nullptr)
    {
        Node* t = new Node;
        t->data = key;
        t->height = 1;
        t->lChild = t->rChild = nullptr;
        return t;
    }

    if(key < p->data)
        p->lChild = rInsert(p->lChild, key);
    else if(key > p->data)
        p->rChild = rInsert(p->rChild, key);
    
    p->height = nodeHeight(p); 

    if(balanceFactor(p) == 2 && balanceFactor(p->lChild) == 1)
        return rotationLL(p);
    else if(balanceFactor(p) == 2 && balanceFactor(p->lChild) == -1) 
        return rotationLR(p);
    else if(balanceFactor(p) == -2 && balanceFactor(p->lChild) == -1) 
        return rotationRR(p);
    else if(balanceFactor(p) == -2 && balanceFactor(p->lChild) == 1) 
        return rotationRL(p);

    return p;    
}

int avlTree::nodeHeight(Node* p)
{
    int hLeft, hRight;
    hLeft = (p && p->lChild ? p->lChild->height : 0);
    hRight = (p && p->rChild ? p->rChild->height : 0);

    return hLeft > hRight ? hLeft + 1 : hRight + 1;
}

int avlTree::balanceFactor(Node* p)
{
    int hLeft, hRight;
    hLeft = (p && p->lChild ? p->lChild->height : 0);
    hRight = (p && p->rChild ? p->rChild->height : 0);

    return hLeft - hRight;
}

Node* avlTree::rotationLL(Node* p)
{
    Node* pLeft = p->lChild;
    Node* pLeftRight = pLeft->rChild;

    pLeft->rChild = p;
    p->lChild = pLeftRight;

    p->height = nodeHeight(p);
    pLeft->height = nodeHeight(pLeft);

    if(root == p)
        root = pLeft;

    return pLeft;
}

Node* avlTree::rotationRR(Node* p)
{
    return nullptr;
}

Node* avlTree::rotationLR(Node* p)
{
    return nullptr;
}

Node* avlTree::rotationRL(Node* p)
{
    return nullptr;
}