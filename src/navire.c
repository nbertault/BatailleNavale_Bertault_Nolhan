//
// Created by Nolhan on 26/11/2025.
//

#include "../include/navire.h"
#include <string.h>

Navire creerNavire(TypeNavire type) {
    int casesTouchees = 0, estCoule = 0, taille;
    char nom[20];

    switch (type) { //défini la taille et le nom du navire en fonction du type en entré
        case PORTE_AVIONS:
            strcpy(nom, "Porte-avions");
            taille = 5;
            break;
        case CROISEUR:
            strcpy(nom, "Croiseur");
            taille = 4;
            break;
        case CONTRE_TORPILLEUR:
            strcpy(nom, "Contre-torpilleur");
            taille = 3;
            break;
        case SOUS_MARIN:
            strcpy(nom, "Sous-marin");
            taille = 3;
            break;
        case TORPILLEUR:
            strcpy(nom, "Torpilleur");
            taille = 2;
            break;
        default:
            strcpy(nom, "Non défini");
            taille = 0;
            break;
    }
    Navire bateau;

    for (int i = 1; i <= taille; taille++) { //initialise le navire à l'horizontal et sur la première ligne
        bateau.positions->ligne = 1;
        bateau.positions->colonne = i;
    }

    bateau.type = type;
    strcpy(bateau.nom, nom);
    bateau.taille = taille;
    bateau.estCoule = estCoule;
    bateau.casesTouchees = casesTouchees;

    return bateau;
}

void calculerPositions(Navire *navire, Position debut, Orientation orientation) {
    const int taille = navire->taille;

    if (orientation == VERTICAL) {
        for (int i = 0; i < taille; i++) {
                navire->positions[i].ligne = debut.ligne;
                navire->positions[i].colonne = debut.colonne+i;
        }
    } else {
        for (int i = 0; i < taille; i++) {
            navire->positions[i].ligne = debut.ligne+i;
            navire->positions[i].colonne = debut.colonne;
        }
    }
}


const char* getNomNavire(TypeNavire type) {
    char* nom[20];
    switch (type) { //défini la taille et le nom du navire en fonction du type en entré
        case PORTE_AVIONS:
            strcpy(*nom, "Porte-avions");
            break;
        case CROISEUR:
            strcpy(*nom, "Croiseur");
            break;
        case CONTRE_TORPILLEUR:
            strcpy(*nom, "Contre-torpilleur");
            break;
        case SOUS_MARIN:
            strcpy(*nom, "Sous-marin");
            break;
        case TORPILLEUR:
            strcpy(*nom, "Torpilleur");
            break;
        default:
            strcpy(*nom, "Non défini");
            break;
    }
    return *nom;
}

int getTailleNavire(TypeNavire type) {
    int taille;

    switch (type) { //défini la taille et le nom du navire en fonction du type en entré
        case PORTE_AVIONS:
            taille = 5;
            break;
        case CROISEUR:
            taille = 4;
            break;
        case CONTRE_TORPILLEUR:
            taille = 3;
            break;
        case SOUS_MARIN:
            taille = 3;
            break;
        case TORPILLEUR:
            taille = 2;
            break;
        default:
            taille = 0;
            break;
    }

    return taille;
}
