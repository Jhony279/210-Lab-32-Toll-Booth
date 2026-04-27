// COMSC-210 | Lab 32 | Johnathan Perez Baltazar
#include <iostream>
#include <deque>
#include "Car.h"
#include <array>
using namespace std;

const int INITIAL_SIZE = 2;
const int PAY_PROB = 55, JOIN_PROB = 45;

/**
 * @brief Simulation of a toll booth by using a deque to manage the queue of cars.
 * @return 
*/
int main() {
    srand(time(0)); // Seed the random number generator

    // Create a deque and populate it with Car objects
    // deque<Car> tollLine;
    array<deque<Car>, 4> tollLanes; // Array of 4 deques for 4 toll lanes

    for (int i = 0; i < INITIAL_SIZE; i++) {
        for (int lane = 0; lane < tollLanes.size(); lane++) {
            tollLanes[lane].push_back(Car());
        }
    }

    // print the initial state of each toll lane
    cout << "Initial queue" << endl;
    for (int lane = 0; lane < tollLanes.size(); lane++) {
        cout << "Lane " << lane + 1 << ":\n";
        for (Car c : tollLanes[lane]) {
            cout << "   ";
            c.print();
        }
    }

    // int i = 1; // Counter for the number of iterations
    // while(!tollLine.empty()){
    //     int p = rand() % 100; // Generate a random number between 0 and 99

    //     cout << "Time: " << i << " Operation: ";
    //     if (p < PAY_PROB) {
    //         cout << "Car Paid: ";
    //         tollLine.front().print(); // Print the front car that is paying
    //         tollLine.pop_front(); // Remove the front car from the deque
    //         ++i;

    //     } else {
    //         cout << "Joined Lane: ";
    //         tollLine.back().print(); // Print the front car that is paying
    //         tollLine.push_back(Car()); // Add a new car to the back of the deque
    //         ++i;
    //     }

    //     // Print remaining cars in the queue
    //     cout << "queue:\n";
    //     for (Car c : tollLine) {
    //         cout << "   ";
    //         c.print();
    //     }
    // }
    // cout << "   Empty\n";

    return 0;
}