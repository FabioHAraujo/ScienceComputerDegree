#include <iostream>

int main() {

    int sizeArray;
    std::cin >> sizeArray;
    int array[sizeArray];
    int m = sizeArray - 1;

    for (int n = 0; n < sizeArray; n++) {
        std::cin >> array[n];
    }

    for (int n = 0; n < sizeArray; n++) {
        std::cout << array[n] << " ";
    }
    std::cout << std::endl;


    int n = 0; 
    while (n < sizeArray/2) {
        int temp = array[n];
        array[n] = array[m];
        array[m] = temp;
        m--;
        n++;
    }

    for (int n = 0; n < sizeArray; n++) {
        std::cout << array[n] << " ";
    }
    std::cout << std::endl;


}