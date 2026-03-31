# Semaine 06/16

- [ ] Tableau Dynamique
  - [ ] Utilise l'allocation dynamique (malloc, calloc, realloc)
  - [ ] Permet d'ajouter des éléments sans se soucier de la taille initiale
  - [ ] Il utilise un facteur de croissance pour augmenter la capacité lorsque nécessaire (généralement en doublant la taille)
- [ ] Compilation séparée
  - [ ] Permet de compiler chaque fichier source (.c) séparément en un fichier objet (.o)
  - [ ] Utilise la commande `gcc -c` pour compiler sans lier
  - [ ] Facilite la gestion de projets plus importants et accélère le processus de compilation

## Compilation séparée

La compilation séparée est une technique qui permet de compiler chaque fichier source (.c) en un fichier objet (.o) de manière indépendante. Cela est particulièrement utile dans les projets plus importants, car cela permet de ne recompiler que les fichiers qui ont été modifiés, plutôt que de recompiler l'ensemble du projet à chaque changement.

Rappelez-vous que la compilation d'un programme passe par plusieurs étapes: 

1. **Prétraitement**: Le préprocesseur traite les directives de préprocesseur (comme `#include` et `#define`) et génère un fichier source modifié.
2. **Compilation**: Le compilateur traduit le code source prétraité en langage machine, produisant un fichier objet (.o).
3. **Édition de liens**: Le linker combine les fichiers objets et les bibliothèques pour créer l'exécutable final.

Chacune de ces étapes peut être faite à la main. Par exemple pour un fichier C unique on peut découper les trois opérations comme suit:

```bash
gcc -E main.c -o main.i   # Prétraitement
gcc -S main.i -o main.s   # Compilation en assembleur
gcc -c main.s -o main.o   # Compilation en objet
gcc -o program main.o     # Édition de liens
```

En pratique gcc permet de faire tout cela en une seule commande:

```bash
gcc -o program main.c
```

Lorque vous avez deux fichiers source ou plus, il est plus efficace de les compiler séparément:

```bash
gcc -c main.c   # Génère main.o
gcc -c prout.c  # Génère prout.o
gcc -o program main.o prout.o  # Lie les fichiers objets 
```

## Makefile

Un Makefile est un fichier de configuration utilisé par l'outil de construction `make` pour automatiser le processus de compilation et de gestion des dépendances dans les projets logiciels. Il définit des règles et des cibles pour compiler les fichiers source, générer des exécutables, nettoyer les fichiers temporaires, etc.

La structure de base est très simple: 

```makefile
<cible>: <ingredients>
	<recette>
```

Par exemple pour faire une crêpe au jambon et fromage, on pourrait écrire:

```makefile
lait: vache
	echo "Traire la vache pour obtenir du lait."

pateacrepe: lait oeuf farine
	echo "Mélangez le lait, les oeufs et la farine pour faire la pâte à crêpe."


crepe-jambon: pateacrepe jambon fromage
	echo "Faites cuire la pâte à crêpe, ajoutez du jambon et du fromage, puis pliez la crêpe."
```

Dans le contexte plus réaliste de notre exemple vu en classe, voici un Makefile pour compiler un projet C avec deux fichiers source `main.c` et `prout.c`:

```makefile
program: main.o prout.o
  gcc -o program main.o prout.o

main.o: main.c
  gcc -c main.c

prout.o: prout.c
  gcc -c prout.c
```

En pratique on n'aime pas répéter les mêmes commandes, on peut utiliser des variables et des règles génériques pour rendre le Makefile plus propre et plus facile à maintenir:

```makefile
EXEC=program
SRC=main.c prout.c
OBJ=$(SRC:.c=.o)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $< -o $@
```

Et pourquoi pas rajouter une règle pour nettoyer les fichiers objets et l'exécutable:

```makefile
clean: 
	$(RM) -f *.o $(EXEC)
```