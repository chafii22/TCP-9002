
#include "timeserver.h"
#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main() {

    // Create a socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    return 0;
}

