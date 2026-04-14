#include <stdio.h>

int main()
{
    FILE *fp = fopen("foo.txt", "rb");
    if(fp == NULL)return -1; 
    fseek(fp, 0, SEEK_END);
    size_t c = ftell(fp);
    fprintf(stdout, "le fichier fait %ld bytes\n", c);
    fclose(fp);
    return 0;
}