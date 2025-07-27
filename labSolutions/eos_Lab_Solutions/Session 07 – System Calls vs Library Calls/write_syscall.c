#include <unistd.h>
int main() {
    const char *msg = "Hello from write syscall!\n";
    write(1, msg, 27);
    return 0;
}