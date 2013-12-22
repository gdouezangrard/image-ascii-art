#include "view.h"

int counter = 0;

uint32_t colors[] = {
  // Colors 0 to 15: original ANSI colors
  0x000000, 0xcd0000, 0x00cd00, 0xcdcd00, 0x0000ee, 0xcd00cd, 0x00cdcd, 0xe5e5e5,
  0x7f7f7f, 0xff0000, 0x00ff00, 0xffff00, 0x5c5cff, 0xff00ff, 0x00ffff, 0xffffff,
  // Color cube colors
  0x000000, 0x00005f, 0x000087, 0x0000af, 0x0000d7, 0x0000ff, 0x005f00, 0x005f5f,
  0x005f87, 0x005faf, 0x005fd7, 0x005fff, 0x008700, 0x00875f, 0x008787, 0x0087af,
  0x0087d7, 0x0087ff, 0x00af00, 0x00af5f, 0x00af87, 0x00afaf, 0x00afd7, 0x00afff,
  0x00d700, 0x00d75f, 0x00d787, 0x00d7af, 0x00d7d7, 0x00d7ff, 0x00ff00, 0x00ff5f,
  0x00ff87, 0x00ffaf, 0x00ffd7, 0x00ffff, 0x5f0000, 0x5f005f, 0x5f0087, 0x5f00af,
  0x5f00d7, 0x5f00ff, 0x5f5f00, 0x5f5f5f, 0x5f5f87, 0x5f5faf, 0x5f5fd7, 0x5f5fff,
  0x5f8700, 0x5f875f, 0x5f8787, 0x5f87af, 0x5f87d7, 0x5f87ff, 0x5faf00, 0x5faf5f,
  0x5faf87, 0x5fafaf, 0x5fafd7, 0x5fafff, 0x5fd700, 0x5fd75f, 0x5fd787, 0x5fd7af,
  0x5fd7d7, 0x5fd7ff, 0x5fff00, 0x5fff5f, 0x5fff87, 0x5fffaf, 0x5fffd7, 0x5fffff,
  0x870000, 0x87005f, 0x870087, 0x8700af, 0x8700d7, 0x8700ff, 0x875f00, 0x875f5f,
  0x875f87, 0x875faf, 0x875fd7, 0x875fff, 0x878700, 0x87875f, 0x878787, 0x8787af,
  0x8787d7, 0x8787ff, 0x87af00, 0x87af5f, 0x87af87, 0x87afaf, 0x87afd7, 0x87afff,
  0x87d700, 0x87d75f, 0x87d787, 0x87d7af, 0x87d7d7, 0x87d7ff, 0x87ff00, 0x87ff5f,
  0x87ff87, 0x87ffaf, 0x87ffd7, 0x87ffff, 0xaf0000, 0xaf005f, 0xaf0087, 0xaf00af,
  0xaf00d7, 0xaf00ff, 0xaf5f00, 0xaf5f5f, 0xaf5f87, 0xaf5faf, 0xaf5fd7, 0xaf5fff,
  0xaf8700, 0xaf875f, 0xaf8787, 0xaf87af, 0xaf87d7, 0xaf87ff, 0xafaf00, 0xafaf5f,
  0xafaf87, 0xafafaf, 0xafafd7, 0xafafff, 0xafd700, 0xafd75f, 0xafd787, 0xafd7af,
  0xafd7d7, 0xafd7ff, 0xafff00, 0xafff5f, 0xafff87, 0xafffaf, 0xafffd7, 0xafffff,
  0xd70000, 0xd7005f, 0xd70087, 0xd700af, 0xd700d7, 0xd700ff, 0xd75f00, 0xd75f5f,
  0xd75f87, 0xd75faf, 0xd75fd7, 0xd75fff, 0xd78700, 0xd7875f, 0xd78787, 0xd787af,
  0xd787d7, 0xd787ff, 0xd7af00, 0xd7af5f, 0xd7af87, 0xd7afaf, 0xd7afd7, 0xd7afff,
  0xd7d700, 0xd7d75f, 0xd7d787, 0xd7d7af, 0xd7d7d7, 0xd7d7ff, 0xd7ff00, 0xd7ff5f,
  0xd7ff87, 0xd7ffaf, 0xd7ffd7, 0xd7ffff, 0xff0000, 0xff005f, 0xff0087, 0xff00af,
  0xff00d7, 0xff00ff, 0xff5f00, 0xff5f5f, 0xff5f87, 0xff5faf, 0xff5fd7, 0xff5fff,
  0xff8700, 0xff875f, 0xff8787, 0xff87af, 0xff87d7, 0xff87ff, 0xffaf00, 0xffaf5f,
  0xffaf87, 0xffafaf, 0xffafd7, 0xffafff, 0xffd700, 0xffd75f, 0xffd787, 0xffd7af,
  0xffd7d7, 0xffd7ff, 0xffff00, 0xffff5f, 0xffff87, 0xffffaf, 0xffffd7, 0xffffff,
  // >= 233: Grey ramp
  0x000000, 0x121212, 0x1c1c1c, 0x262626, 0x303030, 0x3a3a3a, 0x444444, 0x4e4e4e,
  0x585858, 0x626262, 0x6c6c6c, 0x767676, 0x808080, 0x8a8a8a, 0x949494, 0x9e9e9e,
  0xa8a8a8, 0xb2b2b2, 0xbcbcbc, 0xc6c6c6, 0xd0d0d0, 0xdadada, 
};

