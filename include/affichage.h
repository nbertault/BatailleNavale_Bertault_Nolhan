//
// Created by Nolhan on 26/11/2025.
//

#ifndef ALGORITHMEFONDAMENTAUXTP3_AFFICHAGE_H
#define ALGORITHMEFONDAMENTAUXTP3_AFFICHAGE_H
#include "plateau.h"
#include <stdio.h>

// Affiche l'écran d'accueil
void afficherAccueil(void);

// Affiche une grille (flotte ou radar)
void afficherGrille(EtatCase grille[10][10], int montrerNavires);

// Affiche les deux grilles d'un joueur côte à côte
void afficherGrillesJoueur(Joueur *joueur);

// Affiche le résultat d'un tir
void afficherResultatTir(ResultatTir resultat, const char *nomNavire);

// Affiche le message de victoire
void afficherVictoire(const char *nomGagnant, int nbTirs, int tirsReussis);

// Efface l'écran (transition entre joueurs)
void effacerEcran(void);

/*
// Affiche la liste des navires à placer
void afficherNaviresAPlacer(Joueur *joueur);
*/
#endif //ALGORITHMEFONDAMENTAUXTP3_AFFICHAGE_H