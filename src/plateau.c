//
// Created by Nolhan on 26/11/2025.
//

#include "../include/plateau.h"

void initialiserGrille(EtatCase grille[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grille[i][j] = VIDE;
        }
    }
}