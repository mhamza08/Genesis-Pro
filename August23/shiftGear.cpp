// #include <iostream>
// #include <vector>
// #include <cmath>
 
// using namespace std;
 
// struct TransmissionData {
//     int currentGear;
//     vector<double> gearRatios;
//     int targetGear;
// };
 
// int shiftGear(const TransmissionData& transmission, double speed, double throttlePosition, double rpm) {
//     int targetGear = transmission.currentGear;
 
//     // Determine the target gear based on speed
//     if (speed < 20) {
//         targetGear = 1;
//     } else if (speed >= 20 && speed < 40) {
//         targetGear = 2;
//     } else if (speed >= 40 && speed < 60) {
//         targetGear = 3;
//     } else if (speed >= 60) {
//         targetGear = 4;
//     }
 
//     // Adjust gear based on throttle position and RPM
//     if (throttlePosition > 50.0) {
//         targetGear = max(targetGear - 1, 1); // Downshift
//     }
//     if (rpm > 5000) {
//         targetGear = min(targetGear + 1, 4); // Upshift
//     }
 
//     return targetGear;
// }
 
// int main() {
//     TransmissionData transmission = {1, {3.0, 2.5, 1.8, 1.0}, 1};
//     double speed, throttlePosition, rpm;
 
//     cout << "Enter the car's initial speed (km/h): ";
//     cin >> speed;
//     cout << "Enter the car's throttle position (%): ";
//     cin >> throttlePosition;
//     cout << "Enter the car's engine RPM: ";
//     cin >> rpm;
 
//     const double timeStep = 0.1; // 0.1 second intervals
//     const int totalSteps = 100;  // 10 seconds simulation
 
//     for (int i = 0; i < totalSteps; ++i) {
//         transmission.targetGear = shiftGear(transmission, speed, throttlePosition, rpm);
 
//         // Display the transmission system's decision
//         cout << "Time: " << i * timeStep << "s, Speed: " << speed << " km/h, Throttle: "
//              << throttlePosition << "%, RPM: " << rpm << ", Target Gear: " << transmission.targetGear << endl;
 
//         // Simulate car dynamics (for simplicity, assume speed, throttle, and RPM remain constant)
//         speed += 0.5 * (rand() % 10 - 5); // Slight random fluctuation in speed
//         rpm += 100 * (rand() % 3 - 1);    // Slight random fluctuation in RPM
//         throttlePosition += 0.1 * (rand() % 5 - 2); // Slight random fluctuation in throttle
//     }
 
//     cout << "Final Car State:" << endl;
//     cout << "Speed: " << speed << " km/h, Throttle: " << throttlePosition << "%, RPM: " << rpm << ", Gear: " << transmission.targetGear << endl;
 
//     return 0;
// }

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Structure to hold transmission data
struct TransmissionData {
    int currentGear;
    vector<double> gearRatios;
    int targetGear;
};

// Function prototype for gear shifting logic
int shiftGear(const TransmissionData& transmission, double speed, double throttlePosition, double rpm);

// Function to determine the correct gear based on speed, throttle position, and RPM
int shiftGear(const TransmissionData& transmission, double speed, double throttlePosition, double rpm) {
    int targetGear = transmission.currentGear;

    // Determine the target gear based on speed
    if (speed < 20.0) {
        targetGear = 1;
    } else if (speed < 40.0) {
        targetGear = 2;
    } else if (speed < 60.0) {
        targetGear = 3;
    } else {
        targetGear = 4;  // speed >= 60
    }

    // Adjust gear based on throttle position and RPM
    if (throttlePosition > 50.0) {
        targetGear = max(targetGear - 1, 1); // Downshift
    } else if (rpm > 5000.0) {
        targetGear = min(targetGear + 1, 4); // Upshift
    }

    return targetGear;
}

int main() {
    TransmissionData transmission = {1, {3.0, 2.5, 1.8, 1.0}, 1};
    double speed;
    double throttlePosition;
    double rpm;

    cout << "Enter the car's initial speed (km/h): ";
    cin >> speed;
    cout << "Enter the car's throttle position (%): ";
    cin >> throttlePosition;
    cout << "Enter the car's engine RPM: ";
    cin >> rpm;

    const double timeStep = 0.1; // 0.1-second intervals
    const int totalSteps = 100;  // 10 seconds simulation

    for (int i = 0; i < totalSteps; ++i) {
        transmission.targetGear = shiftGear(transmission, speed, throttlePosition, rpm);

        // Display the transmission system's decision
        cout << "Time: " << (i * timeStep) << "s, Speed: " << speed << " km/h, Throttle: "
             << throttlePosition << "%, RPM: " << rpm << ", Target Gear: " << transmission.targetGear << endl;

        // Simulate car dynamics with slight random fluctuation
        speed += (0.5 * static_cast<double>(rand() % 10 - 5)); // Slight random fluctuation in speed
        rpm += (100.0 * static_cast<double>(rand() % 3 - 1));  // Slight random fluctuation in RPM
        throttlePosition += (0.1 * static_cast<double>(rand() % 5 - 2)); // Slight random fluctuation in throttle
    }

    cout << "Final Car State:" << endl;
    cout << "Speed: " << speed << " km/h, Throttle: " << throttlePosition << "%, RPM: " << rpm << ", Gear: " << transmission.targetGear << endl;

    return 0;
}
