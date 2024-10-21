// #include <iostream>
// #include <vector>
 
// using namespace std;
 
// vector<float> kalmanFilterVelocity(const vector<float>& gpsSignals, float dt) {
//     size_t n = gpsSignals.size();
//     vector<float> velocities(n, 0.0);
 
//     // Kalman filter variables
//     float x_prev = 0;        // Previous position estimate
//     float v_prev = 0;        // Previous velocity estimate
//     float p_prev = 1;        // Previous estimate covariance
 
//     // Kalman filter tuning parameters
//     float process_noise = 0.1;  // Process noise covariance
//     float measurement_noise = 0.5;  // Measurement noise covariance
//     float estimation_error = 1;  // Initial estimation error
 
//     for (size_t i = 1; i < n; ++i) {
//         // Calculate the measurement difference (GPS position difference)
//         float measurement = gpsSignals[i] - gpsSignals[i - 1];
 
//         // Prediction step
//         float x_pred = x_prev + v_prev * dt;
//         float p_pred = p_prev + process_noise;
 
//         // Update step
//         float K = p_pred / (p_pred + measurement_noise);  // Kalman gain
//         x_prev = x_pred + K * (measurement - x_pred);  // Update position estimate
//         v_prev = (x_prev - gpsSignals[i - 1]) / dt;    // Update velocity estimate
//         p_prev = (1 - K) * p_pred;                    // Update covariance
 
//         // Store the velocity estimate
//         velocities[i] = v_prev;
//     }
 
//     return velocities;
// }
 
// int main() {
//     vector<float> gpsSignals = {123.456, 122.789, 121.234, 120.567, 119.890, 119.123, 118.456, 117.890};
//     float dt = 1.0;  // Time difference between measurements (assume 1 second)
 
//     vector<float> velocities = kalmanFilterVelocity(gpsSignals, dt);
 
//     cout << "GPS Signals: ";
//     for (float value : gpsSignals) {
//         cout << value << " ";
//     }
//     cout << endl;
 
//     cout << "Estimated Velocities: ";
//     for (float velocity : velocities) {
//         cout << velocity << " ";
//     }
//     cout << endl;
 
//     return 0;
// }

#include <iostream>
#include <vector>

using namespace std;

// Function prototype for Kalman filter velocity estimation
vector<float> kalmanFilterVelocity(const vector<float>& gpsSignals, float dt);

vector<float> kalmanFilterVelocity(const vector<float>& gpsSignals, float dt) {
    size_t n = gpsSignals.size();
    vector<float> velocities(n, 0.0f);

    // Kalman filter variables
    float x_prev = 0.0f;  // Previous position estimate
    float v_prev = 0.0f;  // Previous velocity estimate
    float p_prev = 1.0f;  // Previous estimate covariance

    // Kalman filter tuning parameters
    const float process_noise = 0.1f;  // Process noise covariance
    const float measurement_noise = 0.5f;  // Measurement noise covariance

    for (size_t i = 1; i < n; ++i) {
        // Calculate the measurement difference (GPS position difference)
        float measurement = gpsSignals[i] - gpsSignals[i - 1];

        // Prediction step
        float x_pred = x_prev + (v_prev * dt);
        float p_pred = p_prev + process_noise;

        // Update step
        float K = p_pred / (p_pred + measurement_noise);  // Kalman gain
        x_prev = x_pred + (K * (measurement - x_pred));  // Update position estimate
        v_prev = (x_prev - gpsSignals[i - 1]) / dt;    // Update velocity estimate
        p_prev = (1.0f - K) * p_pred;  // Update covariance

        // Store the velocity estimate
        velocities[i] = v_prev;
    }

    return velocities;
}

int main() {
    vector<float> gpsSignals = {123.456f, 122.789f, 121.234f, 120.567f, 119.890f, 119.123f, 118.456f, 117.890f};
    float dt = 1.0f;  // Time difference between measurements (assume 1 second)

    vector<float> velocities = kalmanFilterVelocity(gpsSignals, dt);

    cout << "GPS Signals: ";
    for (float value : gpsSignals) {
        cout << value << " ";
    }
    cout << endl;

    cout << "Estimated Velocities: ";
    for (float velocity : velocities) {
        cout << velocity << " ";
    }
    cout << endl;

    return 0;
}
