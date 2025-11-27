//
// Created by Nolhan on 26/11/2025.
//

#include "../include/navire.h"

Navire creerNavire(TypeNavire type) {
    int casesTouchees = 0, estCoule = 0, taille;
    char nom[20];

    switch (type) {
        case PORTE_AVIONS:
            nom = "Porte-avions";
            taille = 5;
            break;
        case CROISEUR:
            nom = "Croiseur";
            taille = 4;
            break;
        case CONTRE_TORPILLEUR:
            nom = "Contre-torpilleur";
            taille = 3;
            break;
        case SOUS_MARIN:
            nom = "Sous-marin";
            taille = 3;
            break;
        case TORPILLEUR:
            nom = "Torpilleur";
            taille = 2;
            break;
    }

    Navire bateau = {type,nom,taille,casesTouchees,estCoule};
    return bateau;
}

