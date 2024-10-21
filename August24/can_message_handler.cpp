// #include <iostream>
// #include <thread>
// #include <chrono>
// #include <mutex>
// #include <queue>

// // Structure to represent a CAN message
// struct CANMessage {
//     uint32_t id;        // CAN ID
//     uint8_t dlc;        // Data Length Code
//     uint8_t data[8];    // Data (maximum 8 bytes)
// };

// // Simulated CAN bus queue (for communication between transmitter and receiver)
// std::queue<CANMessage> CANBusQueue;
// std::mutex queueMutex;

// // Function to transmit CAN messages
// void transmitCANMessage(uint32_t id, uint8_t dlc, uint8_t data[8]) {
//     CANMessage message;
//     message.id = id;
//     message.dlc = dlc;
//     for (int i = 0; i < dlc; ++i) {
//         message.data[i] = data[i];
//     }

//     std::lock_guard<std::mutex> lock(queueMutex);
//     CANBusQueue.push(message);
//     std::cout << "Transmitted CAN Message with ID: 0x" << std::hex << id << std::dec << " DLC: " << (int)dlc << std::endl;
// }

// // Function to receive and process CAN messages
// void receiveCANMessage() {
//     while (true) {
//         std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Simulate delay in receiving messages

//         std::lock_guard<std::mutex> lock(queueMutex);
//         if (!CANBusQueue.empty()) {
//             CANMessage message = CANBusQueue.front();
//             CANBusQueue.pop();

//             // Process the message based on ID
//             std::cout << "Received CAN Message with ID: 0x" << std::hex << message.id << std::dec << " DLC: " << (int)message.dlc << std::endl;

//             switch (message.id) {
//                 case 0x100:
//                     std::cout << "Updating display with data: ";
//                     for (int i = 0; i < message.dlc; ++i) {
//                         std::cout << std::hex << (int)message.data[i] << " ";
//                     }
//                     std::cout << std::dec << std::endl;
//                     break;
//                 case 0x200:
//                     std::cout << "Triggering alarm with data: ";
//                     for (int i = 0; i < message.dlc; ++i) {
//                         std::cout << std::hex << (int)message.data[i] << " ";
//                     }
//                     std::cout << std::dec << std::endl;
//                     break;
//                 case 0x300: {
//                     std::cout << "Sending response message" << std::endl;
//                     uint8_t response[8] = {0xA, 0xB, 0xC, 0xD, 0xE, 0xF, 0x1, 0x2};
//                     transmitCANMessage(0x301, 8, response);
//                     break;
//                 }
//                 default:
//                     std::cout << "Unknown CAN message ID" << std::endl;
//                     break;
//             }
//         }
//     }
// }

// int main() {
//     // Create a thread for receiving messages
//     std::thread receiver(receiveCANMessage);

//     // Example messages to transmit
//     uint8_t data1[8] = {0x11, 0x22, 0x33, 0x44};
//     transmitCANMessage(0x100, 4, data1);

//     std::this_thread::sleep_for(std::chrono::milliseconds(500));

//     uint8_t data2[8] = {0xAA, 0xBB, 0xCC, 0xDD};
//     transmitCANMessage(0x200, 4, data2);

//     std::this_thread::sleep_for(std::chrono::milliseconds(500));

//     uint8_t data3[8] = {0x1, 0x2, 0x3, 0x4};
//     transmitCANMessage(0x300, 4, data3);

//     // Wait for the receiver to finish (in this example, it won't, so the program will run indefinitely)
//     receiver.join();

//     return 0;
// }

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <queue>

// Structure to represent a CAN message
struct CANMessage {
    uint32_t id;        // CAN ID
    uint8_t dlc;        // Data Length Code
    uint8_t data[8];    // Data (maximum 8 bytes)
};

// Simulated CAN bus queue (for communication between transmitter and receiver)
std::queue<CANMessage> CANBusQueue;
std::mutex queueMutex;

// Function to transmit CAN messages
void transmitCANMessage(uint32_t id, uint8_t dlc, const uint8_t data[8]) {
    CANMessage message;
    message.id = id;
    message.dlc = dlc;
    for (uint8_t i = 0; i < dlc; ++i) {
        message.data[i] = data[i];
    }

    std::lock_guard<std::mutex> lock(queueMutex);
    CANBusQueue.push(message);
    std::cout << "Transmitted CAN Message with ID: 0x" << std::hex << id << std::dec << " DLC: " << static_cast<int>(dlc) << std::endl;
}

// Function to receive and process CAN messages
void receiveCANMessage(void) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Simulate delay in receiving messages

        std::lock_guard<std::mutex> lock(queueMutex);
        if (!CANBusQueue.empty()) {
            CANMessage message = CANBusQueue.front();
            CANBusQueue.pop();

            // Process the message based on ID
            std::cout << "Received CAN Message with ID: 0x" << std::hex << message.id << std::dec << " DLC: " << static_cast<int>(message.dlc) << std::endl;

            switch (message.id) {
                case 0x100: {
                    std::cout << "Updating display with data: ";
                    for (uint8_t i = 0; i < message.dlc; ++i) {
                        std::cout << std::hex << static_cast<int>(message.data[i]) << " ";
                    }
                    std::cout << std::dec << std::endl;
                    break;
                }
                case 0x200: {
                    std::cout << "Triggering alarm with data: ";
                    for (uint8_t i = 0; i < message.dlc; ++i) {
                        std::cout << std::hex << static_cast<int>(message.data[i]) << " ";
                    }
                    std::cout << std::dec << std::endl;
                    break;
                }
                case 0x300: {
                    std::cout << "Sending response message" << std::endl;
                    uint8_t response[8] = {0xA, 0xB, 0xC, 0xD, 0xE, 0xF, 0x1, 0x2}; // Fully initialized array
                    transmitCANMessage(0x301, 8u, response);
                    break;
                }
                default:
                    std::cout << "Unknown CAN message ID" << std::endl;
                    break;
            }
        }
    }
}

int main(void) {
    // Create a thread for receiving messages
    std::thread receiver(receiveCANMessage);

    // Example messages to transmit
    uint8_t data1[8] = {0x11, 0x22, 0x33, 0x44, 0x00, 0x00, 0x00, 0x00}; // Fully initialized array
    transmitCANMessage(0x100, 4u, data1);

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    uint8_t data2[8] = {0xAA, 0xBB, 0xCC, 0xDD, 0x00, 0x00, 0x00, 0x00}; // Fully initialized array
    transmitCANMessage(0x200, 4u, data2);

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    uint8_t data3[8] = {0x1, 0x2, 0x3, 0x4, 0x00, 0x00, 0x00, 0x00}; // Fully initialized array
    transmitCANMessage(0x300, 4u, data3);

    // Wait for the receiver to finish (in this example, it won't, so the program will run indefinitely)
    receiver.join();

    return 0;
}
