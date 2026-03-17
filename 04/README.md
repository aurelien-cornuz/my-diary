# Semaine 04/16

- [ ] Les fichiers binaires
- [ ] Lecture d'arguments

## Lecture d'arguments

```bash
program arg1 arg2 arg3 "argument 4" 5
program -f -u -v "toto" 56
program -fuv "toto" 56
program --filename="toto"

program -ooutput.txt -o output.txt

program -ooutput input.txt
```

```c
int maint(int argc, char*argv[]) {
    char *filename = NULL;

    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];

        if (strncmp("-o", arg, 2) == 0) {
            if (arg[2] == '\0') {
                filename = argv[i + 1];
                i++;
                continue;
            } else {
                filename = &arg[2];
            }
        }
    }
}
```

Exemple gnu avec la bibliothèque getopt: 

```c
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
    int opt;

    int option_index = 0;

    static struct option long_options[] = {
        {"help",    no_argument,       0, 'h'},
        {"output",  required_argument, 0, 'o'},
        {"verbose", no_argument,       0, 'v'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "ho:v", long_options, &option_index)) != -1) {
        switch (opt) {

            case 'h':
                printf("Usage: program [-h] [-v] [-o file]\n");
                break;

            case 'o':
                printf("Output file: %s\n", optarg);
                break;

            case 'v':
                printf("Verbose mode enabled\n");
                break;

            case '?':
                printf("Unknown option\n");
                break;

            default:
                exit(EXIT_FAILURE);
        }
    }

    printf("Arguments restants:\n");
    for (int i = optind; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    return 0;
}
```
## fread, fwrite

Lire et d'écrire dans un fichier des données brutes binaires

```c
int data[] = {1, 3, 56, 89, -4};

FILE *fp = fopen("data.bin", "wb");
fwrite(data, sizeof(data[0]), 5, fp);
```