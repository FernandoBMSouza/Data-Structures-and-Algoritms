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
            std::cout << i << '(' << hash.get(i) << ") ";
}

void findDuplicates(Array<int>* arr)
{
    std::cout<<"Duplicates: ";
    for(int i = 0; i < arr->getLength()-1; i++)
    {
        int count = 1;
        if(arr->get(i) != -1)
        {
            for(int j = i+1; j < arr->getLength(); j++)
            {
                if(arr->get(i) == arr->get(j))
                {
                    count++;
                    arr->set(j, -1);
                }
            }
            if(count > 1) std::cout << arr->get(i) << "(" << count << ") ";
        }
    }
}

void findDuplicatesHashing(Array<int>* arr)
{
    Array<int> hash(arr->maximum()+1);

    for(int i = 0; i < arr->maximum()+1; i++)
        hash.insert(i, 0);
    
    for(int i = 0; i < arr->getLength(); i++)
        hash.set(arr->get(i), hash.get(arr->get(i)) + 1);

    std::cout << "Duplicated Elements: ";
    for(int i = arr->minimum(); i < hash.getLength(); i++)
        if(hash.get(i) > 1)
            std::cout << i << '(' << hash.get(i) << ") ";
}

void findPairWithSumK(Array<int>* arr, int k)
{
    for(int i = 0; i < arr->getLength()-1; i++)
        for(int j = i+1; j < arr->getLength(); j++)
            if(arr->get(i) + arr->get(j) == k)
                std::cout<<arr->get(i)<<" + "<<arr->get(j)<<" = "<<k<<'\n';
}

void findPairWithSumKHashing(Array<int>* arr, int k)
{
    Array<int> hash(arr->maximum()+1);

    for(int i = 0; i < arr->maximum()+1; i++)
        hash.insert(i, 0);

    std::cout << "Pairs:\n";
    for(int i = 0; i < arr->getLength(); i++)
    {
        if(hash.get(k - arr->get(i)) > 0)
            std::cout<<arr->get(i)<<" + "<<k - arr->get(i)<<" = "<<k<<'\n';

        hash.set(arr->get(i), hash.get(arr->get(i)) + 1);
    }
}

void findPairWithSumKInSortedArray(Array<int>* arr, int k)
{
    if(!arr->isSorted()) return;

    for(int i = 0, j = arr->getLength() - 1; i < j; )
    {
        if(arr->get(i) + arr->get(j) > k) j--;
        else if(arr->get(i) + arr->get(j) < k) i++;
        else 
        {
            std::cout << arr->get(i) << " + " << arr->get(j) << " = " << k << '\n';
            i++;
            j--;
        }
    }
}

void findMaxAndMin(Array<int>* arr)
{
    int max = arr->get(0);
    int min = arr->get(0);

    for(int i = 1; i < arr->getLength(); i++)
    {
        if(arr->get(i) < min) min = arr->get(i);
        else if(arr->get(i) > max) max = arr->get(i);
    }

    std::cout << "Max = " << max << '\n';
    std::cout << "Min = " << min << '\n';
}
