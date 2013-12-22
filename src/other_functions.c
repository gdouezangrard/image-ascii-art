#include "other_functions.h"

int colorDetect(int argc, char *argv[]){
 
  if(argc <= 2) return -1;
  int colorspace = atoi(argv[2]);
  if(strcmp(argv[1],"-color") != 0) return -1;
  if(strcmp(argv[1],"-color") == 0 && ( colorspace >= 0 && colorspace <= 4)) return colorspace;
  return -1;
}

int pathExists(int argc, char *argv[]){
  if( argc <=3) return 0;
  FILE* file = NULL;
  file = fopen(argv[3], "r");
  if ( file != NULL ) return 1;
  return 0;
}

void  outputFileDelete()
{
  if ( access ("output.html", F_OK) != -1) remove("output.html");//Si le fichier output.html existe on le supprime 
}

int outputFileDetect(int argc, char *argv[]){  
  if(argc == 5 && strcmp(argv[4],"-output")) return 0;
  if (argc == 5) {
    output_file_open();
    return 1;
  }
  return 0;
  
}


int outputFileDetectClose(int argc, char *argv[]){
  if(argc == 5 && strcmp(argv[4],"-output")) return 0;
  if (argc == 5) {
    output_file_close();
    return 1;
  }
  return 0;
}

void printUsage(){
  printf("USAGE : ./ascii_art -color [0-4] [valid path] (-output) \n");
}

void output_file_open(){
  FILE* file;
  file = fopen("output.html","a+");
  fprintf(file, "%s", "<?xml version=\"1.0\" encoding=\"UTF-8\" ?> <!DOCTYPE html><html><head><meta charset=\"utf-16\"><title>output HTML</title></head><body><style>body{font-size:8px}</style><pre>");
  fclose(file);
}
void output_file( wchar_t c, int r, int g, int b){
  FILE* file;
  file = fopen("output.html","a+");
  if(r != -1){
    fputs("<span style=\"color:rgb(", file);
    char red[4],green[4],blue[4];
    sprintf(red,"%d",r);
    sprintf(green,"%d",g);
    sprintf(blue,"%d",b);
    fputs(red, file);
    fputc(',',file);
    fputs(green,file);
    fputc(',',file);
    fputs(blue, file);
    fputc(')',file);
  }else{
    fputs("<span", file);
  }
  fputs("\">",file);  
  fclose(file);
  writeWideCaracter(c);
}
void output_file_close(){
  FILE* file;
  file = fopen("output.html","a+");
  const char s[30] = "</pre></body></html>";
  fputs(s, file);
  fclose(file);
} 

void writeWideCaracter( wchar_t c){
  FILE *file;
  file = fopen("output.html","a+");
  fputwc(c, file);
  fputs("</span>",file);
  fflush(file);
  fclose(file);
}
  
