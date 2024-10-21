// #include <iostream>
// #include <cstring>
// #include <cstdio>
// #include <cstdlib>
// #include <unistd.h>
// #include <net/if.h>
// #include <sys/ioctl.h>
// #include <sys/socket.h>
// #include <linux/can.h>
// #include <linux/can/raw.h>
 
// int main() {
//     // Create a socket
//     int socket_fd = socket(PF_CAN, SOCK_RAW, CAN_RAW);
//     if (socket_fd < 0) {
//         std::cerr << "Error while opening socket." << std::endl;
//         return -1;
//     }
 
//     // Specify the CAN interface
//     struct ifreq ifr;
//     std::strcpy(ifr.ifr_name, "can0");
//     ioctl(socket_fd, SIOCGIFINDEX, &ifr);
 
//     // Bind the socket to the CAN interface
//     struct sockaddr_can addr;
//     std::memset(&addr, 0, sizeof(addr));
//     addr.can_family = AF_CAN;
//     addr.can_ifindex = ifr.ifr_ifindex;
 
//     if (bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
//         std::cerr << "Error in socket bind." << std::endl;
//         close(socket_fd);
//         return -2;
//     }
 
//     // Receive CAN messages
//     struct can_frame frame;
//     while (true) {
//         int nbytes = read(socket_fd, &frame, sizeof(struct can_frame));
//         if (nbytes < 0) {
//             std::cerr << "Error reading CAN frame." << std::endl;
//             break;
//         }
 
//         // Print CAN frame details
//         std::cout << "ID: 0x" << std::hex << frame.can_id << std::dec;
//         std::cout << " DLC: " << static_cast<int>(frame.can_dlc) << " Data: ";
 
//         for (int i = 0; i < frame.can_dlc; i++) {
//             std::cout << std::hex << static_cast<int>(frame.data[i]) << " ";
//         }
 
//         std::cout << std::dec << std::endl;
//     }
 
//     // Close the socket
//     close(socket_fd);
//     return 0;
// }

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>

int initialize_socket(int *socket_fd) {
    *socket_fd = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (*socket_fd < 0) {
        std::cerr << "Error while opening socket." << std::endl;
        return -1;
    }

    // Specify the CAN interface
    struct ifreq ifr;
    std::strcpy(ifr.ifr_name, "can0");
    ioctl(*socket_fd, SIOCGIFINDEX, &ifr);

    // Bind the socket to the CAN interface
    struct sockaddr_can addr;
    std::memset(&addr, 0, sizeof(addr));
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(*socket_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        std::cerr << "Error in socket bind." << std::endl;
        close(*socket_fd);
        return -2;
    }

    return 0;
}

int main(void) {
    int socket_fd;
    int ret = initialize_socket(&socket_fd);
    if (ret != 0) {
        return ret;
    }

    // Receive CAN messages
    struct can_frame frame;
    while (true) {
        int nbytes = read(socket_fd, &frame, sizeof(struct can_frame));
        if (nbytes < 0) {
            std::cerr << "Error reading CAN frame." << std::endl;
            close(socket_fd);
            return -3;
        }

        // Print CAN frame details
        std::cout << "ID: 0x" << std::hex << frame.can_id << std::dec;
        std::cout << " DLC: " << static_cast<int>(frame.can_dlc) << " Data: ";

        for (int i = 0; i < frame.can_dlc; i++) {
            std::cout << std::hex << static_cast<int>(frame.data[i]) << " ";
        }

        std::cout << std::dec << std::endl;
    }

    // Close the socket
    close(socket_fd);
    return 0;
}
