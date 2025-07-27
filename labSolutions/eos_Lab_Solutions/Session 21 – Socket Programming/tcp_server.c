
//  Basic TCP Server

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    char buffer[1024] = {0};
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(9090);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);
    printf("Server listening on port 9090...\n");

    client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    read(client_socket, buffer, 1024);
    printf("Message from client: %s\n", buffer);

    char *response = "Hello from server";
    send(client_socket, response, strlen(response), 0);

    close(client_socket);
    close(server_fd);
    return 0;
}


