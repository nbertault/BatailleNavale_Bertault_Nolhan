//
// Created by Nolhan on 26/11/2025.
//

#include "../include/utilitaires.h"

#include <stdio.h>

int convertirCoordonnees(const char *saisie, Position *pos) {
    int erreur = 0, ligne = -1, colonne = -1;

    // Défini la colonne en fonction de l'entrée
    if (saisie[0] >= 'A' && saisie[0] <= 'J') // Si la case est en majuscule
        colonne = saisie[0] - 'A';
    else if (saisie[0] >= 'a' && saisie[0] <= 'j') // Si la case est en minuscule
        colonne = saisie[0] - 'a';
    else if ((saisie[0] > 'j' && saisie[0] <= 'z') || (saisie[0] > 'J' && saisie[0] <= 'Z'))
        erreur = 1;
    else
        erreur = 3; //Format invalide

    // Défini la ligne en fonction de l'entrée
    if (saisie[1] >= '1' && saisie[1] <= '9') {
        // Dans le cas où la case est bien rentrée
        if (saisie[1] == '1' && saisie[2] == '0') // 0 <= ligne <= 9
            ligne = 9;
        else
            ligne = saisie[1] - '0' - 1; // ligne = 10
            ligne = saisie[1] - '0' - 1; // ligne = 10
    } else if (saisie[1] == '0' || saisie[2] > '0') // 0 > ligne > 10
        erreur = 2; //Erreur ligne
    else
        erreur = 3; //Format invalide

    pos->ligne = ligne;
    pos->colonne = colonne;

    switch (erreur) {
        case 1:
            printf("Erreur : Colonne hors de la grille. Colonnes: A-J");
            break;
            case 2:
            printf("Erreur : Ligne hors de la grille. Lignes: 1-10");
            break;
            case 3:
            printf("Erreur : Coordonnées invalides. Utilisez le format lettre+chiffre (ex: B5)");
            break;
    }
    return erreur;
}

int saisirCoordonnees(Position *pos) {
    int erreur = 0;
    char tir[4];

    do {
        printf("Coordonnées de tir (ex: E5) : ");
        scanf("%s", tir);
    } while (convertirCoordonnees(tir, pos) != 0);
    return erreur;
}

int saisirOrientation(Orientation *orientation) {
    char sens;
    int retour = 0;

    printf("Orientation (H)orizontal / (V)ertical : ");
    scanf(" %c", &sens);

    // Défini l'orientation en fonction de l'entrée
    if (sens == 'V') {
        *orientation = VERTICAL;
    } else if (sens == 'H') {
        *orientation = HORIZONTAL;
    } else
        retour = 1;

    return retour;
}

int saisirTypeTir(void) {
    int typeTir = 0;
    printf("Type de tir :\n");
    printf("    [1] Tir simple (1 case)\n");
    printf("    [2] Tir croix (5 cases)\n");
    printf("Votre choix : ");

    scanf("%d", &typeTir);
    viderBuffer();
    return typeTir;
}

void viderBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void attendreTouche(void) {
    printf("\nAppuyez sur ENTRÉE pour continuer...");
    getchar();
}