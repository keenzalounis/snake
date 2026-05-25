#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Grille.h"
#include "liste_Mouvement.h"

/* Alloue une grille de dimensions n x m */
struct Grille * Grille_allouer(int n, int m) {
    int i, j;
    struct Grille *g = malloc(sizeof(struct Grille));
    g->n = n;
    g->m = m;

    /* Allocation des lignes */
    g->tab = malloc(n * sizeof(char **));
    /* Allocation des colonnes */
    for (i = 0; i < n; i++) {
        g->tab[i] = malloc(m * sizeof(char *));
        for (j = 0; j < m; j++) {
            g->tab[i][j] = malloc(8 * sizeof(char)); /*allocation memoire des chaines de caractere*/
        }
    }
    g->x = 0;
    g->y = 0;
    return g;
}

/* Remplit les cases avec un fond noir*/
void Grille_vider(struct Grille *g) {
    int i, j;
    for (i = 0; i < g->n; i++) {
        for (j = 0; j < g->m; j++) {
            strcpy(g->tab[i][j], "\033[40m  "); 
        }
    }
}

/* Place un fruit dans la grille aleatoirement */
void Grille_tirage_fruit(struct Grille *g) {
    srand(time(NULL));
    g->x = rand() % g->m;
    g->y = rand() % g->n;
}

/* Affiche le fruit à la position (x, y) de la grille */
void Grille_remplir_rouge(struct Grille *g, int x, int y) {
    strcpy(g->tab[y][x], "\033[101m  "); // Remplit la case avec une couleur rouge (background)
}

/* Désalloue la mémoire utilisée par la grille*/
void Grille_desallouer(struct Grille **g) {
    int i, j;
    if (*g == NULL)
        return;
   
    for (i = 0; i < (*g)->n; i++) {
        for (j = 0; j < (*g)->m; j++) {
            free((*g)->tab[i][j]);
            (*g)->tab[i][j] = NULL;
        }
        free((*g)->tab[i]);
        (*g)->tab[i] = NULL;
    }
    free(*g);
    *g = NULL;
}

/* Redessine la grille entière*/
void Grille_redessiner(struct Grille *g) {
    int i, j;
    printf("\033[2J"); /* Efface l'écran */
    printf("\033[H");  /* Replace le curseur en haut à gauche*/

    /* Dessine la bordure supérieure */
    for (j = 0; j < g->m + 2; j++) {
      printf("\033[100m  "); /*Pour gris fonce*/
    }
    printf("\033[1E"); /* Saut de ligne*/

    /* Dessine le contenu de la grille avec bordures latérales */
    for (i = 0; i < g->n; i++) {
        printf("\033[44m  "); /* Pour un fond bleu foncé pour la bordure gauche */
        for (j = 0; j < g->m; j++) {
            printf("%s\033[0m", g->tab[i][j]);/* remplit le milieu en noir*/
        }
        printf("\033[44m  "); /* Pour un fond bleu foncé pour la bordure droite */

        printf("\033[1E");    /* Saut de ligne */
    }

    /* Dessine la bordure inférieure */
    for (j = 0; j < g->m + 2; j++) {
        printf("\033[100m  "); /* Jaune (background)*/
    }
    printf("\033[0m\n");
}

/*Remplit une case de la grille avec une couleur spécifique (la case du fruit) */
void Grille_remplir_couleur(struct Grille *g, int x, int y, int couleur) {
    if (couleur > 40 && couleur < 48 && x >= 0 && x < g->m && y >= 0 && y < g->n) {
        snprintf(g->tab[y][x], 8, "\033[%dm  ", couleur); 
    }
}

/* Remplit la grille avec le serpent et la direction spécifiée*/
void Grille_remplir_serp(struct Grille *g, struct Serpent *serp, enum Direction sens) {
    int i, x = serp->x, y = serp->y;        
    struct Section *s = serp->chaine->premier;
    struct Case *c = serp->mouvement->premier;

    if (g == NULL || serp == NULL || est_vide(serp->chaine))
        return;

    while (s != NULL) {
        for (i = 0; i < s->taille; i++) {    
            if (c != NULL && x == c->x && y == c->y) {
                sens = c->sens;
                c = c->suivant;
            }
            Grille_remplir_couleur(g, x, y, s->couleur);      
            switch (sens) {
                case HAUT:
                    y++;
                    break;
                case BAS:
                    y--;
                    break;
                case GAUCHE:
                    x++;
                    break;
                case DROITE:
                    x--;
                    break;
            }
        }
        s = s->suivant;
    }
}
