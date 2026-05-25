#include <stdlib.h>
#include <stdio.h>
#include "Serpent.h"

/* Fonction pour créer un serpent avec une section initiale au centre de la grille */
struct Serpent * creer_serpent(int n, int m) {
    /* Allocation de mémoire pour la structure Serpent */
    struct Serpent * serp = malloc(sizeof(struct Serpent));
   
    /* Initialisation des coordonnées du serpent au centre de la grille */
    serp->x = (n / 2);
    serp->y = (m / 2);
   
    /* Création de la liste de sections du serpent avec une section initiale de taille 1 et couleur 41 (rouge)*/
    serp->chaine = creer_liste();
    ajout_debut_liste(serp->chaine, creer_section(1, 41));
   
    /*Création de la liste de mouvements du serpent*/
    serp->mouvement = creer_liste_mouvement();
   
    return serp; /* Retourne le serpent créé */
}
