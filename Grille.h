#ifndef GRILLE_H
#define GRILLE_H

#include "Serpent.h"
#include "liste_Mouvement.h"

/* Structure Grille : représente une grille de jeu 2D de taille n x m avec des cellules pouvant contenir des chaînes de caractères. */
struct Grille {
    int n;         // Nombre de lignes de la grille
    int m;         // Nombre de colonnes de la grille
    char ***tab;   // Tableau 3D de chaînes de caractères pour stocker les données de chaque cellule
    int x;         // Position actuelle x (utilisée pour le fruit)
    int y;         // Position actuelle y (utilisée pour le fruit)
};

/* Déclaration des fonctions pour Grille.c */

/* Alloue et initialise une grille de dimensions spécifiées */
struct Grille *Grille_allouer(int n, int m);

/* Efface le contenu de la grille en réinitialisant les cellules à un fond noir */
void Grille_vider(struct Grille *g);

/* Génère une position aléatoire pour un fruit dans la grille */
void Grille_tirage_fruit(struct Grille *g);

/* Affiche un fruit rouge à la position (x, y) spécifiée */
void Grille_remplir_rouge(struct Grille *g, int x, int y);

/* Libère toute la mémoire allouée pour la grille et met le pointeur à NULL */
void Grille_desallouer(struct Grille **g);

/* Redessine la grille entière avec des bordures et mise à jour du contenu */
void Grille_redessiner(struct Grille *g);

/* Remplit une cellule spécifiée de la grille avec une couleur de fond */
void Grille_remplir_couleur(struct Grille *g, int x, int y, int couleur);

/* Met à jour la grille avec la position et la couleur des sections du serpent */
void Grille_remplir_serp(struct Grille *g, struct Serpent *serp, enum Direction sens);

#endif

