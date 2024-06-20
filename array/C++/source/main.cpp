#include "array.h"
#include <iostream>

int main()
{
    int option = 0;
    int x = 0;
    int index = 0;
    int size = 0;

    std::cout << "Enter array size: ";
    std::cin >> size;

    Array<int>* arr = new Array<int>(size);
    if (!arr) {
        std::cerr << "Failed to create array!\n";
        return 1;
    }

    // arr->append(1);
    // arr->append(2);
    // arr->append(3);
    // arr->append(4);
    // arr->append(5);

    do
    {
        std::cout << "\nMenu\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Delete\n";
        std::cout << "3. Search\n";
        std::cout << "4. Sum\n";
        std::cout << "5. Display\n";
        std::cout << "6. Exit\n";

        std::cout << "\nEnter your choice: ";
        std::cin >> option;

        switch(option)
        {
            case 1: 
                std::cout << "Enter element: ";
                std::cin >> x;

                std::cout << "Enter index: ";
                std::cin >> index;

                arr->insert(index,x);
            break;
            case 2: 
                std::cout << "Enter index: ";
                std::cin >> index;

                std::cout << "Deleted element is " << arr->get(index) << '\n';
                arr->myDelete(index);
            break;
            case 3:
                std::cout << "Enter element: ";
                std::cin >> x;

                index = arr->linearSearch(x);
                std::cout << "Element index: " << index;
            break;
            case 4: std:: cout << "Sum is " << arr->sum() << '\n'; break;
            case 5: arr->display(); break;
            case 6: 
                std::cout << "Exiting the program.\n";
            break;
            default: 
                std::cout << "Invalid option. Please try again." << std::endl;
            break;
        }
    }while(option != 6);

    delete arr;
    arr = nullptr;

    // Array<int>* mergedArray = arr1.merge(&arr2);
    // if (mergedArray) 
    // {
    //     mergedArray->display();
    //     delete mergedArray;
    //     mergedArray = nullptr;
    // }
    // std::cout << '\n';

    return 0;
}