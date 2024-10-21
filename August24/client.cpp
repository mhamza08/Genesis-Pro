// #include <iostream>
// #include <sys/socket.h>
// #include <arpa/inet.h>
// #include <unistd.h>
// #include <cstring>
 
// #define PORT 8080
 
// int main() {
//     int sock = 0;
//     struct sockaddr_in serv_addr;
//     const char *message = "Hello from the client!";
 
//     if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
//         std::cerr << "Socket creation error" << std::endl;
//         return -1;
//     }
 
//     serv_addr.sin_family = AF_INET;
//     serv_addr.sin_port = htons(PORT);
 
// if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
//         std::cerr << "Invalid address/ Address not supported" << std::endl;
//         return -1;
//     }
 
//     if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
//         std::cerr << "Connection Failed" << std::endl;
//         return -1;
//     }
 
//     send(sock, message, strlen(message), 0);
//     std::cout << "Message sent from client" << std::endl;
 
//     close(sock);
//     return 0;
// }

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

#define PORT 8080

// Function prototypes
int createSocket(void);
void connectToServer(int sock, struct sockaddr_in* serv_addr);
void sendMessage(int sock, const char* message);

int main() {
    int sock = createSocket();
    struct sockaddr_in serv_addr;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        return -1;
    }

    connectToServer(sock, &serv_addr);
    sendMessage(sock, "Hello from the client!");

    close(sock);
    return 0;
}

// Create a socket
int createSocket(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Socket creation error" << std::endl;
        _Exit(EXIT_FAILURE);
    }
    return sock;
}

// Connect to the server
void connectToServer(int sock, struct sockaddr_in* serv_addr) {
    if (connect(sock, (struct sockaddr*)serv_addr, sizeof(*serv_addr)) < 0) {
        std::cerr << "Connection Failed" << std::endl;
        _Exit(EXIT_FAILURE);
    }
}

// Send a message to the server
void sendMessage(int sock, const char* message) {
    if (send(sock, message, strlen(message), 0) < 0) {
        std::cerr << "Send failed" << std::endl;
        _Exit(EXIT_FAILURE);
    } else {
        std::cout << "Message sent from client" << std::endl;
    }
}
