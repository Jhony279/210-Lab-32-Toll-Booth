// COMSC-210 | Lab 32 | Johnathan Perez Baltazar

#include <iostream>
#include <deque>
#include "Car.h"
using namespace std;

// Function Prototypes:

const int INITIAL_SIZE = 2;
const int PAY_PROB = 55, JOIN_PROB = 45;

/**
 * @brief - Description of main
 * @return 
*/
int main() {
    srand(time(0)); // Seed the random number generator

    // Create a deque and populate it with Car objects
    deque<Car> tollLine;
    for (int i = 0; i < INITIAL_SIZE; i++) {
        tollLine.push_back(Car());
    }

    // Print the initial deque
    cout << "Initial Deque:\n";
    for (Car c : tollLine) {
        c.print();
    }

    while(!tollLine.empty()){
        // Generate a random number between 0 and 99
        int p, j = rand() % 100;

        if (p < PAY_PROB) {
            tollLine.pop_front(); // Remove the front car from the deque
        }
        if (j < JOIN_PROB) {
            tollLine.push_back(Car()); // Add a new car to the back of the deque
        }
        
    }

    return 0;
}