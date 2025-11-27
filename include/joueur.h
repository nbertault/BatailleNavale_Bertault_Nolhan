//
// Created by Nolhan on 26/11/2025.
//

#ifndef ALGORITHMEFONDAMENTAUXTP3_JOUEUR_H
#define ALGORITHMEFONDAMENTAUXTP3_JOUEUR_H
#include "constante.h"
#include "navire.h"
#include "plateau.h"

// Joueur
typedef struct {
    char nom[50];
    Plateau plateau;
    Navire flotte[6];           // Les 6 navires
    int naviresRestants;        // Navires non coulés
} Joueur;

/*
// Initialise un joueur avec son nom
void initialiserJoueur(Joueur *joueur, const char *nom);
*/

// Gère le placement de tous les navires d'un joueur
void placerFlotte(Joueur *joueur);

/*
// Compte les navires restants (non coulés)
int compterNaviresRestants(Joueur *joueur);

// Met à jour l'état d'un navire après un tir
void mettreAJourNavire(Joueur *joueur, Position pos);
*/
#endif //ALGORITHMEFONDAMENTAUXTP3_JOUEUR_H