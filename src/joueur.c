//
// Created by Nolhan on 26/11/2025.
//

#include "../include/joueur.h"
#include "../include/affichage.h"
#include "../include/utilitaires.h"

void placerFlotte(Joueur *joueur) {
    char coordonnees[3], sens;
    Position pos;
    afficherGrille(joueur->plateau.grilleFlotte, 1);
    for (int i = joueur->naviresRestants; i > 0; i--) {
        printf("Coordonnées du bateau ?");
        scanf("%s", coordonnees);

        switch (convertirCoordonnees(coordonnees, &pos)) { //Vérifier les coordonnées rentrées
            case 1:
                printf("Erreur ligne");
                break;
            case 2:
                printf("Erreur colonne");
                break;
            case 3:
                printf("Format Invalide");
                break;
            default:
                break;
        }
        printf("Dans quelle sens ? (V ou H)");
        scanf("%c", sens);
        calculerPositions(&joueur->flotte[i], pos, (sens = 'V' ? VERTICAL  : HORIZONTAL));

    }
}
