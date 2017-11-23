  /**--------------------------------------------------------**/
  /**       C o n v e r s i o n   Z vers C (Standard)        **/
  /**             Réalisée par Pr D.E ZEGOUR                 **/
  /**             E S I - Alger                              **/
  /**             Copywrite 2014                             **/
  /**--------------------------------------------------------**/
/*========================================================================================*
=*                                                                                        =*
=*                ALGORITHMIQUE: TP2_S2                                                   =*
=*                       REALISE PAR:                                                     =*
=*                               GACEM               MEKHALFA                             =*
=*                                          G10                                           =*
=*                             ABDERAOUF            TAKIEDDINE                            =*
==========================================================================================*/


  /*****************************AAAVL*****************************/

  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  typedef int bool ;

  #define True 1
  #define False 0

  #define Alea() Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+\
  Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+\
  Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+\
    Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+\
  Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+\
    Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+\
Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+\
    Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)+Aleanombre(1000000000)\
  /** Implémentation **\: ARBRE BINAIRE DE STRUCTURES**/

  /** Structures dynamiques **/

  typedef struct Uii * Pointeur_Uii  ;
  typedef int Type1_Uii ;
  typedef int Type2_Uii ;
  int nb_vis_avl;
  int nb_vis_dsw;
  int max;
  struct Uii
    {
      Type1_Uii Champ1 ;
      Type2_Uii Champ2 ;
    };

  Type1_Uii Struct1_Uii ( Pointeur_Uii S)
    {
       return  S->Champ1 ;
    }

  Type2_Uii Struct2_Uii ( Pointeur_Uii S)
    {
       return  S->Champ2 ;
    }

  void Aff_struct1_Uii ( Pointeur_Uii S, Type1_Uii Val )
    {
       S->Champ1 = Val ;
    }

  void Aff_struct2_Uii ( Pointeur_Uii S, Type2_Uii Val )
    {
       S->Champ2 = Val ;
    }

  void Alloc_struct_Uii( Pointeur_Uii *S)
     {
      *S = (struct Uii *) malloc( sizeof( struct Uii))   ;
     }

  void Liber_struct_Uii( Pointeur_Uii S )
     { free(S); }


  /** Arbres de recherche binaire **/

  typedef Pointeur_Uii Typeelem_AUii   ;
  typedef struct Noeud_AUii * Pointeur_AUii ;

  struct Noeud_AUii
    {
      Typeelem_AUii  Val ;
      Pointeur_AUii Fg ;
      Pointeur_AUii Fd ;
      Pointeur_AUii Pere ;
     } ;

  Typeelem_AUii Info_AUii( Pointeur_AUii P )
    { return P->Val;   }

  Pointeur_AUii Fg_AUii( Pointeur_AUii P)
    { nb_vis_avl++;;return P->Fg ; }

  Pointeur_AUii Fd_AUii( Pointeur_AUii P)
    { nb_vis_avl++;return P->Fd ; }

  Pointeur_AUii Pere_AUii( Pointeur_AUii P)
    { nb_vis_avl++;return P->Pere ;}

  void Aff_info_AUii ( Pointeur_AUii P, Typeelem_AUii Val)
    {
       P->Val = Val ;
    }

  void Aff_fg_AUii( Pointeur_AUii P, Pointeur_AUii Q)
    { P->Fg =  Q;  }

  void Aff_fd_AUii( Pointeur_AUii P, Pointeur_AUii Q)
    { P->Fd =  Q ; }

  void Aff_pere_AUii( Pointeur_AUii P, Pointeur_AUii Q)
    { P->Pere =  Q ; }

  void Creernoeud_AUii( Pointeur_AUii *P)
    {
      *P = (struct Noeud_AUii *) malloc( sizeof( struct Noeud_AUii))   ;
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_AUii( Pointeur_AUii P)
    { free( P ) ; }


  /** Implémentation **\: ARBRE BINAIRE DE ENTIERS**/

  /** Arbres de recherche binaire **/

  typedef int Typeelem_Ai   ;
  typedef struct Noeud_Ai * Pointeur_Ai ;

  struct Noeud_Ai
    {
      Typeelem_Ai  Val ;
      Pointeur_Ai Fg ;
      Pointeur_Ai Fd ;
      Pointeur_Ai Pere ;
     } ;

  Typeelem_Ai Info_Ai( Pointeur_Ai P )
    { nb_vis_dsw++;return P->Val;}

  Pointeur_Ai Fg_Ai( Pointeur_Ai P)
    { nb_vis_dsw++;return P->Fg ;}

  Pointeur_Ai Fd_Ai( Pointeur_Ai P)
    {nb_vis_dsw++; return P->Fd ;}

  Pointeur_Ai Pere_Ai( Pointeur_Ai P)
    { return P->Pere ; }

  void Aff_info_Ai ( Pointeur_Ai P, Typeelem_Ai Val)
    {
       P->Val = Val ;
    }

  void Aff_fg_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Fg =  Q;  }

  void Aff_fd_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Fd =  Q ; }

  void Aff_pere_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Pere =  Q ; }

  void Creernoeud_Ai( Pointeur_Ai *P)
    {
      *P = (struct Noeud_Ai *) malloc( sizeof( struct Noeud_Ai))   ;
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_Ai( Pointeur_Ai P)
    { free( P ) ; }


  /** Implémentation **\: TABLEAU DE ENTIERS**/

  /** Tableaux **/

  typedef int Typeelem_V15i ;
  typedef Typeelem_V15i * Typevect_V15i ;

  Typeelem_V15i Element_V15i ( Typevect_V15i V , int I1  )
    {
      return  *(V + I1-1 ) ;
    }

  void Aff_element_V15i ( Typevect_V15i V  , int I1 ,  Typeelem_V15i Val )
    {
      *(V + I1-1 ) = Val ;
    }

  /** Variables du programme principal **/
  Pointeur_AUii Avl;
  Pointeur_Ai Dsw;
  bool Boolavl;
  int Prf;
  Typevect_V15i Vect;
  int I;
  int J;
  int _Px1;
  int _Px2;
  int nb1=0,nb2=0;
  int exist;
  int tempo;
/** Compteurs DSW**/
 int nbrot_dsw;
 int    nbrot_Moy_dsw;
 int    Prof_max_Moy_dsw;
 int    Prof_min_Moy_dsw;
 float Time_moy_dsw;
 int dif_dsw,dif_moy_dsw;
 int nb_visit_dsw,nb_visit_moy_dsw;
/**/       /**/
/** Compteurs AVL**/
int nbrot_avl;
int    nbrot_Moy_avl;
int    Prof_max_Moy_avl;
int    Prof_min_Moy_avl;
float Time_moy_avl;
int dif_avl,dif_moy_avl;
int nb_visit_avl,nb_visit_moy_avl;
  /** Fonctions standards **/

  int Max (int a, int b)
    {
      if (a > b) return(a);
      else return(b);
    }

  int Min (int a, int b)
    {
      if (a < b) return(a);
      else return(b);
    }

  int Aleanombre( int N )
    { return ( rand() % N ); }


  /** Prototypes des fonctions **/

  void Aff_info_ (Pointeur_AUii *P , int *Val);
  void Aff_eq_ (Pointeur_AUii *P , int *Val);
  int  Info_ (Pointeur_AUii *P) ;
  int  Eq_ (Pointeur_AUii *P) ;
  Pointeur_AUii Right_rot (Pointeur_AUii *P) ;
  Pointeur_AUii Left_rot (Pointeur_AUii *P) ;
  void Insert (Pointeur_AUii *P , int *E);
  Pointeur_AUii Add_l (Pointeur_AUii *P , int *Val) ;
  Pointeur_AUii Add_r (Pointeur_AUii *P , int *Val) ;
  void Equ_noeud (Pointeur_AUii *P);
  bool  Equilibre (Pointeur_AUii *A) ;
  Pointeur_AUii Sv_post (Pointeur_AUii *P) ;
  void Equ_arb (Pointeur_AUii *A);
  int  Prof_max (Pointeur_AUii *P) ;
  int  Prof_min (Pointeur_AUii *P) ;
  void Free_avl (Pointeur_AUii *A);
  void Inordre_avl (Pointeur_AUii *Arbre);
  void Post_avl (Pointeur_AUii *Arbre);
  void Refresh (Pointeur_AUii *P);
  void Init_bal (Pointeur_AUii *A , int *P);
  void Creer_noeud (Pointeur_AUii *Q);
  int  Nb_rot (int *Nb_noeuds) ;
  void Rotation (Pointeur_Ai *N , int *M);
  int  Nbr_n (Pointeur_Ai *N) ;
  void Liste_vers_arbre (Pointeur_Ai *N);
  void Rotation_dsw (Pointeur_Ai *Le_gp , Pointeur_Ai *Le_p , Pointeur_Ai *Le_f);
  void Transformer_arbre (Pointeur_Ai *Racine);
  void Isavl (Pointeur_Ai *N , int *Prf , bool *Avl);
  void Libererarbre (Pointeur_Ai *N);
  void Inordre_dsw (Pointeur_Ai *Arbre);
  void Post_dsw (Pointeur_Ai *Arbre);
  void Insert_in_tree (Pointeur_Ai *Root , int *Val);
  void Parcourir (Pointeur_Ai *Arbre);
  void Init_alea (Typevect_V15i *Tab);
   int  Prof_max_dsw (Pointeur_Ai *R) ;
  int  Prof_min_dsw (Pointeur_Ai *R) ;
  void debut();


   void debut()
{
    puts("=========================================================================================\n");
    puts("=                                                                                       =\n");
    puts("=               ALGORITHMIQUE: TP2_S2                                                   =\n");
    puts("=                      REALISE PAR:                                                     =\n");
    puts("=                              GACEM               MEKHALFA                             =\n");
    puts("=                                         &&                                            =\n");
    puts("=                            ABDERAOUF            TAKIEDDINE                            =\n");
    puts("=========================================================================================\n\n");
    puts("appuyez sur entrer.....");
    getchar();
};
  /*******************************AAAVL*******************************/
  void Inordre_avl (Pointeur_AUii *Arbre)
    {
      /** Variables locales **/
      Pointeur_AUii _Px1;
      Pointeur_AUii _Px2;

      /** Corps du module **/
     if( ( *Arbre != NULL )) {
       _Px1 =  Fg_AUii(*Arbre ) ;
       Inordre_avl ( &_Px1) ;
       printf ( " %d", Info_(&*Arbre) ) ;
       _Px2 =  Fd_AUii(*Arbre ) ;
       Inordre_avl ( &_Px2) ;

     } ;

    }
  /*////////////////////////////////////////////////////*/
  void Post_avl (Pointeur_AUii *Arbre)
    {
      /** Variables locales **/
      Pointeur_AUii _Px1;
      Pointeur_AUii _Px2;

      /** Corps du module **/
     if( ( *Arbre != NULL )) {
       _Px1 =  Fg_AUii(*Arbre ) ;
       Post_avl ( &_Px1) ;
       _Px2 =  Fd_AUii(*Arbre ) ;
       Post_avl ( &_Px2) ;
       printf ( " %d", Info_(&*Arbre) ) ;

     } ;

    }
  /*////////////////////////////////////////////////////*/
  void Aff_info_ (Pointeur_AUii *P , int *Val)
    {

      /** Corps du module **/
     Aff_struct1_Uii(Info_AUii(*P )  , *Val ) ;

    }
  /*////////////////////////////////////////////////////*/
  void Aff_eq_ (Pointeur_AUii *P , int *Val)
    {

      /** Corps du module **/
     Aff_struct2_Uii(Info_AUii(*P )  , *Val ) ;

    }
  /*////////////////////////////////////////////////////*/
  int  Info_ (Pointeur_AUii *P)
    {
      /** Variables locales **/
      int  Info_2 ;

      /** Corps du module **/
     nb_vis_avl++;
     Info_2  =  Struct1_Uii(Info_AUii(*P )  ) ;

     return Info_2 ;
    }
  /*////////////////////////////////////////////////////*/
  int  Eq_ (Pointeur_AUii *P)
    {
      /** Variables locales **/
      int  Eq_2 ;

      /** Corps du module **/
     nb_vis_avl++;
     Eq_2  =  Struct2_Uii(Info_AUii(*P )  ) ;

     return Eq_2 ;
    }
  /*////////////////////////////////////////////////////*/
  Pointeur_AUii Right_rot (Pointeur_AUii *P)
    {
      /** Variables locales **/
      Pointeur_AUii Right_rot2 ;
      Pointeur_AUii X;
      Pointeur_AUii Q,fd;
      int _Px1;
      int _Px2,_Px3;

      /** Corps du module **/
      nbrot_avl++;
     X  =  Fg_AUii(*P ) ;
     Q  =  Pere_AUii(*P ) ;
     if( ( Q != NULL )) {
       if( ( *P == Fg_AUii(Q ) )) {
         Aff_fg_AUii(Q , X ) ;
         }
       else
         {
         Aff_fd_AUii(Q , X ) ;

       } ;

     } ;
     Aff_pere_AUii(X , Q ) ;
     Aff_pere_AUii(*P , X ) ;
     fd=Fd_AUii(X ) ;
     Aff_fg_AUii(*P , fd) ;
     if( ( fd != NULL )) {
       Aff_pere_AUii(fd, *P ) ;

     } ;
     Aff_fd_AUii(X , *P ) ;
     _Px3=Eq_ ( & X );
     _Px1 =  ( Eq_ ( & *P ) - Max(_Px3 , 0 ) - 1 ) ;
     Aff_eq_ ( & *P , &_Px1) ;

     _Px2 =  ( _Px3 + Min(Eq_ ( & *P ) , 0 ) - 1 ) ;
     Aff_eq_ ( & X , &_Px2) ;
     Right_rot2  =  X ;

     return Right_rot2 ;
    }
  /*////////////////////////////////////////////////////*/
  Pointeur_AUii Left_rot (Pointeur_AUii *P)
    {
      /** Variables locales **/
      Pointeur_AUii Left_rot2 ;
      Pointeur_AUii Y,fg;
      Pointeur_AUii Q;
      int _Px1;
      int _Px2,_Px3;

      /** Corps du module **/
     nbrot_avl++;
     Y  =  Fd_AUii(*P ) ;
     Q  =  Pere_AUii(*P ) ;
     if( ( Q != NULL )) {
       if( *P == Fg_AUii(Q )) {
         Aff_fg_AUii(Q , Y ) ;
         }
       else
         {
         Aff_fd_AUii(Q , Y ) ;

       } ;

     } ;
     Aff_pere_AUii(Y , Q ) ;
     Aff_pere_AUii(*P , Y ) ;
     fg=Fg_AUii(Y ) ;
     Aff_fd_AUii(*P , fg) ;
     if( ( fg != NULL )) {
       Aff_pere_AUii(fg, *P ) ;

     } ;
     Aff_fg_AUii(Y , *P ) ;
     _Px3=Eq_ ( & Y );
     _Px1 =  ( Eq_ ( & *P ) - Min(_Px3 , 0 ) + 1 ) ;
     Aff_eq_ ( & *P , &_Px1) ;
     _Px2 =  ( _Px3 + Max(Eq_ ( & *P ) , 0 ) + 1 ) ;
     Aff_eq_ ( & Y , &_Px2) ;
     Left_rot2  =  Y ;

     return Left_rot2 ;
    }
  /*////////////////////////////////////////////////////*/
  void Insert (Pointeur_AUii *P , int *E)
    {
      /** Variables locales **/
      Pointeur_AUii S;
      Pointeur_AUii Q;
      int v;

      /** Corps du module **/
     if( ( *P != NULL )) {
       v=Info_ ( & *P );
       if( *E < v) {
         S  =  Fg_AUii(*P ) ;
         if( S == NULL) {
           Q  =  Add_l ( & *P , & *E ) ;
           nb2++;
           }
         else
           {
           Insert ( & S , & *E ) ;

         } ;
         }
       else
         {
         if( *E > v) {
           S  =  Fd_AUii(*P ) ;
           if( S == NULL) {
             Q  =  Add_r ( & *P , & *E ) ;
             nb2++;
             }
           else
             {
             Insert ( & S , & *E ) ;

           } ;

         }
         else{
            exist=1;
         }

       } ;
       }
     else
       {
       Creer_noeud ( & *P ) ;
       Aff_info_ ( & *P , & *E ) ;
       nb2++;

     } ;

    }
  /*////////////////////////////////////////////////////*/
  Pointeur_AUii Add_l (Pointeur_AUii *P , int *Val)
    {
      /** Variables locales **/
      Pointeur_AUii Add_l2 ;
      Pointeur_AUii Q;

      /** Corps du module **/
     if( *P != NULL) {
       Creer_noeud ( & Q ) ;
       Aff_info_ ( & Q , & *Val ) ;
       Aff_pere_AUii(Q , *P ) ;
       Aff_fg_AUii(*P , Q ) ;
       Add_l2  =  Q ;
       }
     else
       {
       Add_l2  =  NULL ;

     } ;

     return Add_l2 ;
    }
  /*////////////////////////////////////////////////////*/
  Pointeur_AUii Add_r (Pointeur_AUii *P , int *Val)
    {
      /** Variables locales **/
      Pointeur_AUii Add_r2 ;
      Pointeur_AUii Q;

      /** Corps du module **/
     if( *P != NULL) {
       Creer_noeud ( & Q ) ;
       Aff_info_ ( & Q , & *Val ) ;
       Aff_pere_AUii(Q , *P ) ;
       Aff_fd_AUii(*P , Q ) ;
       Add_r2  =  Q ;
       }
     else
       {
       Add_r2  =  NULL ;

     } ;

     return Add_r2 ;
    }
  /*////////////////////////////////////////////////////*/
  void Equ_noeud (Pointeur_AUii *P)
    {
      /** Variables locales **/
      Pointeur_AUii Inutil;
      Pointeur_AUii Sauv1;
      Pointeur_AUii Sauv2;
      bool Miseajour;
      Pointeur_AUii _Px1;
      int _Px2,e1,e2,e3,e4;

      Pointeur_AUii _Px4;


      /** Corps du module **/
     Sauv1  =  *P ;
     _Px2= Eq_ ( & *P );
     if( _Px2 <= - 2 ) {
       _Px1 =  Fd_AUii(*P ) ;
       e1=Eq_ ( &_Px1);
       if( ( e1 < 1 )) {

         if( ( e1 == - 1 )) {
           Miseajour  =  True ;
           }
         else
           {
           Miseajour  =  False ;

         } ;
         *P  =  Left_rot ( & *P ) ;
         }
       else
         {
         Inutil  =  Right_rot ( &_Px1) ;
         *P  =  Left_rot ( & *P ) ;
         Miseajour  =  True ;

       } ;
       }
     else
       {
       if( _Px2 >= 2 ) {
         _Px4 =  Fg_AUii(*P ) ;
         e2= Eq_ ( &_Px4);
         if( e2 > - 1 ) {
           if( e2 == 1 ) {
             Miseajour  =  True ;
             }
           else
             {
             Miseajour  =  False ;

           } ;
           *P  =  Right_rot ( & *P ) ;
           }
         else
           {
           Inutil  =  Left_rot ( &_Px4) ;
           *P  =  Right_rot ( & *P ) ;
           Miseajour  =  True ;

         } ;

       } ;

     } ;
     Sauv2  =  *P ;
     if( ( Miseajour == True )) {
       Refresh ( & Sauv2 ) ;

     } ;
     e3=Eq_ ( & Sauv1 );
     if( ( ( e3 <= - 2 ) || ( e3 >= 2 ) )) {
       Equ_noeud ( & Sauv1 ) ;
       e4=Eq_ ( & *P );
       if( ( ( e4 <= - 2 ) || ( e4 >= 2 ) )) {
         Equ_noeud ( & *P ) ;

       } ;

     } ;

    }
  /*////////////////////////////////////////////////////*/
  bool  Equilibre (Pointeur_AUii *A)
    {
      /** Variables locales **/
      bool  Equilibre2 ;
      bool Ok1;
      bool Ok2;
      Pointeur_AUii _Px1;
      Pointeur_AUii _Px2;

      /** Corps du module **/
     if( ( *A != NULL )) {
       if( ( ( Eq_ ( & *A ) < - 1 ) || ( Eq_ ( & *A ) > 1 ) )) {
         Equilibre2  =  False ;
         }
       else
         {
         if( ( ( Fg_AUii(*A ) == NULL ) && ( Fd_AUii(*A ) == NULL ) )) {
           Equilibre2  =  True ;
           }
         else
           {
           _Px1 =  Fg_AUii(*A ) ;
           Ok1  =  Equilibre ( &_Px1) ;
           _Px2 =  Fd_AUii(*A ) ;
           Ok2  =  Equilibre ( &_Px2) ;
           if( ( ( Ok1 == True ) && ( Ok2 == True ) )) {
             Equilibre2  =  True ;
             }
           else
             {
             Equilibre2  =  False ;

           } ;

         } ;

       } ;
       }
     else
       {
       Equilibre2  =  True ;

     } ;

     return Equilibre2 ;
    }
  /*//////////////////////////////////////////////////*/
  Pointeur_AUii Sv_post (Pointeur_AUii *P)
    {
      /** Variables locales **/
      Pointeur_AUii Sv_post2 ;
      Pointeur_AUii Q,fd,fgg,fdd;

      /** Corps du module **/
     Q  =  Pere_AUii(*P ) ;
     if( ( Q != NULL )) {
       fd=Fd_AUii(Q );
       if( ( ( fd == *P ) || ( fd == NULL ) )) {
         Sv_post2  =  Q ;
         }
       else
         {
         *P  =  fd ;
         fgg=Fg_AUii(*P ) ;
         fdd=Fd_AUii(*P );
         while( ( ( fgg!= NULL ) || ( fdd!= NULL ) )) {
           if( ( fgg != NULL )) {
             *P  =  fgg;
             }
           else
             {
             *P  =  fdd;

           } ;
           fgg=Fg_AUii(*P ) ;
         fdd=Fd_AUii(*P );

         } ;
         Sv_post2  =  *P ;

       } ;
       }
     else
       {
       Sv_post2  =  NULL ;

     }
     return Sv_post2 ;
    }
  /*///////////////////////////////////////////////////////////////////*/
  void Equ_arb (Pointeur_AUii *A)
    {
      /** Variables locales **/
      Pointeur_AUii P;
      Pointeur_AUii Q,fgg,fdd;
      int N,e;

      /** Corps du module **/
     Init_bal ( & *A , & N ) ;



     P  =  *A ;

     fgg=Fg_AUii(P ) ;
         fdd=Fd_AUii(P );


         while( ( ( fgg!= NULL ) || ( fdd!= NULL ) )) {
           if( ( fgg != NULL )) {
             P  =  fgg;
             }
           else
             {
             P  =  fdd;

           } ;
           fgg=Fg_AUii(P ) ;
         fdd=Fd_AUii(P );

         } ;

     while( ( P != NULL )) {
       Q  =  P ;
       P  =  Sv_post ( & P ) ;
       e=Eq_ ( & Q );
       if( ( ( e < - 1 ) || ( e> 1 ) )) {
         if( ( Q == *A )) {
           Equ_noeud ( & *A ) ;
           }
         else
           {
           Equ_noeud ( & Q ) ;

         } ;

       } ;

     } ;

    }
  /*///////////////////////////////////////////////////////////////////*/
  int  Prof_max (Pointeur_AUii *P)
    {
      /** Variables locales **/
      int  Prof_max2 ;
      Pointeur_AUii P1;
      int D1;

      /** Corps du module **/
     D1  =  0 ;
     if( ( *P != NULL )) {
       P1  =  *P ;
       D1  =  1 ;
       while( ( ( Fg_AUii(P1 ) != NULL ) || ( Fd_AUii(P1 ) != NULL ) )) {
         D1  =  D1 + 1 ;
         if( ( Eq_ ( & P1 ) > 0 )) {
           P1  =  Fg_AUii(P1 ) ;
           }
         else
           {
           P1  =  Fd_AUii(P1 );
         } ;

       } ;

     } ;
     Prof_max2  =  D1 ;

     return Prof_max2 ;
    }
  /*///////////////////////////////////////////////////////////////////*/
  int  Prof_min (Pointeur_AUii *P)
    {
      /** Variables locales **/
      int  Prof_min2 ;
      Pointeur_AUii P1,fg,fd;
      int D1,continu=1;

      /** Corps du module **/
     D1  =  0 ;
     if( ( *P != NULL )) {
       P1  =  *P ;
       D1  =  1 ;
       fg=Fg_AUii(P1 ) ;
       fd=Fd_AUii(P1 ) ;
       while( ( ( fd!= NULL ) || ( fd != NULL ) )&& continu) {
         D1  =  D1 + 1 ;
         if( ( Eq_ ( & P1 ) > 0 )) {
           if (fd)P1  =  fd ;
           else continu=0;
           }
         else
           {
           if (fg)P1  =  fg;
           else continu=0;
         } ;

       fg=Fg_AUii(P1 ) ;
       fd=Fd_AUii(P1 ) ;

       } ;

     } ;
     Prof_min2  =  D1 ;

     return Prof_min2 ;
    }
  /*////////////////////////////////////////////////////////////*/
  void Free_avl (Pointeur_AUii *A)
    {
      /** Variables locales **/
      Pointeur_AUii _Px1;
      Pointeur_AUii _Px2;

      /** Corps du module **/
     if( ( *A != NULL )) {
       Liber_struct_Uii(Info_AUii(*A ) ) ;
       _Px1 =  Fg_AUii(*A ) ;
       Free_avl ( &_Px1) ;
       _Px2 =  Fd_AUii(*A ) ;
       Free_avl ( &_Px2) ;
       Liberernoeud_AUii(*A ) ;

     } ;

    }
  /*//////////////////////////////////////////////////////////*/
  void Refresh (Pointeur_AUii *P)
    {
      /** Variables locales **/
      Pointeur_AUii Q;
      int Old;
      int New;
      bool Continue;
      int _Px1;
      int _Px2;

      /** Corps du module **/
     Q  =  Pere_AUii(*P ) ;
     Continue  =  True ;
     while( ( ( Q != NULL ) && ( Continue == True ) )) {
       Old  =  Eq_ ( & Q ) ;
       if( ( *P == Fg_AUii(Q ) )) {
         _Px1 =  ( Old - 1 ) ;
         Aff_eq_ ( & Q , &_Px1) ;
         }
       else
         {
         _Px2 =  ( Old + 1 ) ;
         Aff_eq_ ( & Q , &_Px2) ;

       } ;
       New  =  Eq_ ( & Q ) ;
       if( ( New > 0 )) {
         if( ( New == Max(New , Old ) )) {
           Continue  =  False ;

         } ;
         }
       else
         {
         if( ( New < 0 )) {
           if( ( New == Min(New , Old ) )) {
             Continue  =  False ;

           } ;

         } ;

       } ;
       *P  =  Q ;
       Q  =  Pere_AUii(Q ) ;

     } ;

    }
  /*/////////////////////////////////////////////////////////*/
  void Init_bal (Pointeur_AUii *A , int *P)
    {
      /** Variables locales **/
      Pointeur_AUii Q;
      int P1;
      int P2;
      Pointeur_AUii _Px1;
      Pointeur_AUii _Px2;
      int _Px3;

      /** Corps du module **/
     Q  =  *A ;
     if( ( Q == NULL )) {
       *P  =  0 ;
       }
     else
       {
       _Px1 =  Fg_AUii(Q ) ;
       Init_bal ( &_Px1, & P1 ) ;
       _Px2 =  Fd_AUii(Q ) ;
       Init_bal ( &_Px2, & P2 ) ;
       *P  =  1 + Max(P1 , P2 ) ;
       _Px3 =  ( P1 - P2 ) ;
       Aff_eq_ ( & Q , &_Px3) ;

     } ;

    }
  /*////////////////////////////////////////////////////*/
  void Creer_noeud (Pointeur_AUii *Q)
    {
      /** Variables locales **/
      Pointeur_Uii S;

      /** Corps du module **/
     Creernoeud_AUii(&*Q ) ;
     Aff_pere_AUii(*Q , NULL ) ;
     Aff_fg_AUii(*Q , NULL ) ;
     Aff_fd_AUii(*Q , NULL ) ;
     Alloc_struct_Uii(&S ) ;
     Aff_struct1_Uii(S  , 0 ) ;
     Aff_struct2_Uii(S  , 0 ) ;
     Aff_info_AUii(*Q , S ) ;

    }
  /********************************DDDSW*********************************/
    void Inordre_dsw (Pointeur_Ai *Arbre)
    {
      /** Variables locales **/
      Pointeur_Ai _Px1;
      Pointeur_Ai _Px2;

      /** Corps du module **/
     if( ( *Arbre != NULL )) {
       _Px1 =  Fg_Ai(*Arbre ) ;
       Inordre_dsw ( &_Px1) ;
       printf ( " %d", Info_Ai(*Arbre) ) ;
       _Px2 =  Fd_Ai(*Arbre ) ;
       Inordre_dsw ( &_Px2) ;

     } ;

    }
 /***************************************************************************/
  void Post_dsw (Pointeur_Ai *Arbre)
    {
      /** Variables locales **/
      Pointeur_Ai _Px1;
      Pointeur_Ai _Px2;

      /** Corps du module **/
     if( ( *Arbre != NULL )) {
       _Px1 =  Fg_Ai(*Arbre ) ;
       Post_dsw ( &_Px1) ;
       _Px2 =  Fd_Ai(*Arbre ) ;
       Post_dsw ( &_Px2) ;
       printf ( " %d", Info_Ai(*Arbre) ) ;

     } ;

    }
  /***************************************************************************/
  int  Nb_rot (int *Nb_noeuds)
    {
      /** Variables locales **/
      int  Nb_rot2 ;
      int I;
      int Cpt;
      int Temp;
      int M;

      /** Corps du module **/
     Temp  =  *Nb_noeuds + 1 ;
     Cpt  =  0 ;
     M  =  1 ;
     while( ( ( Temp / 2 ) != 0 )) {
       Cpt  =  Cpt + 1 ;
       Temp  =  Temp / 2 ;

     } ;
     for( I  =  1 ;I <=  Cpt ; ++I){
       M  =  M * 2 ;

     } ;
     M  =  M - 1 ;
     Nb_rot2  =  M ;

     return Nb_rot2 ;
    }
  /*************************************************/
  void Rotation (Pointeur_Ai *N , int *M)
    {
      /** Variables locales **/
      Pointeur_Ai Tempo1;
      Pointeur_Ai Tempo2;
      Pointeur_Ai Liaison;
      int I;

      /** Corps du module **/
     Tempo1  =  *N ;
     Liaison  =  NULL ;
     for( I  =  1 ;I <=  *M ; ++I){
       nbrot_dsw++;
       Tempo2  =  Fd_Ai(Tempo1 ) ;
       Aff_fd_Ai(Tempo1 , Fg_Ai(Tempo2 ) ) ;
       Aff_fg_Ai(Tempo2 , Tempo1 ) ;
       if( ( Liaison == NULL ))   {
         *N  =  Tempo2 ;
         Liaison  =  Tempo2 ;
         }
       else
         {
         Aff_fd_Ai(Liaison , Tempo2 ) ;
         Liaison  =  Tempo2 ;

       } ;
       Tempo1  =  Fd_Ai(Tempo2 ) ;

     } ;

    }
  /********************************************/
  int  Nbr_n (Pointeur_Ai *N)
    {
      /** Variables locales **/
      int  Nbr_n2 ;
      Pointeur_Ai Tempo;
      int Cpt;

      /** Corps du module **/
     Tempo  =  *N ;
     Cpt  =  0 ;
     while( ( Tempo != NULL )) {
       Cpt  =  Cpt + 1 ;
       Tempo  =  Fd_Ai(Tempo ) ;

     } ;
     Nbr_n2  =  Cpt ;

     return Nbr_n2 ;
    }
  /**********************************************/
  void Liste_vers_arbre (Pointeur_Ai *N)
    {
      /** Variables locales **/
      int I;
      int M;
      int _Px1;

      /** Corps du module **/
     I  =  Nbr_n ( & *N ) ;
     M  =  Nb_rot ( & I ) ;
     _Px1 =  I - M ;
     Rotation ( & *N , &_Px1) ;
     while( ( M > 1 )) {
       M  =  M / 2 ;
       Rotation ( & *N , & M ) ;

     } ;

    }
  /*******************************************************/
  void Rotation_dsw (Pointeur_Ai *Le_gp , Pointeur_Ai *Le_p , Pointeur_Ai *Le_f)
    {

      /** Corps du module **/
     nbrot_dsw++;
     Aff_fg_Ai(*Le_p , Fd_Ai(*Le_f ) ) ;
     Aff_fd_Ai(*Le_f , *Le_p ) ;
     *Le_p  =  *Le_f ;
     if( ( *Le_gp != NULL ))   {
       Aff_fd_Ai(*Le_gp , *Le_p ) ;

     } ;

    }
  /*****************************************************/
  void Transformer_arbre (Pointeur_Ai *Racine)
    {
      /** Variables locales **/
      Pointeur_Ai Le_gp;
      Pointeur_Ai Le_p;
      Pointeur_Ai Le_f;

      /** Corps du module **/
     Le_p  =  *Racine ;
     Le_gp  =  NULL ;
     while( ( Le_p != NULL )) {
       Le_f  =  Fg_Ai(Le_p ) ;
       if( ( Le_f != NULL )) {
         Rotation_dsw ( & Le_gp , & Le_p , & Le_f ) ;
         }
       else
         {
         if( ( Le_gp == NULL ))   {
           *Racine  =  Le_p ;

         } ;
         Le_gp  =  Le_p ;
         Le_p  =  Fd_Ai(Le_p ) ;

       }
     }
    }
  /******************************************************************/
  void Isavl (Pointeur_Ai *N , int *Prf , bool *Avl)
    {
      /** Variables locales **/
      int P1;
      int P2;
      Pointeur_Ai _Px1;
      Pointeur_Ai _Px2;

      /** Corps du module **/
     if( ( *Avl == True )) {
       if( ( *N == NULL )) {
         *Prf  =  0 ;
         }
       else
         {
         _Px1 =  Fd_Ai(*N ) ;
         Isavl ( &_Px1, & P1 , & *Avl ) ;
         _Px2 =  Fg_Ai(*N ) ;
         Isavl ( &_Px2, & P2 , & *Avl ) ;
         *Prf  =  1 + Max(P1 , P2 ) ;
         if( ( ( ( P1 - P2 ) < - 1 ) || ( ( P1 - P2 ) > 1 ) )) {
           *Avl  =  False ;

         } ;

       } ;

     } ;

    }
  /************************************************************************/
  void Libererarbre (Pointeur_Ai *N)
    {
      /** Variables locales **/
      Pointeur_Ai _Px1;
      Pointeur_Ai _Px2;

      /** Corps du module **/
     if( ( *N != NULL ))   {
       _Px1 =  Fd_Ai(*N ) ;
       Libererarbre ( &_Px1) ;
       _Px2 =  Fg_Ai(*N ) ;
       Libererarbre ( &_Px2) ;
       Liberernoeud_Ai(*N ) ;

     } ;

    }

  /****************************************************************************/
  void Insert_in_tree (Pointeur_Ai *Root , int *Val)
    {
      /** Variables locales **/
      Pointeur_Ai P;
      Pointeur_Ai Q;
      bool Existing;
      int info;
      /** Corps du module **/
     Existing  =  False ;
     P  =  *Root ;
     Q  =  NULL ;
     while( ( ( P != NULL ) && ( ! Existing ) )) {
       Q  =  P ;
       info=Info_Ai(P );
       if( ( info < *Val ))   {
         P  =  Fd_Ai(P ) ;
         }
       else
         {
         if( ( info > *Val ))   {
           P  =  Fg_Ai(P ) ;
           }
         else
           {
           Existing  =  True ;
           exist=1;

         } ;

       } ;

     } ;
     if( ( ! Existing ))   {
       nb1++;
       Creernoeud_Ai(&P ) ;
       Aff_info_Ai(P , *Val ) ;
       if( ( *Root == NULL )) {
         *Root  =  P ;
         }
       else
         {
         if( ( Info_Ai(Q ) < *Val )) {
           Aff_fd_Ai(Q , P ) ;
           }
         else
           {
           Aff_fg_Ai(Q , P ) ;

         } ;

       } ;

     } ;

    }
  /******************************************************************/
  void Parcourir (Pointeur_Ai *Arbre)
    {
      /** Variables locales **/
      Pointeur_Ai _Px1;
      Pointeur_Ai _Px2;

      /** Corps du module **/
     if( ( *Arbre != NULL )) {
       _Px1 =  Fg_Ai(*Arbre ) ;
       Parcourir ( &_Px1) ;
       printf ( " %d", Info_Ai(*Arbre) ) ;
       _Px2 =  Fd_Ai(*Arbre ) ;
       Parcourir ( &_Px2) ;

     } ;

    }
  /******************************************************************/
  void Init_alea (Typevect_V15i *Tab)
    {
      /** Variables locales **/
      int I;

      /** Corps du module **/
     for( I  =  1 ;I <=  max; ++I){
       Aff_element_V15i(*Tab , I   , Alea())  ;

     } ;

    }
    /***********************************************************************/
int  Prof_max_dsw (Pointeur_Ai *R)
    {
      /** Variables locales **/
      int  Prof_max_dsw2 ;
      int P_1;
      int P_2;
      Pointeur_Ai _Px1;
      Pointeur_Ai _Px2;

      /** Corps du module **/
     if( ( *R == NULL )) {
       Prof_max_dsw2  =  0 ;
       }
     else
       {
       _Px1 =  Fg_Ai(*R ) ;
       P_1  =  Prof_max_dsw ( &_Px1) ;
       _Px2 =  Fd_Ai(*R ) ;
       P_2  =  Prof_max_dsw ( &_Px2) ;
       Prof_max_dsw2  =  1 + Max(P_1 , P_2 ) ;

     } ;

     return Prof_max_dsw2 ;
    }
    /***********************************************************************/
  int  Prof_min_dsw (Pointeur_Ai *R)
    {
      /** Variables locales **/
      int  Prof_min_dsw2 ;
      int P_1;
      int P_2;
      Pointeur_Ai _Px1;
      Pointeur_Ai _Px2;

      /** Corps du module **/
     if( ( *R == NULL )) {
       Prof_min_dsw2  =  0 ;
       }
     else
       {
       _Px1 =  Fg_Ai(*R ) ;
       P_1  =  Prof_min_dsw ( &_Px1) ;
       _Px2 =  Fd_Ai(*R ) ;
       P_2  =  Prof_min_dsw ( &_Px2) ;
       Prof_min_dsw2  =  1 + Min(P_1 , P_2 ) ;

     } ;

     return Prof_min_dsw2 ;
    }
    /***********************************************************************/

  int main(int argc, char *argv[])
    {
        char o[5]="w+";
        char nom[100];
     int trees,min_dsw,max_dsw,min_avl,max_avl,rep;
     clock_t begin_dsw, end_dsw,begin_avl, end_avl;
     double time_spent_dsw,time_spent_avl;
     FILE  *stat_avl_dsw,*mravl,*mrdsw,*mvavl,*mvdsw,*mpMavl,*mpMdsw,*mpmavl,*mpmdsw,*mtavl,*mtdsw,*mdavl,*mddsw,*demo;

    begin:
     debut();
     printf("Donnez votre choix d'exection parmi:\n");
     printf("                                        1.execution complete du TP(execution de simulation)\n                                        2.execution pour teste des algorithmes\n");
     choix: printf(" votre choix est:");
     scanf("%d",&rep);
     printf("\n");

     if(rep==1){
     printf("ATTENTION: le contenu des fichiers de statistiques va etre ecrase\n voulez vous  changer le mode d'ouverture des fichier? (1<=>oui)");
     scanf("%d",&rep);
     printf("\n");
     if(rep==1){o[0]='a'; o[1]='+';o[2]='\0';goto continu;}
     else{
     continu:
    trees=120;
    stat_avl_dsw=fopen("statistique generales.txt",o);
    mrdsw=fopen("DSWrotaionEXCEL.txt",o);
   mravl=fopen("AVLrotaionEXCEL.txt",o);
    mvavl=fopen("AVLvisitEXCEL.txt",o);
    mvdsw=fopen("DSWvisitEXCEL.txt",o);
    mddsw=fopen("DSWprof_difEXCEL.txt",o);
    mdavl=fopen("AVLprof_difEXCEL.txt",o);
    mpmdsw=fopen("DSWprof_mEXCEL.txt",o);
    mpMdsw=fopen("DSWprofMEXCEL.txt",o);
    mpmavl=fopen("AVLprof_mEXCEL.txt",o);
    mpMavl=fopen("AVLprofMEXCEL.txt",o);
    mtavl=fopen("AVLtimeEXCEL.txt",o);
    mtdsw=fopen("DSWtimeEXCEL.txt",o);
    for(max=1000;max<=400000;max=max+1000){
    printf("L'ensemble d'arbre a traiter a %d noeuds\n",max);
    Vect = malloc(max * sizeof(int));
    nbrot_Moy_dsw=0;
    nbrot_Moy_avl=0;
    Time_moy_avl=0.0;
    Time_moy_dsw=0.0;
    nb_visit_moy_avl=0;
    nb_visit_moy_dsw=0;
    Prof_max_Moy_avl=0;
    Prof_max_Moy_dsw=0;
    Prof_min_Moy_avl=0;
    Prof_min_Moy_dsw=0;
    fprintf(stat_avl_dsw,"\n\n/************NOMBRE DE NOEUDS DES ARBRES: %d *************/ \n",max);

     for( J  =  1 ;J <=  trees ; ++J){
        nbrot_dsw=0;
        nbrot_avl=0;
     fprintf(stat_avl_dsw,"L'ARBRE %d :\n",J);
       fprintf(stat_avl_dsw,"                                    /****************************|****************************/ \n");
       fprintf(stat_avl_dsw,"                                    /**     DSW                 *|*                 AVL     **/ \n");
       fprintf(stat_avl_dsw,"                                    /****************************|****************************/ \n");

       Init_alea ( & Vect ) ;
       Avl  =  NULL ;
       Dsw  =  NULL ;
       Boolavl  =  True ;
       nb1=0;
       nb2=0;
       for( I  =  1 ;I <=  max ; I++){
      if (nb1<max-1)
      {
         _Px1 =  Element_V15i(Vect , I   ) ;
         Insert_in_tree ( & Dsw , &_Px1) ;
        if (_Px1>500000){
            _Px1=_Px1%500000;
            Insert_in_tree ( & Dsw , &_Px1) ;
          }

       } ;
       }
       nb_vis_dsw=0;
       begin_dsw = clock();
       Transformer_arbre ( & Dsw ) ;
       Liste_vers_arbre ( & Dsw ) ;
       end_dsw = clock();
       time_spent_dsw=(double)(end_dsw-begin_dsw)/CLOCKS_PER_SEC;
        nb_visit_dsw=nb_vis_dsw;
       Isavl ( & Dsw , & Prf , & Boolavl ) ;
       if(Boolavl) fprintf(stat_avl_dsw,"EQUILIBRE                           /                OK          |");
       else fprintf(stat_avl_dsw,"EQUILIBRE                           /            NOT OK          |");
       min_dsw=Prof_min_dsw(&Dsw);
       max_dsw=Prof_max_dsw(&Dsw);

       Libererarbre ( & Dsw ) ;

      for( I  =  1 ;I <=  max ; I++){
      if (nb2<max-1)
      {
         _Px2 =  Element_V15i(Vect , I   ) ;
         Insert ( & Avl , &_Px2) ;
        if (_Px2>500000){
            _Px2=_Px2%500000;
            Insert ( & Avl , &_Px2) ;
          }

       } ;
       }
       nb_vis_avl=0;
       begin_avl=clock();
       Equ_arb ( & Avl ) ;
       end_avl=clock();
       nb_visit_avl=nb_vis_avl;
        time_spent_avl=(double)(end_avl-begin_avl)/CLOCKS_PER_SEC;
        min_avl=Prof_min(&Avl);
        max_avl=Prof_max(&Avl);
       Boolavl  =  Equilibre ( & Avl ) ;
        if(Boolavl) fprintf(stat_avl_dsw,"           OK               /\n");
       else fprintf(stat_avl_dsw,"      NOT OK                /\n");
       Free_avl ( & Avl ) ;
       fprintf(stat_avl_dsw,"NOMBRE DE NOEUDS VISITES:           /     %12d           |    %12d            /\n",nb_visit_dsw,nb_visit_avl);
       fprintf(stat_avl_dsw,"NOMBRE DE ROTATIONS:                /       %12d         |   %12d             /\n",nbrot_dsw,nbrot_avl);
       fprintf(stat_avl_dsw,"TEMPS D'EXECUTION : (ms)            /  %4.20f    |    %4.20f  /\n",time_spent_dsw*1000,1000*time_spent_avl);
       fprintf(stat_avl_dsw,"LONGUEUR DE LA PLUS GRANDE BRANCHE: /             %3d            |       %3d                  /\n",max_dsw,max_avl);
       fprintf(stat_avl_dsw,"LONGUEUR DE LA PLUS PETITE BRANCHE: /             %3d            |       %3d                  /\n",min_dsw,min_avl);
       fprintf(stat_avl_dsw,"                                    /****************************|****************************/ \n");
       nb_visit_moy_avl=nb_visit_moy_avl+nb_visit_avl;
       nb_visit_moy_dsw=nb_visit_moy_dsw+nb_visit_dsw;
       nbrot_Moy_avl=nbrot_Moy_avl+nbrot_avl;
       nbrot_Moy_dsw=nbrot_Moy_dsw+nbrot_dsw;
       Time_moy_avl=time_spent_avl+Time_moy_avl;
       Time_moy_dsw=Time_moy_dsw+time_spent_dsw;
       Prof_max_Moy_avl=Prof_max_Moy_avl+max_avl;
       Prof_max_Moy_dsw=Prof_max_Moy_dsw+max_dsw;
       Prof_min_Moy_avl=Prof_min_Moy_avl+min_avl;
       Prof_min_Moy_dsw=Prof_min_Moy_dsw+min_dsw;
     } ;

       nb_visit_moy_avl=nb_visit_moy_avl/trees;
       nb_visit_moy_dsw=nb_visit_moy_dsw/trees;
       nbrot_Moy_avl=nbrot_Moy_avl/trees;
       nbrot_Moy_dsw=nbrot_Moy_dsw/trees;
       Time_moy_avl=Time_moy_avl/trees;
       Time_moy_dsw=Time_moy_dsw/trees;
       Prof_max_Moy_avl=Prof_max_Moy_avl/trees;
       Prof_max_Moy_dsw=Prof_max_Moy_dsw/trees;
       Prof_min_Moy_avl=Prof_min_Moy_avl/trees;
       Prof_min_Moy_dsw=Prof_min_Moy_dsw/trees;
       fprintf(mvavl,"%d,%d\n",max,nb_visit_moy_avl);
       fprintf(mvdsw,"%d,%d\n",max,nb_visit_moy_dsw);
       fprintf(mravl,"%d,%d\n",max,nbrot_Moy_avl);
       fprintf(mrdsw,"%d,%d\n",max,nbrot_Moy_dsw);
       fprintf(mtavl,"%d,%f\n",max,Time_moy_avl);
       fprintf(mtdsw,"%d,%f\n",max,Time_moy_dsw);
       fprintf(mpMavl,"%d,%d\n",max,Prof_max_Moy_avl);
       fprintf(mpMdsw,"%d,%d\n",max,Prof_max_Moy_dsw);
       fprintf(mpmavl,"%d,%d\n",max,Prof_min_Moy_avl);
       fprintf(mpmdsw,"%d,%d\n",max,Prof_min_Moy_dsw);
       fprintf(mddsw,"%d,%d\n",max,Prof_max_Moy_dsw-Prof_min_Moy_dsw);
       fprintf(mdavl,"%d,%d\n",max,Prof_max_Moy_avl-Prof_min_Moy_avl);

       fprintf(stat_avl_dsw," LES MOYENNES POUR UN ARBRE DE %d NOEUDS\n",max);
       fprintf(stat_avl_dsw,"                                    /****************************|****************************/ \n");
       fprintf(stat_avl_dsw,"                                    /**     DSW                 *|*                 AVL     **/ \n");
       fprintf(stat_avl_dsw,"                                    /****************************|****************************/ \n");
       fprintf(stat_avl_dsw,"NOMBRE DE NOEUDS VISITES:           /     %12d           |    %12d            /\n",nb_visit_moy_dsw,nb_visit_moy_avl);
       fprintf(stat_avl_dsw,"NOMBRE DE ROTATIONS:                /       %12d         |   %12d             /\n",nbrot_Moy_dsw,nbrot_Moy_avl);
       fprintf(stat_avl_dsw,"TEMPS D'EXECUTION : (ms)            /     %4.15f      |     %4.15f      /\n",Time_moy_dsw*1000,1000*Time_moy_avl);
       fprintf(stat_avl_dsw,"LONGUEUR DE LA PLUS GRANDE BRANCHE: /             %3d            |       %3d                  /\n",Prof_max_Moy_dsw,Prof_max_Moy_avl);
       fprintf(stat_avl_dsw,"LONGUEUR DE LA PLUS PETITE BRANCHE: /             %3d            |       %3d                  /\n",Prof_min_Moy_dsw,Prof_min_Moy_avl);
       fprintf(stat_avl_dsw,"                                    /****************************|****************************/ \n");


    }
    fclose(mrdsw);
    fclose(mravl);
    fclose(mvavl);
    fclose(mvdsw);
    fclose(mddsw);
    fclose(mdavl);
    fclose(mpmdsw);
    fclose(mpMdsw);
    fclose(mpmavl);
    fclose(mpMavl);
    fclose(mtavl);
    fclose(mtdsw);}
     }
    else{
            if(rep==2){
                    Boolavl  = False  ;
                    test:
                         Avl  =  NULL ;
                   Dsw  =  NULL ;
                printf("donnez le nombre de noeud de votre arbre :");
                scanf("%d",&max);
                printf("\n donnez les elements de votre arbre :\n");
                for(I=1;I<=max;I++){
                    printf("elem %d: ",I);
                    scanf("%d",&rep);
                    Insert ( & Avl , &rep) ;
                    Insert_in_tree ( & Dsw , &rep) ;

                }

                if(!Boolavl){
                printf("donnez le nom du fichier pour reccuperer les compteurs:(NomDuFfichier.txt) ");
                scanf("%s",nom);
                demo=fopen(nom,"a+");
                }

                nbrot_dsw=0;
                    nbrot_avl=0;

                   Boolavl  =  True ;
                   printf("\nl'arbre en inordre avant traitement  \n");
                   Inordre_dsw(&Dsw);
                   printf("\nl'arbre en post ordre avant traitement  \n");
                   Post_dsw(&Dsw);
                   nb_vis_dsw=0;
                   begin_dsw = clock();
                   Transformer_arbre ( & Dsw ) ;
                   Liste_vers_arbre ( & Dsw ) ;
                   end_dsw = clock();
                   time_spent_dsw=(double)(end_dsw-begin_dsw)/CLOCKS_PER_SEC;
                    nb_visit_dsw=nb_vis_dsw;
                   Isavl ( & Dsw , & Prf , & Boolavl ) ;
                   if(Boolavl){
                            printf("\nvotre arbre est equilibre par la methode DSW \n");
                   }
                   else printf("EQUILIBRE DSW  NOT OK \n ");
                   min_dsw=Prof_min_dsw(&Dsw);
                   max_dsw=Prof_max_dsw(&Dsw);
                   printf("l'arbre en inordre apres traitement par la methode DSW \n");
                   Inordre_dsw(&Dsw);
                   printf("\nl'arbre en post ordre apres traitement par la methode DSW \n");
                   Post_dsw(&Dsw);
                   Libererarbre ( & Dsw ) ;

                   nb_vis_avl=0;
                   begin_avl=clock();
                   Equ_arb ( & Avl ) ;
                   end_avl=clock();
                   nb_visit_avl=nb_vis_avl;
                    time_spent_avl=(double)(end_avl-begin_avl)/CLOCKS_PER_SEC;
                    min_avl=Prof_min(&Avl);
                    max_avl=Prof_max(&Avl);
                   Boolavl  =  Equilibre ( & Avl ) ;
                   if(Boolavl){
                            printf("\nvotre arbre est equilibre par la methode AVL \n");
                   }
                   else printf("EQUILIBRE DSW  NOT OK \n ");
                   printf("l'arbre en inordre apres traitement par la methode AVL \n");
                   Inordre_avl(&Avl);
                   printf("\nl'arbre en post ordre apres traitement par la methode AVL \n");
                   Post_avl(&Avl);
                   Free_avl ( & Avl ) ;

                   fprintf(demo," LE NOMBRE DE NOEUD : %d \n",max);
                   fprintf(demo,"                                    /****************************|****************************/ \n");
                   fprintf(demo,"                                    /**     DSW                 *|*                 AVL     **/ \n");
                   fprintf(demo,"                                    /****************************|****************************/ \n");
                   fprintf(demo,"NOMBRE DE NOEUDS VISITES:           /     %12d           |    %12d            /\n",nb_visit_dsw,nb_visit_avl);
                   fprintf(demo,"NOMBRE DE ROTATIONS:                /       %12d         |   %12d             /\n",nbrot_dsw,nbrot_avl);
                   fprintf(demo,"TEMPS D'EXECUTION : (ms)            /     %4.15f      |     %4.15f      /\n",time_spent_dsw*1000,1000*time_spent_avl);
                   fprintf(demo,"LONGUEUR DE LA PLUS GRANDE BRANCHE: /             %3d            |       %3d                  /\n",max_dsw,max_avl);
                   fprintf(demo,"LONGUEUR DE LA PLUS PETITE BRANCHE: /             %3d            |       %3d                  /\n",min_dsw,min_avl);
                   fprintf(demo,"                                    /****************************|****************************/ \n");
                   printf("\nvoulez retester les algorithmes sur un autre arbre ?");
                   scanf("%d",&rep);
                   if (rep==1) goto test;
                   fclose(demo);
        }
        else{goto choix;};
    };

      printf("\nvoulez revenir a la realisation de la simulation  ?");
      scanf("%d",&rep);
      if (rep==1) goto begin;
      system("PAUSE");
      return 0;
    }
