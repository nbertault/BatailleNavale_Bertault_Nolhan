//
// Created by abomb on 26/11/2025.
//

#ifndef ALGORITHMEFONDAMENTAUXTP3_CONSTANTE_H
#define ALGORITHMEFONDAMENTAUXTP3_CONSTANTE_H

// Position sur la grille
typedef struct {
    int ligne;      // 0 à 9 (correspond à 1-10 pour l'utilisateur)
    int colonne;    // 0 à 9 (correspond à A-J pour l'utilisateur)
} Position;

/*

// Partie
typedef struct {
    Joueur joueur1;
    Joueur joueur2;
    int joueurActif;            // 1 ou 2
    int partieTerminee;         // 0 = en cours, 1 = terminée
} Partie; */

#define TAILLE_GRILLE 10
#define NB_NAVIRES 6
#define NB_TYPES_NAVIRES 5

#endif //ALGORITHMEFONDAMENTAUXTP3_CONSTANTE_H