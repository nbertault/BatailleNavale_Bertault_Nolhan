cmake_minimum_required(VERSION 3.30)
project(AlgorithmeFondamentauxTP3 C)

set(CMAKE_C_STANDARD 11)

add_executable(AlgorithmeFondamentauxTP3 src/main.c
        src/joueur.c
        include/joueur.h
        src/jeu.c
        include/jeu.h
        src/plateau.c
        include/plateau.h
        src/navire.c
        include/navire.h
        src/affichage.c
        include/affichage.h
        src/utilitaires.c
        include/utilitaires.h
        include/constante.h)
