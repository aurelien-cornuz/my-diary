# Semaine 05/16

- [x] Structures avec membres flexibles
- [x] Structures imbriquées
- [ ] Labo météo

## Membres Flexibles

Un membre flexible est un élément d'une structure dont on a pas
spécifié la taille. La taille d'une structure est uniquement définie
par rapports aux membres dont la taille est connue. 

Un membre flexible doit impérativement se trouver à la fin de la structure.

```c
typedef struct measurements {
    int32_t timestamp; // EPOCH
    char description[256]; 
    float data[]; // Membre flexible
} Measurements;
```

## Structures imbriquées

- Département
  - Filière
    - Étudiants
      - Nom
      - Note Insuffisante
  
```c
struct student {
    char name[64];
    float note;
};

typedef struct filiere {
    char name[64];
    struct student students[20];
} Filiere;

typedef struct department {
    char name[64];
    char acronym[10];
    Filiere filieres[5];
} Department;

int main() {
    Department tin;
    tin.filieres[2].students[5].note;
}