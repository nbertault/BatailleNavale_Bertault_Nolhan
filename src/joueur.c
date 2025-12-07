//
// Created by Nolhan on 26/11/2025.
//

#include "../include/joueur.h"
#include "../include/affichage.h"
#include "../include/utilitaires.h"

void placerFlotte(Joueur *joueur) {
    char coordonnees[3], sens;
    Orientation orientation;
    Position pos;

    // Pour chaque navire
    for (int i = 0; i < NB_NAVIRES; i++) {
        sens = ' ';

        // Affiche la grille
        afficherGrille(joueur->plateau.grilleFlotte, 1);

        // Affiche le neavire en cours de placement
        printf("Vous etes en train de placer : %s\n", joueur->flotte[i].nom);

        coordonnees[0] = '\0';
        int bateauPlace = 1;
        do {
            printf("Coordonnees du bateau ?\n");
            scanf(" %s", coordonnees);

            // Gestion des erreurs des coordonnées
            switch (convertirCoordonnees(coordonnees, &pos)) { //Vérifier les coordonnées rentrées
                case 0:
                    printf("Dans quelle sens ? (V ou H)\n");
                    scanf(" %c", &sens);

                    // Défini l'orientation en fonction de l'entrée
                    if (sens == 'V') {
                        orientation = VERTICAL;
                    } else if (sens == 'H') {
                        orientation = HORIZONTAL;
                    }

                    break;
                case 1:
                    printf("Position hors de la grille (Colonnes: A-J)\n");
                    break;
                case 2:
                    printf("Position hors de la grille (Lignes: 1-10)\n");
                    break;
                case 3:
                    printf("Coordonnées invalides. Utilisez le format lettre+chiffre (ex: B5)\n");
                    break;
                default:
                    break;
            }

            // Gestion des erreurs du placements
            switch(verifierPlacement(joueur->plateau.grilleFlotte,pos,joueur->flotte[i].taille, orientation)) {
                case 0:
                    // Défini les positions du navire
                    calculerPositions(&joueur->flotte[i], pos, orientation);
                    // Place le navire sur la grille
                    placerNavireSurGrille(joueur->plateau.grilleFlotte,&joueur->flotte[i]);
                    bateauPlace = 0;
                    break;
                case 1:
                    printf("Le bateau depasse du plateau avec cette orientation\n");
                    break;
                case 2:
                    printf("Un navire occupe deja cette position\n");
                    break;
                default:
                    break;
            }
        }while (bateauPlace);
    }
}