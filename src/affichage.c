//
// Created by Nolhan on 26/11/2025.
//

#include "../include/affichage.h"

#include <stdio.h>
#include <stdlib.h>

#include "../include/jeu.h"
#include "../include/utilitaires.h"

void afficherAccueil(void) {
    printf("╔══════════════════════════════════════════════════════╗\n");
    printf("║                                                      ║\n");
    printf("║           ⚓ BATAILLE NAVALE ⚓                      ║\n");
    printf("║                                                      ║\n");
    printf("║              MéquaLine Games                         ║\n");
    printf("║                  v1.0                                ║\n");
    printf("║                                                      ║\n");
    printf("╠══════════════════════════════════════════════════════╣\n");
    printf("║                                                      ║\n");
    printf("║  Règles :                                            ║\n");
    printf("║  - Placez vos 6 navires sur votre grille             ║\n");
    printf("║  - Coulez tous les navires adverses pour gagner      ║\n");
    printf("║  - Tir simple : 1 case                               ║\n");
    printf("║  - Tir en croix : 5 cases (+ bonus)                  ║\n");
    printf("║                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════╝\n");

    attendreTouche();
}

void afficherGrille(EtatCase grille[TAILLE_GRILLE][TAILLE_GRILLE], int montrerNavires) {
    printf("    A   B   C   D   E   F   G   H   I   J\n");
    for (int i = 1; i <= TAILLE_GRILLE; i++) {
        printf("  +---+---+---+---+---+---+---+---+---+---+\n");
        i < TAILLE_GRILLE ? printf("%d ", i) : printf("%d", i);
        for (int j = 1; j <= TAILLE_GRILLE; j++) {
            switch (grille[i - 1][j - 1]) {
                case VIDE:
                    printf("|   ");
                    break;
                case TOUCHE:
                    printf("| X ");
                    break;
                case MANQUE:
                    printf("| - ");
                    break;
                case NAVIRE:
                    if (montrerNavires == 1)
                        printf("| O ");
                    break;
            }
        }
        printf("|\n");
    }
    printf("  +---+---+---+---+---+---+---+---+---+---+\n");
}

void afficherGrillesJoueur(Joueur *joueur) {
    afficherGrille(joueur->plateau.grilleRadar, 0);

    printf("\033[4;50H");
    printf("    A   B   C   D   E   F   G   H   I   J\n");

    for (int i = 1; i <= TAILLE_GRILLE; i++) {
        printf("\033[%d;50H", 3 + i * 2);
        printf("  +---+---+---+---+---+---+---+---+---+---+\n");

        printf("\033[%d;50H", 3 + i * 2 + 1);
        i < TAILLE_GRILLE ? printf("%d ", i) : printf("%d", i);
        for (int j = 1; j <= TAILLE_GRILLE; j++) {
            switch (joueur->plateau.grilleFlotte[i - 1][j - 1]) {
                case VIDE:
                    printf("|   ");
                    break;
                case TOUCHE:
                    printf("| X ");
                    break;
                case MANQUE:
                    printf("| - ");
                    break;
                case NAVIRE:
                        printf("| O ");
                    break;
            }
        }
        printf("|\n");
    }
    printf("\033[%d;50H", 5 + TAILLE_GRILLE * 2);

    printf("  +---+---+---+---+---+---+---+---+---+---+\n");
    printf("\033[%d;0H", 5 + TAILLE_GRILLE * 2 + 2);
}

void afficherResultatTir(ResultatTir resultat, const char *nomNavire) {
    switch (resultat) {
        case TIR_EAU:
            printf(">>> Manqué <<<\n");
            break;
        case TIR_TOUCHE:
            printf(">>> Touché ! <<\n");
            break;
        case TIR_COULE:
            printf("╔══════════════════════════════════════════════════════╗\n");
            printf("║           💥 COULÉ ! 💥                              ║\n");
            printf("║      Vous avez coulé le %15s ennemi !         ║\n", nomNavire);
            printf("╚══════════════════════════════════════════════════════╝\n");
            break;
        case TIR_INVALIDE:
            printf(">>> Tir Invalide <<<\n");
            break;
        case TIR_DEJA_JOUE:
            printf(">>> Vous avez déja joué ce coup <<<\n");
            break;
    }
}

void afficherVictoire(const char *nomGagnant, int nbTirs, int tirsReussis) {
    effacerEcran();
    double moyenne = tirsReussis * 100.0 / nbTirs;
    printf("╔══════════════════════════════════════════════════════╗\n");
    printf("║                                                      ║\n");
    printf("║           🏆 VICTOIRE ! 🏆                           ║\n");
    printf("║                                                      ║\n");
    printf("║              %s remporte la partie !              ║\n", nomGagnant);
    printf("║                                                      ║\n");
    printf("╠══════════════════════════════════════════════════════╣\n");
    printf("║  Statistiques :                                      ║\n");
    printf("║  - Tirs effectués : %d                               ║\n", nbTirs);
    printf("║  - Tirs réussis : %d                                 ║\n", tirsReussis);
    printf("║  - Précision : %.2f %%                               ║\n", moyenne);
    printf("║                                                      ║\n");
    printf("║                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════╝\n");

    attendreTouche();
}

void effacerEcran(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
