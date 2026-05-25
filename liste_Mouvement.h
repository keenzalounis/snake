#ifndef LISTE_MOUVEMENT_H
#define LISTE_MOUVEMENT_H

/* Définition des directions possibles pour les mouvements */
enum Direction { HAUT, BAS, GAUCHE, DROITE, NEUTRE };

/* Structure représentant une case dans la liste de mouvements*/
struct Case {
    int x;                 /* Coordonnée x de la case*/
    int y;                 /* Coordonnée y de la case*/
    enum Direction sens ;       /* Direction du mouvement */
    struct Case * suivant;     /* Pointeur vers la case suivante */
};

/*Structure représentant la liste des mouvements*/
struct Liste_Mouvement {
    struct Case * premier;     /* Pointeur vers la première case de la liste*/
    struct Case * dernier;     /* Pointeur vers la dernière case de la liste */
    int longueur;              /*Longueur de la liste*/
};

/* Fonction pour créer une nouvelle case */
struct Case * creer_case(int x, int y, enum Direction sens);

/*Fonction pour désallouer une case*/
void desalouer_case(struct Case ** c);

/* Fonction pour créer une nouvelle liste de mouvements*/
struct Liste_Mouvement * creer_liste_mouvement();

/*Fonction pour vérifier si la liste de mouvements est vide*/
int est_vide_lm(struct Liste_Mouvement * lm);

/*Fonction pour ajouter une case au début de la liste de mouvements*/
void ajout_debut_liste_mouvement(struct Liste_Mouvement * lm, struct Case * c);

/* Fonction pour ajouter une case à la fin de la liste de mouvements*/
void ajout_fin_liste_mouvement(struct Liste_Mouvement * lm, struct Case * c);

/* Fonction pour extraire (retirer et retourner) la première case de la liste de mouvements*/
struct Case * extraire_case(struct Liste_Mouvement * lm);

/* Fonction pour désallouer la liste de mouvements et toutes ses cases*/
void desalouer_liste_mouvement(struct Liste_Mouvement ** lm);

#endif
