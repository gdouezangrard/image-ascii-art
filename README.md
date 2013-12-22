```
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

                                (actual output)
```

[Rapport](doc/main.pdf)

## Compilation

    make

## Exécution

```
Usage: ./ascii_art -color 0..4 PATH [-output]


Args:

	PATH  chemin vers l'image à transformer en ascii-art en n'importe quel
	      format standard: png, jpg, gif...


Colors:

	0  Image en noir et blanc avec trames
	1  Image en niveaux de gris en caractères ascii
	2  Image en couleurs en caractères ascii
	3  Image en niveaux de gris avec trames
	4  Image en couleurs avec trames


Options:

	-output  Générer un fichier HTML `output.html` pour afficher les images
		 générées dans le navigateur (optional)
```
