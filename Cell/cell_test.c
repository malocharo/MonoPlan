//
// Created by polesmal on 23/11/17.
//
#include "cell.h"
#include <stdio.h>

int main()
{
    init_op();
    feuille_t f1;
    s_cell a_1;
   // s_cell a_2;
    feuille_t * f = &f1;
    s_cell * a1 = &a_1;
  //  s_cell * a2 = &a_2;

    char * saisie1 = "= 3 2 +";
 //   char * saisie2 = "= 3";
    a1->nom = "A1";
  //  a2->nom = "A2";
    a1->contenu = saisie1;
   // a2->contenu = saisie2;

    f->cell = list_create();
    f->cell= list_insert(f->cell,a1);
   // f->cell = list_insert(f->cell,a2);

    analyze(f,a1);
    evaluate(a1);
    printf("%lf",a1->val);




}