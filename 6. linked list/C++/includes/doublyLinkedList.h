#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

template <typename T>
class DoublyLinkedList
{
private:
    struct Node
    {
        Node* previous;
        T data;
        Node* next;
        Node(Node* previous, T data, Node* next) :  previous(previous), data(data), next(next) {}
    };
    Node* head;
public:
    DoublyLinkedList(T* values, int length);
    ~DoublyLinkedList();
    void display() const;
    int length() const;
    void insert(int index, const T& data);
    void remove(int index);
    void reverse();
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(T* values, int length)
{
    if (length <= 0)
    {
        head = nullptr;
        return;
    }

    head = new Node(nullptr, values[0], nullptr);
    Node* tail = head;

    for (int i = 1; i < length; i++)
    {
        tail->next = new Node(tail, values[i], nullptr);
        tail = tail->next;
    }  
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while (head)
    {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }
}

template <typename T>
void DoublyLinkedList<T>::display() const
{
    Node* current = head;
    while(current)
    {
        std::cout << current->data << ' ';
        current = current->next;
    }
    std::cout<<'\n';
}

template <typename T>
int DoublyLinkedList<T>::length() const
{
    int count = 0;
    Node* current = head;
    while(current)
    {
        count++;
        current = current->next;
    }
    return count;
}

template <typename T>
void DoublyLinkedList<T>::insert(int index, const T& data)
{
    if(index < 0 || index > length()) return;

    if(index == 0)
    {
        head = new Node(nullptr, data, head);
        if (head->next) 
            head->next->previous = head;
    }
    else
    {
        Node* current = head;
        for (int i = 0; i < index - 1; i++)
            current = current->next;

        Node* newNode = new Node(current, data, current->next);
        if (current->next) current->next->previous = newNode;
        current->next = newNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::remove(int index)
{
    if (index < 0 || head == nullptr || index >= length()) return;

    Node* toDelete = nullptr;

    if(index == 0)
    {
        toDelete = head;
        head = head->next;
        if(head) head->previous = nullptr;
    }
    else
    {
        Node* current = head;

        for(int i = 0; i < index - 1; i++)
            current = current->next;

        toDelete = current->next;
        current->next = toDelete->next;
        if(toDelete->next) toDelete->next->previous = current;
    }
    delete toDelete;
}

template <typename T>
void DoublyLinkedList<T>::reverse()
{
    Node* current = head;
    Node* temp = nullptr;

    while(current)
    {
        temp = current->next;
        current->next = current->previous;
        current->previous = temp;

        current = current->previous;
        if(current && current->next == nullptr) head = current;
    }
}

#endif