#include "binarySearchTree.h"
#include <iostream>

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