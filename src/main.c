/*

:1uuuuuuf+`  ]nuuuuuuj],    ',|U00Jti         ^xu[ 'juuuuuuuuvi   `[rQ0U\I  I(uuuuuuuuv1'      ,1X00Ct:'   '}(((((}'  
iC$$$$$$$$C' u%$$$$$$$$p^  'xh$$$$$$%/I       ;&$c `#$$$$$$$$$}  ]L$$$$$$W|`~O$$$$$$$$$L'     ,d$$$$$$k/   ,8$$$$$o'  
iC$W}})fk$$_ u%%L}}{(Q$$)'`{$$k/_~)O@@m`      ;&$c `#$m|}}}}}}; IW$*U_+j&$$1,+}}td$q}}}~'    `($$v_+|#$M,  +$$mJJJv'  
iC$*'   ~$$|'u%8n    !%$j^[d$#:     u$$_      ;&$c `#$Ul       ,j$@+'   ~hq\    <O$L'        ^f$@['  1LY: ^t$B+I,     
iC$*`'`:n$${'u%BQ{{)/O$$]'v%BX      i@$j^     ;&$c `#$bvrrrrx{'~O$o'     `      <O$L'         <B$@aQr?`   iL$@&@&0>   
iC$@*oM%$$a, u%$$$$$$$%X` U@Mt      ,8$v:     ;&$c `#$$$$$$$$0'?q$d             <O$L'          1bB$$$$ku' )a$Bha@$a^  
iC$$WWWMkc!  u%BqcmB$#]'  XB8u      IB$n,     ;&$c `#$wt)))))_'_m$a'     !,'    <O$L'           '!}nOW$$}'i1j>''j$$?  
iC$*^^^`'    u%8n  )%$B}  \*$d`     ($${:zJ]  l8$c `#$Ul       ;v$Bi    lM&Y    <O$L'        ?Up)    !%$c;l+-   _$${  
iC$*'        u%8n   _W$*, Iu$$X!`';/W$#,IB$Q^`/$$f `#$J>^^^^^^` >%$pf;:}o$$t    <O$L'        ~0$&}^'^)@$x,v%8}`^c$@<  
iC$*'        u%8n    |$$cl ,qB$B#a%$$O[ 'Z@$W*$$#i `#$B8888888t  /b$$%%$$Bc^    <O$L'        '+%$@MaW$$&! iU$$#M$$Q'  
lvam'        tbdt    `jhbu  ,_Z#88Mpj^   I|o88*XI  `waaaaaaaaa|  ',rQhadY_      iXav'          -Lo888hr~   ^X*88kj,   
                         '     `,,^        `,,`                                                  `,,,'       `,,'     
                                                                                                                      
                                                                                                                      
                                                                                                                      
                                                                                                                      
                 -1}`      '<1xnf?,      :~jnr1I    +1[! ,{1i          +1{,     >}111111];' '[111111111_              
                :W$@|     lx@$$$$$h+   ^]#@$$$$&u,  J@#\ <B$j         ,a$$z'    x&$$$$$$$WQ`'o$$$$$$$$$0              
               `|$$$Ml    YBBb\(U@$&!  X8$#r)no$$c  J@#\ <B$j        'u$$$B~    x&@zxxncd$${`/xxx&$hrxx{              
               ]p$wB$r    w$o|  'nkp+ l%$Ui   ,p8m` J@#\ <B$j        <%$b&$Y    x&%i    lB$n,   'a$Q                  
               0@*:Z$a^   u&$B0r[I'  '1$$_     :,'  J@#\ <B$j        z$8<Y$W:   x&B[>><-v$$(`   'a$Q                  
              l%$v 1$$n'  ,{W$$$$Bp1``t$@l          J@#\ <B$j       ,M$Q _@$(`  x&$$$$$$$%w^    'a$Q                  
             ,j$$(+?#$%<    :~n0o@$$t`/$$>     ``   J@#\ <B$j      `)$$j+_q$p]  x&@wmo$$M~^     'a$Q                  
             )h$$$$$$$$c ;cY?`  `~*$q ?$$(`    c#Q, J@#\ <B$j      -w$$$$$$$@Q  x&%i `j@$0-     'a$Q                  
            'w$WmCCCJa$M,;8$p1' '>#$w ^o$*n^ :t%$k` J@#\ <B$j      C@%LCCCJb$%l x&%i  '18$h^    'a$Q                  
            >@$u;    {$$1`X8$@p0bB$$|  ]O$$MkW$$&]  J@#\ <B$j     ;8$L     +@$j,x&%i    f$$r;   'a$Q                  

*/

#include "main.h"


int main(int argc, char *argv[]){
  setlocale(LC_ALL, "fr_FR.utf8");
  FILE* file = NULL;
  image myImage;
  int image_array[IMAGE_ARRAY_SIZE];
  int colorspace = colorDetect(argc, argv);
  if(argc > 5){
    printUsage();
    return 1;
  }
  if (colorspace == -1){
    printUsage();
    return 1;
  }
  if (!pathExists(argc, argv)){
    printUsage();
    return 1;
  }
  generatePbm(argv[3], colorspace);
  file = fopen("tmp", "r");
  if(file ==  NULL){
    printUsage();
    return 1;
  }
  outputFileDelete();
  outputFileDetect(argc, argv);
  myImage = getSize(file);
  readImage(file,image_array, myImage, colorspace);
  printImageFonction(image_array, myImage,colorspace, argc);
  fclose(file);
  outputFileDetectClose(argc, argv);
  return (EXIT_SUCCESS);
}
  
  
  
