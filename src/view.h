#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED

#include <locale.h>
#include <stdint.h>
#include "other_functions.h"

void masking(int * mask, char bool);

void maskingGrey(int * mask, char bool);

void maskingGreyWithTrame(int * mask, char bool);

void printImage(int * image_array, image image, int mode,char bool);// Affichage des images en noir et blanc ou en niveaux de gris

void maskingColor(int * maskR, int * maskG, int * maskB, char bool);

void maskingColorWithTrame(int * maskR, int * maskG, int * maskB, char bool);

void printImageColor(int * image_array, image image, int mode, char bool); //Affichage des images en couleurs

uint8_t mostNear(int r, int g, int b);// détermine le code hexadécimal d'une couleur RGB

void printImageFonction(int * image_array, image image, int colorspace, char bool);

#endif