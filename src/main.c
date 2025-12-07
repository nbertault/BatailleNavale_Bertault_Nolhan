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
    Position pos;
    Joueur joueur;

    printf("Quel est votre nom ?\n");
    scanf("%s", joueur.nom);

    initialiserGrille(joueur.plateau.grilleFlotte);

    joueur.naviresRestants = NB_NAVIRES;
    joueur.flotte[0] = creerNavire(PORTE_AVIONS);
    joueur.flotte[1] = creerNavire(CROISEUR);
    joueur.flotte[2] = creerNavire(CONTRE_TORPILLEUR);
    joueur.flotte[3] = creerNavire(CONTRE_TORPILLEUR);
    joueur.flotte[4] = creerNavire(SOUS_MARIN);
    joueur.flotte[5] = creerNavire(TORPILLEUR);

    placerFlotte(&joueur);


    return 0;
}