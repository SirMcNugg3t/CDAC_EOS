// Basic TCP Client

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sock;
    struct sockaddr_in server_address;
    char buffer[1024] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9090);
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);

    connect(sock, (struct sockaddr *)&server_address, sizeof(server_address));
    send(sock, "Hello from client", strlen("Hello from client"), 0);
    read(sock, buffer, 1024);
    printf("Server response: %s\n", buffer);
    close(sock);
    return 0;
}
