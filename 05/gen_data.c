#include <stdio.h>
#include <stdint.h>

typedef struct measurements {
    int32_t timestamp; // EPOCH
    char description[256]; 
    char data[]; // Membre flexible
} Measurements;

int main() {
    FILE *fp = fopen("data.bin", "wb");
    Measurements m = {
        .timestamp = 12457483,
        .description = "Données météo"
    };
    fwrite(&m, sizeof(m), 1, fp);

    for (char i = 0; i < 120; i++) {
        fwrite(&i, sizeof(i), 1, fp);
    }
}