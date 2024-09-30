#include "binarySearchTree.h"
#include <iostream>
#include <stack>

binarySearchTree::binarySearchTree()
{
    root = nullptr;
}

binarySearchTree::~binarySearchTree()
{
    deleteTree(root);
    root = nullptr;
}

void binarySearchTree::deleteTree(Node* node)
{
    if(node)
    {
        deleteTree(node->lchild);
        deleteTree(node->rchild);
        delete node;
    }
}

void binarySearchTree::insert(int key)
{
    Node *t = root;
    Node *r, *p;

    if(root == nullptr)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = nullptr;
        root = p;
        return;
    }

    while (t != nullptr)
    {
        r = t;
        if(key < t->data)
            t = t->lchild;
        else if(key > t->data)
            t = t->rchild;
        else return;
    }
    
    p = new Node;
    p->data = key;
    p->lchild = p->rchild = nullptr;

    if(key < r->data) r->lchild = p;
    else r->rchild = p;
}

void binarySearchTree::inorder(Node* p)
{
    if(p)
    {
        inorder(p->lchild);
        std::cout << p->data << ' ';
        inorder(p->rchild);
    }
}

void binarySearchTree::setRoot(Node* p)
{
    root = p;
}

int binarySearchTree::getHeight(Node* p)
{
    if(!p) return 0;

    int x = getHeight(p->lchild);
    int y = getHeight(p->rchild);

    return x > y ? x + 1 : y + 1;
}

Node* binarySearchTree::getRoot()
{
    return root;
}

Node* binarySearchTree::search(int key)
{
    Node* p = root;
    while (p)
    {
        if(p->data == key)
            return p;
        else if(p->data > key)
            p = p->lchild;
        else
            p = p->rchild;
    }
    return nullptr;
}

Node* binarySearchTree::rInsert(Node* p, int key)
{
    if(p == nullptr)
    {
        Node* t = new Node;
        t->data = key;
        t->lchild = t->rchild = nullptr;
        return t;
    }

    if(key < p->data)
        p->lchild = rInsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = rInsert(p->rchild, key);
    
    return p;    
}

Node* binarySearchTree::deleteNode(Node* p, int key)
{
    if(p == nullptr) return nullptr;

    if(!p->lchild && !p->rchild)
    {
        if(p == root) root = nullptr;
        delete p;
        return nullptr;
    }

    if(key < p->data)
        p->lchild = deleteNode(p->lchild, key);
    else if(key > p->data)
        p->rchild = deleteNode(p->rchild, key);
    else
    {
        if(getHeight(p->lchild) > getHeight(p->rchild))
        {
            Node* q = inorderPredecessor(p->lchild);
            p->data = q->data;
            p->lchild = deleteNode(p->lchild, q->data);
        }
        else
        {
            Node* q = inorderSuccessor(p->rchild);
            p->data = q->data;
            p->rchild = deleteNode(p->rchild, q->data);
        }
    }
    return p;
}

Node* binarySearchTree::inorderPredecessor(Node* p)
{
    while (p && p->rchild)
        p = p->rchild;

    return p;
}

Node* binarySearchTree::inorderSuccessor(Node* p)
{
    while (p && p->lchild)
        p = p->lchild;
        
    return p;
}
