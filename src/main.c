#include <stdio.h>
#include "../include/constante.h"
#include "../include/affichage.h"
#include "../include/jeu.h"
#include "../include/joueur.h"
#include "../include/navire.h"
#include "../include/plateau.h"
#include "../include/utilitaires.h"

int main(void) {
#ifdef _WIN32
    system("chcp 65001 > nul"); // Active UTF-8 dans la console Windows
#endif

    afficherAccueil();

    Partie partie;
    initialiserPartie(&partie);

    return 0;
}
