//
// Created by Nolhan on 26/11/2025.
//

#include "../include/affichage.h"

#include <stdio.h>

void afficherGrille(EtatCase grille[10][10], int montrerNavires) {
    printf("    A   B   C   D   E   F   G   H   I   J\n");
    for (int i = 1; i <= 10; i++) {
          printf("  +---+---+---+---+---+---+---+---+---+---+\n");
        if (i==10 ? printf("%d|   |   |   |   |   |   |   |   |   |   |\n",i) :printf("%d |   |   |   |   |   |   |   |   |   |   |\n",i));
    }
    printf("  +---+---+---+---+---+---+---+---+---+---+\n");
}
