#include <iostream>
#include <windows.h>
#include <wtypes.h>

using namespace std;
void mainMenu();
void GetDesktopResolution(int& horizontal, int& vertical);
void logoGen();
int main(){
	mainMenu();
	return 0;
}

void GetDesktopResolution(int& horizontal, int& vertical)
{
   RECT desktop;											// Handler del escritorio. (Rectángulo como desktop).
   const HWND hDesktop = GetDesktopWindow();				// Def. hDesktop como ventana.
   GetWindowRect(hDesktop, &desktop);						// Obtenemos tamaño.
   horizontal = desktop.right;								// Def. valores variables.
   vertical = desktop.bottom;
}

void mainMenu(){
	int horizontal = 0;
	int vertical = 0;
	GetDesktopResolution(horizontal, vertical);									// Func. obtener resolución.
	HWND console = GetConsoleWindow();											// Obt. consola en la que se ejecuta el programa.
    RECT r;																		// Handler consola. (Rectángulo como r).
    MoveWindow(console, (horizontal - (horizontal - 200)) / 2, (vertical - (vertical - 100)) / 2, horizontal - 200, vertical - 100, TRUE); // Modificamos tamaño consola && centramos.
	GetWindowRect(console, &r);													// Obtenemos tamaño.
	//cout << r.right << "\n";
	//cout << "12345678901234567890123456789012345687901234567890";
	//cout << "Hola owo :3";
	system("CLS");
	logoGen();
}

