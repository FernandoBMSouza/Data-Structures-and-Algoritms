#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename T>
class Array
{
private:
    T* m_elements = nullptr;
    int m_size = 0;
    int m_length = 0;
    void swap(T* x, T* y);
public:
    Array(int size);
    ~Array();
    int getLength() { return m_length; }
    void display();
    void append(T value);
    void insert(int index, T value);
    void myDelete(int index);
    void set(int index, T value);
    void reverse();
    void reverseAux();
    void shiftLeft();
    void shiftRight();
    void rotateLeft();
    void rotateRight();
    void insertSorted(T value);
    void rearrange();
    bool isSorted();
    int linearSearch(T key);
    int binarySearch(T key);
    int recursiveBinarySearch(int low, int high, T key);
    float avg();
    T get(int index);
    T maximum();
    T minimum();
    T sum();
    T recursiveSum(int n);
    Array<T>* merge(Array<T>* other);
    Array<T>* intersection(Array<T>* other);
    Array<T>* difference(Array<T>* other);
    Array<T>* myUnion(Array<T>* other);
};

template<typename T>
Array<T>::Array(int size) : m_size(size), m_length(0)
{
    m_elements = new T[size];
}

template<typename T>
Array<T>::~Array()
{
    delete[] m_elements;
    m_elements = nullptr;
}

template<typename T>
void Array<T>::display()
{
    std::cout << "Elements: ";
    for(int i = 0; i < m_length; i++)
        std::cout << m_elements[i] << ' ';
    std::cout << '\n';
}

template<typename T>
void Array<T>::append(T value)
{
    if(m_length < m_size)
        m_elements[m_length++] = value;
}

template<typename T>
void Array<T>::insert(int index, T value)
{
    if(m_length >= m_size) return;
    if(index < 0 || index > m_length) return;

    for(int i = m_length; i > index; i--)
        m_elements[i] = m_elements[i-1];

    m_elements[index] = value;
    m_length++;
}

template<typename T>
void Array<T>::myDelete(int index)
{
    if(index >= m_length || index < 0) return;

    for(int i = index; i < m_length - 1; i++)
        m_elements[i] = m_elements[i+1];
    
    m_length--;
}

template<typename T>
void Array<T>::set(int index, T value)
{
    if(index >= 0 && index < m_length)
        m_elements[index] = value;
}

template<typename T>
void Array<T>::swap(T* x, T* y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}

template<typename T>
void Array<T>::reverseAux()
{
    // Using auxiliar array
    T* aux = new T[m_length];
    for(int i = 0, j = m_length - 1; j >= 0;i++, j--)
        aux[i] = m_elements[j];
    for(int i = 0; i < m_length; i++)
        m_elements[i] = aux[i];

    delete[] aux;
    aux = nullptr;
}

template<typename T>
void Array<T>::reverse()
{
    for(int i = 0, j = m_length - 1; i < j; i++, j--)
        swap(&m_elements[i], &m_elements[j]);
}

template<typename T>
void Array<T>::shiftLeft()
{
    if(m_length <= 1) return;
    for(int i = 0; i < m_length; i++)
        m_elements[i] = m_elements[i+1];
    m_elements[m_length-1] = 0;
}

template<typename T>
void Array<T>::shiftRight()
{
    if(m_length <= 1) return;
    for(int i = m_length - 1; i > 0; i--)
        m_elements[i] = m_elements[i-1]; 
    m_elements[0] = 0;
}

template<typename T>
void Array<T>::rotateLeft()
{
    if(m_length <= 1) return;
    int temp = m_elements[0];
    for(int i = 0; i < m_length; i++)
        m_elements[i] = m_elements[i+1];
    m_elements[m_length-1] = temp;
}

template<typename T>
void Array<T>::rotateRight()
{
    if(m_length <= 1) return;
    int temp = m_elements[m_length-1];
    for(int i = m_length - 1; i > 0; i--)
        m_elements[i] = m_elements[i-1]; 
    m_elements[0] = temp;
}

template<typename T>
void Array<T>::insertSorted(T value)
{
    if(m_length >= m_size || !isSorted()) return;

    int i = m_length-1;
    while(i >= 0 && m_elements[i] > value)
    {
        m_elements[i+1] = m_elements[i];
        i--;
    }
    m_elements[i+1] = value;
    m_length++;
}

template<typename T>
void Array<T>::rearrange()
{
    //Positive right
    //Negative left

    int i = 0;
    int j = m_length-1;

    while(i < j)
    {
        while(m_elements[i] < 0) i++;
        while(m_elements[j] >= 0) j--;
        if(i < j) swap(&m_elements[i], &m_elements[j]);
    }
}

template<typename T>
bool Array<T>::isSorted()
{
    for(int i = 0; i < m_length-1; i++)
        if(m_elements[i] > m_elements[i+1]) return 0;
    return 1;   
}

template<typename T>
int Array<T>::linearSearch(T key)
{
    for(int i = 0; i < m_length; i ++)
    {
        if(m_elements[i] == key)
        {
            // Optimizations

            // 1. Transposition
            // swap(&m_elements[i], &m_elements[i-1]);
            // return i-1;

            // 2. Move to Front/Head
            // if(i > 0)
            // { 
            //     swap(&m_elements[i], &m_elements[0]);
            //     return 0;
            // }

            return i;
        }
    }
    return -1;
}

