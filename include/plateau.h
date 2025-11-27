//
// Created by Nolhan on 26/11/2025.
//

#ifndef ALGORITHMEFONDAMENTAUXTP3_PLATEAU_H
#define ALGORITHMEFONDAMENTAUXTP3_PLATEAU_H
#include "constante.h"
#include "navire.h"

// État d'une case
typedef enum {
    VIDE,           // Case non occupée, non ciblée
    NAVIRE,         // Case occupée par un navire (non touché), 'O'
    TOUCHE,         // Case occupée et touchée, 'X'
    MANQUE          // Case ciblée mais vide (à l'eau), '-'
} EtatCase;

// Résultat d'un tir
typedef enum {
    TIR_EAU,
    TIR_TOUCHE,
    TIR_COULE,
    TIR_INVALIDE,
    TIR_DEJA_JOUE
} ResultatTir;

// Plateau d'un joueur
typedef struct {
    EtatCase grilleFlotte[10][10];  // Grille avec ses navires
    EtatCase grilleRadar[10][10];   // Grille de suivi des tirs
} Plateau;

// Initialise une grille avec des cases vides
void initialiserGrille(EtatCase grille[10][10]);

// Vérifie si un placement est valide
int verifierPlacement(EtatCase grille[10][10], Position debut,
                      int taille, Orientation orientation);

/*
// Place un navire sur la grille
void placerNavireSurGrille(EtatCase grille[10][10], Navire *navire);

// Applique un tir sur la grille
ResultatTir appliquerTir(Joueur *cible, Position pos);

// Applique un tir en croix
void appliquerTirCroix(Joueur *tireur, Joueur *cible, Position centre);
*/
#endif //ALGORITHMEFONDAMENTAUXTP3_PLATEAU_H