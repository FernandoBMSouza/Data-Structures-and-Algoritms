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
    else if(balanceFactor(p) == -2 && balanceFactor(p->rChild) == -1) 
        return rotationRR(p);
    else if(balanceFactor(p) == -2 && balanceFactor(p->rChild) == 1) 
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
    Node* pRight = p->rChild;
    Node* pRightLeft = pRight->lChild;

    pRight->lChild = p;
    p->rChild = pRightLeft;

    p->height = nodeHeight(p);
    pRight->height = nodeHeight(pRight);

    if(root == p)
        root = pRight;

    return pRight;
}

Node* avlTree::rotationLR(Node* p)
{
    Node* pLeft = p->lChild;
    Node* pLeftRight = pLeft->rChild;

    pLeft->rChild = pLeftRight->lChild;
    p->lChild = pLeftRight->rChild;

    pLeftRight->lChild = pLeft;
    pLeftRight->rChild = p;

    pLeft->height = nodeHeight(pLeft);
    p->height = nodeHeight(p);
    pLeftRight->height = nodeHeight(pLeftRight);

    if(root == p) root = pLeftRight;

    return pLeftRight;
}

Node* avlTree::rotationRL(Node* p)
{
    Node* pRight = p->rChild;
    Node* pRightLeft = pRight->lChild;

    pRight->lChild = pRightLeft->rChild;
    p->rChild = pRightLeft->lChild;

    pRightLeft->lChild = p;
    pRightLeft->rChild = pRight;

    pRight->height = nodeHeight(pRight);
    p->height = nodeHeight(p);
    pRightLeft->height = nodeHeight(pRightLeft);

    if(root == p) root = pRightLeft;

    return pRightLeft;
}