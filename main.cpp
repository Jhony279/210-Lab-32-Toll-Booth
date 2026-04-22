// COMSC-210 | Lab 32 | Johnathan Perez Baltazar

#include <iostream>
#include <deque>
#include "Car.h"
using namespace std;

// Function Prototypes:

const int INITIAL_SIZE = 2;

/**
 * @brief - Description of main
 * @return 
*/
int main() {
    srand(time(0)); // Seed the random number generator

    // Create a deque and populate it with Car objects
    deque<Car> d;
    for (int i = 0; i < INITIAL_SIZE; i++) {
        d.push_back(Car());
    }

    // Print the initial deque
    cout << "Initial Deque:\n";
    for (Car c : d) {
        c.print();
    }

    return 0;
}