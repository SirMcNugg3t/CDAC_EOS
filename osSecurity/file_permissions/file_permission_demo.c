// Demonstrates how to set file permissions programmatically using chmod() and chown()

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    const char *filename = "secure_file.txt";
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("File creation failed");
        return 1;
    }
    fprintf(fp, "This is a secure file.\n");
    fclose(fp);

    // Set permissions to 600 (rw-------)
    if (chmod(filename, S_IRUSR | S_IWUSR) != 0) {
        perror("chmod failed");
    }

    // Change ownership (only works if run as root)
    chown(filename, 1001, 1001); // Example: UID=1001, GID=1001

    printf("File created with secure permissions.\n");
    return 0;
}
