#ifndef OTHER_FUNCTIONS_H_INCLUDED
#define OTHER_FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <unistd.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILED 1
#define DIMS_SIZE 5
#define IMAGE_ARRAY_SIZE 900000// Nombre de pixel maximum par image


struct image {// Définition d'une structure contenant les attributs entiers width et height
  int width;
  int height;
  
};

typedef struct image image;// Alias pour cette structure défini à "image" (c'est un type maintenant utilisable via le type "image")

int pclose(FILE *file);

void itoa(int number, char * array);

int ctoi(char current_char);// Convertion d'un char en int (on peut aussi caster directement)

void writeWideCaracter( wchar_t c); // Ecriture d'un caractère étendu dans le fichier output.html

void output_file_open(); // Génère le fichier HTML et insère les balises de début

void output_file( wchar_t c, int r, int g, int b); // Insertion des balises span et des couleurs 

void output_file_close(); // ferme le fichier HTML

int  colorDetect(int argc, char *argv[]);

int pathExists(int argc, char *argv[]);

void outputFileDelete();

int outputFileDetect(int argc, char *argv[]);

int outputFileDetectClose(int argc, char *argv[]);

void printUsage();

#endif