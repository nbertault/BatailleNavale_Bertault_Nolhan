//
// Created by Nolhan on 26/11/2025.
//

#include "../include/jeu.h"

#include "../include/affichage.h"
#include "../include/navire.h"
#include "../include/utilitaires.h"
#include "../include/joueur.h"

void initialiserPartie(Partie *partie) {
    partie->joueurActif = 1;

    initialiserGrille(partie->joueur1.plateau.grilleFlotte);
    initialiserGrille(partie->joueur2.plateau.grilleFlotte);
    initialiserGrille(partie->joueur1.plateau.grilleRadar);
    initialiserGrille(partie->joueur2.plateau.grilleRadar);

    partie->joueur1.nbTirs = 0;
    partie->joueur1.precisionTir = 0;

    partie->joueur2.nbTirs = 0;
    partie->joueur2.precisionTir = 0;

    partie->joueur1.naviresRestants = NB_NAVIRES;
    partie->joueur1.flotte[0] = creerNavire(PORTE_AVIONS);
    partie->joueur1.flotte[1] = creerNavire(CROISEUR);
    partie->joueur1.flotte[2] = creerNavire(CONTRE_TORPILLEUR);
    partie->joueur1.flotte[3] = creerNavire(CONTRE_TORPILLEUR);
    partie->joueur1.flotte[4] = creerNavire(SOUS_MARIN);
    partie->joueur1.flotte[5] = creerNavire(TORPILLEUR);

    partie->joueur2.naviresRestants = NB_NAVIRES;
    partie->joueur2.flotte[0] = creerNavire(PORTE_AVIONS);
    partie->joueur2.flotte[1] = creerNavire(CROISEUR);
    partie->joueur2.flotte[2] = creerNavire(CONTRE_TORPILLEUR);
    partie->joueur2.flotte[3] = creerNavire(CONTRE_TORPILLEUR);
    partie->joueur2.flotte[4] = creerNavire(SOUS_MARIN);
    partie->joueur2.flotte[5] = creerNavire(TORPILLEUR);

    char joueur1[50], joueur2[50];
    effacerEcran();
    printf("=== CONFIGURATION DE LA PARTIE ===\n\n");
    printf("Nom du Joueur 1 : ");
    scanf("%s", joueur1);
    initialiserJoueur(&partie->joueur1, joueur1);
    viderBuffer();
    printf("Nom du Joueur 2 : ");
    scanf("%s", joueur2);
    initialiserJoueur(&partie->joueur2, joueur2);
    viderBuffer();
    printf("\nBienvenue %s et %s !\n", partie->joueur1.nom, partie->joueur2.nom);
    printf("La partie va commencer...\n\n");
    attendreTouche();
    placerFlotte(&partie->joueur1);
    placerFlotte(&partie->joueur2);
    lancerPartie(partie);
}

void jouerTour(Partie *partie) {
    Joueur *joueur, *adversaire;
    Position pos;

    effacerEcran();

    if (partie->joueurActif == 1) {
        printf(ROUGE);
        adversaire = &partie->joueur2;
        joueur = &partie->joueur1;
    } else {
        printf(VERT);
        adversaire = &partie->joueur1;
        joueur = &partie->joueur2;
    }

    printf("╔══════════════════════════════════════════════════════╗\n");
    printf("║              TOUR DE : %s                         ║\n", joueur->nom);
    printf("╚══════════════════════════════════════════════════════╝\n");

    afficherGrillesJoueur(joueur);

    printf("Navires ennemis restants : %d/6\n", compterNaviresRestants(adversaire));
    printf("Vos navires restants : %d/6\n", compterNaviresRestants(joueur));

    int typeTir;
    printf(RESET);

    do {
        typeTir = saisirTypeTir();
    } while (typeTir != 1 && typeTir != 2);


    if (typeTir == 1) {
        joueur->nbTirs++;
        ResultatTir tir;
        do {
            saisirCoordonnees(&pos);
            tir = appliquerTir(adversaire, pos);
            if (tir == TIR_COULE || tir == TIR_TOUCHE)
                joueur->precisionTir++;
            afficherResultatTir(tir, getNavire(*adversaire, pos).nom);
        } while (tir == TIR_INVALIDE || tir == TIR_DEJA_JOUE);
        joueur->plateau.grilleRadar[pos.ligne][pos.colonne] = adversaire->plateau.grilleFlotte[pos.ligne][pos.
            colonne];
    } else {
        joueur->nbTirs += 5;
        saisirCoordonnees(&pos);
        appliquerTirCroix(joueur, adversaire, pos);
    }

    attendreTouche();
    viderBuffer();
}

void lancerPartie(Partie *partie) {
    int fin = 0;
    do {
        jouerTour(partie);
        changerJoueur(partie);
        fin = verifierFinPartie(partie);
    } while (fin == 0);

    if (fin == 1)
        afficherVictoire(partie->joueur1.nom, partie->joueur1.nbTirs, partie->joueur1.precisionTir);
    else
        afficherVictoire(partie->joueur2.nom, partie->joueur2.nbTirs, partie->joueur2.precisionTir);


    if (demanderRejouer()) {
        initialiserPartie(partie);
    } else {
        printf("Merci d'avoir joué\n");
        attendreTouche();
    }
}

int verifierFinPartie(Partie *partie) {
    int retour = 0;

    if (partie->joueur1.naviresRestants == 0) {
        retour = 2;
    }

    if (partie->joueur2.naviresRestants == 0) {
        retour = 1;
    }

    return retour;
}

void changerJoueur(Partie *partie) {
    if (partie->joueurActif == 1)
        partie->joueurActif = 2;
    else
        partie->joueurActif = 1;
}

int demanderRejouer(void) {
    char rejouer;
    do {
        printf("Voulez-vous rejouer ? (O/N) : ");
        rejouer = getchar();
        viderBuffer();
    } while (rejouer != 'O' && rejouer != 'N');

    int retour;
    if (rejouer == 'O')
        retour = 1;
    else
        retour = 0;

    return retour;
}