template<typename T>
int Array<T>::binarySearch(T key)
{
    if(!isSorted()) return -1;

    int low = 0;
    int high = m_length-1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(m_elements[mid] == key)     
            return mid;
        else if(m_elements[mid] > key) 
            high = mid - 1;
        else                       
            low = mid + 1;
    }
    return -1;
}

template<typename T>
int Array<T>::recursiveBinarySearch(int low, int high, T key)
{
    if(low <= high)
    {
        int mid = (low + high) / 2;

        if(m_elements[mid] == key)     
            return mid;
        else if(m_elements[mid] > key) 
            return recursiveBinarySearch(low, mid - 1, key);
        else                
            return recursiveBinarySearch(mid + 1, high, key);
    }
    return -1;
}

template<typename T>
T Array<T>::get(int index)
{
    if(index < 0 || index >= m_length) return -1;
    return m_elements[index];
}

template<typename T>
T Array<T>::maximum()
{
    T max = m_elements[0];
    for(int i = 1; i < m_length; i++)
    {
        if(m_elements[i] > max)
            max = m_elements[i];
    }
    return max;
}

template<typename T>
T Array<T>::minimum()
{
    T min = m_elements[0];
    for(int i = 1; i < m_length; i++)
    {
        if(m_elements[i] < min)
            min = m_elements[i];
    }
    return min;
}

template<typename T>
T Array<T>::sum()
{
    T total = 0;
    for(int i = 0; i < m_length; i++)
        total += m_elements[i];

    return total;
}

template<typename T>
T Array<T>::recursiveSum(int n)
{
    if (n <= 0)
        return 0;
    return m_elements[n-1] + recursiveSum(n-1);
}

template<typename T>
float Array<T>::avg()
{
    //if(length != 0)
    return (float)sum() / m_length;
}

template<typename T>
Array<T>* Array<T>::merge(Array<T>* other)
{
    if(!isSorted() || !other->isSorted()) return nullptr;

    Array<T>* out = new Array<T>(m_length + other->m_length);

    int i = 0;
    int j = 0;
    int k = 0;

    while(i < m_length && j < other->m_length)
    {
        if(m_elements[i] < other->m_elements[j]) 
            out->m_elements[k++] = m_elements[i++];
        else                        
            out->m_elements[k++] = other->m_elements[j++];
    }

    for(; i < m_length; i++)
        out->m_elements[k++] = m_elements[i];

    for(; j < other->m_length; j++)
        out->m_elements[k++] = other->m_elements[j];

    out->m_length = m_length + other->m_length;
    return out;
}

template<typename T>
Array<T>* Array<T>::myUnion(Array<T>* other)
{
    Array<T>* out = new Array<T>(m_length + other->m_length);

    int i = 0;
    int j = 0;
    int k = 0;
    
    if(isSorted() && other->isSorted())
    {
        while(i < m_length && j < other->m_length)
        {
            if(m_elements[i] < other->m_elements[j])
                out->m_elements[k++] = m_elements[i++];
            else if(m_elements[i] > other->m_elements[j])
                out->m_elements[k++] = other->m_elements[j++];
            else
            {
                out->m_elements[k++] = m_elements[i++];
                j++;
            }
        }

        for(; i < m_length; i++)
            out->m_elements[k++] = m_elements[i];

        for(; j < other->m_length; j++)
            out->m_elements[k++] = other->m_elements[j];
    }
    else
    {
        for(int i = 0; i < m_length; i++)
            out->m_elements[k++] = m_elements[i];
        
        for(int i = 0; i < other->m_length; i++)
            if(linearSearch(other->m_elements[i]) == -1)
                out->m_elements[k++] = other->m_elements[i];
    }

    out->m_length = k;
    return out;
}

template<typename T>
Array<T>* Array<T>::intersection(Array<T>* other)
{
    Array<T>* out = new Array<T>(m_length + other->m_length);

    int i = 0;
    int j = 0;
    int k = 0;
    
    if(isSorted() && other->isSorted())
    {
        while(i < m_length && j < other->m_length)
        {
            if(m_elements[i] < other->m_elements[j]) i++;
            else if(m_elements[i] > other->m_elements[j]) j++;
            else
            {
                out->m_elements[k++] = m_elements[i++];
                j++;
            }
        }
    }
    else
    {
        for(int i = 0; i < m_length; i++)
            if(other->linearSearch(m_elements[i]) != -1)
                out->m_elements[k++] = m_elements[i];
    }

    out->m_length = k;
    return out;
}

template<typename T>
Array<T>* Array<T>::difference(Array<T>* other)
{
    Array<T>* out = new Array<T>(m_length + other->m_length);

    int i = 0;
    int j = 0;
    int k = 0;
    
    if(isSorted() && other->isSorted())
    {
        while(i < m_length && j < other->m_length)
        {
            if(m_elements[i] < other->m_elements[j])
                out->m_elements[k++] = m_elements[i++];
            else if(m_elements[i] > other->m_elements[j])
                j++;
            else
            {
                i++;
                j++;
            }
        }

        for(; i < m_length; i++)
            out->m_elements[k++] = m_elements[i];
    }
    else
    {
        for(int i = 0; i < m_length; i++)
            if(other->linearSearch(m_elements[i]) == -1)
                out->m_elements[k++] = m_elements[i];
    }

    out->m_length = k;
    return out;
}

#endif