void printImage(int* image_array, image image, int mode, char bool) {
  int mask[4] = { 0 };
  for (int i = 0 ; i < image.height / 2 - 1 ; i++) {
    for (int j = 0 ; j < image.width / 2 - 1 ; j++) {
      mask[0] = image_array[2*i * image.width + 2*j];
      mask[1] = image_array[2*i * image.width + 2*j + 1];
      mask[2] = image_array[(2*i+1) * image.width + 2*j];
      mask[3] = image_array[(2*i+1) * image.width + 2*j + 1];
      switch(mode) {
      case 0:
	masking(mask,bool);
	break;
      case 1:
	maskingGrey(mask,bool);
	break;
      case 3:
	maskingGreyWithTrame(mask,bool);
	break;
	
      }
    }
    putwchar('\n');
    if(bool == 5 )output_file('\n', -1,-1,-1);
  }
  
}

void printImageColor(int* image_array, image image, int mode, char bool) {
  int maskR[4] = { 0 }, maskG[4] = { 0 }, maskB[4] = { 0 };
  counter = 0;
  for (int i = 0 ; i < image.height - 1 ; i++) {
    for (int j = 0 ; j < image.width ; j++) {
      int beginL = 3*i*image.width + 3*j, beginNL = 3*(i+1)*image.width + 3*j;
      int k = 0;
      maskR[k] = image_array[beginL];
      maskG[k] = image_array[beginL + 1];
      maskB[k] = image_array[beginL + 2]; 
  
      if(mode == 4) maskingColorWithTrame(maskR, maskG, maskB, bool);
      else if(mode == 2){
	maskingColor(maskR, maskG, maskB, bool);
      }
    }
    printf("\x1b[0m\n");
    if(bool == 5)output_file('\n', -1,-1,-1);
    counter++;
  }
}

void masking(int * mask,char bool) {
  wchar_t c;
  if (mask[0] == 1 && mask[1] == 1 && mask[2] == 1 && mask[3] == 1) c = 0x2588;
  if (mask[0] == 1 && mask[1] == 0 && mask[2] == 0 && mask[3] == 0) c = 0x2598;
  if (mask[0] == 1 && mask[1] == 1 && mask[2] == 0 && mask[3] == 0) c = 0x2580;
  if (mask[0] == 1 && mask[1] == 1 && mask[2] == 1 && mask[3] == 0) c = 0x259b;
  if (mask[0] == 1 && mask[1] == 1 && mask[2] == 0 && mask[3] == 1) c = 0x259d;
  if (mask[0] == 1 && mask[1] == 0 && mask[2] == 1 && mask[3] == 1) c = 0x259a;
  if (mask[0] == 0 && mask[1] == 1 && mask[2] == 1 && mask[3] == 1) c = 0x259f;
  if (mask[0] == 0 && mask[1] == 0 && mask[2] == 1 && mask[3] == 1) c = 0x2583;
  if (mask[0] == 0 && mask[1] == 1 && mask[2] == 0 && mask[3] == 0) c = 0x2584;
  if (mask[0] == 0 && mask[1] == 0 && mask[2] == 1 && mask[3] == 0) c = 0x2596;
  if (mask[0] == 0 && mask[1] == 0 && mask[2] == 0 && mask[3] == 1) c = 0x2597;
  if (mask[0] == 1 && mask[1] == 0 && mask[2] == 1 && mask[3] == 0) c = 0x258d;
  if (mask[0] == 0 && mask[1] == 1 && mask[2] == 0 && mask[3] == 1) c = 0x2590;
  if (mask[0] == 0 && mask[1] == 0 && mask[2] == 0 && mask[3] == 0) c = 0x0020;
  if (mask[0] == 1 && mask[1] == 0 && mask[2] == 0 && mask[3] == 1) c = 0x259a;
  if (mask[0] == 0 && mask[1] == 1 && mask[2] == 1 && mask[3] == 0) c = 0x259e;

  putwchar(c);
  if(bool == 5) output_file(c, -1,-1,-1);
}

