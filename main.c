#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "Grille.h"
#include "Serpent.h"
#include "liste_Section.h"
#include "Fonction_Jeu.h"

int main(int argc, char ** argv) {
    int delai; /* Déclaration de la variable pour le délai entre les mouvements du serpent*/
    struct Grille * g; /*Déclaration d'un pointeur vers une grille*/
    struct Serpent * serp; /*Déclaration d'un pointeur vers un serpent*/

    /* Vérification du nombre d'arguments passés en ligne de commande*/
    if (argc != 4) {
        fprintf(stderr, "Veuillez entrer le bon nombre d'arguments (3)\n");
        exit(1); /* Sortie du programme avec un code d'erreur*/
    }
   
    /* Allocation d'une grille avec les dimensions spécifiées en argument*/
    g = Grille_allouer(atoi(argv[1]), atoi(argv[2]));

    /* Vérification que les dimensions de la grille sont positives*/
    if ((g->n < 0) || (g->m < 0)) {
        fprintf(stderr, "Un des arguments est négatif\n");
        exit(1); /* Sortie du programme avec un code d'erreur*/
    }

    /* Création d'un serpent avec les dimensions de la grille*/
    serp = creer_serpent(g->n, g->m);

    /* Récupération du délai entre les mouvements du serpent*/
    delai = atoi(argv[3]);

    /* Lancement du jeu avec la grille, le serpent et le délai spécifiés*/
    Jouer_Serpent(g, serp, delai);

    /* Désallocation de la mémoire allouée pour la grille*/
    Grille_desallouer(&g);

    printf("\n\nbye bye !\n");

    return EXIT_SUCCESS; /* Fin du programme avec un code de succès*/
}
