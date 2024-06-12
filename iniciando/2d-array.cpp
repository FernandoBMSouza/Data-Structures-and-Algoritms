#include <iostream>

int main()
{
    std::cout << "Array in Stack\n";

    int arr[3][4] = 
    {
        {1,2,3,4},
        {2,4,6,8},
        {3,6,9,12},
    };

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "\nArray in Heap\n";
    std::cout << "Using pointer array in stack:\n";

    int* arr1[3];
    // arr1[0] = new int[4];
    // arr1[1] = new int[4];
    // arr1[2] = new int[4];
    for(int i = 0; i < 3; i++)
        arr1[i] = new int[4];

    arr1[0][0] = 1;
    arr1[0][1] = 2;
    arr1[0][2] = 3;
    arr1[0][3] = 4;

    arr1[1][0] = 2;
    arr1[1][1] = 4;
    arr1[1][2] = 6;
    arr1[1][3] = 8;

    arr1[2][0] = 3;
    arr1[2][1] = 6;
    arr1[2][2] = 9;
    arr1[2][3] = 12;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            std::cout << arr1[i][j] << ' ';
        }
        std::cout << '\n';
    }

    for(int i = 0; i < 3; i++)
    {
        delete[] arr1[i];
        arr1[i] = nullptr;
    }

    std::cout << "\nUsing pointer array in heap:\n";

    int** arr2 = new int*[3];
    // arr2[0] = new int [4];
    // arr2[1] = new int [4];
    // arr2[2] = new int [4];
    for(int i = 0; i < 3; i++)
        arr2[i] = new int[4];

    arr2[0][0] = 1;
    arr2[0][1] = 2;
    arr2[0][2] = 3;
    arr2[0][3] = 4;

    arr2[1][0] = 2;
    arr2[1][1] = 4;
    arr2[1][2] = 6;
    arr2[1][3] = 8;

    arr2[2][0] = 3;
    arr2[2][1] = 6;
    arr2[2][2] = 9;
    arr2[2][3] = 12;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            std::cout << arr2[i][j] << ' ';
        }
        std::cout << '\n';
    }

    for(int i = 0; i < 3; i++)
    {
        delete[] arr2[i];
        arr2[i] = nullptr;
    }

    delete[] arr2;
    arr2 = nullptr;

    return 0;
}