// #include <iostream>
// #include <vector>
 
// using namespace std;
 
// // Function to apply a 2nd-order Butterworth filter
// vector<float> butterworthFilter(const vector<float>& signal, float cutoffFrequency, float samplingRate) {
//     // Filter coefficients for a 2nd-order Butterworth filter
//     const float PI = 3.14159265359;
//     float wc = 2 * PI * cutoffFrequency / samplingRate;  // Angular cutoff frequency
//     float k1 = 1.41421356237 * wc;  // sqrt(2) * wc
//     float k2 = wc * wc;
 
//     // Coefficients for the difference equation
//     float a0 = k2 / (1 + k1 + k2);
//     float a1 = 2 * a0;
//     float a2 = a0;
//     float b1 = 2 * (k2 - 1) / (1 + k1 + k2);
//     float b2 = (1 - k1 + k2) / (1 + k1 + k2);
 
//     // Initialize previous inputs (x[n-1], x[n-2]) and outputs (y[n-1], y[n-2])
//     float x1 = 0, x2 = 0;
//     float y1 = 0, y2 = 0;
 
//     vector<float> filteredSignal(signal.size(), 0.0);
 
//     // Apply the filter using the difference equation
//     for (size_t i = 0; i < signal.size(); ++i) {
//         float x0 = signal[i];  // Current input
 
//         // Difference equation for a 2nd-order Butterworth filter
//         float y0 = a0 * x0 + a1 * x1 + a2 * x2 - b1 * y1 - b2 * y2;
 
//         // Store the result in the filtered signal
//         filteredSignal[i] = y0;
 
//         // Update previous inputs and outputs
//         x2 = x1;
//         x1 = x0;
//         y2 = y1;
//         y1 = y0;
//     }
 
//     return filteredSignal;
// }
 
// int main() {
//     vector<float> accelerometerSignal = {1.2, 2.5, 3.1, 4.8, 5.2, 6.5, 7.1, 8.3};
//     float cutoffFrequency = 1.0;  // Cutoff frequency in Hz
//     float samplingRate = 10.0;    // Sampling rate in Hz
 
//     vector<float> filteredSignal = butterworthFilter(accelerometerSignal, cutoffFrequency, samplingRate);
 
//     cout << "Original Signal: ";
//     for (float value : accelerometerSignal) {
//         cout << value << " ";
//     }
//     cout << endl;
 
//     cout << "Filtered Signal: ";
//     for (float value : filteredSignal) {
//         cout << value << " ";
//     }
//     cout << endl;
 
//     return 0;
// }

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function prototype for Butterworth filter
vector<float> butterworthFilter(const vector<float>& signal, float cutoffFrequency, float samplingRate);

vector<float> butterworthFilter(const vector<float>& signal, float cutoffFrequency, float samplingRate) {
    // Constants and calculations
    const float PI = 3.14159265359f;
    float wc = 2.0f * PI * cutoffFrequency / samplingRate;  // Angular cutoff frequency
    float k1 = 1.41421356237f * wc;  // sqrt(2) * wc
    float k2 = wc * wc;
    
    // Coefficients for the difference equation
    float a0 = k2 / (1.0f + k1 + k2);
    float a1 = 2.0f * a0;
    float a2 = a0;
    float b1 = 2.0f * ((k2 - 1.0f) / (1.0f + k1 + k2));
    float b2 = (1.0f - k1 + k2) / (1.0f + k1 + k2);

    // Initialize previous inputs (x[n-1], x[n-2]) and outputs (y[n-1], y[n-2])
    float x1 = 0.0f;
    float x2 = 0.0f;
    float y1 = 0.0f;
    float y2 = 0.0f;

    vector<float> filteredSignal(signal.size(), 0.0f);

    // Apply the filter using the difference equation
    for (size_t i = 0; i < signal.size(); ++i) {
        float x0 = signal[i];  // Current input

        // Difference equation for a 2nd-order Butterworth filter
        float y0 = (a0 * x0) + (a1 * x1) + (a2 * x2) - (b1 * y1) - (b2 * y2);

        // Store the result in the filtered signal
        filteredSignal[i] = y0;

        // Update previous inputs and outputs
        x2 = x1;
        x1 = x0;
        y2 = y1;
        y1 = y0;
    }

    return filteredSignal;
}

int main() {
    vector<float> accelerometerSignal = {1.2f, 2.5f, 3.1f, 4.8f, 5.2f, 6.5f, 7.1f, 8.3f};
    float cutoffFrequency = 1.0f;  // Cutoff frequency in Hz
    float samplingRate = 10.0f;    // Sampling rate in Hz

    vector<float> filteredSignal = butterworthFilter(accelerometerSignal, cutoffFrequency, samplingRate);

    cout << "Original Signal: ";
    for (float value : accelerometerSignal) {
        cout << value << " ";
    }
    cout << endl;

    cout << "Filtered Signal: ";
    for (float value : filteredSignal) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
