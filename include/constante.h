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
// Navire
typedef struct {
    TypeNavire type;
    char nom[20];
    int taille;
    Position positions[5];      // Tableau des positions occupées
    int casesTouchees;          // Nombre de cases touchées
    int estCoule;               // 0 = non, 1 = oui
} Navire;

// Plateau d'un joueur
typedef struct {
    EtatCase grilleFlotte[10][10];  // Grille avec ses navires
    EtatCase grilleRadar[10][10];   // Grille de suivi des tirs
} Plateau;

// Joueur
typedef struct {
    char nom[50];
    Plateau plateau;
    Navire flotte[6];           // Les 6 navires
    int naviresRestants;        // Navires non coulés
} Joueur;

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