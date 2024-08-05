#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H

#include <iostream>

template <typename T>
class CircularDoublyLinkedList
{
private:
    struct Node
    {
        T data;
        Node* previous;
        Node* next;
        Node(T data, Node* previous = nullptr, Node* next = nullptr) : data(data), previous(previous), next(next) {}
    };
    Node* head;
public:
    CircularDoublyLinkedList(T* values, int length);
    ~CircularDoublyLinkedList();
    int length() const;
    void display() const;
    void insert(int index, T value);
    void remove(int index);
};

template <typename T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList(T* values, int length)
{
    if (length <= 0)
    {
        head = nullptr;
        return;
    }

    head = new Node(values[0]);
    head->previous = head;
    head->next = head;

    Node* current = head;

    for (int i = 1; i < length; i++)
    {
        current->next = new Node(values[i], current);
        current = current->next;
    }
    current->next = head;
    head->previous = current;
}

template <typename T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList()
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
int CircularDoublyLinkedList<T>::length() const
{
    int count = 0;
    Node* current = head;
    do
    {
        count++;
        current = current->next;
    } while (current != head);
    return count;
}

template <typename T>
void CircularDoublyLinkedList<T>::display() const
{
    Node* current = head;
    do
    {
        std::cout << current->data << ' ';
        current = current->next;
    } while (current != head);
    std::cout << '\n';
}

template <typename T>
void CircularDoublyLinkedList<T>::insert(int index, T value)
{
    if (index < 0 || index > length()) return;

    Node* newNode = new Node(value);

    if (index == 0)
    {
        if (head == nullptr)
        {
            newNode->next = newNode;
            newNode->previous = newNode;
        }
        else
        {
            newNode->next = head;
            newNode->previous = head->previous;

            head->previous->next = newNode;
            head->previous = newNode;
        }

        head = newNode;
    }
    else
    {
        Node* current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
            if (current == head) return;
        }

        newNode->previous = current;
        newNode->next = current->next;
        current->next->previous = newNode;
        current->next = newNode;
    }
}

template <typename T>
void CircularDoublyLinkedList<T>::remove(int index)
{
    if (index < 0 || index >= length() || head == nullptr) return;

    Node* toDelete = nullptr;

    if (index == 0)
    {
        if (head->next == head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            toDelete = head;
            head->previous->next = head->next;
            head->next->previous = head->previous;
            head = head->next;
            delete toDelete;
        }
    }
    else
    {
        Node* current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
            if (current == head) return;
        }

        toDelete = current->next;


        toDelete->next->previous = current;
        current->next = toDelete->next;

        delete toDelete;
    }
}

#endif