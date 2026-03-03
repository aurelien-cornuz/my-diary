# Semaine 03/16

- [ ] Structures de données

## Traitement des arguments

La convention POSIX et GNU pour les arguments de ligne de commande est la suivante:

- Les options *courtes* sont précédées d'un tiret (`-`)
- ou de deux tirets (`--`) pour les options *longues*.

```bash
$ my_program -a -b --option=value
```

Le traitement des arguments peut être effectué manuellement en parcourant `argv`:

```c
#include <stdio.h>

typedef struct options {
    bool a;
    bool b;
    char *option_value;
} Options;

Options parse_options(int argc, char *argv[]) {
    Options options = {false, false, NULL};
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-a") == 0) {
            options.a = true;
        } else if (strcmp(argv[i], "-b") == 0) {
            options.b = true;
        } else if (strncmp(argv[i], "--option=", 9) == 0) {
            options.option_value = argv[i] + 9;
        }
    }
    return options;
}

int main(int argc, char *argv[]) {
    Options options = parse_options(argc, argv);
    printf("Option a: %s\n", options.a ? "true" : "false");
    printf("Option b: %s\n", options.b ? "true" : "false");
    if (options.option_value) {
        printf("Option value: %s\n", options.option_value);
    }
}
```

## Choix entrée standard ou fichier

Souvent, un programme peut soit lire à partir d'un fichier, soit à partir de l'entrée standard. Une convention courante est d'utiliser `-` pour indiquer que le programme doit lire à partir de l'entrée standard mais souvent en cas d'absence de fichier, le programme lit automatiquement à partir de l'entrée standard. Voici les deux approches:

```bash
$ my_program -f input.txt  # Lire à partir d'un fichier
$ cat input.txt | my_program - # Lire à partir de l'entrée standard
$ cat input.txt | my_program   # Lire à partir de l'entrée standard
```

Dans le code, cela peut être géré en vérifiant si un fichier a été spécifié ou non:

```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *input = stdin; // Par défaut, lire à partir de l'entrée standard

    if (argc > 1 && strcmp(argv[1], "-") != 0) {
        input = fopen(argv[1], "r");
        if (input == NULL) {
            perror("Error opening file");
            return 1;
        }
    }

    // ... lecture en utilisant `input` ...

    if (input != stdin) fclose(input);
}
```
