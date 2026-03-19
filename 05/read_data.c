#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct measurements {
    int32_t timestamp; // EPOCH
    char description[256]; 
    char data[]; // Membre flexible
} Measurements;

int main() {
    FILE *fp = fopen("data.bin", "rb");

    // Read file size
    fseek(fp, 0, SEEK_END);
    const size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    printf("Size: %lu\n", size);

    Measurements *m = malloc(size);
    fread(m, size, 1, fp);
    fclose(fp);

    printf("Description: %s\n", m->description);
    printf("Timestamp: %u\n", m->timestamp);

    printf("Offset, data: 0x%lx\n", m->data - (char*)m);

    const int n = (size - sizeof(Measurements)) / sizeof(m->data[0]);
    printf("Number of measurements: %d\n", n);
    for (int i = 0; i < n; i++) {
        printf("Data %d: %hhd\n", i, m->data[i]);
    }
}