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

int verifierPlacement(EtatCase grille[10][10], Position debut,
                      int taille, Orientation orientation) {
    int erreur = 0;

    for (int i = 0; i < taille; i++) {
        if (orientation == VERTICAL) {
            if (debut.colonne + i > 10) {
                erreur = 1; //case hors plateau
            } else if (grille[debut.ligne][debut.colonne + i] != VIDE) {
                erreur = 2; //case occupée
            }
        } else {
            if (debut.ligne + i > 10) {
                erreur = 1; //case hors plateau
            } else if (grille[debut.ligne + i][debut.colonne] != VIDE) {
                erreur = 2; //case occupée
            }
        }
    }

    return  erreur;
}