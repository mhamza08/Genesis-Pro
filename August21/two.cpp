// #include <iostream>
// using namespace std;
 
// class FuelTank {
// private:
//     double capacity;
//     double fuelLevel;
 
// public:
//     // Constructor to initialize the fuel tank with a capacity
//     FuelTank(double tankCapacity) {
//         capacity = tankCapacity;
//         fuelLevel = 0; // Tank starts empty
//     }
 
//     // Method to fill the tank with a specified amount of fuel
//     void fillTank(double amount) {
//         if (amount < 0) {
//             cout << "Cannot add negative fuel!" << endl;
//             return;
//         }
 
//         if (fuelLevel + amount > capacity) {
//             fuelLevel = capacity;
//             cout << "Tank is full. Excess fuel spilled." << endl;
//         } else {
//             fuelLevel += amount;
//             cout << "Added " << amount << " liters of fuel to the tank. ";
//         }
//         displayFuelLevel();
//     }
 
//     // Method to simulate fuel consumption
//     void consumeFuel(double amount) {
//         if (amount < 0) {
//             cout << "Cannot consume negative fuel!" << endl;
//             return;
//         }
 
//         if (fuelLevel - amount < 0) {
//             fuelLevel = 0;
//             cout << "Fuel tank is empty!" << endl;
//         } else {
//             fuelLevel -= amount;
//             cout << "Consumed " << amount << " liters of fuel. ";
//         }
//         displayFuelLevel();
 
//         // Display warning if fuel level is below 10 liters
//         if (fuelLevel < 10) {
//             cout << "Warning: Fuel level is below 10 liters!" << endl;
//         }
//     }
 
//     // Method to display the current fuel level as a percentage
//     void displayFuelLevel() {
//         double percentage = (fuelLevel / capacity) * 100;
//         cout << "Current fuel level: " << fuelLevel << " liters (" << percentage << "%)" << endl;
//     }
// };
 
// int main() {
//     double capacity, amount;
    
//     cout << "Enter the fuel tank capacity (liters): ";
//     cin >> capacity;
 
//     FuelTank myTank(capacity);
 
//     int choice;
//     do {
//         cout << "\nChoose an option:" << endl;
//         cout << "1. Fill the tank" << endl;
//         cout << "2. Consume fuel" << endl;
//         cout << "3. Display fuel level" << endl;
//         cout << "4. Exit" << endl;
//         cout << "Enter your choice: ";
//         cin >> choice;
 
//         switch (choice) {
//         case 1:
//             cout << "Enter the amount of fuel to add (liters): ";
//             cin >> amount;
//             myTank.fillTank(amount);
//             break;
//         case 2:
//             cout << "Enter the amount of fuel to consume (liters): ";
//             cin >> amount;
//             myTank.consumeFuel(amount);
//             break;
//         case 3:
//             myTank.displayFuelLevel();
//             break;
//         case 4:
//             cout << "Exiting the program." << endl;
//             break;
//         default:
//             cout << "Invalid choice! Please try again." << endl;
//             break;
//         }
//     } while (choice != 4);
 
//     return 0;
// }

#include <iostream>
using namespace std;

class FuelTank {
private:
    double capacity;
    double fuelLevel;

public:
    // Constructor to initialize the fuel tank with a capacity
    explicit FuelTank(double tankCapacity) : capacity(tankCapacity), fuelLevel(0.0) {
        // Ensure that capacity is a valid positive number
        if (tankCapacity < 0) {
            capacity = 0.0;
        }
    }

    // Method to fill the tank with a specified amount of fuel
    void fillTank(double amount) {
        if (amount < 0) {
            cout << "Cannot add negative fuel!" << endl;
        } else {
            if ((fuelLevel + amount) > capacity) {
                fuelLevel = capacity;
                cout << "Tank is full. Excess fuel spilled." << endl;
            } else {
                fuelLevel += amount;
                cout << "Added " << amount << " liters of fuel to the tank. ";
            }
            displayFuelLevel();
        }
    }

    // Method to simulate fuel consumption
    void consumeFuel(double amount) {
        if (amount < 0) {
            cout << "Cannot consume negative fuel!" << endl;
        } else {
            if ((fuelLevel - amount) < 0) {
                fuelLevel = 0.0;
                cout << "Fuel tank is empty!" << endl;
            } else {
                fuelLevel -= amount;
                cout << "Consumed " << amount << " liters of fuel. ";
            }
            displayFuelLevel();

            // Display warning if fuel level is below 10 liters
            if (fuelLevel < 10.0) {
                cout << "Warning: Fuel level is below 10 liters!" << endl;
            }
        }
    }

    // Method to display the current fuel level as a percentage
    void displayFuelLevel() const {
        double percentage = (fuelLevel / capacity) * 100.0;
        cout << "Current fuel level: " << fuelLevel << " liters (" << percentage << "%)" << endl;
    }
};

int main() {
    double capacity = 0.0;
    double amount = 0.0;
    int choice = 0;

    cout << "Enter the fuel tank capacity (liters): ";
    cin >> capacity;

    FuelTank myTank(capacity);

    do {
        cout << "\nChoose an option:" << endl;
        cout << "1. Fill the tank" << endl;
        cout << "2. Consume fuel" << endl;
        cout << "3. Display fuel level" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the amount of fuel to add (liters): ";
            cin >> amount;
            myTank.fillTank(amount);
            break;
        case 2:
            cout << "Enter the amount of fuel to consume (liters): ";
            cin >> amount;
            myTank.consumeFuel(amount);
            break;
        case 3:
            myTank.displayFuelLevel();
            break;
        case 4:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
