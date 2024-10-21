// #include <iostream>
// using namespace std;
 
// // Sensor struct definition
// struct Sensor {
//     char type;
//     float distance;
//     float velocity;
// };
 
// // Function to get the Sensor object at the specified index
// Sensor& getSensorData(Sensor* sensorArray, int index) {
//     // Using pointer arithmetic to access the Sensor object at the specified index
//     return *(sensorArray + index);
// }
 
// int main() {
//     // Example usage
//     Sensor sensors[5] = {
//         {'R', 100.0f, 60.0f},
//         {'L', 150.0f, 55.0f},
//         {'U', 30.0f, 45.0f},
//         {'C', 200.0f, 50.0f},
//         {'I', 250.0f, 65.0f}
//     };
 
//     int index = 2;
    
//     // Accessing the Sensor at the specified index
//     Sensor& sensor = getSensorData(sensors, index);
 
//     cout << "Sensor at index " << index << ": " << endl;
//     cout << "Type: " << sensor.type << endl;
//     cout << "Distance: " << sensor.distance << " meters" << endl;
//     cout << "Velocity: " << sensor.velocity << " km/h" << endl;
 
//     return 0;
// }

#include <iostream>
using namespace std;

// RadarSensor struct definition
struct RadarSensor {
    char type;
    float distance;
    float velocity;
};

// Function to get the RadarSensor object at the specified index
const RadarSensor& getSensorData(RadarSensor* sensorArray, int sensorIndex) {
    // Using pointer arithmetic to access the RadarSensor object at the specified index
    return sensorArray[sensorIndex];
}

int main() {
    // Example usage
    RadarSensor sensors[5] = {
        {'R', 100.0f, 60.0f},
        {'L', 150.0f, 55.0f},
        {'U', 30.0f, 45.0f},
        {'C', 200.0f, 50.0f},
        {'I', 250.0f, 65.0f}
    };

    int sensorIndex = 2;

    // Accessing the RadarSensor at the specified index
    const RadarSensor& sensor = getSensorData(sensors, sensorIndex);

    cout << "Sensor at index " << sensorIndex << ": " << endl;
    cout << "Type: " << sensor.type << endl;
    cout << "Distance: " << sensor.distance << " meters" << endl;
    cout << "Velocity: " << sensor.velocity << " km/h" << endl;

    return 0;
}
