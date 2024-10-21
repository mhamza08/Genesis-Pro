// #include <iostream>
// #include <bitset>
// #include <cstdint>
 
// // Structure to represent a CAN message using bit fields
// struct CANMessage {
//     uint16_t id : 11;     // 11-bit Identifier
//     uint8_t dlc : 4;       // 4-bit Data Length Code (0-8)
//     uint8_t data[8];       // Array to store up to 8 bytes of data
 
//     void transmit() const {
//         std::cout << "Transmitting CAN Message:\n";
//         std::cout << "ID: 0x" << std::hex << id << "\n";
//         std::cout << "DLC: " << std::dec << static_cast<int>(dlc) << "\n";
//         std::cout << "Data: ";
//         for (int i = 0; i < dlc; ++i) {
//             std::cout << "0x" << std::hex << static_cast<int>(data[i]) << " ";
//         }
//         std::cout << "\n";
//     }
// };
 
// int main() {
//     CANMessage message;
 
//     // Temporary variables to store input
//     uint16_t inputID;
//     uint8_t inputDLC;
 
//     // Input the CAN message ID, DLC, and data bytes
//     std::cout << "Enter CAN message ID (11-bit hexadecimal, e.g., 0x7FF): ";
//     std::cin >> std::hex >> inputID;
 
//     std::cout << "Enter DLC (Data Length Code, 0-8): ";
//     std::cin >> std::dec >> inputDLC;
 
//     if (inputDLC > 8) {
//         std::cerr << "Error: DLC must be between 0 and 8.\n";
//         return 1;
//     }
 
//     std::cout << "Enter data bytes (space-separated hexadecimal values): ";
//     for (int i = 0; i < inputDLC; ++i) {
//         std::cin >> std::hex >> message.data[i];
//     }
 
//     // Assign the temporary values to the bit fields
// message.id = inputID;
//     message.dlc = inputDLC;
 
//     // Transmit the CAN message
//     message.transmit();
 
//     return 0;
// }

#include <iostream>
#include <bitset>
#include <cstdint>

// Structure to represent a CAN message using bit fields
struct CANMessage {
    uint16_t id : 11;     // 11-bit Identifier
    uint8_t dlc : 4;       // 4-bit Data Length Code (0-8)
    uint8_t data[8];       // Array to store up to 8 bytes of data

    void transmit(void) const {
        std::cout << "Transmitting CAN Message:\n";
        std::cout << "ID: 0x" << std::hex << id << "\n";
        std::cout << "DLC: " << std::dec << static_cast<int>(dlc) << "\n";
        std::cout << "Data: ";
        for (int i = 0; i < dlc; ++i) {
            std::cout << "0x" << std::hex << static_cast<int>(data[i]) << " ";
        }
        std::cout << "\n";
    }
};

int main(void) {
    CANMessage message;

    // Temporary variables to store input
    uint16_t inputID;
    uint8_t inputDLC;

    // Input the CAN message ID, DLC, and data bytes
    std::cout << "Enter CAN message ID (11-bit hexadecimal, e.g., 0x7FF): ";
    std::cin >> std::hex >> inputID;

    std::cout << "Enter DLC (Data Length Code, 0-8): ";
    std::cin >> std::dec >> inputDLC;

    if (inputDLC > 8u) {
        std::cerr << "Error: DLC must be between 0 and 8.\n";
        return 1;
    }

    std::cout << "Enter data bytes (space-separated hexadecimal values): ";
    for (int i = 0; i < inputDLC; ++i) {
        std::cin >> std::hex >> message.data[i];
    }

    // Assign the temporary values to the bit fields
    message.id = inputID;
    message.dlc = inputDLC;

    // Transmit the CAN message
    message.transmit();

    return 0;
}
