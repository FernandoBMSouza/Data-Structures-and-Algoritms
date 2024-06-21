#include "challenges.h"
#include <iostream>

void findSingleMissingElement(Array<int>* arr)
{
    if(!arr->isSorted()) return;

    int low = arr->get(0);
    int diff = low - 0;

    for(int i = 0; i < arr->getLength(); i++)
    {
        if(arr->get(i) - i != diff)
        {
            std::cout << "Missing Element: " << i + diff << '\n';
            break;
        }
    }
}

void findMultipleMissingElements(Array<int>* arr)
{
    if(!arr->isSorted()) return;

    int low = arr->get(0);
    int diff = low - 0;

    std::cout << "Missing Elements: "; 
    for(int i = 0; i < arr->getLength(); i++)
    {
        if(arr->get(i) - i != diff)
        {
            while(diff < arr->get(i) - i)
            {
                std::cout << i + diff << ' ';
                diff++;
            }
        }
    }
}

void findMultipleMissingElementsHashing(Array<int>* arr)
{
    Array<int> hash(arr->maximum());

    for(int i = 0; i < arr->maximum(); i++)
        hash.insert(i, 0);
    
    for(int i = 0; i < arr->getLength(); i++)
        hash.set(arr->get(i), hash.get(arr->get(i)) + 1);

    std::cout << "Missing Elements: ";
    for(int i = arr->minimum(); i < hash.getLength(); i++)
        if(hash.get(i) == 0)
            std::cout << i << ' ';
}

void findDuplicatesInSortedArray(Array<int>* arr)
{
    if(!arr->isSorted()) return;

    std::cout << "Duplicates: ";
    for(int i = 0; i < arr->getLength(); i++)
    {
        if(arr->get(i) == arr->get(i+1))
        {
            int j = i+1;
            while(arr->get(i) == arr->get(j)) j++;
            std::cout << arr->get(i) << " (" << j-i << ") ";
            i = j-1;
        }
    }
}

void findDuplicatesInSortedArrayHashing(Array<int>* arr)
{
    Array<int> hash(arr->maximum());

    for(int i = 0; i < arr->maximum(); i++)
        hash.insert(i, 0);
    
    for(int i = 0; i < arr->getLength(); i++)
        hash.set(arr->get(i), hash.get(arr->get(i)) + 1);

    std::cout << "Duplicated Elements: ";
    for(int i = arr->minimum(); i < hash.getLength(); i++)
        if(hash.get(i) > 1)
            std::cout << i << " (" << hash.get(i) << ") ";
}

