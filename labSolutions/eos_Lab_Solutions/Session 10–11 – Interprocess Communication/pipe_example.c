#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    char buffer[20];
    pipe(pipefd);
    if (fork() == 0) {
        close(pipefd[0]);
        write(pipefd[1], "Hello Parent", 13);
    } else {
        close(pipefd[1]);
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Received: %s\n", buffer);
    }
    return 0;
}