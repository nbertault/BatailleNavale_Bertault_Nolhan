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
    EtatCase grille[10][10];
    initialiserGrille(grille);
    afficherGrille(grille,1);
    return 0;
}