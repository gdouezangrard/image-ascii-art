#ifndef PARSE_H_INCLUDED
#define PARSE_H_INCLUDED

#include "other_functions.h"

void generatePbm(char *filepath, int color); // Génère les fichier ppm, pgm ou pbm à partir d'une image donnée en entrée

void readImage(FILE * file, int * image_array, image image, int colorspace);// Lecture du fichier image pour le placer dans un tableau

image getSize(FILE * file);// Obtention de la donnée de la taille de l'image

void fileGet(FILE* file, int * tableau, int colorspace);// Lecture caractère par caractère

#endif