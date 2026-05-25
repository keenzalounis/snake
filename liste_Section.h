#ifndef LISTE_SECTION_H
#define LISTE_SECTION_H

// Structure représentant une section du serpent
struct Section {
    int taille;                 /* Taille de la section */
    int couleur;                /* Couleur de la section */
    struct Section * suivant;   /* Pointeur vers la section suivante dans la liste*/
};

// Structure représentant une liste de sections du serpent
struct Liste {
    struct Section * premier;   /* Pointeur vers la première section de la liste */
    struct Section * dernier;   /* Pointeur vers la dernière section de la liste */
    int longueur;               /* Longueur de la liste (nombre de sections) */
};

/* Fonction pour créer une nouvelle section avec une taille et une couleur données */
struct Section * creer_section(int taille, int couleur);

/* Fonction pour désallouer une section de la mémoire*/
void desalouer_section(struct Section ** s);

/* Fonction pour créer une nouvelle liste de sections*/
struct Liste * creer_liste();

/* Fonction pour vérifier si la liste de sections est vide */
int est_vide(struct Liste * l);

/* Fonction pour ajouter une section au début de la liste de sections */
void ajout_debut_liste(struct Liste * l, struct Section * s);

/* Fonction pour ajouter une section à la fin de la liste de sections */
void ajout_fin_liste(struct Liste * l, struct Section * s);

/* Fonction pour extraire et retourner la première section de la liste de sections */
struct Section * extraire_section(struct Liste * l);

/* Fonction pour désallouer la liste de sections et toutes ses sections*/
void desalouer_liste(struct Liste ** l);

#endif
