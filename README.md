# Snike

**Projet realise par Kenza Lounis**

Snike est un jeu de type Snake developpe en langage C avec la bibliotheque `ncurses`. Le projet met en pratique la programmation modulaire, la manipulation de structures, les listes chainees, la gestion dynamique de la memoire et l'affichage terminal.

## Objectif

Le joueur controle un serpent dans une grille. Le serpent se deplace, change de direction avec les touches du clavier, mange des fruits et perd lorsqu'il touche les bordures. Le projet se concentre sur la logique de jeu, la representation de la grille et la gestion des mouvements du serpent.

## Structure

```text
main.c
Fonction_Jeu_1_Serpent.c / Fonction_Jeu.h
Grille.c / Grille.h
Serpent.c / Serpent.h
liste_Section.c / liste_Section.h
liste_Mouvement.c / liste_Mouvement.h
compte_rendu.txt
Makefile
```

## Fonctionnalites

- Allocation et affichage d'une grille de jeu.
- Representation du serpent avec une liste de sections.
- Gestion des mouvements avec une liste de positions/directions.
- Tirage aleatoire du fruit.
- Affichage colore dans le terminal avec `ncurses`.
- Boucle principale de jeu avec detection des collisions.

## Compilation

Le projet necessite `gcc`, `make` et la bibliotheque `ncurses`.

```bash
make
```

## Execution

```bash
./snike <lignes> <colonnes> <delai>
```

Exemple :

```bash
./snike 20 40 100
```

## Nettoyage

```bash
make clean
```

## Rapport

Le fichier `compte_rendu.txt` explique les structures utilisees et les principales fonctions du projet.

