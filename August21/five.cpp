// #include <iostream>
// using namespace std;
 
// // Function to calculate the fuel injection duration
// float calculateFuelInjectionDuration(int engineRPM, int throttlePosition, float airFuelRatio) {
//     return (engineRPM / 100.0f) * (throttlePosition / 10.0f) * airFuelRatio;
// }
 
// // Function to get the ignition timing using the lookup table
// int getIgnitionTiming(int engineRPM, int throttlePosition) {
//     const int ignitionTimingMap[5][5] = {
//         {10, 12, 15, 18, 20},  // RPM 1000
//         {12, 15, 18, 22, 25},  // RPM 1500
//         {15, 18, 22, 25, 28},  // RPM 2000
//         {18, 22, 25, 28, 30},  // RPM 2500
//         {20, 25, 28, 30, 32}   // RPM 3000
//     };
 
//     int rpmIndex, throttleIndex;
 
//     // Determine the index for RPM
//     switch (engineRPM) {
//         case 1000: rpmIndex = 0; break;
//         case 1500: rpmIndex = 1; break;
//         case 2000: rpmIndex = 2; break;
//         case 2500: rpmIndex = 3; break;
//         case 3000: rpmIndex = 4; break;
//         default: return -1;  // Invalid RPM value
//     }
 
//     // Ensure throttle position index is within bounds
//     if (throttlePosition < 0 || throttlePosition > 4) {
//         return -1;  // Invalid throttle position
//     } else {
//         throttleIndex = throttlePosition;
//     }
 
//     return ignitionTimingMap[rpmIndex][throttleIndex];
// }
 
// // Function to monitor engine speed and return a safe or warning status
// bool monitorEngineSpeed(int engineRPM) {
//     const int thresholdRPM = 6000;
//     return engineRPM <= thresholdRPM;
// }
 
// int main() {
//     int engineRPM, throttlePosition;
//     float airFuelRatio;
 
//     // User inputs
//     cout << "Enter engine speed (RPM): ";
//     cin >> engineRPM;
//     cout << "Enter throttle position (%): ";
//     cin >> throttlePosition;
//     cout << "Enter air-fuel ratio (0-1): ";
//     cin >> airFuelRatio;
 
//     // Calculate fuel injection duration
//     float fuelInjectionDuration = calculateFuelInjectionDuration(engineRPM, throttlePosition, airFuelRatio);
//     cout << "Fuel injection duration: " << fuelInjectionDuration << " milliseconds" << endl;
 
//     // Get ignition timing
//     int ignitionTiming = getIgnitionTiming(engineRPM, throttlePosition / 20);
//     if (ignitionTiming != -1) {
//         cout << "Ignition timing: " << ignitionTiming << " degrees" << endl;
//     } else {
//         cout << "Invalid input for engine RPM or throttle position!" << endl;
//     }
 
//     // Monitor engine speed
//     bool isEngineSpeedSafe = monitorEngineSpeed(engineRPM);
//     if (isEngineSpeedSafe) {
//         cout << "Engine speed: Safe" << endl;
//     } else {
//         cout << "Engine speed: Warning" << endl;
//     }
 
//     return 0;
// }

#include <iostream>
using namespace std;

// Function to calculate the fuel injection duration
float calculateFuelInjectionDuration(int engineRPM, int throttlePosition, float airFuelRatio) {
    float rpmFactor = engineRPM / 100.0f;
    float throttleFactor = throttlePosition / 10.0f;
    float fuelInjectionDuration = rpmFactor * throttleFactor * airFuelRatio;
    
    return fuelInjectionDuration;
}

// Function to get the ignition timing using the lookup table
int getIgnitionTiming(int engineRPM, int throttlePositionPercentage) {
    const int ignitionTimingMap[5][5] = {
        {10, 12, 15, 18, 20},  // RPM 1000
        {12, 15, 18, 22, 25},  // RPM 1500
        {15, 18, 22, 25, 28},  // RPM 2000
        {18, 22, 25, 28, 30},  // RPM 2500
        {20, 25, 28, 30, 32}   // RPM 3000
    };

    int rpmIndex = -1;
    int throttleIndex = throttlePositionPercentage / 20;

    // Determine the index for RPM
    if (engineRPM == 1000) {
        rpmIndex = 0;
    } else if (engineRPM == 1500) {
        rpmIndex = 1;
    } else if (engineRPM == 2000) {
        rpmIndex = 2;
    } else if (engineRPM == 2500) {
        rpmIndex = 3;
    } else if (engineRPM == 3000) {
        rpmIndex = 4;
    }

    if (rpmIndex == -1 || throttleIndex < 0 || throttleIndex >= 5) {
        return -1;  // Invalid input
    }

    int ignitionTiming = ignitionTimingMap[rpmIndex][throttleIndex];
    return ignitionTiming;
}

// Function to monitor engine speed and return a safe or warning status
bool monitorEngineSpeed(int engineRPM) {
    const int thresholdRPM = 6000;
    bool isSafe = (engineRPM <= thresholdRPM);
    
    return isSafe;
}

int main() {
    int engineRPM, throttlePosition;
    float airFuelRatio;

    // User inputs
    cout << "Enter engine speed (RPM): ";
    cin >> engineRPM;
    cout << "Enter throttle position (%): ";
    cin >> throttlePosition;
    cout << "Enter air-fuel ratio (0-1): ";
    cin >> airFuelRatio;

    // Calculate fuel injection duration
    float fuelInjectionDuration = calculateFuelInjectionDuration(engineRPM, throttlePosition, airFuelRatio);
    cout << "Fuel injection duration: " << fuelInjectionDuration << " milliseconds" << endl;

    // Get ignition timing
    int ignitionTiming = getIgnitionTiming(engineRPM, throttlePosition / 20);
    if (ignitionTiming != -1) {
        cout << "Ignition timing: " << ignitionTiming << " degrees" << endl;
    } else {
        cout << "Invalid input for engine RPM or throttle position!" << endl;
    }

    // Monitor engine speed
    bool isEngineSpeedSafe = monitorEngineSpeed(engineRPM);
    if (isEngineSpeedSafe) {
        cout << "Engine speed: Safe" << endl;
    } else {
        cout << "Engine speed: Warning" << endl;
    }

    return 0;
}
