#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <cmath>
#include <stack>

template <typename T>
class LinkedList
{
private:   
    struct Node
    {
        T data;
        Node* next;
        Node(T data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* first;
    
public:
    LinkedList() : first(nullptr) {}
    LinkedList(T* values, int length);
    ~LinkedList();

    void display() const;
    void insert(int index, const T& data);
    void remove(int index);
    void middleNode1() const;
    void middleNode2() const;
    void middleNode3() const;
    int length() const;

    T sum();
    T maxValue();
    T minValue();
};

template <typename T>
LinkedList<T>::LinkedList(T* values, int length)
{
    if (length <= 0)
    {
        first = nullptr;
        return;
    }

    first = new Node(values[0]);
    Node* last = first;

    for(int i = 1; i < length; i++)
    {
        last->next = new Node(values[i]);
        last = last->next;
    }
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    while (first)
    {
        Node* toDelete = first;
        first = first->next;
        delete toDelete;
    }
}

template <typename T>
void LinkedList<T>::display() const
{
    Node* current = first;
    while(current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << '\n';
}

template <typename T>
void LinkedList<T>::insert(int index,const T& data)
{
    if(index < 0 || index > length()) return;

    Node* newNode = new Node(data);

    if(index == 0)
    {
        newNode->next = first;
        first = newNode;
    }
    else
    {
        Node* current = first;

        for(int i = 0; i < index - 1; i++)
            current = current->next;
        
        newNode->next = current->next;
        current->next = newNode;
    }
}

template <typename T>
void LinkedList<T>::remove(int index)
{
    if (index < 0 || first == nullptr || index >= length()) return;

    Node* toDelete = nullptr;

    if(index == 0)
    {
        toDelete = first;
        first = first->next;
    }
    else
    {
        Node* current = first;

        for(int i = 0; i < index - 1; i++)
            current = current->next;

        toDelete = current->next;
        current->next = toDelete->next;
    }
    delete toDelete;
}

template <typename T>
int LinkedList<T>::length() const
{
    int count = 0;
    Node* current = first;
    while (current)
    {
        count++;
        current = current->next;
    }
    return count;
}

template <typename T>
T LinkedList<T>::maxValue()
{
    Node* current = first;
    T max = current->data;

    while (current)
    {
        if(current->data > max)
            max = current->data;

        current = current->next;
    }
    return max;
}

template <typename T>
T LinkedList<T>::minValue()
{
    Node* current = first;
    T min = current->data;

    while (current)
    {
        if(current->data < min)
            min = current->data;

        current = current->next;
    }
    return min;
}

template <typename T>
T LinkedList<T>::sum()
{
    T total = T();
    Node* current = first;

    while (current)
    {
        total += current->data;
        current = current->next;
    }
    return total;
}

template<typename T>
void LinkedList<T>::middleNode1() const
{
    int middleNodeIndex = (int)ceil(length() / 2.0f) - 1;

    Node* current = first;
    for(int i = 0; i < middleNodeIndex; i++)
        current = current->next;

    T middleNodeValue = current->data;

    std::cout << "Middle Node Index: " << middleNodeIndex << '\n';
    std::cout << "Middle Node Value: " << middleNodeValue << '\n';
}

template<typename T>
void LinkedList<T>::middleNode2() const
{
    Node* p = first;
    Node* q = first;

    int index = 0;

    while (q)
    {
        q = q->next;
        if(q) q = q->next;
        if(q) 
        {
            p = p->next;
            index++;
        }
    }
    std::cout << "Middle Node Index: " << index << '\n';
    std::cout << "Middle Node Value: " << p->data << '\n';
}

template<typename T>
void LinkedList<T>::middleNode3() const
{
    std::stack<Node*> pilha;
    Node* current = first;
    while (current)
    {
        pilha.push(current);
        current = current->next;
    }
    
    int popLength = (int)floor(pilha.size() / 2.0f);
    while (popLength)
    {
        pilha.pop();
        popLength--;
    }
    std::cout << "Middle Node Value: " << pilha.top()->data << '\n';
}

#endif