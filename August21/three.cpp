// #include <iostream>
// using namespace std;
 
// // Sensor struct definition
// struct Sensor {
//     string type;
//     float distance;
//     float velocity;
// };
 
// // Function to calculate the average velocity
// float calculateAverageVelocity(Sensor* sensorArray, int numSensors) {
//     if (numSensors == 0) {
//         return 0.0f;  // Avoid division by zero
//     }
 
//     float totalVelocity = 0.0f;
 
//     // Iterate over the sensor array using pointer arithmetic
//     for (Sensor* ptr = sensorArray; ptr < sensorArray + numSensors; ++ptr) {
//         totalVelocity += ptr->velocity;
//     }
 
//     return totalVelocity / numSensors;
// }
 
// int main() {
//     // Example usage
//     Sensor sensors[5] = {
//         {"Radar", 100.0f, 60.0f},
//         {"Lidar", 150.0f, 55.0f},
//         {"Ultrasonic", 30.0f, 45.0f},
//         {"Camera", 200.0f, 50.0f},
//         {"Infrared", 250.0f, 65.0f}
//     };
 
//     int numSensors = 5;
 
//     float averageVelocity = calculateAverageVelocity(sensors, numSensors);
 
//     cout << "Average Velocity: " << averageVelocity << " km/h" << endl;
 
//     return 0;
// }

#include <iostream>
using namespace std;

// Sensor struct definition
struct Sensor {
    string type;
    float distance;
    float velocity;
};

// Function to calculate the average velocity
float calculateAverageVelocity(Sensor* sensorArray, int numSensors) {
    float averageVelocity = 0.0f;

    if (numSensors > 0) {
        float totalVelocity = 0.0f;

        // Iterate over the sensor array using pointer arithmetic
        for (int i = 0; i < numSensors; ++i) {
            totalVelocity += sensorArray[i].velocity;
        }

        averageVelocity = totalVelocity / static_cast<float>(numSensors);
    }

    return averageVelocity;
}

int main() {
    // Example usage
    Sensor sensors[5] = {
        {"Radar", 100.0f, 60.0f},
        {"Lidar", 150.0f, 55.0f},
        {"Ultrasonic", 30.0f, 45.0f},
        {"Camera", 200.0f, 50.0f},
        {"Infrared", 250.0f, 65.0f}
    };

    int numSensors = 5;

    float averageVelocity = calculateAverageVelocity(sensors, numSensors);

    cout << "Average Velocity: " << averageVelocity << " km/h" << endl;

    return 0;
}
