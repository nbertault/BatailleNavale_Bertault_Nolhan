#include <stdio.h>
#include "../include/constante.h"
#include "../include/affichage.h"
#include "../include/jeu.h"
#include "../include/joueur.h"
#include "../include/navire.h"
#include "../include/plateau.h"
#include "../include/utilitaires.h"

int main(void) {
    char saisie[4],saisieTire[4];
    Position pos, posTire;
    Joueur joueur1, joueur2;

    printf("Quel est votre nom ?(Joueur1)\n");
    scanf("%s", joueur1.nom);

    initialiserGrille(joueur1.plateau.grilleFlotte);

    joueur1.naviresRestants = NB_NAVIRES;
    joueur1.flotte[0] = creerNavire(PORTE_AVIONS);
    joueur1.flotte[1] = creerNavire(CROISEUR);
    joueur1.flotte[2] = creerNavire(CONTRE_TORPILLEUR);
    joueur1.flotte[3] = creerNavire(CONTRE_TORPILLEUR);
    joueur1.flotte[4] = creerNavire(SOUS_MARIN);
    joueur1.flotte[5] = creerNavire(TORPILLEUR);

    // Placement Manuel pour les tests
    calculerPositions(&joueur1.flotte[0], (Position){2,2}, HORIZONTAL);
    calculerPositions(&joueur1.flotte[1], (Position){3,3}, VERTICAL);
    calculerPositions(&joueur1.flotte[2], (Position){9,0}, HORIZONTAL);
    calculerPositions(&joueur1.flotte[3], (Position){6,5}, HORIZONTAL);
    calculerPositions(&joueur1.flotte[4], (Position){7,4}, HORIZONTAL);
    calculerPositions(&joueur1.flotte[5], (Position){8,0}, HORIZONTAL);
    placerFlotte(&joueur1);

    printf("Ou tirez-vous ?");
    scanf("%s", saisieTire);
    convertirCoordonnees(saisieTire, &posTire);

    switch (appliquerTir(&joueur1, posTire)) {
        case TIR_COULE:
            printf("Bateau coule");
            break;
        case TIR_EAU:
            printf("Tire rate");
            break;
        case TIR_DEJA_JOUE:
            printf("Tire deja placer");
            break;
        case TIR_INVALIDE:
            printf("Mauvaise Coordonnees");
            break;
        case TIR_TOUCHE:
            printf("Bateau touche");
            break;
    }

    return 0;
}