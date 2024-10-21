// #include <iostream>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <unistd.h>
// #include <cstring>
 
// #define PORT 8080
 
// int main() {
//     int server_fd, new_socket;
//     struct sockaddr_in address;
//     int addrlen = sizeof(address);
//     char buffer[1024] = {0};
 
//     // Creating socket file descriptor
//     if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
//         std::cerr << "Socket failed" << std::endl;
//         exit(EXIT_FAILURE);
//     }
 
//     // Forcefully attaching socket to the port 8080
//     address.sin_family = AF_INET;
//     address.sin_addr.s_addr = INADDR_ANY;
//     address.sin_port = htons(PORT);
 
//     if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
//         std::cerr << "Bind failed" << std::endl;
//         exit(EXIT_FAILURE);
//     }
 
//     if (listen(server_fd, 3) < 0) {
//         std::cerr << "Listen failed" << std::endl;
//         exit(EXIT_FAILURE);
//     }
 
//     std::cout << "Server listening on port " << PORT << std::endl;
 
//     if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
//         std::cerr << "Accept failed" << std::endl;
//         exit(EXIT_FAILURE);
//     }
 
//     int valread = read(new_socket, buffer, 1024);
//     std::cout << "Received message: " << buffer << std::endl;
 
//     close(new_socket);
//     close(server_fd);
//     return 0;
// }

    #include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

#define PORT 8080

// Function prototypes
int createSocket(void);
void bindSocket(int server_fd, struct sockaddr_in* address);
void listenForConnections(int server_fd);
int acceptConnection(int server_fd, struct sockaddr_in* address);
void receiveMessage(int socket, char* buffer, int buffer_size);

int main() {
    int server_fd = createSocket();
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bindSocket(server_fd, &address);
    listenForConnections(server_fd);
    int new_socket = acceptConnection(server_fd, &address);

    receiveMessage(new_socket, buffer, 1024);
    std::cout << "Received message: " << buffer << std::endl;

    close(new_socket);
    close(server_fd);
    return 0;
}

// Create a socket
int createSocket(void) {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        std::cerr << "Socket creation failed" << std::endl;
        _Exit(EXIT_FAILURE);
    }
    return server_fd;
}

// Bind the socket to the specified address and port
void bindSocket(int server_fd, struct sockaddr_in* address) {
    if (bind(server_fd, (struct sockaddr*)address, sizeof(*address)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        _Exit(EXIT_FAILURE);
    }
}

// Listen for incoming connections
void listenForConnections(int server_fd) {
    if (listen(server_fd, 3) < 0) {
        std::cerr << "Listen failed" << std::endl;
        _Exit(EXIT_FAILURE);
    }
    std::cout << "Server listening on port " << PORT << std::endl;
}

// Accept an incoming connection
int acceptConnection(int server_fd, struct sockaddr_in* address) {
    int addrlen = sizeof(*address);
    int new_socket = accept(server_fd, (struct sockaddr*)address, (socklen_t*)&addrlen);
    if (new_socket < 0) {
        std::cerr << "Accept failed" << std::endl;
        _Exit(EXIT_FAILURE);
    }
    return new_socket;
}

// Receive a message from the connected client
void receiveMessage(int socket, char* buffer, int buffer_size) {
    int valread = read(socket, buffer, buffer_size);
    if (valread < 0) {
        std::cerr << "Read failed" << std::endl;
        _Exit(EXIT_FAILURE);
    }
}
