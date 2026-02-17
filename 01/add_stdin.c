#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Usage: echo 23 42 | %s\n", argv[0]);
        return 1;
    }
    int sum = a + b;
    printf("%d\n", sum);
}