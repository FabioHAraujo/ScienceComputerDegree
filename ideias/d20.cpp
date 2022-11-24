#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void roll(int number_of_rolls) {
    
    srand(time(NULL));
    for (int i = 0; i < number_of_rolls; i++) {
        cout << (rand() % 20 + 1) << endl;
    }
}


int main() {
        
    roll(3);

return 0;
}