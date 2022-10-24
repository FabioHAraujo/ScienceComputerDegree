#include <iostream>

int main() {

    int sizeArray = 5;
    int array[sizeArray];
    int m = sizeArray - 1;

    for (int n = 0; n < sizeArray; n++) {
        std::cin >> array[n];
    }

    for (int n = 0; n < sizeArray; n++) {
        std::cout << array[n] << " ";
    }
    std::cout << std::endl;


    for (int n = 0; n < sizeArray/2; n++) {
        int temp = array[n];
        array[n] = array[m];
        array[m] = temp;
        m--;
    }

    for (int n = 0; n < sizeArray; n++) {
        std::cout << array[n] << " ";
    }
    std::cout << std::endl;


}