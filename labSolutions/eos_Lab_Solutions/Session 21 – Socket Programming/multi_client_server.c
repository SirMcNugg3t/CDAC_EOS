
// Multi-client Echo Server using fork()

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>

void handle_client(int client_socket) {
    char buffer[1024];
    int bytes;
    while ((bytes = read(client_socket, buffer, sizeof(buffer))) > 0) {
        buffer[bytes] = 0;
        printf("Client says: %s", buffer);
        send(client_socket, buffer, bytes, 0);
    }
    close(client_socket);
    exit(0);
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(9091);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 5);
    printf("Multi-client server listening on port 9091...\n");

    while (1) {
        client_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);
        if (fork() == 0) {
            close(server_fd);
            handle_client(client_socket);
        }
        close(client_socket);
    }
    return 0;
}
