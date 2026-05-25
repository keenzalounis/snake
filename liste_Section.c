#include <stdlib.h>
#include <stdio.h>
#include "liste_Section.h"

/* Fonction pour créer une nouvelle section avec une taille et une couleur données*/
struct Section * creer_section(int taille, int couleur) {
    /* Allocation de mémoire pour la nouvelle section */
    struct Section * s = malloc(sizeof(struct Section));
   
    /* Initialisation des attributs de la section*/
    s->taille = taille;
    s->couleur = couleur;
    s->suivant = NULL;
   
    return s; /* Retourne la nouvelle section créée*/
}

/* Fonction pour désallouer une section de la mémoire*/
void desalouer_section(struct Section ** s) {
    /* Vérifie si la section existe*/
    if (*s != NULL) {
        /* Libération de la mémoire allouée pour la section*/
        free(*s);
        /* Attribution de la valeur NULL au pointeur de section pour éviter les références invalides*/
        *s = NULL;
    }
}

/* Fonction pour créer une nouvelle liste de sections*/
struct Liste * creer_liste() {
    /* Allocation de mémoire pour la nouvelle liste de sections*/
    struct Liste * l = malloc(sizeof(struct Liste));
   
    /* Initialisation des attributs de la liste*/
    l->premier = NULL;
    l->dernier = NULL;
    l->longueur = 0;
   
    return l; /* Retourne la nouvelle liste créée*/
}

/* Fonction pour vérifier si la liste de sections est vide*/
int est_vide(struct Liste * l) {
    return (l->longueur == 0); /* Retourne vrai si la liste est vide, faux sinon*/
}

/* Fonction pour ajouter une section au début de la liste de sections*/
void ajout_debut_liste(struct Liste * l, struct Section * s) {
    /* Vérifie si la liste est vide*/
    if (est_vide(l))
        l->dernier = s; /* Si oui, la section devient également la dernière de la liste*/
   
    /* Mise à jour des pointeurs pour ajouter la section au début de la liste*/
    s->suivant = l->premier;
    l->premier = s;
   
    l->longueur++; /* Incrémente la longueur de la liste*/
}

/* Fonction pour ajouter une section à la fin de la liste de sections */
void ajout_fin_liste(struct Liste * l, struct Section * s) {
    /* Mise à jour des pointeurs pour ajouter la section à la fin de la liste */
    s->suivant = NULL;
   
    /* Vérifie si la liste est vide*/
    if (est_vide(l)) {
        l->premier = s; /* Si oui, la section devient également la première de la liste*/
    } else {
        l->dernier->suivant = s; /* Sinon, la section devient le suivant de la dernière section actuelle*/
    }
   
    l->dernier = s; /* La section devient la dernière de la liste*/
   
    l->longueur++; /* Incrémente la longueur de la liste*/
}

/* Fonction pour extraire et retourner la première section de la liste de sections*/
struct Section * extraire_section(struct Liste * l) {
    /* Récupération de la première section de la liste*/
    struct Section * s = l->premier;
   
    /* Vérifie si la liste n'est pas vide*/
    if (s != NULL) {
        l->premier = s->suivant; /* Mise à jour du premier élément de la liste*/
       
        l->longueur--; /* Décrémente la longueur de la liste*/
       
        /* Si la liste est maintenant vide, met à jour le dernier élément de la liste*/
        if (est_vide(l))
            l->dernier = NULL;
       
        s->suivant = NULL; /* Détache la section de la liste*/
    }
   
    return s; /* Retourne la première section extraite*/
}

/* Fonction pour désallouer la liste de sections et toutes ses sections*/
void desalouer_liste(struct Liste ** l) {
    /* Vérifie si la liste existe*/
    if (*l != NULL) {
        struct Section * s; /* Section temporaire pour stocker chaque section à désallouer*/
       
        /* Parcourt la liste jusqu'à ce qu'elle soit vide*/
        while (!est_vide(*l)) {
            s = extraire_section(*l); /* Extrait la première section de la liste*/
            desalouer_section(&s); /* Désalloue la section extraite*/
        }
       
        free(*l); /* Désalloue la liste de sections*/
        *l = NULL; /* Attribue la valeur NULL au pointeur de liste pour éviter les références invalides*/
    }
}
