// #include <iostream>
// #include <vector>
 
// using namespace std;
 
// vector<float> movingAverageFilter(const vector<float>& signal, int windowSize) {
//     vector<float> filteredSignal(signal.size(), 0.0);
 
//     for (size_t i = 0; i < signal.size(); ++i) {
//         float sum = 0.0;
//         int count = 0;
 
//         // Calculate the sum of elements within the window
//         for (int j = i; j > i - windowSize && j >= 0; --j) {
//             sum += signal[j];
//             count++;
//         }
 
//         // Calculate the average and store it in the filtered signal array
//         filteredSignal[i] = sum / count;
//     }
 
//     return filteredSignal;
// }
 
// int main() {
//     vector<float> signal = {1.0, 2.5, 3.8, 5.0, 4.5, 3.5, 2.0, 1.0};
//     int windowSize = 3;
 
//     vector<float> filteredSignal = movingAverageFilter(signal, windowSize);
 
//     cout << "Original Signal: ";
//     for (float value : signal) {
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

using namespace std;

// Function prototype for moving average filter
vector<float> movingAverageFilter(const vector<float>& signal, int windowSize);

vector<float> movingAverageFilter(const vector<float>& signal, int windowSize) {
    vector<float> filteredSignal(signal.size(), 0.0f);

    // Loop through the signal
    for (size_t i = 0; i < signal.size(); ++i) {
        float sum = 0.0f;
        int count = 0;

        // Calculate the sum of elements within the window
        for (int j = static_cast<int>(i); (j > static_cast<int>(i) - windowSize) && (j >= 0); --j) {
            sum += signal[j];
            count++;
        }

        // Calculate the average and store it in the filtered signal array
        filteredSignal[i] = sum / static_cast<float>(count);
    }

    return filteredSignal;
}

int main() {
    vector<float> signal = {1.0f, 2.5f, 3.8f, 5.0f, 4.5f, 3.5f, 2.0f, 1.0f};
    int windowSize = 3;

    // Apply the moving average filter
    vector<float> filteredSignal = movingAverageFilter(signal, windowSize);

    // Output the original signal
    cout << "Original Signal: ";
    for (float value : signal) {
        cout << value << " ";
    }
    cout << endl;

    // Output the filtered signal
    cout << "Filtered Signal: ";
    for (float value : filteredSignal) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
