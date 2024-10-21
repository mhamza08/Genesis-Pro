// #include <iostream>
// using namespace std;
 
// class Car {
// private:
//     int speed;
 
// public:
//     // Constructor to initialize the speed
//     Car(int initialSpeed = 0) {
//         if (initialSpeed < 0) {
//             speed = 0;
//         } else {
//             speed = initialSpeed;
//         }
//     }
 
//     // Method to accelerate the car
//     void accelerate(int amount) {
//         speed += amount;
//         cout << "Car accelerated by " << amount << " km/h. ";
//         displaySpeed();
//     }
 
//     // Method to brake the car
//     void brake(int amount) {
//         speed -= amount;
//         if (speed < 0) {
//             speed = 0;
//         }
//         cout << "Car slowed down by " << amount << " km/h. ";
//         displaySpeed();
//     }
 
//     // Method to display the current speed
//     void displaySpeed() {
//         cout << "Current speed: " << speed << " km/h" << endl;
//     }
 
//     // Method to set the initial speed
//     void setSpeed(int initialSpeed) {
//         if (initialSpeed < 0) {
//             speed = 0;
//         } else {
//             speed = initialSpeed;
//         }
//         cout << "Initial speed set to " << speed << " km/h" << endl;
//     }
// };
 
// int main() {
//     int speed, accelerateAmount, brakeAmount;
    
//     cout << "Enter the initial speed of the car: ";
//     cin >> speed;
 
//     Car myCar(speed);
 
//     int choice;
//     do {
//         cout << "\nChoose an option:" << endl;
//         cout << "1. Accelerate" << endl;
//         cout << "2. Brake" << endl;
//         cout << "3. Display Speed" << endl;
//         cout << "4. Exit" << endl;
//         cout << "Enter your choice: ";
//         cin >> choice;
 
//         switch (choice) {
//         case 1:
//             cout << "Enter the amount to accelerate (km/h): ";
//             cin >> accelerateAmount;
//             myCar.accelerate(accelerateAmount);
//             break;
//         case 2:
//             cout << "Enter the amount to brake (km/h): ";
//             cin >> brakeAmount;
//             myCar.brake(brakeAmount);
//             break;
//         case 3:
//             myCar.displaySpeed();
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

class Car {
private:
    int speed;

public:
    // Constructor to initialize the speed
    Car(int initialSpeed = 0) {
        if (initialSpeed < 0) {
            speed = 0;
        } else {
            speed = initialSpeed;
        }
    }

    // Method to accelerate the car
    void accelerate(const int amount) {
        speed += amount;
        cout << "Car accelerated by " << amount << " km/h. ";
        displaySpeed();
    }

    // Method to brake the car
    void brake(const int amount) {
        speed -= amount;
        if (speed < 0) {
            speed = 0;
        }
        cout << "Car slowed down by " << amount << " km/h. ";
        displaySpeed();
    }

    // Method to display the current speed
    void displaySpeed() const {
        cout << "Current speed: " << speed << " km/h" << endl;
    }
};

int main() {
    int initialSpeed = 0;
    int accelerateAmount = 0;
    int brakeAmount = 0;
    int choice = 0;

    cout << "Enter the initial speed of the car: ";
    cin >> initialSpeed;

    Car myCar(initialSpeed);

    do {
        cout << "\nChoose an option:" << endl;
        cout << "1. Accelerate" << endl;
        cout << "2. Brake" << endl;
        cout << "3. Display Speed" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the amount to accelerate (km/h): ";
            cin >> accelerateAmount;
            myCar.accelerate(accelerateAmount);
            break;
        case 2:
            cout << "Enter the amount to brake (km/h): ";
            cin >> brakeAmount;
            myCar.brake(brakeAmount);
            break;
        case 3:
            myCar.displaySpeed();
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
