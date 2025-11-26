# TP3 - Algorithmique Fondamentaux
## Développement d'un Jeu de Bataille Navale en C

<p>
  <img 
    src="https://upload.wikimedia.org/wikipedia/commons/8/86/LOGO-ensim-couleur-HD.png" 
    width="550"
    alt="Logo ENSIM">
</p>

**1er Cycle Ingénieur | Niveau Bac+3**

**Module : Algorithmique Fondamentaux**

---

## Table des matières

1. [Introduction pédagogique](#1-introduction-pédagogique)
2. [Objectifs pédagogiques](#2-objectifs-pédagogiques)
3. [Contexte professionnel](#3-contexte-professionnel)
4. [Règles du jeu - Version classique](#4-règles-du-jeu---version-classique)
5. [Règles simplifiées appliquées au TP](#5-règles-simplifiées-appliquées-au-tp)
6. [Logigramme - Phase d'initialisation](#6-logigramme---phase-dinitialisation)
7. [Logigramme - Déroulement d'un tour](#7-logigramme---déroulement-dun-tour)
8. [Contraintes techniques obligatoires](#8-contraintes-techniques-obligatoires)
9. [Architecture du projet](#9-architecture-du-projet)
10. [Types personnalisés à implémenter](#10-types-personnalisés-à-implémenter)
11. [Fonctions obligatoires](#11-fonctions-obligatoires)
12. [Exercices guidés](#12-exercices-guidés)
13. [Exemples d'affichage attendu](#13-exemples-daffichage-attendu)
14. [FAQ et erreurs courantes](#14-faq-et-erreurs-courantes)
15. [Consignes de rendu GitHub](#15-consignes-de-rendu-github)
16. [Barème de notation](#16-barème-de-notation)
17. [Checklist d'évaluation](#17-checklist-dévaluation)

---

## 1. Introduction pédagogique

Ce travail pratique constitue du module d'Algorithmique Fondamentaux. Il mobilise l'ensemble des compétences acquises au cours du semestre : manipulation de variables, structures de contrôle, tableaux multidimensionnels, pointeurs, fonctions, structures de données personnalisées et programmation modulaire.

Le développement d'un jeu de bataille navale représente un excellent exercice d'intégration car il nécessite de concevoir une architecture logicielle cohérente, de gérer des états complexes et d'implémenter des algorithmes de recherche et de validation.

**Prérequis nécessaires :**
- Maîtrise des types primitifs et des opérateurs en C
- Manipulation des tableaux à une et/ou plusieurs dimensions
- Compréhension des pointeurs et du passage par référence
- Création et utilisation de structures (`struct`) et énumérations (`enum`)
- Écriture de fonctions avec prototypes
- Lecture et écriture formatées (`printf`, `scanf`)
- Notions de programmation modulaire (fichiers `.h` et `.c`)
- Utilisation basique de Git

---

## 2. Objectifs pédagogiques

À l'issue de ce TP, vous serez capable de :

### Compétences techniques
- **Structurer** un programme C en plusieurs fichiers sources et en-têtes
- **Déclarer et manipuler** des types personnalisés (structures, énumérations, tableaux de structures)
- **Implémenter** des algorithmes de recherche et de validation sur des tableaux bidimensionnels
- **Utiliser** les pointeurs pour le passage de paramètres par référence
- **Concevoir** des fonctions modulaires avec une responsabilité unique
- **Gérer** les entrées utilisateur avec validation et gestion d'erreurs

### Compétences transversales
- **Respecter** un cahier des charges technique précis
- **Produire** un code lisible, commenté et maintenable
- **Appliquer** les conventions de nommage et de formatage
- **Utiliser** un système de gestion de versions (Git/GitHub)
- **Documenter** son travail de manière professionnelle

---

## 3. Contexte professionnel

Vous avez été mandaté par **MéquaLine Games**, une entreprise spécialisée dans les jeux de société numériques, pour développer un **Proof of Concept (POC)** d'une bataille navale jouable en terminal.

### Mission
Produire une première version fonctionnelle du moteur de jeu qui servira de base technique pour le futur prototype de la gamme **« MéquaLine - Bataille Navale »**.

### Exigences du client
- Code **modulaire** et **réutilisable** pour faciliter les évolutions futures
- Interface utilisateur **claire** et **intuitive** en mode console
- **Robustesse** face aux erreurs de saisie utilisateur
- **Documentation** technique minimale (commentaires, nommage explicite)

### Livrables attendus
1. Code source complet et fonctionnel
2. Fichiers organisés selon l'architecture imposée
3. Programme compilable sans erreurs ni warnings
4. Dépôt GitHub respectant les conventions de versionnement

---

## 4. Règles du jeu - Version classique

> **Ressource vidéo :** [Règles officielles de la Bataille Navale](https://www.youtube.com/watch?v=Sd774wAvXB0)

### Principe général
La bataille navale oppose deux joueurs. Chaque joueur dispose d'une flotte de navires qu'il positionne secrètement sur sa grille. À tour de rôle, les joueurs tentent de localiser et de couler les navires adverses en annonçant des coordonnées de tir.

### Déroulement classique
1. **Phase de placement** : Chaque joueur place ses navires sur sa grille personnelle
2. **Phase de jeu** : Les joueurs alternent les tirs jusqu'à ce qu'une flotte soit entièrement coulée
3. **Fin de partie** : Le premier joueur à couler tous les navires adverses remporte la victoire

---

## 5. Règles simplifiées appliquées au TP

### 5.1 Configuration de la grille

| Paramètre | Valeur |
|-----------|--------|
| Dimensions | 10 × 10 cases |
| Colonnes | A à J |
| Lignes | 1 à 10 |
| Nombre de joueurs | 2 |

### 5.2 Grilles par joueur

Chaque joueur dispose de **deux grilles** :

| Grille | Fonction |
|--------|----------|
| **Grille Flotte** | Affiche les navires du joueur et les tirs adverses reçus |
| **Grille Radar** | Affiche les tirs effectués par le joueur sur la zone adverse |

### 5.3 Composition de la flotte

Chaque joueur possède **6 navires** :

| Type de navire | Taille (cases) | Quantité | Symbole |
|----------------|----------------|----------|---------|
| Porte-avions | 5 | 1 | P |
| Croiseur | 4 | 1 | C |
| Contre-torpilleur | 3 | 2 | T |
| Sous-marin | 3 | 1 | S |
| Torpilleur | 2 | 1 | O |

**Total : 6 navires occupant 21 cases**

### 5.4 Règles de placement

- Les navires sont positionnés **horizontalement** ou **verticalement** uniquement
- Les navires **ne peuvent pas se chevaucher**
- Les navires **ne peuvent pas dépasser** les limites de la grille
- Chaque navire doit être **entièrement positionné** avant de passer au suivant

### 5.5 Types de tirs

| Type | Description | Effet |
|------|-------------|-------|
| **Tir simple** | Cible une seule case | Touche uniquement la case visée |
| **Tir en croix** | Cible une case centrale + 4 cases adjacentes | Touche la case visée + cases Nord, Sud, Est, Ouest |

**Schéma du tir en croix (cible : E5) :**
```
      E4
       ↑
D5 ← [E5] → F5
       ↓
      E6
```

### 5.6 Résultats possibles d'un tir

| Résultat | Condition | Affichage |
|----------|-----------|-----------|
| **À l'eau** | Aucun navire sur la case | `~` ou `O` |
| **Touché** | Case occupée par un navire non coulé | `X` |
| **Coulé** | Dernière case d'un navire touchée | Message spécial + `X` |

### 5.7 Conditions de victoire

Le premier joueur ayant **coulé tous les navires adverses** remporte la partie.

### 5.8 Option de rejeu

À la fin de chaque partie, les joueurs peuvent choisir de **recommencer une nouvelle partie** ou de **quitter le jeu**.

---

## 6. Logigramme - Phase d'initialisation

```
                    ┌─────────────────┐
                    │     DÉBUT       │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │ Afficher écran  │
                    │   d'accueil     │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │  Saisir nom     │
                    │   Joueur 1      │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │  Saisir nom     │
                    │   Joueur 2      │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │ Initialiser les │
                    │ grilles vides   │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │ joueurCourant=1 │
                    └────────┬────────┘
                             │
                             ▼
            ┌───────────────────────────────┐
            │  Tous les navires des 2       │
       ┌────│  joueurs sont placés ?        │────┐
       │    └───────────────────────────────┘    │
       │ NON                                 OUI │
       ▼                                         ▼
┌──────────────┐                        ┌─────────────────┐
│ Afficher     │                        │ Aller à la      │
│ grille du    │                        │ phase de jeu    │
│ joueur       │                        └─────────────────┘
└──────┬───────┘
       │
       ▼
┌──────────────┐
│ Reste-t-il   │
│ des navires  │───────────────────┐
│ à placer ?   │                   │
└──────┬───────┘                   │
       │ OUI                   NON │
       ▼                           ▼
┌──────────────┐            ┌──────────────┐
│ Sélectionner │            │ Changer de   │
│ navire       │            │ joueur       │
└──────┬───────┘            └──────┬───────┘
       │                           │
       ▼                           │
┌──────────────┐                   │
│ Saisir       │                   │
│ coordonnées  │                   │
│ + orientation│                   │
└──────┬───────┘                   │
       │                           │
       ▼                           │
┌──────────────┐                   │
│ Position     │                   │
│ valide ?     │                   │
└──────┬───────┘                   │
       │                           │
  OUI  │  NON                      │
   ┌───┴───┐                       │
   │       │                       │
   ▼       ▼                       │
┌──────┐ ┌──────────┐              │
│Placer│ │ Afficher │              │
│navire│ │ erreur   │              │
└──┬───┘ └────┬─────┘              │
   │          │                    │
   │          └──────────┐         │
   │                     │         │
   └─────────────────────┴─────────┘
              │
              ▼
        (Retour boucle)
```

### Description des étapes

1. **Saisie des informations** : Collecte des noms des deux joueurs
2. **Initialisation** : Création des grilles vides (10×10) pour chaque joueur
3. **Boucle de placement** : Pour chaque joueur, placement séquentiel de tous les navires
4. **Validation** : Vérification que le placement respecte les contraintes
5. **Transition** : Passage à la phase de jeu une fois tous les navires placés

---

## 7. Logigramme - Déroulement d'un tour

```
                    ┌─────────────────┐
                    │  DÉBUT DU TOUR  │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │ Afficher grille │
                    │ radar du joueur │
                    │ courant         │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │ Choisir type    │
                    │ de tir          │
                    │ (simple/croix)  │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │ Saisir          │
                    │ coordonnées     │
                    │ cible (ex: B5)  │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │ Coordonnées     │
                    │ valides ?       │
                    └────────┬────────┘
                             │
                ┌────────────┴────────────┐
                │ NON                 OUI │
                ▼                         ▼
       ┌─────────────────┐      ┌─────────────────┐
       │ Afficher        │      │ Case déjà       │
       │ message erreur  │      │ ciblée ?        │
       └────────┬────────┘      └────────┬────────┘
                │                        │
                │               ┌────────┴────────┐
                │               │ OUI         NON │
                │               ▼                 ▼
                │      ┌─────────────┐   ┌─────────────────┐
                │      │ Afficher    │   │ Exécuter le     │
                │      │ "Déjà tiré" │   │ tir             │
                │      └──────┬──────┘   └────────┬────────┘
                │             │                   │
                │             │                   ▼
                └─────────────┤          ┌─────────────────┐
                              │          │ Évaluer         │
                              │          │ résultat        │
                              │          └────────┬────────┘
                              │                   │
                              │     ┌─────────────┼─────────────┐
                              │     │             │             │
                              │     ▼             ▼             ▼
                              │  ┌──────┐    ┌────────┐   ┌─────────┐
                              │  │À l'eau│   │ Touché │   │ Coulé   │
                              │  └───┬───┘   └───┬────┘   └────┬────┘
                              │      │           │             │
                              │      ▼           ▼             ▼
                              │  ┌──────┐    ┌────────┐   ┌─────────┐
                              │  │Marquer│   │Marquer │   │Marquer  │
                              │  │grilles│   │grilles │   │+ message│
                              │  └───┬───┘   └───┬────┘   └────┬────┘
                              │      │           │             │
                              │      └─────┬─────┴─────────────┘
                              │            │
                              │            ▼
                              │   ┌─────────────────┐
                              │   │ Flotte adverse  │
                              │   │ coulée ?        │
                              │   └────────┬────────┘
                              │            │
                              │   ┌────────┴────────┐
                              │   │ NON         OUI │
                              │   ▼                 ▼
                              │ ┌──────────┐  ┌───────────────┐
                              │ │ Changer  │  │ Déclarer      │
                              │ │ joueur   │  │ vainqueur     │
                              │ └────┬─────┘  └───────┬───────┘
                              │      │                │
                              │      │                ▼
                              │      │        ┌───────────────┐
                              │      │        │ Rejouer ?     │
                              │      │        └───────┬───────┘
                              │      │                │
                              │      │        ┌───────┴───────┐
                              │      │        │ OUI       NON │
                              │      │        ▼               ▼
                              │      │   ┌─────────┐   ┌─────────┐
                              │      │   │ Reset   │   │  FIN    │
                              │      │   │ partie  │   │         │
                              │      │   └─────────┘   └─────────┘
                              │      │
                              └──────┴───────────────────┐
                                                         │
                                            (Retour début tour)
```

---

## 8. Contraintes techniques obligatoires

### 8.1 Contraintes de compilation

| Contrainte | Exigence                                       |
|------------|------------------------------------------------|
| Compilateur | GCC (MinGW sous Windows, GCC sous Linux/macOS) |
| Standard | C99 minimum                                    |
| Options | `-Wall -Wextra -std=c99`                       |
| Résultat | **Aucun warning notable, aucune erreur**       |

### 8.2 Contraintes de structure

- Le projet **doit** être divisé en plusieurs fichiers `.c` et `.h`
- Chaque fichier `.c` (sauf `main.c`) doit avoir son fichier `.h` correspondant
- Les fichiers `.h` doivent utiliser des **guards d'inclusion** (`#ifndef`, `#define`, `#endif`)
- Le fichier `main.c` contient **uniquement** la fonction `main()`

### 8.3 Contraintes de codage

| Règle | Description                                            |
|-------|--------------------------------------------------------|
| Nommage variables | `camelCase` (ex: `nomJoueur`, `positionX`)             |
| Nommage fonctions | `camelCase` (ex: `placerNavire`, `verifierTir`)        |
| Nommage constantes | `MAJUSCULES_SNAKE` (ex: `TAILLE_GRILLE`, `NB_NAVIRES`) |
| Nommage structures | `CamelCase` (ex: `Navire`, `Plateau`, `Joueur`)        |
| Indentation | 4 espaces (pas de tabulations)                         |
| Commentaires | En français, pertinents et non redondants              |
| Longueur ligne | Envion 100 caractères max, votre IDE vous guide        |

### 8.4 Contraintes fonctionnelles

- Validation **systématique** des entrées utilisateur
- Messages d'erreur **explicites** et informatifs
- Aucune variable globale (sauf constantes `#define` ou `const`)
- Pas de `goto`
- Utilisation de `return` pour indiquer le succès/échec des fonctions

---

## 9. Architecture du projet

### 9.1 Arborescence imposée

```
BatailleNavale/
│
├── src/
│   ├── main.c              # Point d'entrée du programme
│   ├── jeu.c               # Logique principale du jeu
│   ├── plateau.c           # Gestion des grilles
│   ├── navire.c            # Gestion des navires
│   ├── joueur.c            # Gestion des joueurs
│   ├── affichage.c         # Fonctions d'affichage
│   └── utilitaires.c       # Fonctions utilitaires
│
├── include/
│   ├── jeu.h
│   ├── plateau.h
│   ├── navire.h
│   ├── joueur.h
│   ├── affichage.h
│   ├── utilitaires.h
│   └── constantes.h        # Constantes globales du projet
│
├── .gitignore
├── README.md
└── CMakeLists                # (Bonus)
```

### 9.2 Description des modules

| Module | Responsabilité |
|--------|----------------|
| `main.c` | Initialisation et boucle principale |
| `jeu.c/.h` | Orchestration de la partie (tours, fin de jeu) |
| `plateau.c/.h` | Création, modification et validation des grilles |
| `navire.c/.h` | Création et gestion des navires |
| `joueur.c/.h` | Gestion des données joueur |
| `affichage.c/.h` | Toutes les fonctions `printf` et affichage console |
| `utilitaires.c/.h` | Fonctions génériques (saisie, conversion, validation) |
| `constantes.h` | Définition des constantes (`#define`) |

---

## 10. Types personnalisés à implémenter

### 10.1 Énumérations

```c
// Orientation d'un navire
typedef enum {
    HORIZONTAL,
    VERTICAL
} Orientation;

// État d'une case
typedef enum {
    VIDE,           // Case non occupée, non ciblée
    NAVIRE,         // Case occupée par un navire (non touché)
    TOUCHE,         // Case occupée et touchée
    MANQUE          // Case ciblée mais vide (à l'eau)
} EtatCase;

// Type de navire
typedef enum {
    PORTE_AVIONS,
    CROISEUR,
    CONTRE_TORPILLEUR,
    SOUS_MARIN,
    TORPILLEUR
} TypeNavire;

// Résultat d'un tir
typedef enum {
    TIR_EAU,
    TIR_TOUCHE,
    TIR_COULE,
    TIR_INVALIDE,
    TIR_DEJA_JOUE
} ResultatTir;
```

### 10.2 Structures

```c
// Position sur la grille
typedef struct {
    int ligne;      // 0 à 9 (correspond à 1-10 pour l'utilisateur)
    int colonne;    // 0 à 9 (correspond à A-J pour l'utilisateur)
} Position;

// Navire
typedef struct {
    TypeNavire type;
    char nom[20];
    int taille;
    Position positions[5];      // Tableau des positions occupées
    int casesTouchees;          // Nombre de cases touchées
    int estCoule;               // 0 = non, 1 = oui
} Navire;

// Plateau d'un joueur
typedef struct {
    EtatCase grilleFlotte[10][10];  // Grille avec ses navires
    EtatCase grilleRadar[10][10];   // Grille de suivi des tirs
} Plateau;

// Joueur
typedef struct {
    char nom[50];
    Plateau plateau;
    Navire flotte[6];           // Les 6 navires
    int naviresRestants;        // Navires non coulés
} Joueur;

// Partie
typedef struct {
    Joueur joueur1;
    Joueur joueur2;
    int joueurActif;            // 1 ou 2
    int partieTerminee;         // 0 = en cours, 1 = terminée
} Partie;
```

---

## 11. Fonctions obligatoires

### 11.1 Module `jeu.c`

```c
// Initialise une nouvelle partie
void initialiserPartie(Partie *partie);

// Lance la boucle principale du jeu
void lancerPartie(Partie *partie);

// Exécute un tour de jeu complet
void jouerTour(Partie *partie);

// Vérifie si la partie est terminée
int verifierFinPartie(Partie *partie);

// Change le joueur actif
void changerJoueur(Partie *partie);

// Propose de rejouer
int demanderRejouer(void);
```

### 11.2 Module `plateau.c`

```c
// Initialise une grille avec des cases vides
void initialiserGrille(EtatCase grille[10][10]);

// Vérifie si un placement est valide
int verifierPlacement(EtatCase grille[10][10], Position debut, 
                      int taille, Orientation orientation);

// Place un navire sur la grille
void placerNavireSurGrille(EtatCase grille[10][10], Navire *navire);

// Applique un tir sur la grille
ResultatTir appliquerTir(Joueur *cible, Position pos);

// Applique un tir en croix
void appliquerTirCroix(Joueur *tireur, Joueur *cible, Position centre);
```

### 11.3 Module `navire.c`

```c
// Crée et initialise un navire selon son type
Navire creerNavire(TypeNavire type);

// Calcule les positions d'un navire à partir de sa position de départ
void calculerPositions(Navire *navire, Position debut, Orientation orientation);

// Vérifie si un navire est coulé
int estCoule(Navire *navire);

// Retourne le nom d'un type de navire
const char* getNomNavire(TypeNavire type);

// Retourne la taille d'un type de navire
int getTailleNavire(TypeNavire type);
```

### 11.4 Module `joueur.c`

```c
// Initialise un joueur avec son nom
void initialiserJoueur(Joueur *joueur, const char *nom);

// Gère le placement de tous les navires d'un joueur
void placerFlotte(Joueur *joueur);

// Compte les navires restants (non coulés)
int compterNaviresRestants(Joueur *joueur);

// Met à jour l'état d'un navire après un tir
void mettreAJourNavire(Joueur *joueur, Position pos);
```

### 11.5 Module `affichage.c`

```c
// Affiche l'écran d'accueil
void afficherAccueil(void);

// Affiche une grille (flotte ou radar)
void afficherGrille(EtatCase grille[10][10], int montrerNavires);

// Affiche les deux grilles d'un joueur côte à côte
void afficherGrillesJoueur(Joueur *joueur);

// Affiche le résultat d'un tir
void afficherResultatTir(ResultatTir resultat, const char *nomNavire);

// Affiche le message de victoire
void afficherVictoire(const char *nomGagnant);

// Efface l'écran (transition entre joueurs)
void effacerEcran(void);

// Affiche la liste des navires à placer
void afficherNaviresAPlacer(Joueur *joueur);
```

### 11.6 Module `utilitaires.c`

```c
// Convertit une saisie utilisateur (ex: "B5") en Position
int convertirCoordonnees(const char *saisie, Position *pos);

// Demande et valide une saisie de coordonnées
int saisirCoordonnees(Position *pos);

// Demande et valide une orientation (H/V)
int saisirOrientation(Orientation *orientation);

// Demande et valide un choix de type de tir
int saisirTypeTir(void);

// Vide le buffer d'entrée
void viderBuffer(void);

// Attend une action de l'utilisateur (pause)
void attendreTouche(void);

// Génère un nombre aléatoire dans un intervalle
int aleatoire(int min, int max);
```

---

## 12. Exercices guidés

Ces exercices vous guident dans le développement progressif du jeu.

### Exercice 1 : Mise en place du projet

**Objectif** : Créer la structure de fichiers et les types de base.

1. Créez l'arborescence de dossiers `src/` et `include/`
2. Créez le fichier `constantes.h` avec les définitions :
   ```c
   #define TAILLE_GRILLE 10
   #define NB_NAVIRES 6
   #define NB_TYPES_NAVIRES 5
   ```
3. Créez les énumérations dans les fichiers `.h` appropriés
4. Vérifiez que le projet compile (même vide)

**Validation** : `gcc -Wall -Wextra src/*.c -I include/ -o bataille` sans erreur

---

### Exercice 2 : Affichage d'une grille vide

**Objectif** : Implémenter l'affichage de base.

1. Implémentez `initialiserGrille()` pour remplir une grille de `VIDE`
2. Implémentez `afficherGrille()` avec le format suivant :
   - En-tête : colonnes A-J
   - Lignes numérotées 1-10
   - Cases représentées par des symboles

**Attendu** :
```
    A   B   C   D   E   F   G   H   I   J
  +---+---+---+---+---+---+---+---+---+---+
1 |   |   |   |   |   |   |   |   |   |   |
  +---+---+---+---+---+---+---+---+---+---+
2 |   |   |   |   |   |   |   |   |   |   |
  ...
```

---

### Exercice 3 : Conversion des coordonnées

**Objectif** : Traduire les saisies utilisateur en positions internes.

1. Implémentez `convertirCoordonnees()` :
   - Entrée : chaîne comme "B5" ou "b5"
   - Sortie : Position avec ligne=4, colonne=1
2. Gérez les cas d'erreur (hors limites, format invalide)
3. Testez avec plusieurs entrées

**Cas de test** :
- "A1" → ligne=0, colonne=0 ✓
- "J10" → ligne=9, colonne=9 ✓
- "K5" → Erreur (colonne invalide)
- "A11" → Erreur (ligne invalide)
- "AA" → Erreur (format invalide)

---

### Exercice 4 : Création des navires

**Objectif** : Implémenter la structure Navire et ses fonctions.

1. Implémentez `creerNavire()` qui initialise un navire selon son type
2. Implémentez `getTailleNavire()` et `getNomNavire()`
3. Implémentez `calculerPositions()` pour générer les cases occupées

**Tableau de référence** :

| Type | Nom | Taille |
|------|-----|--------|
| PORTE_AVIONS | "Porte-avions" | 5 |
| CROISEUR | "Croiseur" | 4 |
| CONTRE_TORPILLEUR | "Contre-torpilleur" | 3 |
| SOUS_MARIN | "Sous-marin" | 3 |
| TORPILLEUR | "Torpilleur" | 2 |

---

### Exercice 5 : Validation du placement

**Objectif** : Vérifier qu'un navire peut être placé.

Implémentez `verifierPlacement()` qui vérifie :
1. Le navire ne dépasse pas de la grille
2. Le navire ne chevauche pas un navire existant

**Algorithme suggéré** :
```
POUR chaque case que le navire occuperait
    SI case hors limites OU case déjà occupée
        RETOURNER FAUX
    FIN SI
FIN POUR
RETOURNER VRAI
```

---

### Exercice 6 : Phase de placement complète

**Objectif** : Permettre à un joueur de placer tous ses navires.

1. Implémentez `placerFlotte()` :
   - Affiche la grille actuelle
   - Affiche les navires restants à placer
   - Demande les coordonnées et l'orientation
   - Valide et place le navire
   - Recommence jusqu'à ce que tous les navires soient placés

2. Gérez les erreurs de saisie avec des messages clairs

---

### Exercice 7 : Système de tir

**Objectif** : Implémenter la mécanique de tir.

1. Implémentez `appliquerTir()` :
   - Vérifie si la case a déjà été ciblée
   - Détermine si c'est un touché ou un raté
   - Met à jour les grilles
   - Vérifie si un navire est coulé

2. Implémentez `appliquerTirCroix()` :
   - Applique 5 tirs (centre + 4 adjacents)
   - Ignore les cases hors limites

---

### Exercice 8 : Boucle de jeu principale

**Objectif** : Assembler tous les modules.

1. Implémentez `jouerTour()` :
   - Affiche les grilles du joueur actif
   - Demande le type de tir
   - Demande les coordonnées
   - Exécute le tir et affiche le résultat
   - Vérifie la fin de partie

2. Implémentez `lancerPartie()` :
   - Alterne les tours jusqu'à la victoire
   - Gère la transition entre joueurs (écran vide + message)

---

### Exercice 9 : Finitions et polish

**Objectif** : Améliorer l'expérience utilisateur.

1. Ajoutez un écran d'accueil attractif
2. Implémentez la fonction de rejeu
3. Ajoutez des statistiques de fin de partie :
   - Nombre de tirs effectués
   - Précision (tirs réussis / total)
4. Testez le jeu complet et corrigez les bugs

---

## 13. Exemples d'affichage type attendu

### 13.1 Écran d'accueil

```
╔══════════════════════════════════════════════════════╗
║                                                      ║
║           ⚓ BATAILLE NAVALE ⚓                     ║
║                                                      ║
║              MéquaLine Games                         ║
║                  v1.0                                ║
║                                                      ║
╠══════════════════════════════════════════════════════╣
║                                                      ║
║  Règles :                                            ║
║  - Placez vos 6 navires sur votre grille             ║
║  - Coulez tous les navires adverses pour gagner      ║
║  - Tir simple : 1 case                               ║
║  - Tir en croix : 5 cases (+ bonus)                  ║
║                                                      ║
╚══════════════════════════════════════════════════════╝

Appuyez sur ENTRÉE pour commencer...
```

### 13.2 Saisie des joueurs

```
=== CONFIGURATION DE LA PARTIE ===

Nom du Joueur 1 : Alice
Nom du Joueur 2 : Bob

Bienvenue Alice et Bob !
La partie va commencer...

Appuyez sur ENTRÉE pour continuer...
```

### 13.3 Phase de placement

```
=== PLACEMENT DES NAVIRES - Alice ===

Votre grille actuelle :
    A   B   C   D   E   F   G   H   I   J
  +---+---+---+---+---+---+---+---+---+---+
1 |   |   |   |   |   |   |   |   |   |   |
  +---+---+---+---+---+---+---+---+---+---+
2 |   |   |   |   |   |   |   |   |   |   |
  +---+---+---+---+---+---+---+---+---+---+
...

Navires à placer :
  [1] Porte-avions (5 cases)
  [2] Croiseur (4 cases)
  [3] Contre-torpilleur (3 cases)
  [4] Contre-torpilleur (3 cases)
  [5] Sous-marin (3 cases)
  [6] Torpilleur (2 cases)

Placement du Porte-avions (5 cases)
Coordonnées de départ (ex: A1) : B2
Orientation (H)orizontal / (V)ertical : H

✓ Porte-avions placé avec succès !
```

### 13.4 Grille avec navires placés

```
    A   B   C   D   E   F   G   H   I   J
  +---+---+---+---+---+---+---+---+---+---+
1 |   |   |   |   |   |   |   |   |   |   |
  +---+---+---+---+---+---+---+---+---+---+
2 |   | P | P | P | P | P |   |   |   |   |
  +---+---+---+---+---+---+---+---+---+---+
3 |   |   |   |   |   |   |   |   |   |   |
  +---+---+---+---+---+---+---+---+---+---+
4 | C |   |   |   | T | T | T |   |   |   |
  +---+---+---+---+---+---+---+---+---+---+
5 | C |   |   |   |   |   |   |   |   |   |
  +---+---+---+---+---+---+---+---+---+---+
6 | C |   |   |   |   |   |   | S |   |   |
  +---+---+---+---+---+---+---+---+---+---+
7 | C |   |   |   |   |   |   | S |   |   |
  +---+---+---+---+---+---+---+---+---+---+
8 |   |   | T | T | T |   |   | S |   |   |
  +---+---+---+---+---+---+---+---+---+---+
9 |   |   |   |   |   |   |   |   |   |   |
  +---+---+---+---+---+---+---+---+---+---+
10|   |   |   |   |   |   | O | O |   |   |
  +---+---+---+---+---+---+---+---+---+---+

Légende : P=Porte-avions, C=Croiseur, T=Contre-torpilleur, S=Sous-marin, O=Torpilleur
```

### 13.5 Tour de jeu

```
╔══════════════════════════════════════════════════════╗
║              TOUR DE : Alice                         ║
╚══════════════════════════════════════════════════════╝

       VOTRE FLOTTE                    RADAR (Zone adverse)
    A B C D E F G H I J             A B C D E F G H I J
  +---+---+---+---+---+---+       +---+---+---+---+---+---+
1 |   | P | P | P | P | P |     1 |   |   |   | O |   |   |
  +---+---+---+---+---+---+       +---+---+---+---+---+---+
2 |   |   |   |   |   |   |     2 |   |   |   |   |   | X |
  +---+---+---+---+---+---+       +---+---+---+---+---+---+
3 | C | C | C | C |   |   |     3 |   |   |   |   |   |   |
...

Navires ennemis restants : 5/6
Vos navires restants : 6/6

Type de tir :
  [1] Tir simple (1 case)
  [2] Tir en croix (5 cases)
Votre choix : 1

Coordonnées de tir (ex: E5) : F7

>>> TOUCHÉ ! <<<
```

### 13.6 Navire coulé

```
Coordonnées de tir (ex: E5) : G3

╔══════════════════════════════════════════════════════╗
║           💥 COULÉ ! 💥                              ║
║      Vous avez coulé le Torpilleur ennemi !         ║
╚══════════════════════════════════════════════════════╝

Navires ennemis restants : 4/6
```

### 13.7 Fin de partie

```
╔══════════════════════════════════════════════════════╗
║                                                      ║
║           🏆 VICTOIRE ! 🏆                           ║
║                                                      ║
║              Alice remporte la partie !              ║
║                                                      ║
╠══════════════════════════════════════════════════════╣
║                                                      ║
║  Statistiques :                                      ║
║  - Tirs effectués : 47                               ║
║  - Tirs réussis : 21                                 ║
║  - Précision : 44.7%                                 ║
║                                                      ║
╚══════════════════════════════════════════════════════╝

Voulez-vous rejouer ? (O/N) : 
```

### 13.8 Messages d'erreur

```
❌ Erreur : Coordonnées invalides. Utilisez le format lettre+chiffre (ex: B5)

❌ Erreur : Position hors de la grille. Colonnes: A-J, Lignes: 1-10

❌ Erreur : Le navire dépasse de la grille avec cette orientation.

❌ Erreur : Un navire occupe déjà cette position.

❌ Erreur : Vous avez déjà tiré sur cette case.
```

---

## 14. FAQ et erreurs courantes

### 14.1 Questions fréquentes

**Q1 : Comment gérer l'affichage des caractères spéciaux (╔, ═, etc.) ?**

Ces caractères sont en UTF-8. Sous Windows, ajoutez au début de `main()` :
```c
#ifdef _WIN32
    system("chcp 65001 > nul");  // Active UTF-8 dans la console Windows
#endif
```

**Q2 : Comment vider le buffer clavier après un `scanf` ?**
```c
void viderBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
```

**Q3 : Comment effacer l'écran de manière portable ?**
```c
void effacerEcran(void) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
```

**Q4 : Comment convertir une lettre en indice de colonne ?**
```c
int colonneVersIndice(char lettre) {
    lettre = toupper(lettre);  // Nécessite <ctype.h>
    if (lettre >= 'A' && lettre <= 'J') {
        return lettre - 'A';
    }
    return -1;  // Erreur
}
```

**Q5 : Puis-je utiliser des couleurs dans le terminal ?**

Oui, avec les codes ANSI (fonctionne sous Linux/macOS, Windows 10+) :
```c
#define ROUGE "\033[31m"
#define VERT "\033[32m"
#define RESET "\033[0m"

printf(ROUGE "TOUCHÉ !" RESET "\n");
```

### 14.2 Erreurs courantes

| Erreur | Cause probable | Solution |
|--------|----------------|----------|
| Segmentation fault | Accès hors tableau | Vérifiez les indices (0-9) |
| Boucle infinie | Condition jamais fausse | Vérifiez la mise à jour des variables |
| Affichage décalé | Mélange `\n` et `\r\n` | Utilisez uniquement `\n` |
| scanf ignore saisie | Buffer non vidé | Appelez `viderBuffer()` après chaque `scanf` |
| Navire mal placé | Calcul de position erroné | Vérifiez `calculerPositions()` |
| Compilation échoue | Include manquant | Vérifiez les `#include` et les chemins |

### 14.3 Conseils de débogage

1. **Ajoutez des `printf` de debug** avec les valeurs des variables clés
2. **Compilez souvent** : ne pas attendre d'avoir 500 lignes de code
3. **Testez chaque fonction** individuellement avant l'intégration
4. **Utilisez un débogueur** (GDB ou celui de votre IDE)
5. **Relisez les warnings** : ils signalent souvent des problèmes réels

---

## 15. Consignes de rendu GitHub

### 15.1 Création du dépôt

1. Créez un dépôt **privé** sur GitHub
2. Nommez-le exactement : `AlgorithmiqueFondamentaux_TP3_Prenom_NOM`
   - Exemple : `AlgorithmiqueFondamentaux_TP3_Alice_DUPONT`
3. **Ne pas** initialiser avec un README (le créer manuellement ensuite)
4. Ajoutez le lien du dépôt dans l'Excel partagé : https://docs.google.com/spreadsheets/d/17dF0d39g-6NB1lSE3EqaRPe6_629-CrWE07tyCRsDH0/edit?usp=sharing

### 15.2 Ajout du collaborateur

1. Allez dans **Settings** → **Collaborators**
2. Ajoutez l'utilisateur : `jessy70210` ou `jessy70210@gmail.com`
3. Vérifiez que l'invitation a bien été envoyée

### 15.3 Structure du dépôt

```
AlgorithmiqueFondamentaux_TP3_Prenom_NOM/
├── src/
│   └── (tous vos fichiers .c)
├── include/
│   └── (tous vos fichiers .h)
├── .gitignore
├── README.md
└── (Makefile - bonus)
```

### 15.4 Contenu du README.md

Votre README doit contenir :
- Votre nom et prénom
- La date de rendu
- Les instructions de compilation
- Les fonctionnalités implémentées
- Les difficultés rencontrées (optionnel)

### 15.5 Fichier .gitignore recommandé

```gitignore
# Exécutables
*.exe
*.out
bataille

# Fichiers objets
*.o
*.obj

# Fichiers IDE
.vscode/
.idea/
*.cbp
*.layout

# Fichiers temporaires
*.tmp
*~
```

### 15.6 Bonnes pratiques Git

- **Commits réguliers** avec des messages explicites
- **Un commit par fonctionnalité** (pas un commit géant à la fin)
- **Messages en français** au présent : "Ajoute l'affichage de la grille"
- **Push régulier** pour sauvegarder votre travail

### 15.7 Date limite

- **Date de rendu** : À définir par l'enseignant
- Tout commit après la date limite sera ignoré
- **Aucun dépôt = 0/20** sans négociation possible

---

## 16. Barème de notation

### 16.1 Répartition des points (sur 20)

| Critère | Points | Détail |
|---------|--------|--------|
| **Compilation** | 2 pts | Sans erreur ni warning |
| **Architecture projet** | 2 pts | Respect de la structure imposée |
| **Types personnalisés** | 2 pts | Structures et énumérations conformes |
| **Placement des navires** | 3 pts | Saisie, validation, affichage |
| **Système de tir** | 3 pts | Tir simple, tir en croix, résultats |
| **Boucle de jeu** | 3 pts | Alternance, fin de partie, rejeu |
| **Qualité du code** | 2 pts | Lisibilité, commentaires, nommage |
| **Gestion des erreurs** | 2 pts | Validation des entrées, messages |
| **Rendu GitHub** | 1 pt | Dépôt conforme, commits réguliers |

### 16.2 Bonus possibles (+3 pts max)

| Bonus                       | Points   |
|-----------------------------|----------|
| Makefile fonctionnel        | +0.25 pt |
| Statistiques de fin de partie | +0.5 pt  |
| Affichage avec couleurs ANSI | +0.25 pt |
| Mode joueur vs ordinateur | +1 pt    |
| Sauvegarde/chargement de partie | +1 pt    |

### 16.3 Malus possibles

| Malus | Points |
|-------|--------|
| Warnings à la compilation | -0.5 pt par warning |
| Variables globales (hors constantes) | -1 pt |
| Code non indenté | -1 pt |
| Plagiat avéré | -20 pts (= 0/20) |
| Rendu hors délai | -2 pts par jour |

---

## 17. Checklist d'évaluation

### Pour l'étudiant (auto-évaluation)

Avant de rendre votre projet, vérifiez :

**Compilation**
- [ ] Le projet compile avec `gcc -Wall -Wextra -std=c99`
- [ ] Aucun warning n'est affiché
- [ ] L'exécutable se lance correctement

**Structure**
- [ ] Les dossiers `src/` et `include/` sont présents
- [ ] Tous les fichiers `.h` ont des guards d'inclusion
- [ ] Le fichier `main.c` ne contient que la fonction `main()`

**Fonctionnalités**
- [ ] L'écran d'accueil s'affiche
- [ ] Les deux joueurs peuvent entrer leur nom
- [ ] Chaque joueur peut placer ses 6 navires
- [ ] Le placement est validé (pas de chevauchement, pas de dépassement)
- [ ] Les grilles s'affichent correctement
- [ ] Le tir simple fonctionne
- [ ] Le tir en croix fonctionne
- [ ] Les messages Touché/Coulé/À l'eau s'affichent
- [ ] Le jeu détecte la fin de partie
- [ ] Le vainqueur est annoncé
- [ ] L'option de rejouer fonctionne

**Qualité**
- [ ] Le code est indenté uniformément
- [ ] Les fonctions sont commentées
- [ ] Les noms de variables sont explicites
- [ ] Les entrées utilisateur sont validées
- [ ] Les messages d'erreur sont clairs

**GitHub**
- [ ] Le dépôt est nommé correctement
- [ ] Le collaborateur `jessy70210` est ajouté
- [ ] Le README.md est présent et complet
- [ ] Le .gitignore est présent
- [ ] Plusieurs commits avec des messages clairs

### Pour l'enseignant

**Évaluation technique**
- [ ] Compilation sans erreur (2 pts)
- [ ] Architecture respectée (2 pts)
- [ ] Types conformes au sujet (2 pts)
- [ ] Placement fonctionnel (3 pts)
- [ ] Tirs fonctionnels (3 pts)
- [ ] Boucle de jeu complète (3 pts)
- [ ] Code propre et commenté (2 pts)
- [ ] Gestion des erreurs (2 pts)
- [ ] Rendu GitHub conforme (1 pt)

**Bonus attribués** : ___/3 pts

**Malus appliqués** : ___pts

**Note finale** : ___/20

**Commentaires** :
```
_________________________________________________________________
_________________________________________________________________
_________________________________________________________________
```

---

## Annexe A : Rappels de syntaxe C

### Déclaration d'une structure

```c
typedef struct {
    int x;
    int y;
} Position;
```

### Déclaration d'une énumération

```c
typedef enum {
    HORIZONTAL,
    VERTICAL
} Orientation;
```

### Passage par référence

```c
void modifierValeur(int *ptr) {
    *ptr = 42;
}

int main() {
    int valeur = 0;
    modifierValeur(&valeur);  // valeur vaut maintenant 42
}
```

### Accès aux champs d'une structure via pointeur

```c
void afficherPosition(Position *pos) {
    printf("(%d, %d)\n", pos->ligne, pos->colonne);
}
```

---

## Annexe B : Commandes Git essentielles

```bash
# Initialiser un dépôt local
git init

# Cloner un dépôt distant
git clone <url>

# Voir l'état des fichiers
git status

# Ajouter des fichiers au staging
git add <fichier>
git add .  # Tous les fichiers

# Créer un commit
git commit -m "Message explicite"

# Envoyer vers le dépôt distant
git push origin main

# Récupérer les modifications distantes
git pull origin main

# Voir l'historique des commits
git log --oneline
```
---

## Annexe C : Guide d'utilisation de CLion

### C.1 Création d'un nouveau projet

1. `File` → `New Project`
2. Sélectionnez `C Executable`
3. Choisissez le standard : `C99`
4. Nommez votre projet : `BatailleNavale`
5. Cliquez sur `Create`

CLion génère automatiquement :
```
BatailleNavale/
├── CMakeLists.txt
└── main.c
```

---

### C.2 Configuration du CMakeLists.txt

Le fichier `CMakeLists.txt` indique à CLion comment compiler votre projet.

#### Configuration pour le TP Bataille Navale :

```cmake
cmake_minimum_required(VERSION 3.10)
project(BatailleNavale C)

# Standard C99
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Options de compilation strictes
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")

# Inclusion du dossier des headers
include_directories(include)

# Liste des fichiers sources
set(SOURCES
    src/main.c
    src/jeu.c
    src/plateau.c
    src/navire.c
    src/joueur.c
    src/affichage.c
    src/utilitaires.c
)

# Création de l'exécutable
add_executable(BatailleNavale ${SOURCES})
```

#### Rechargement du CMake :

Après modification du `CMakeLists.txt` :
- CLion affiche une notification → Cliquez sur `Reload CMake Project`
- Ou : `Tools` → `CMake` → `Reload CMake Project`
- Raccourci : `Ctrl+Shift+O` (Windows/Linux) ou `Cmd+Shift+O` (macOS)

---

### C.3 Organisation des fichiers dans CLion

#### Création de la structure de dossiers :

1. Clic droit sur le nom du projet dans l'arborescence
2. `New` → `Directory`
3. Créez `src` et `include`

#### Création d'un nouveau fichier :

1. Clic droit sur le dossier cible (`src` ou `include`)
2. `New` → `C/C++ Source File` ou `C/C++ Header File`
3. Nommez le fichier (sans extension, CLion l'ajoute)

#### Astuce : Création simultanée .c et .h

1. Clic droit sur `src`
2. `New` → `C/C++ Source File`
3. Cochez `Create associated header`
4. CLion crée les deux fichiers avec le guard d'inclusion avec la gestion automatique du CMake

---

### C.4 Fonctionnalités essentielles

#### Autocomplétion

- S'active automatiquement pendant la frappe
- `Ctrl+Space` : Force l'affichage des suggestions
- `Ctrl+Shift+Space` : Suggestions intelligentes (contextuelles)

#### Navigation dans le code

| Action | Raccourci Windows/Linux | Raccourci macOS |
|--------|------------------------|-----------------|
| Aller à la définition | `Ctrl+B` ou `Ctrl+Click` | `Cmd+B` |
| Aller à la déclaration | `Ctrl+Shift+B` | `Cmd+Shift+B` |
| Trouver les utilisations | `Alt+F7` | `Option+F7` |
| Rechercher partout | `Shift+Shift` (double) | `Shift+Shift` |
| Rechercher un fichier | `Ctrl+Shift+N` | `Cmd+Shift+O` |
| Rechercher un symbole | `Ctrl+Alt+Shift+N` | `Cmd+Option+O` |

#### Refactoring

| Action | Raccourci |
|--------|-----------|
| Renommer (variable, fonction) | `Shift+F6` |
| Extraire une fonction | `Ctrl+Alt+M` |
| Extraire une variable | `Ctrl+Alt+V` |
| Reformater le code | `Ctrl+Alt+L` |

#### Génération de code

- `Alt+Insert` : Menu de génération (getters, constructeurs, etc.)
- Tapez `main` puis `Tab` : Génère la fonction main complète

---

### C.5 Compilation et exécution

#### Compiler le projet :

1. Menu : `Build` → `Build Project`
2. Raccourci : `Ctrl+F9`
3. Les erreurs apparaissent dans l'onglet `Messages` en bas

#### Exécuter le programme :

1. Cliquez sur le bouton vert ▶ (Run) en haut à droite
2. Ou : `Shift+F10`
3. La console s'ouvre dans l'onglet `Run` en bas

#### Configuration d'exécution :

1. `Run` → `Edit Configurations`
2. Vérifiez que l'exécutable `BatailleNavale` est sélectionné
3. Vous pouvez ajouter des arguments de ligne de commande si nécessaire

---

### C.6 Utilisation du débogueur

Le débogueur permet d'exécuter le programme pas à pas et d'inspecter les variables.

#### Placer un point d'arrêt (breakpoint) :

- Cliquez dans la marge gauche (à côté du numéro de ligne)
- Un point rouge apparaît
- Recliquez pour le supprimer

#### Lancer le débogage :

1. Cliquez sur l'icône insecte 🐛 (Debug) au lieu de ▶
2. Ou : `Shift+F9`
3. Le programme s'arrête au premier breakpoint

#### Commandes de débogage :

| Action | Raccourci | Description |
|--------|-----------|-------------|
| Step Over | `F8` | Exécute la ligne, sans entrer dans les fonctions |
| Step Into | `F7` | Entre dans la fonction appelée |
| Step Out | `Shift+F8` | Sort de la fonction actuelle |
| Resume | `F9` | Continue jusqu'au prochain breakpoint |
| Stop | `Ctrl+F2` | Arrête le débogage |

#### Inspecter les variables :

- Onglet `Variables` : Affiche toutes les variables locales
- Onglet `Watches` : Ajoutez des expressions à surveiller
- Survolez une variable dans le code pour voir sa valeur

#### Exemple de session de débogage :

```c
void placerNavire(Navire *navire, Position pos) {
    // Placez un breakpoint ici
    navire->positions[0] = pos;  // Inspectez navire et pos
    
    for (int i = 1; i < navire->taille; i++) {
        // Utilisez F8 pour voir chaque itération
        navire->positions[i].ligne = pos.ligne + i;
    }
}
```

---

### C.7 Intégration Git dans CLion

CLion intègre nativement Git, ce qui simplifie la gestion de versions.

#### Initialiser Git :

1. `VCS` → `Enable Version Control Integration`
2. Sélectionnez `Git`
3. CLion crée le dossier `.git`

#### Interface Git :

- Onglet `Git` en bas : Historique des commits
- Onglet `Commit` à gauche : Fichiers modifiés

#### Opérations courantes :

| Action | Menu | Raccourci |
|--------|------|-----------|
| Commit | `Git` → `Commit` | `Ctrl+K` |
| Push | `Git` → `Push` | `Ctrl+Shift+K` |
| Pull | `Git` → `Pull` | `Ctrl+T` |
| Voir l'historique | `Git` → `Show Git Log` | `Alt+9` |

#### Workflow typique :

1. Modifiez vos fichiers
2. `Ctrl+K` : Ouvre la fenêtre de commit
3. Cochez les fichiers à inclure
4. Écrivez un message de commit explicite
5. Cliquez sur `Commit` ou `Commit and Push`

#### Connecter à GitHub :

1. `Git` → `Manage Remotes`
2. Ajoutez l'URL de votre dépôt : `https://github.com/username/repo.git`
3. Lors du premier push, entrez vos identifiants GitHub

---

### C.8 Résolution des problèmes courants

#### Problème : "CMake Error: Cannot find compiler"

**Solution :**
1. `File` → `Settings` → `Build, Execution, Deployment` → `Toolchains`
2. Vérifiez que le compilateur est détecté
3. Si non, réinstallez-le via CLion

#### Problème : "No executable specified"

**Solution :**
1. Vérifiez que `CMakeLists.txt` contient `add_executable(...)`
2. Rechargez CMake : `Tools` → `CMake` → `Reset Cache and Reload Project`

#### Problème : Les accents s'affichent mal dans la console

**Solution Windows :**
Ajoutez au début de `main()` :
```c
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);  // Nécessite <windows.h>
#endif
```

Ou dans les paramètres de CLion :
1. `Run` → `Edit Configurations`
2. Dans `Environment variables`, ajoutez : `LANG=fr_FR.UTF-8`

#### Problème : Le programme ne s'arrête pas pour lire les entrées

**Solution :**
Dans `Run` → `Edit Configurations` :
- Cochez `Emulate terminal in output console`

#### Problème : "undefined reference to..."

**Solution :**
1. Vérifiez que tous les fichiers `.c` sont listés dans `CMakeLists.txt`
2. Vérifiez les `#include` dans vos fichiers
3. Rechargez CMake

---

### C.11 Raccourcis clavier essentiels (récapitulatif)

| Catégorie | Action | Windows/Linux | macOS |
|-----------|--------|---------------|-------|
| **Général** | Paramètres | `Ctrl+Alt+S` | `Cmd+,` |
| | Recherche globale | `Shift+Shift` | `Shift+Shift` |
| | Actions | `Ctrl+Shift+A` | `Cmd+Shift+A` |
| **Édition** | Complétion | `Ctrl+Space` | `Ctrl+Space` |
| | Reformater | `Ctrl+Alt+L` | `Cmd+Option+L` |
| | Commenter ligne | `Ctrl+/` | `Cmd+/` |
| | Dupliquer ligne | `Ctrl+D` | `Cmd+D` |
| | Supprimer ligne | `Ctrl+Y` | `Cmd+Backspace` |
| **Navigation** | Aller à définition | `Ctrl+B` | `Cmd+B` |
| | Fichier récent | `Ctrl+E` | `Cmd+E` |
| | Structure fichier | `Ctrl+F12` | `Cmd+F12` |
| **Build/Run** | Compiler | `Ctrl+F9` | `Cmd+F9` |
| | Exécuter | `Shift+F10` | `Ctrl+R` |
| | Déboguer | `Shift+F9` | `Ctrl+D` |
| **Git** | Commit | `Ctrl+K` | `Cmd+K` |
| | Push | `Ctrl+Shift+K` | `Cmd+Shift+K` |
| | Pull | `Ctrl+T` | `Cmd+T` |

---

### C.12 Conseils pour une utilisation efficace

1. **Utilisez les Live Templates** : Tapez `fori` + `Tab` pour générer une boucle `for`

2. **Activez l'auto-save** : `Settings` → `Appearance & Behavior` → `System Settings` → Cochez `Save files automatically`

3. **Personnalisez le thème** : `Settings` → `Appearance & Behavior` → `Appearance` → Thème Darcula (sombre) recommandé

4. **Utilisez les TODO** : Écrivez `// TODO: message` pour créer des rappels visibles dans `View` → `Tool Windows` → `TODO`

5. **Explorez les inspections** : CLion souligne les problèmes potentiels. Passez la souris pour voir les suggestions et `Alt+Enter` pour les appliquer

6. **Configurez le formatage** : `Settings` → `Editor` → `Code Style` → `C/C++` pour définir vos préférences d'indentation


---

**Bon courage et bon développement !**

*MéquaLine Games compte sur vous pour livrer un POC de qualité.*
