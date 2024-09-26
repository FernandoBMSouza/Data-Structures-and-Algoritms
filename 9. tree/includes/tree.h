#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <stack>
#include "queue.h"

template <typename T>
class Node
{
public:
    Node<T>* leftChild;
    T data;
    Node<T>* rightChild;
};

template<typename T>
class Tree
{
private:
    Node<T>* root;
    void deleteTree(Node<T>* node);
public:
    Tree();
    ~Tree();

    void createTree();
    void preOrderIterative(Node<T>* p);
    void inOrderIterative(Node<T>* p);
    void postOrderIterative(Node<T>* p);
    void preOrder(Node<T>* p);
    void inOrder(Node<T>* p);
    void postOrder(Node<T>* p);
    void levelOrder(Node<T>* p);
    int getHeight(Node<T>* root);
    Node<T>* getRoot();
};

template<typename T>
Node<T>* Tree<T>::getRoot()
{
    return root;
}

template<typename T>
Tree<T>::Tree()
{
    root = nullptr;
}

template<typename T>
Tree<T>::~Tree()
{
    deleteTree(root);
    root = nullptr;
}

template<typename T>
void Tree<T>::deleteTree(Node<T>* node)
{
    if (node) {
        deleteTree(node->leftChild);
        deleteTree(node->rightChild);
        delete node;
    }
}

template<typename T>
void Tree<T>::createTree()
{
    Node<T> *p, *t;
    T x;
    Queue<Node<T>*> q(100);

    std::cout << "Enter root value: ";
    std::cin >> x;

    root = new Node<T>;
    root->data = x;
    root->leftChild = root->rightChild = nullptr;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        std::cout << "Enter left child of " << p->data << ": ";
        std::cin >> x;
        if(x != -1)
        {
            t = new Node<T>;
            t->data = x;
            t->leftChild = t->rightChild = nullptr;
            p->leftChild = t;
            q.enqueue(t);
        }

        std::cout << "Enter right child of " << p->data << ": ";
        std::cin >> x;
        if(x != -1)
        {
            t = new Node<T>;
            t->data = x;
            t->leftChild = t->rightChild = nullptr;
            p->rightChild = t;
            q.enqueue(t);
        }
    }
}

template<typename T>
void Tree<T>::preOrder(Node<T>* p)
{
    if(p)
    {
        std::cout << p->data << ' ';
        preOrder(p->leftChild);
        preOrder(p->rightChild);
    }
}

template<typename T>
void Tree<T>::inOrder(Node<T>* p)
{
    if(p)
    {
        inOrder(p->leftChild);
        std::cout << p->data << ' ';
        inOrder(p->rightChild);
    }
}

template<typename T>
void Tree<T>::postOrder(Node<T>* p)
{
    if(p)
    {
        postOrder(p->leftChild);
        postOrder(p->rightChild);
        std::cout << p->data << ' ';
    }
}

template<typename T>
void Tree<T>::preOrderIterative(Node<T>* p)
{
    std::stack<Node<T>*> stack;
    while (p != nullptr || !stack.empty())
    {
        if(p != nullptr)
        {
            std::cout << p->data << ' ';
            stack.push(p);
            p = p->leftChild;
        }
        else
        {
            p = stack.top();
            stack.pop();
            p = p->rightChild;
        }
    }
}

template<typename T>
void Tree<T>::inOrderIterative(Node<T>* p)
{
    std::stack<Node<T>*> stack;
    while (p != nullptr || !stack.empty())
    {
        if(p != nullptr)
        {
            stack.push(p);
            p = p->leftChild;
        }
        else
        {
            p = stack.top();
            stack.pop();
            std::cout << p->data << ' ';
            p = p->rightChild;
        }
    }
}

template<typename T>
void Tree<T>::postOrderIterative(Node<T>* p)
{
    std::stack<Node<T>*> stack;
    Node<T>* lastVisitedNode = nullptr;

    while (p != nullptr || !stack.empty())
    {
        if (p != nullptr)
        {
            // Empilha todos os filhos à esquerda
            stack.push(p);
            p = p->leftChild;
        }
        else
        {
            // Pega o nó do topo da pilha
            Node<T>* topNode = stack.top();

            // Se o filho à direita é nulo ou já foi visitado, processa o nó
            if (topNode->rightChild == nullptr || topNode->rightChild == lastVisitedNode)
            {
                std::cout << topNode->data << ' ';
                stack.pop();
                lastVisitedNode = topNode;
                p = nullptr; // Garante que vai para o próximo nó na pilha
            }
            else
            {
                // Se o nó à direita não foi visitado, explora o lado direito
                p = topNode->rightChild;
            }
        }
    }
}

template<typename T>
void Tree<T>::levelOrder(Node<T>* root)
{
    Queue<Node<T>*> q(100);

    std::cout << root->data << ' ';
    q.enqueue(root);

    while (!q.isEmpty())
    {
        root = q.dequeue();
        if(root->leftChild)
        {
            std::cout << root->leftChild->data << ' ';
            q.enqueue(root->leftChild);
        }
        if(root->rightChild)
        {
            std::cout << root->rightChild->data << ' ';
            q.enqueue(root->rightChild);
        }
    }
    
}

template<typename T>
int Tree<T>::getHeight(Node<T>* root)
{
    int x = 0;
    int y = 0;

    if(root == nullptr) return 0;

    x = getHeight(root->leftChild);
    y = getHeight(root->rightChild);

    if(x>y) return x+1;
    else return y+1;
}

#endif