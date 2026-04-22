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
    cout << "Initial queue:\n";
    for (Car c : tollLine) {
        cout << "   ";
        c.print();
    }

    while(!tollLine.empty()){
        int p = rand() % 100; // Generate a random number between 0 and 99
        int i = 1; // Counter for the number of iterations

        cout << "Time: " << i << " Operation: ";

        if (p < PAY_PROB) {
            cout << "Car Paid: ";
            tollLine.front().print(); // Print the front car that is paying
            tollLine.pop_front(); // Remove the front car from the deque
            i++;
        } else {
            cout << "Joined Lane: ";
            tollLine.back().print(); // Print the front car that is paying
            tollLine.push_back(Car()); // Add a new car to the back of the deque
            i++;
        }

    // Print ramining cars in the queue
    cout << "queue:\n";
    for (Car c : tollLine) {
        cout << "   ";
        c.print();
    }
    }

    return 0;
}