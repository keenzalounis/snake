CC = gcc
CFLAGS = -Wall -pedantic -std=c99
LDFLAGS = -lncurses
TARGET = snake
OBJ = liste_Mouvement.o liste_Section.o Serpent.o Grille.o Fonction_Jeu_1_Serpent.o main.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

liste_Section.o: liste_Section.c liste_Section.h
	$(CC) $(CFLAGS) -c liste_Section.c

liste_Mouvement.o: liste_Mouvement.c liste_Mouvement.h
	$(CC) $(CFLAGS) -c liste_Mouvement.c

Serpent.o: Serpent.c Serpent.h liste_Section.h liste_Mouvement.h
	$(CC) $(CFLAGS) -c Serpent.c

Grille.o: Grille.c Grille.h Serpent.h liste_Section.h liste_Mouvement.h
	$(CC) $(CFLAGS) -c Grille.c

Fonction_Jeu_1_Serpent.o: Fonction_Jeu_1_Serpent.c Fonction_Jeu.h Grille.h Serpent.h liste_Section.h liste_Mouvement.h
	$(CC) $(CFLAGS) -c Fonction_Jeu_1_Serpent.c

main.o: main.c Fonction_Jeu.h Grille.h Serpent.h liste_Section.h liste_Mouvement.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o $(TARGET) exec projet
