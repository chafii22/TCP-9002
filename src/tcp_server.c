#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <unistd.h> // close() function

int main() {

    char server_message[256] = "You have reached the server!";

    // Create a socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("There was an error creating the server socket\n");
        perror("Error creating the server socket"); 
        close(server_socket);
        return 1;
    }
    
    // Define the server address
    struct sockaddr_in server_address;
    server_address.sin_port = htons(9002);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the address
    bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    // Listen for incoming connections
    listen(server_socket, 5);

    if (listen(server_socket, 5) == -1) {
        printf("There was an error listening on the server socket\n");
        perror("Error listening on the server socket");
        close(server_socket);
        return 1;
    }

    // Accept a connection
    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);

    if(client_socket == -1) {
        printf("There was an error accepting the client socket\n");
        perror("Error accepting the client socket");
        close(server_socket);
        return 1;
    }

    // Send data to the client
    send(client_socket, server_message, sizeof(server_message), 0);

    if(send(client_socket, server_message, sizeof(server_message), 0) == -1) {
        printf("There was an error sending the message to the client\n");
        perror("Error sending the message to the client");
        close(client_socket);
        close(server_socket);
        return 1;
    }

    if(close(client_socket) == -1) {
        printf("There was an error closing the client socket\n");
        perror("Error closing the client socket");
        return 1;
    }

    if(close(server_socket) == -1) {
        printf("There was an error closing the server socket\n");
        perror("Error closing the server socket");
        return 1;
    }

    return 0;
}
