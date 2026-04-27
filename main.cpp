// COMSC-210 | Lab 32 | Johnathan Perez Baltazar
#include <iostream>
#include <deque>
#include "Car.h"
#include <array>
using namespace std;

const int INITIAL_SIZE = 2, LANES = 4;
const int PAY_PROB = 50, JOIN_PROB = 50;

void printQueue(const array<deque<Car>, LANES>&);
bool tollLineEmpty(const array<deque<Car>, LANES>&);

/**
 * @brief Simulation of a toll booth by using a deque to manage the queue of cars.
 * @return 
*/
int main() {
    srand(time(0)); // Seed the random number generator

    // Create a deque and populate it with Car objects
    array<deque<Car>, LANES> tollLanes; // Array of 4 deques for 4 toll lanes
    for (int i = 0; i < INITIAL_SIZE; i++) {
        for (int lane = 0; lane < tollLanes.size(); lane++) {
            tollLanes[lane].push_back(Car());
        }
    }

    // print the initial state of each toll lane
    cout << "Initial queue:" << endl;
    for (int lane = 0; lane < tollLanes.size(); lane++) {
        cout << "Lane " << lane + 1 << ":\n";
        for (Car c : tollLanes[lane]) {
            cout << "   ";
            c.print();
        }
    }

    int i = 1; // Counter for the number of iterations
    while(!tollLineEmpty(tollLanes)){
        int p = rand() % 100; // Generate a random number between 0 and 99
        
        cout << "Time: " << i << endl;
        for (int lane = 0; lane < tollLanes.size(); lane++) {
            auto& tollLine = tollLanes[lane]; // Reference to the current lane's deque

            if (p < PAY_PROB) {
                cout << "Lane: " << lane + 1 << " Paid: ";
                tollLine.front().print(); // Print the front car that is paying
                tollLine.pop_front(); // Remove the front car from the deque
                ++i;

            } else {
                cout << "Lane: " << lane + 1 << " Joined: ";
                tollLine.back().print(); // Print the front car that is paying
                tollLine.push_back(Car()); // Add a new car to the back of the deque
                ++i;
            }
        }
        // Print remaining cars in the queue
        printQueue(tollLanes);
    }
    cout << "   All lanes are empty\n";

    return 0;
}

void printQueue(const array<deque<Car>, LANES>& tollLanes) {
    for (int lane = 0; lane < tollLanes.size(); lane++) {
        cout << "Lane: " << lane + 1 << ":\n";
        if (tollLanes[lane].empty()) {
            cout << "   Empty\n";
        } else {
            for (Car c : tollLanes[lane]) {
                cout << "   ";
                c.print();
            }
        }
    }
}

bool tollLineEmpty(const array<deque<Car>, LANES>& tollLanes) {
    for (const auto& lane : tollLanes) {
        if (!lane.empty()) {
            return false; // At least one lane has cars
        }
    }
    return true; // All lanes are empty
}