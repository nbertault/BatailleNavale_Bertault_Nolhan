//
// Created by Nolhan on 26/11/2025.
//

#include "../include/utilitaires.h"

int convertirCoordonnees(const char *saisie, Position *pos) {
    int erreur = 0, ligne, colonne;
    if (saisie[0] >= 'A' && saisie[0] <= 'J')
        ligne = saisie[0] - 'A';
    else if (saisie[0] >= 'a' && saisie[0] <= 'j')
        ligne = saisie[0] - 'a';
    else if ((saisie[0] < 'A' && saisie[0] > 'J') || (saisie[0] < 'a' && saisie[0] > 'j'))
        erreur = 1; //Erreur ligne
    else
        erreur = 3; //Format invalide

    if (saisie[1] >= '1' && saisie[1] <= '9') {
        if (saisie[2] == '1' && saisie[3] == '0')
            colonne = 9;
        else
            colonne = saisie[2] - '0';
    } else if (saisie[1] == '0' || saisie[2] > '0')
        erreur = 2; //Erreur colonne
    else
        erreur = 3; //Format invalide

    pos->ligne = ligne;
    pos->colonne = colonne;

    return erreur;
}