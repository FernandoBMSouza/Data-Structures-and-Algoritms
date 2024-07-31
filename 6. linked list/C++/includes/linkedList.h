#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

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
    int length() const;
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

#endif