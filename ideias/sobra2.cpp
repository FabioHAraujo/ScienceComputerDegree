#include <iostream>

int main ()
{
    int div, expo;
    std::cin >> div;
    std::cin >> expo;
    while (div >= expo)
    {
        div = div - expo;
    }
    std::cout << div;
    return 0;
}