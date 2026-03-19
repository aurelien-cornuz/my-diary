#include <stdio.h>
#include <stdint.h> 
#include <stdlib.h> 

typedef struct measurements {
    int32_t timestamp; // EPOCH
    char description[256]; 
    float data[]; // Membre flexible
} Measurements;

typedef struct foo {
    int a, b;
} Foo;

int main() {
    printf("%lu\n", sizeof(Measurements));

    Measurements *m = malloc(sizeof(Measurements) + sizeof(float) * 256);

    m = realloc(m, 1000);
    
    m->data[127] = 42; // *(int*)(m + 4 + 256 + 4*127) = 42;

    // m.data[127] = 42; // Dangereux. 
    // printf("%d\n", m.timestamp);
}