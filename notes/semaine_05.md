# Smaine 05/16 

## Structure 

La structure est une région mémoire ou je connais l'adresse de chaque mémoir. Exemple dans un champ la structure d'une taille de 260 mètre la structure me permetras de savoir sur combien de mettre j'ai planté mes patates, sur vombien de mètre j'ai planté mes patates etc... 

On défini alors comment la mémoire est organisée 

### Fonction utile pour les structures

**timestamp** : 

Un timestamp dans une structure sert à :

- savoir quand une donnée a été créée / modifiée
- comparer des événements dans le temps
- gérer durée de vie / expiration

**malloc** : 

sert a réagrandir la taille de mon champ. Je réserve une région méoire suppléamntaire lorsque la taille de ma structure est insuffisante. 

**realloc** : 

sert a réagrandir la taille mémoir allouée pour une variable. 

Si j'ai alloué 4 byte pour size je peux realloc pour en avoir plus. 

### fonction 

**fseek** : 

lit la position du curseur sur le fichier.  
Dans ce type de fonction : 

- **SEEK_SET** permet de mettre le curseur de au début du fichier 
- **SEEK_END** permet de mettre le curseur a la fin du fichier 

**ftell** 

Donne la position actuelle du fichier donc la taille de celui ci selon ou se trouve le curseur du fichier. 

**fopen / fclose**

Ouvre un fichier, choisir le type d'ouverture en lecture, lecture + ecriture, ... voir le "man" de fopen. 

fclose ferme le fichier. 

### exemple de code en C 

avec l'utilisation de : 

- ftell 
- fseek 
- fopen / fclose 

```c
#include <stdio.h>

int main() {
    FILE *f = fopen("test.txt", "r");

    fseek(f, 0, SEEK_END);     // aller à la fin
    long size = ftell(f);      // récupérer position = taille

    fseek(f, 0, SEEK_SET);     // revenir au début

    printf("Taille : %ld octets\n", size);

    fclose(f);
    return 0;
}
```
Donc ce code ouvre un fichier en .txt en lecture. Ensuite je vais a la fin du fichier avec mon curseur et **SEEK_END** ensuite je récupère la position a l'aide de ftell. Je stocke la position dans un size de préférance const. et ensuite je reviens au début avec **SEEK_SET**. Dans fseek je passe mon pointeur FILE donc f et 0 car je veux dépacer 0 octet. 

La ou FILE est une structure opaque. Une structure ou l'on ne voit pas ce qu'elle contient mais les fontion : 

- ftell 
- fseek 
- fopen / fclose 
- ...

Ces fonctions la utilisent la structure opaque FILE pour tavailler. 








