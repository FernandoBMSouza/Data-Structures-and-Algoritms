#include <iostream>
#include <string>

int main()
{
    std::cout << "How many cars do you have? ";
    int numberOfCars = 0;
    std::cin >> numberOfCars;
    std::cin.ignore();

    std::string* pCars = new std::string[numberOfCars];

    for(int i = 0; i < numberOfCars; i++)
    {
        std::cout << "Enter car #" << i + 1 << ": ";
        getline(std::cin, pCars[i]);
    }

    std::cout << "\nHere is your garage!\n";
    std::cout << "---------------------\n";
    for(int i = 0; i < numberOfCars; i++)
    {
        std::cout << "Parking spot #" << i + 1 << ": " << pCars[i] << '\n';
    }

    delete[] pCars;

    std::cout << '\n';
    std::cin.get();
    return 0;
}