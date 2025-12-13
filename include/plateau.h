//
// Created by Nolhan on 26/11/2025.
//

#ifndef ALGORITHMEFONDAMENTAUXTP3_PLATEAU_H
#define ALGORITHMEFONDAMENTAUXTP3_PLATEAU_H
#include "constante.h"

// Initialise une grille avec des cases vides
void initialiserGrille(EtatCase grille[10][10]);

// Vérifie si un placement est valide
int verifierPlacement(EtatCase grille[10][10], Position debut,
                      int taille, Orientation orientation);

// Place un navire sur la grille
void placerNavireSurGrille(EtatCase grille[10][10], Navire *navire);

// Applique un tir sur la grille
ResultatTir appliquerTir(Joueur *cible, Position pos);

// Applique un tir en croix
void appliquerTirCroix(Joueur *tireur, Joueur *cible, Position centre);

#endif //ALGORITHMEFONDAMENTAUXTP3_PLATEAU_H