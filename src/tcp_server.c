

#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main() {

    char server_message[256] = "You have reached the server!";

    // Create a socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Define the server address
    struct sockaddr_in server_address;
    server_address.sin_port = htons(9002);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the address
    bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    // Listen for incoming connections
    listen(server_socket, 5);

    // Accept a connection
    int client_socket;
    client_socket = accept(server_socket, NULL/*struct sockaddr*/, NULL/*socklen_t*/);//we cna send and receive data from client_socket

    // Send data to the client
    send(client_socket, server_message, sizeof(server_message), 0);

    // Close the socket 
    close(server_socket);

    return 0;
}

