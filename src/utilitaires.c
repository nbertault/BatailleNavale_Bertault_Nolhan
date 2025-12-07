//
// Created by Nolhan on 26/11/2025.
//

#include "../include/utilitaires.h"

int convertirCoordonnees(const char *saisie, Position *pos) {
    int erreur = 0, ligne = -1, colonne = -1;

    if (saisie[0] >= 'A' && saisie[0] <= 'J')
        colonne = saisie[0] - 'A';
    else if (saisie[0] >= 'a' && saisie[0] <= 'j')
        colonne = saisie[0] - 'a';
    else
        erreur = 3; //Format invalide

    if (saisie[1] >= '1' && saisie[1] <= '9') {
        if (saisie[1] == '1' && saisie[2] == '0')
            ligne = 9;
        else
            ligne = saisie[1] - '0' - 1;
    } else if (saisie[1] == '0' || saisie[2] > '0')
        erreur = 2; //Erreur ligne
    else
        erreur = 3; //Format invalide

    pos->ligne = ligne;
    pos->colonne = colonne;

    return erreur;
}