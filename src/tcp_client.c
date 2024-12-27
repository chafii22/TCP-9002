
//A simple client program that connects to a server and receives the current time from the server. 
//(making that at literaly 1AM in the morning)

#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main() {

    // Create a socket
    int client_socket;
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Specify an address for the socket (a structure)
    struct sockaddr_in server_address;
    server_address.sin_port = htons(9002);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Connect to the server
    int connect_result = connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));


    // Check if the connection was successful
    if (connect_result == -1) {
        printf("There was an error making a connection to the remote socket\n");
        perror("connect");
        close(client_socket);
        return 1;
    }

    // Receive data from the server
    char server_response[256];
    ssize_t bytes_received = recv(client_socket, &server_response, sizeof(server_response), 0);

    // Check if the data was received
    if (bytes_received == -1) {
        printf("There was an error receiving data from the remote socket\n");
        perror("recv");
        close(client_socket);
        return 1;
    }
    server_response[bytes_received] = '\0';

    // Print out the server's response
    printf("The server sent the data: %s\n", server_response);

    // Close the socket
    close(client_socket);

    if(close(client_socket) == -1) {
        printf("There was an error closing the client socket\n");
        perror("close");
        return 1;
    }

    return 0;
}
