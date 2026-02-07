#include <stdio.h>
#include <stdlib.h>


void compressFile() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("compressed.txt", "w");
    char ch, prev;
    int count = 1;

    if (in == NULL || out == NULL) {
        printf("File error\n");
        return;
    }

    prev = fgetc(in);
    while ((ch = fgetc(in)) != EOF) {
        if (ch == prev) {
            count++;
        } else {
            fprintf(out, "%c%d", prev, count);
            prev = ch;
            count = 1;
        }
    }
    fprintf(out, "%c%d", prev, count);

    fclose(in);
    fclose(out);
}


void decompressFile() {
    FILE *in = fopen("compressed.txt", "r");
    FILE *out = fopen("decompressed.txt", "w");
    char ch;
    int count;

    if (in == NULL || out == NULL) {
        printf("File error\n");
        return;
    }

    while (fscanf(in, "%c%d", &ch, &count) != EOF) {
        for (int i = 0; i < count; i++) {
            fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);
}

int main() {
    compressFile();
    decompressFile();

    printf("Compression and Decompression completed.\n");
    return 0;
}
