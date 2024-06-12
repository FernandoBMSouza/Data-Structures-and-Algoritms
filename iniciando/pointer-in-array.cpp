#include <iostream>

int main()
{
    int example[] = { 1,2,3,4,5 };

    //example[3] = 9;
    *(example + 3) = 9;

    for(auto i : example)
        std::cout << i << ' ';

    std::cin.get();
    std::cout << '\n';

    return 0;
}