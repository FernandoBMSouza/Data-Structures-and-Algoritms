#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <iostream>

template <typename T>
class CircularLinkedList
{
private:   
    struct Node
    {
        T data;
        Node* next;
        Node(T data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* head;
    
public:
    CircularLinkedList(T* values, int length);
    ~CircularLinkedList();
    int length() const;
    void display() const;
    void insert(int index, const T& data);
    void remove(int index);
};

template <typename T>
CircularLinkedList<T>::CircularLinkedList(T* values, int length)
{
    if (length <= 0) 
    {
        head = nullptr;
        return;
    }

    head = new Node(values[0]);
    head->next = head;
    Node* last = head;

    for(int i = 1; i < length; i++)
    {
        last->next = new Node(values[i]);
        last = last->next;
        last->next = head;
    }
}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList()
{
    if (head == nullptr) return;

    Node* current = head;
    Node* nextNode = nullptr;

    do
    {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != head);

    head = nullptr;
}

template <typename T>
int CircularLinkedList<T>::length() const
{
    int count = 0;
    Node* current = head;
    do
    {
        count++;
        current = current->next;
    } while (current!=head);
    return count;
}

template <typename T>
void CircularLinkedList<T>::display() const
{
    Node* current = head;
    do
    {
        std::cout << current->data << ' ';
        current = current->next;
    } while (current != head);
    std::cout<<'\n';
}

template <typename T>
void CircularLinkedList<T>::insert(int index,const T& data)
{
    if(index < 0 || index > length()) return;

    Node* newNode = new Node(data);

    if(index == 0)
    {
        if (head == nullptr)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node* current = head;
            while (current->next != head)
                current = current->next;
            
            current->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }
    else
    {
        Node* current = head;
        for(int i = 0; i < index - 1; i++)
            current = current->next;
        
        newNode->next = current->next;
        current->next = newNode;
    }
}

template <typename T>
void CircularLinkedList<T>::remove(int index)
{
    if (index < 0 || head == nullptr || index >= length()) return;

    Node* toDelete = nullptr;

    if(index == 0)
    {
        toDelete = head;

        if (head->next == head)  
        {
            head = nullptr;
        }
        else
        {
            Node* current = head;
            while (current->next != head)
            {
                current = current->next;
            }
            current->next = head->next;
            head = head->next;
        }
    }
    else
    {
        Node* current = head;

        for(int i = 0; i < index - 1; i++)
            current = current->next;

        toDelete = current->next;
        current->next = toDelete->next;
    }
    delete toDelete;
}

#endif