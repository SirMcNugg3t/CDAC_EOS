// Demonstrates non-blocking file input.

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    char buffer[100];
    int fd = open("input.txt", O_RDONLY | O_NONBLOCK);
    if (fd < 0) {
        perror("Open failed");
        return 1;
    }
    int n = read(fd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("Read failed");
    } else {
        write(1, buffer, n);
    }
    close(fd);
    return 0;
}