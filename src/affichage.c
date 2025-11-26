//
// Created by Nolhan on 26/11/2025.
//

#include "../include/affichage.h"

#include <stdio.h>

void afficherGrille(EtatCase grille[TAILLE_GRILLE][TAILLE_GRILLE], int montrerNavires) {
    printf("    A   B   C   D   E   F   G   H   I   J\n");
    for (int i = 1; i <= 10; i++) {
            printf("  +---+---+---+---+---+---+---+---+---+---+\n");
            if (i < 10 ? printf("%d ",i) : printf("%d",i));
        for (int j = 1; j <= 10; j++) {
            switch (grille[i-1][j-1]) {
                case VIDE:
                    printf("|   ");
                    break;
                case TOUCHE:
                    printf("| X ");
                    break;
                case MANQUE:
                    printf("| - ");
                    break;
                case NAVIRE:
                    if (montrerNavires == 1)
                        printf("| O ");
                    break;
            }
        }
            printf("|\n");
    }
    printf("  +---+---+---+---+---+---+---+---+---+---+\n");
}