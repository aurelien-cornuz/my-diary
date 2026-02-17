#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [number] [number]\n", argv[0]);
        return 0;
    }
    int sum = (atoi(argv[1]) + atoi(argv[2]));
    printf("%d\n", sum);
}