void logoGen(){
cout << "	                                                                          f " << endl;                                                                            
cout << "                                                                .)           a           )." << endl ;                                                                
cout << "                                                                 )Q          @          uv " << endl ;                                                                
cout << "                                                                  r<         $         `Z  " << endl ;                                                                
cout << "                                                                   B~        $        l@:  " << endl ;                                                                
cout << "                                                      la,           B        $        M^          ,#_ " << endl ;                                                     
cout << "                                                        1b          Cr'      k      .jY          b1   " << endl ;                                                     
cout << "                                                          tw'        m#      ti     mq         wt     " << endl ;                                                     
cout << "                                                            Ub!      -`)    l:J    |^]      ^wq'      " << endl ;                                                     
cout << "                                                             !Ou      J;C   Y a   C:&      wr~        " << endl ;                                                     
cout << "                                                               |.L     [_;  a a  ;_}     L |          " << endl ;                                                     
cout << "                                                  M@-            0 B    X')Ol lkI|i~   B 0            :@M " << endl ;                                                 
cout << "                                                      *_8{,       .W'hI _;v.a a c^< `m.8!       ,>&_M     " << endl ;                                                 
cout << "                                             :>>    '>,   k}fk}>>>I rn Ul# Y* oO klb ~u ;>>>?bf]b`  ^>'  ' ii;" << endl ;                                             
cout << "                                        /?Uh~u>,k^  :`]     ?[q-'/mnX 0; LY~JmL>UQ ;0 v)Zx ?d[?     l;i   afX~?p{[Z" << endl ;                                        
cout << "                                         .?]:L.!~m$Y.!>c   nu.p`]!q)I }CaJ       uaJn ;1Y-(`Q'xc.  v>Iiu$m~, j)l['" << endl ;                                         
cout << "                                          (]xh';^Y&zp&z:,z@@nv[0L[r!0kqfY         |fp&L^U}*C)v)@@C'+/8Zz8z :.hUlJ " << endl ;                                         
cout << "                                          0)lt&nUQU%8hLzvvvvvnj}:      ;           x      :[fnvvvvvzCb8MOcwnw1 C)  " << endl ;                                        
cout << "                                         'J^ {lX!{.+O$>X^>[b$Zkw:I- `iM q         L M<` [:!0qO$h;},X:$O~ [>/_[;>m' " << endl ;                                        
cout << "                                          z_%X:-<?{-^;`hXLl'$Wkx l]rZr]i^0'      Q^>]]ZQ]i vwU$./QYw`.+<>+]i,J$<z  " << endl ;                                        
cout << "                                          I Y1qU<n!|{fMxwdYBwBfXWrwrX[]]]]]nfftn]]]]]]JrccojtB#8Cqwxot{q:J<?n};`<. " << endl ;                                        
cout << "                                          ''}|!;,moLiB                       B                       &~0q_:+.J{l.  " << endl ;                                        
cout << "                                         '{~X$@w- MB$$ ,:       .k        `  B        n@$$B#         &$@M `8B$Ml}' " << endl ;                                        
cout << "                                         .qi>-J ]$$XWB i$M$$BZ&`$@%^<BB$@%$  B      %$$$$$$$$$`      &%n$$l r~I_u. " << endl ;                                        
cout << "                                          !ro8L:U$$L[B izYI$$$$|@o$?o$$$iMz  B     /@#W@B#@$$$$      &}v$$0,m&*;j  " << endl ;                                        
cout << "                                         ,*O+J^+:' zfB i$Q$1+   >$   `+Y%/W  B     0+      W$$$      &-z  :~^L>O8< " << endl ;                                        
cout << "                                         BfiQuY8c  __@ i$0$1]Z$U.$ B$Q'YM%$  B     1.>I;Cdj f8Q      &~~  uBbu0+-& " << endl ;                                        
cout << "                                         !0L/(fB_  fiB i$b$1>J$$$$$$$U'Y@&$  B      -:<.jI  ?_l      &~f  Ia)|/Lbj " << endl ;                                        
cout << "                                          ;@$j?h'  /iB iqvI1 ]M$$$$$0- YfQw  B     I1 I     %^       &~]  `p1-$$+  " << endl ;                                        
cout << "                                         .O~c^z:   UiB i$($1f- XY$0t.lXYM|#  B      },~     J@_      &~n  .(Ulti0. " << endl ;                                        
cout << "                                         C +}/z~n  xp@ i$a$1CLwfk$p{r0aY&B$  B      '0`-   QnBq      &d(  [|{+}< h` " << endl ;                                       
cout << "                                        -%r <@C8O  Ur@ i$m[M  0_`$ _f  WW_$  B     m$@)J:{.v?&$@d    &(O  d%d$c <%[ " << endl ;                                       
cout << "                                         lYL8^v    1b@ ;8duq$*aak.aaaM$*!p$  B    q$${]ucw&$t@$@$$%I &o>    C;&OQ+ " << endl ;                                        
cout << "                                          ,$#Z8%@M&*%B  `$@&m$BBMmY@@$I&$$'  B   &$$@z; .($|%$$/$$$i &$M*d@8%w*$;  " << endl ;                                        
cout << "                                           .X&h#ZZ f%$          B$0          B  @$$$!t; 0bBJ@$$u$$$i &Bf qb%mMu_  " << endl ;                                         
cout << "                                           .%Jz Mlm.vB                       B                       &0.C<* zuB:  " << endl ;                                         
cout << "                                           tkI   ,.U<Bbbbbbbbbbbbbbbbbbbbbbbb@bbbbbbbbbbbbbbbbbbbbbbbB~v';,  ~Ou  " << endl ;                                         
cout << "                                          ^|C+  u< I@@                       B                       &$l >U .}u1:  " << endl ;                                        
cout << "                                         'MrI~: [f*qcB                       B           (Bo#$!      &Xqof{ `!,fW'  " << endl ;                                       
cout << "                                       <i'n] i`l,x%j&%         ?f0n.         B         r$)    k      B@t%n^~': }f'li  " << endl ;                                     
cout << "                                      ^[(fhjc{  ^i%xt@                       B        Z@l     XL     @fn8l;  _cjk/((, " << endl ;                                     
cout << "                                      .CQCt`0}frj_tvv%/   `:'Y (J:< )jY,     B       Z8       X!    -BYuu_|}f[Z'/CQc. " << endl ;                                     
cout << "                                           <'z*p/.>1z8z    0I8cX/_[._~Z]     B      ^$)       X     x%nt_ j0oz'l  " << endl ;                                         
cout << "                                             LO &>^ti;u                      B      $$bbkB$$$$#j+<  X,i/^<& OL   " << endl ;                                          
cout << "                                           .mZn#Wwa:@M?#^        ^{X~        B  f;;r$]      _@t    ajM@:amM#rQC.  " << endl ;                                         
cout << "                                         Wk   I.Uf.I+iuiB          .         B     |$]     )$$    Binl/I.{C :o  Ml " << endl ;                                        
cout << "                                         'B]  O | 1f.O:W%8   * YM[&cpZh#~:xq B      ${    )$0    ddd-v`x  ? '] (C' " << endl ;                                        
cout << "                                         '}X@%/'^!`{  1 tro1 b^YnU0;,C i q:{ B      `%$Yw$#~   [or<./q' k+``{M@c}^ " << endl ;                                        
cout << "                                        |<+Z@Lp+tdr]^> l!I,Wk~               B               ipd^j/  ` <Ckj+pq$b<<| " << endl ;                                       
cout << "                                        >}xlI'';_Ol~aU-c jflU)W{             B             [$moIzu z<k*Ivu};''I!f+~ " << endl ;                                       
cout << "                                          tfIOm.    ,nLf( ^Ct%o_nbJ|         B         )v*#){;Xo` rnUnI    .w0:rf " << endl ;                                         
cout << "                                           Q        :[Qf] J^^fq~nX-nvkn$wunnn@nnnuZ@nmXn{]x<)>`I> ;wc^:        Q  " << endl ;                                         
cout << "                                                   fn)d} Q' :pm  /}Q~| l;^O/h&?X%'l_ t_@u)}~]~1  U.nt|vn          " << endl ;                                         
cout << "                                                   YMJn8#Z?i|`  c. % u'`?}}]i[_-}}_' ._[   -  n`YC0Wu?)x        " << endl ;                                           
cout << "                                                    >Mf  d*l``C]f [. -` ;-  Y}  j ? ^?  , I]LvI'whI }%{        " << endl ;                                            
cout << "                                               |aa/         ,0O|&B$_Yao)` ^..'  ^.'{odX!@$@fm>)         tabc   " << endl ;                                            
cout << "                                              ` x  tZ..b       ''jML8%%Q%n'     .]#d%%%0aQ`'.      w`i< 8]     " << endl ;                                            
cout << "                                              -^ .*v z/ L I~.  (.}r - L{   ba ;!C /.^]x'!8`(   l}x. n  t . `!  " << endl ;                                            
cout << "                                               w'   L^I: ?'mn .LoX  +:  O: Z`,. .>L;a i>| oq, f _ >!/,0   `a   " << endl ;                                            
cout << "                                                 -: Il( C:<!^MuI.+^.U                 O :-,.   >::v.!+! ,?    " << endl ;                                             
cout << "                                                 Z    f)_   f,_]    !                 +    {?:t   +~x    j   " << endl ;                                              
cout << "                                                 :'       :)      |/                   /f.     1>       'l  " << endl ;                                               
cout << "                                                     I)^,    :                               _.   ,,1^    " << endl ;                                                 
cout << "                                                         <|!;x                              'jl:!>      " << endl ;                                                   
cout << "                                                          'Q  1                             :. a'       " << endl ;                                                   
cout << "                                                                                                                                                           " << endl ;
cout << "                                                                                                                                                           " << endl ;
cout << "}$8  .$> iB$d  h[ 'M$  /$(  ^$I $$z::$  $B<:@@^ z$>`]$ i$X  u${:l$w    J$$    $$::d@a     W$q:u$W   $#' W$^'mL@z:%$+:$  $a::$B  ^$% {$:t$jIWj d$@i   J$?   " << endl ;
cout << "}$M   $; iBn$& w_ '#$  lB$  Xv  $$u`o   $B; B$Q J$@    i$v  t$?  0$$  n/($j   $$   O$]    *$m  +$h  $*. $$Y      %$l    $h  $$|  $%    )$/   <$n$*   X$?   " << endl ;
cout << "}$M   $; iB ~$YJ_ '#$   b$m^u   $$uI@   $@&B$.   l#$$~ i$v  t$?  v$$ ?@,-B$   $$   t$]    *$m  +$B  $*.  ,&$$>   %$l    $BW@*.   $%    )$/   $~,$$~  X$?   " << endl ;
cout << "]@$  '$; iB  J$$_ '#$    8B@    $$u  8  $B;I@$; b   $$ i$v  t$?  w@. $^  h$b  $$  ^$8`    *$m  u$|  $*._Z  `$L   %$l    $h ]$$:  $%    )$/  XO  !$J  X$? .$" << endl ;
cout << "  wwww+  ww|  {w> mwww   jw^   |wwwwww cwwZ  wwCwwwwY  www>]wwwww_  wwZ :Zww{)wwwww.     +wwwwwj   Jwwv_wwww-   +www^  Lwwz :wwfJww+  fwww QwC' mwwQxwwwwww" << endl ;
cout << "                                                                                                                                                           " << endl ;
cout << "                                                                                      Uz`                                                                  " << endl ;
cout << "rWn|wh^pd/Lu     U#   -Wn  )bi  vxnMIiWhi )Jxh)  uux&: 'jYvU_     XW!  {QxQ|  ,QxpU tW||m0    +Wr|Cu   C*|/W?     }uxqz    $   'dhi   -Wt|Ju    'ov   ivxB-" << endl ;
cout << ".B>  , :q  no   jx@_   0%x  f  M,  .' J? '$   ` d)  '. $>   $     {$  &/   $! $<  ` ^$   :     kI  .$  fM   '    vC   l   hj*   vJ     o`  '$   Ui%   B~  ." << endl ;
cout << ".Bmw@  :&OOY   ,L Ih   0 0Z f  $      J?  ~XB1  $     }8I   8]    {$ :%|   qO `1@C' ^$]1&      kI   %! f&]m^     %|      ?i $~  vJ     o`   @, )J rm  .J80 " << endl ;
cout << ".B>    :q '$.  #_iipx  0  thf  $      J?     LO 8-    .$>   $     {$  &/   $!    ;$ ^$   ;     kI   $  fM   ^    &r     ?oii?$  vJ  -_ o`   $  pii>B>    ~o" << endl ;
cout << "/@Z   `hB- ^@L#B~ 'W8;z%!  lf  ^B**$~!BW;'%**O. ^h**8l .a**M,     {$   L**&;  @#*al L$***Z    +@#*#?'  W@**&[     Y#oWd+8b` t@a'h8**W ?@**M~'l%&  }$M-@**B`" << endl ;
cout << "                                                                  C;                                                                                       " << endl ;
}

