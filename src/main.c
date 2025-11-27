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
    printf("Entrez la case visé\n");
    scanf("%3s", saisie);
    initialiserGrille(grille);
    afficherGrille(grille,0);
    switch (convertirCoordonnees(saisie,&pos)) {
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
    return 0;
}