void maskingGreyWithTrame(int * mask, char bool) {
    wchar_t c;
    int moy = (mask[0] + mask[1] + mask[2] + mask[3]) / 4;

    if (moy >= 204) {
      c = 0x0020;
    }
    else if (moy >= 153) {
      c = 0x2591;
    }
    else if (moy >= 102) {
      c = 0x2592;
    }
    else if (moy >= 51) {
      c = 0x2593;
    }
    else {
      c = 0x2588;
    }
    
    putwchar(c);

    if(bool == 5)output_file(c, -1,-1, -1);
}

void maskingGrey(int * mask, char bool) {
  
  wchar_t table_ascii[68] = {'$','@','B','%','8','&','W','M','#','*','o','a','h','k','b','d','p','q','w','m','Z','O','0','Q','L','C','J','U','Y','X','z','c','v','u','n','x','r','j','f','t','/','\\','|','(',')','1','{','}','[',']','?','-','_','+','~','<','>','i','!','l','I',';',':',',','^','`','\'',' '};
  static char c;
  int moy = (mask[0] + mask[1] + mask[2] + mask[3]) / 4;
  double indice = moy * 67.0 / 255.0;
  int ind = (int)indice;
  c = table_ascii[ind];
  fputs(&c, stdout);
  if(bool == 5)output_file(c, -1,-1, -1);
  
}

void maskingColor(int * maskR, int * maskG, int * maskB, char bool) {
   
   int moy = (maskB[0] + maskG[0] + maskR[0])/3;
  static char upper;  
  char table_ascii[68] = {'$','@','B','%','8','&','W','M','#','*','o','a','h','k','b','d','p','q','w','m','Z','O','0','Q','L','C','J','U','Y','X','z','c','v','u','n','x','r','j','f','t','/','\\','|','(',')','1','{','}','[',']','?','-','_','+','~','<','>','i','!','l','I',';',':',',','^','`','\'', ' '};
  float indice = moy *67.0 / 255.0;
  int ind = (int) indice;
  upper = table_ascii[ind];
  uint32_t color = mostNear(maskR[0], maskG[0], maskB[0]);
  printf("\033[38;5;%dm", color);
  fputs(&upper, stdout);
  
  if(bool == 5)  output_file(upper, maskR[0], maskG[0],maskB[0]);
 }

void maskingColorWithTrame(int * maskR, int * maskG, int * maskB, char bool) {

  static char*  lower = "█";
  int color = mostNear(maskR[0], maskG[0], maskB[0]);
  printf("\x1b[38;5;%dm\x1b[48;5;%dm", color, color);
  fputs(lower, stdout);
  if(bool == 5)  output_file((wchar_t)*lower, maskR[0], maskG[0],maskB[0]);
 
 }

uint8_t mostNear(int r, int g, int b) {
  int indic = 0;
  int c_r, c_g, c_b, c_dist, dist;
  dist = 100000000;
  for (int i = 0 ; i < 254 ; i++) {
    c_r = ((0xff0000 & colors[i]) >> 16) - r;
    c_g = ((0x00ff00 & colors[i]) >> 8) - g;
    c_b = (0x0000ff & colors[i]) - b;
    c_dist = c_b * c_b + c_r * c_r + c_g * c_g;
    if (c_dist < dist) {
      dist = c_dist;
      indic = i;
    }
  }
  return indic;
}

void printImageFonction(int * image_array, image image, int colorspace, char bool){
  if ( colorspace == 4 || colorspace == 2) {
    printImageColor(image_array, image, colorspace, bool);
  }
  else {
    printImage(image_array, image, colorspace, bool);
  }
}
