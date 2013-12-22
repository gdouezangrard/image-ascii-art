#include "parse.h"

void generatePbm(char * filepath, int color){
  FILE *in;
  extern FILE *popen();
  char first[1000] = "convert ";
  char end[1000] = "-compress none -normalize  -strip -depth 8 -channel RGB  -colorspace RGB -resize 30% -sample 150x100%!  target.";
  strcat(first, filepath);
  strcat(first, " ");
  strcat(first, end);
  switch(color){
  case 0:
    strcat(first, "pbm; cat target.pbm | head -n 2 > tmp ; cat target.pbm | tail -n +3 | sed -e ':a;N;$!ba;s/\\n//g' >> tmp");
    break;
  case 1:
    strcat(first, "pgm; cat target.pgm | head -n 3 > tmp ; cat target.pgm | tail -n +4 | sed -e ':a;N;$!ba;s/\\n//g' >> tmp");
    break;
  case 2:
    strcat(first, "ppm; cat target.ppm | head -n 3 > tmp ; cat target.ppm | tail -n +4 | sed -e ':a;N;$!ba;s/\\n//g' >> tmp");
    break;
  case 3:
    strcat(first, "pgm; cat target.pgm | head -n 3 > tmp ; cat target.pgm | tail -n +4 | sed -e ':a;N;$!ba;s/\\n//g' >> tmp");
    break;
  case 4:
    strcat(first, "ppm; cat target.ppm | head -n 3 > tmp ; cat target.ppm | tail -n +4 | sed -e ':a;N;$!ba;s/\\n//g' >> tmp");
    break;
    
  }
  if(!(in = popen(first, "r"))){
    exit(1);
  }
  
  pclose(in);
  
}

image getSize(FILE * file) {
  image image;
  
  char string[4], str1[DIMS_SIZE], str2[DIMS_SIZE];
  
  if (file != NULL) {
    
    fgets(string, 3, file);// On ne fait pas encore de filtrage ici, mais ce que l'on récupère est en réalité la première ligne du fichier image qui indique de quel type il est (P1, P2, ...). Ça servira plus tard pour les fichiers avec les indications de couleurs ou non.
    
    
    fscanf(file, "%s %s\n", str1, str2);// On récupère deux chaînes suivant le format indiqué dans le second paramètre. La lecture du fichier se fait par un curseur virtuel, qui récupère élément après élément. Ainsi on ne s'occupe plus de la première ligne ici.
    
  }
  
  image.width=atoi(str1);
  image.height=atoi(str2);
  
  return image;
}


void readImage(FILE* file, int * image_array, image image, int colorspace) {
  int result, j = 0;
  int string[1000000] = { 0 };
  fileGet(file, image_array, colorspace);
}

void fileGet(FILE *file, int * tableau, int colorspace) {
  char trash[100];
  if (colorspace != 0) {
    fgets(trash, 100, file);// ATTENTION !!!!! PROBLEME AVEC 0
  }
  char num[100] = { 0 };
  char caracter = 'a';
  int i = 0;
  int j = 0;
  do {
    while ( ' ' != (caracter = fgetc(file)) && caracter != EOF) {
      num[i] = caracter;
      i++;
    }
    if (caracter != EOF) {
      tableau[j] = atoi(num);
      j++;
      i = 0;
      for (int k = 0 ; k < 10 ; k++) {
	num[k] = 0;
      }
    }
  }
  while ( caracter != EOF );
  tableau[j] = -1;
}
