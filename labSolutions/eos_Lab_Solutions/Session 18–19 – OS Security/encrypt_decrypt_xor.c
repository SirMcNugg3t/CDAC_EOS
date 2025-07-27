// A simple XOR encryption/decryption (for demo purposes only, not secure for real-world use).

#include <stdio.h>
#include <stdlib.h>

void xor_cipher(const char *input, const char *output, char key) {
    FILE *fin = fopen(input, "rb");
    FILE *fout = fopen(output, "wb");

    if (!fin || !fout) {
        perror("File error");
        return;
    }

    int ch;
    while ((ch = fgetc(fin)) != EOF) {
        fputc(ch ^ key, fout);
    }

    fclose(fin);
    fclose(fout);
}

int main() {
    const char *infile = "secret.txt";
    const char *encfile = "secret.enc";
    const char *decfile = "secret.dec";

    xor_cipher(infile, encfile, 0xAA);  // Encrypt
    xor_cipher(encfile, decfile, 0xAA); // Decrypt

    printf("Encryption and decryption done using XOR.\n");
    return 0;
}
