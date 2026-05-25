#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "Fonction_Jeu.h"
#include "Grille.h"
#include "Serpent.h"
#include "liste_Section.h"
#include "liste_Mouvement.h"

/* Fonction principale pour jouer au jeu du serpent */
void Jouer_Serpent(struct Grille *g, struct Serpent *serp, int delai) {
    int ch; /* Variable pour stocker les entrées clavier */
    enum Direction sens = NEUTRE; /* Direction initiale du serpent */
    int couleur, longueur; /* Variables pour la couleur et la longueur des sections */

    /*Initialisation de ncurses et du clavier */
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    halfdelay(delai);

    /* Initialisation de la grille */
    Grille_tirage_fruit(g); /*Place un fruit aléatoirement dans la grille */
    Grille_vider(g); /* Vide la grille */
    Grille_remplir_rouge(g, g->x, g->y); /* Affiche le fruit dans la grille*/
    Grille_remplir_serp(g, serp, sens); /*Affiche le serpent dans la grille*/
    Grille_redessiner(g); /*Redessine la grille*/
    refresh(); /* Rafraîchit l'affichage */

    /*Boucle principale du jeu */
    while ((ch = getch()) != 'a') { /* Continue jusqu'à ce que 'a' soit pressé*/
        /* Gestion des entrées clavier pour changer la direction du serpent */
        switch (ch) {
            case KEY_UP:
                if (sens != BAS) {
                    ajout_fin_liste_mouvement(serp->mouvement, creer_case(serp->x, serp->y, HAUT));
                    sens = HAUT;
                }
                break;
            case KEY_DOWN:
                if (sens != HAUT) {
                    ajout_fin_liste_mouvement(serp->mouvement, creer_case(serp->x, serp->y, BAS));
                    sens = BAS;
                }
                break;
            case KEY_LEFT:
                if (sens != DROITE) {
                    ajout_fin_liste_mouvement(serp->mouvement, creer_case(serp->x, serp->y, GAUCHE));
                    sens = GAUCHE;
                }
                break;
            case KEY_RIGHT:
                if (sens != GAUCHE) {
                    ajout_fin_liste_mouvement(serp->mouvement, creer_case(serp->x, serp->y, DROITE));
                    sens = DROITE;
                }
                break;
        }

        /* Mise à jour des coordonnées du serpent en fonction de la direction */
        switch (sens) {
            case HAUT:
                serp->y--;
                break;
            case BAS:
                serp->y++;
                break;
            case DROITE:
                serp->x++;
                break;
            case GAUCHE:
                serp->x--;
                break;
        }

        /* Vérification de la collision avec le bord */
        if (serp->x < 0 || serp->x >= g->m || serp->y < 0 || serp->y >= g->n) {
            break;
        }

        /* Vérification de la collision avec le fruit */
        if (serp->x == g->x && serp->y == g->y) {
            longueur = (rand() % 2) + 1; /* Détermination de la longueur de la nouvelle section */
            couleur = (rand() % 6) + 41; /* Détermination de la couleur de la nouvelle section */
            ajout_fin_liste(serp->chaine, creer_section(longueur, couleur)); /* Ajout de la nouvelle section au serpent */
            Grille_tirage_fruit(g); /*Placement d'un nouveau fruit*/
        }

        /* Mise à jour de la grille */
        Grille_vider(g); /*Vide la grillez*/
        Grille_remplir_rouge(g, g->x, g->y); /* Affiche le fruit dans la grille */
        Grille_remplir_serp(g, serp, sens); /* Affiche le serpent dans la grille */
        Grille_redessiner(g); /*Redessine la grille*/
        refresh(); /* Rafraîchit l'affichage */
    }

    /* Terminer la session ncurses */
    endwin();

    printf("loose\n"); /* Message de fin de jeu */
}
