//
// Created by Nolhan on 26/11/2025.
//

#include "../include/plateau.h"

void initialiserGrille(EtatCase grille[TAILLE_GRILLE][TAILLE_GRILLE]) {
    for (int i = 0; i < TAILLE_GRILLE; i++) {
        for (int j = 0; j < TAILLE_GRILLE; j++) {
            grille[i][j] = VIDE;
        }
    }
}

int verifierPlacement(EtatCase grille[TAILLE_GRILLE][TAILLE_GRILLE], Position debut,
                      int taille, Orientation orientation) {
    int erreur = 0;

    switch (orientation) {
        case HORIZONTAL:
            if (debut.colonne + taille > TAILLE_GRILLE) {
                erreur = 1; //case hors plateau
            }
            for (int i = 0; i < taille; i++) {
                if (grille[debut.ligne][debut.colonne + i] != VIDE) {
                    erreur = 2; //case occupée
                }
            }
            break;

            case VERTICAL:
            if (debut.ligne + taille > TAILLE_GRILLE) {
                erreur = 1; //case hors plateau
            }
            for (int i = 0; i < taille; i++) {
                if (grille[debut.ligne + i][debut.colonne] != VIDE) {
                    erreur = 2; //case occupée
                }
            }
            break;
    }


    return  erreur;
}


void placerNavireSurGrille(EtatCase grille[10][10], Navire *navire) {
    for (int i = 0; i < navire->taille; i++) {
        grille[navire->positions[i].ligne][navire->positions[i].colonne] = NAVIRE;
        /* switch (navire->type) { # A voir pour l'affichage des différents navires
            case CONTRE_TORPILLEUR:
                grille[navire->positions[i].ligne][navire->positions[i].colonne] = 'T';
                break;
            case CROISEUR:
                grille[navire->positions[i].ligne][navire->positions[i].colonne] = 'C';
                break;
            case PORTE_AVIONS:
                grille[navire->positions[i].ligne][navire->positions[i].colonne] = 'P';
                break;
            case SOUS_MARIN:
                grille[navire->positions[i].ligne][navire->positions[i].colonne] = 'S';
                break;
            case TORPILLEUR:
                grille[navire->positions[i].ligne][navire->positions[i].colonne] = 'O';
                break;
        }
        */
    }
}