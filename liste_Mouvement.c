#include <stdlib.h>
#include <stdio.h>
#include "liste_Mouvement.h"

/*Crée une nouvelle case avec les coordonnées spécifiées et la direction*/
struct Case * creer_case(int x, int y, enum Direction sens) {
    struct Case * c = malloc(sizeof(struct Case)); /* Alloue la mémoire pour une nouvelle case*/
    c->x = x; /* Initialise la coordonnée x*/
    c->y = y; /* Initialise la coordonnée y*/
    c->sens = sens; /*Initialise la direction*/
    c->suivant = NULL; /* Initialise le pointeur suivant à NULL */
    return c; /* Retourne le pointeur vers la nouvelle case*/
}

/* Désalloue la mémoire utilisée par une case et met le pointeur à NULL */
void desalouer_case(struct Case ** c) {
    if (*c != NULL) { /* Vérifie si le pointeur n'est pas NULL*/
        free(*c); /* Libère la mémoire allouée pour la case*/
        *c = NULL; /* Met le pointeur à NULL pour éviter les accès invalides*/
    }
}

/*Crée une nouvelle liste de mouvements initialisée vide*/
struct Liste_Mouvement * creer_liste_mouvement() {
    struct Liste_Mouvement * lm = malloc(sizeof(struct Liste_Mouvement)); /* Alloue la mémoire pour une nouvelle liste de mouvements*/
    lm->premier = NULL; /* Initialise le premier élément de la liste à NULL*/
    lm->dernier = NULL; /* Initialise le dernier élément de la liste à NULL*/
    lm->longueur = 0; /* Initialise la longueur de la liste à 0*/
    return lm; /* Retourne le pointeur vers la nouvelle liste de mouvements*/
}

/* Vérifie si la liste de mouvements est vide*/
int est_vide_lm(struct Liste_Mouvement * lm) {
    return (lm->longueur == 0); /* Retourne 1 si la longueur de la liste est 0, sinon retourne 0*/
}

/* Ajoute une case au début de la liste de mouvements*/
void ajout_debut_liste_mouvement(struct Liste_Mouvement * lm, struct Case * c) {
    if (est_vide_lm(lm)) /*Si la liste est vide, met à jour le dernier élément*/
        lm->dernier = c;
    c->suivant = lm->premier; /* Pointe la nouvelle case vers l'ancien premier élément*/
    lm->premier = c; /* Met à jour le premier élément de la liste*/
    lm->longueur++; /* Incrémente la longueur de la liste*/
}

/* Ajoute une case à la fin de la liste de mouvements*/
void ajout_fin_liste_mouvement(struct Liste_Mouvement * lm, struct Case * c) {
    c->suivant = NULL; /* Assure que le nouveau dernier élément pointe vers NULL*/
    if (est_vide_lm(lm)) {
        lm->premier = c; /* Si la liste est vide, met à jour le premier élément*/
    } else {
        lm->dernier->suivant = c; /*Pointe l'ancien dernier élément vers la nouvelle case*/
    }
    lm->dernier = c; /* Met à jour le dernier élément de la liste*/
    lm->longueur++; /* Incrémente la longueur de la liste*/
}

/* Extrait (retire et retourne) la première case de la liste de mouvements*/
struct Case * extraire_case(struct Liste_Mouvement * lm) {
    struct Case * c = lm->premier; /* Sauvegarde le premier élément*/
    if (c != NULL) { /* Si la liste n'est pas vide*/
        lm->premier = c->suivant; /* Met à jour le premier élément de la liste*/
        lm->longueur--; /* Décrémente la longueur de la liste*/
        if (est_vide_lm(lm))
            lm->dernier = NULL; /* Si la liste est maintenant vide, met à jour le dernier élément*/
        c->suivant = NULL; /* Déconnecte la case extraite de la liste*/
    }
    return c; /*Retourne la case extraite*/
}

/* Désalloue la mémoire utilisée par la liste de mouvements et ses cases*/
void desalouer_liste_mouvement(struct Liste_Mouvement ** lm) {
    if (*lm != NULL) { /* Vérifie si la liste de mouvements existe*/
        struct Case * c; /* Déclare un pointeur pour les cases*/
        while(!est_vide_lm(*lm)) { /* Libère chaque case de la liste*/
            c = extraire_case(*lm); /* Extrait la première case*/
        }
        desalouer_case(&c); /* Libère la dernière case extraite */
        free(*lm); /* Libère la structure de la liste de mouvements elle-même*/
        *lm = NULL; /* Met le pointeur de la liste à NULL*/
    }
}
