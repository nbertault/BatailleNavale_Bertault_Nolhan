#include <stdio.h>
#include "../include/constante.h"
#include "../include/affichage.h"
#include "../include/jeu.h"
#include "../include/joueur.h"
#include "../include/navire.h"
#include "../include/plateau.h"
#include "../include/utilitaires.h"

int main(void) {
    printf("Hello, l'ENSIM !\n");
    unsigned char saisie;
    EtatCase grille[10][10];
    scanf("%c", saisie);
    initialiserGrille(grille);
    afficherGrille(grille,0);
    return 0;
}