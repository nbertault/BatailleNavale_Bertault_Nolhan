//
// Created by Nolhan on 26/11/2025.
//

#include "../include/joueur.h"
#include "../include/affichage.h"
#include "../include/navire.h"
#include "../include/utilitaires.h"

void initialiserJoueur(Joueur *joueur, const char *nom) {
    int i = 0;
    do {
        joueur->nom[i] = nom[i];
        i++;
    } while (nom[i - 1] != '\0');
}

void placerFlotte(Joueur *joueur) {
    char coordonnees[3], lettreSens;
    int sens = 0;
    Orientation orientation;
    Position pos;

    // Pour chaque navire
    for (int i = 0; i < NB_NAVIRES; i++) {
        effacerEcran();
        printf("=== PLACEMENT DES NAVIRES - %s ===\n", joueur->nom);
        lettreSens = ' ';
        // Affiche la grille
        afficherGrille(joueur->plateau.grilleFlotte, 1);

        // Affiche le navire en cours de placement
        printf("Placement du %s (%d cases)\n", joueur->flotte[i].nom, joueur->flotte[i].taille);

        coordonnees[0] = '\0';
        int bateauPlace = 1;
        do {
            printf("Coordonnées de départ (ex: A1) : ");
            scanf(" %s", coordonnees);

            // Gestion des erreurs des coordonnées
            switch (convertirCoordonnees(coordonnees, &pos)) {
                //Vérifier les coordonnées rentrées
                case 0:
                    do {
                        int sens = saisirOrientation(&orientation);
                        if (sens == 1)
                            printf("Orientation invalide. Utilisez le bon format (V ou H)\n");
                    }while (sens);
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
            switch (verifierPlacement(joueur->plateau.grilleFlotte, pos, joueur->flotte[i].taille, orientation)) {
                case 0:
                    // Défini les positions du navire
                    calculerPositions(&joueur->flotte[i], pos, orientation);
                    // Place le navire sur la grille
                    placerNavireSurGrille(joueur->plateau.grilleFlotte, &joueur->flotte[i]);
                    bateauPlace = 0;
                    break;
                case 1:
                    printf("Le navire dépasse de la grille avec cette orientation.\n");
                    break;
                case 2:
                    printf("Un navire occupe déjà cette position.\n");
                    break;
                default:
                    break;
            }
        } while (bateauPlace);
    }

    afficherGrille(joueur->plateau.grilleFlotte, 1);

    attendreTouche();
}

int compterNaviresRestants(Joueur *joueur) {
    int compteur = 0;

    for (int i = 0; i < NB_NAVIRES; i++) {
        if (!joueur->flotte[i].estCoule)
            compteur++;
    }

    joueur->naviresRestants = compteur;
    return compteur;
}

void mettreAJourNavire(Joueur *joueur, Position pos) {
    Navire navire = getNavire(*joueur, pos);

    if (navire.type != -1) {
        navire.casesTouchees += 1;
        estCoule(&navire);
    }
}

Navire getNavire(Joueur joueur, Position pos) {
    Navire navire;

    navire.type = -1;

    for (int i = 0; i < NB_NAVIRES; i++) {
        for (int j = 0; j < joueur.flotte[i].taille; j++) {
            if (pos.colonne == joueur.flotte[i].positions[j].colonne &&
                pos.ligne == joueur.flotte[i].positions[j].ligne) {
                navire = joueur.flotte[i];
            }
        }
    }

    return navire;
}