// COMSC-210 | Lab 32 | Johnathan Perez Baltazar

#include <iostream>
#include <deque>
#include "Car.h"
using namespace std;

// Function Prototypes:

/**
 * @brief - Description of main
 * @return 
*/
int main() {
    deque<Car> d = {Car(), Car()};

    // Print the initial deque
    cout << "Initial Deque:\n";
    for (Car c : d) {
        c.print();
    }

    return 0;
}