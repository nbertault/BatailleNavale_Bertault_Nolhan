#include <stdio.h>
#include "../include/constante.h"
#include "../include/affichage.h"
#include "../include/jeu.h"
#include "../include/joueur.h"
#include "../include/navire.h"
#include "../include/plateau.h"
#include "../include/utilitaires.h"

int main(void) {
    char saisie[4];
    EtatCase grille[10][10];
    Position pos;
    Joueur *joueur;
    printf("Entrez la case visé\n");
    scanf("%3s", saisie);
    initialiserGrille(grille);
    joueur->plateau.grilleFlotte = grille;
    placerFlotte(joueur);

    return 0;
}