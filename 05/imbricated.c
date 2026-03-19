#include <stdio.h>

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
    char acronym[10]; // Nom court du département
    Filiere filieres[5];
} Department;

int main() {
    Department tin;
    tin.filieres[2].students[3].note = 3.74;
}