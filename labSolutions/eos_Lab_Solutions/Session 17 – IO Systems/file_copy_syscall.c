#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    char buffer[1024];
    int src = open("input.txt", O_RDONLY);
    int dest = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    int bytes;
    while ((bytes = read(src, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytes);
    }
    close(src);
    close(dest);
    return 0;
}