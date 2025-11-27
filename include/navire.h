//
// Created by Nolhan on 26/11/2025.
//

#ifndef ALGORITHMEFONDAMENTAUXTP3_NAVIRE_H
#define ALGORITHMEFONDAMENTAUXTP3_NAVIRE_H
#include "constante.h"

// Orientation d'un navire
typedef enum {
    HORIZONTAL,
    VERTICAL
} Orientation;

// Type de navire
typedef enum {
    PORTE_AVIONS,
    CROISEUR,
    CONTRE_TORPILLEUR,
    SOUS_MARIN,
    TORPILLEUR
} TypeNavire;

// Navire
typedef struct {
    TypeNavire type;
    char nom[20];
    int taille;
    Position positions[5];      // Tableau des positions occupées
    int casesTouchees;          // Nombre de cases touchées
    int estCoule;               // 0 = non, 1 = oui
} Navire;

// Crée et initialise un navire selon son type
Navire creerNavire(TypeNavire type);

// Calcule les positions d'un navire à partir de sa position de départ
void calculerPositions(Navire *navire, Position debut, Orientation orientation);

/*
// Vérifie si un navire est coulé
int estCoule(Navire *navire);
*/

// Retourne le nom d'un type de navire
const char* getNomNavire(TypeNavire type);

// Retourne la taille d'un type de navire
int getTailleNavire(TypeNavire type);
#endif //ALGORITHMEFONDAMENTAUXTP3_NAVIRE_H