//
// Created by polesmal on 23/11/17.
//
#include "cell.h"
#include <stdio.h>

void printCell(s_cell *c)
{
    if(c->val == 0.0)
        printf("Value of %s is %s\n",c->nom,c->contenu);
    else
        printf("Value of %s is %lf\n",c->nom,c->val);
}

void viewListCell(node_t* list) {
    node_t* tmp = list;
    int i;
    i = 0;
    while(tmp) {
        if (((s_token*)(tmp->data))->type == 0)
            printf("Element %d : %f\n", i, ((s_token*)(tmp->data))->value.cst);
        else
            printf("Element %d : %p  %d (0)val (1)ref (2)op\n", i, (void*)((s_token*)(tmp->data))->value.ref,(int)((s_token*)(tmp->data))->type);
        tmp = tmp->next;
        i++;
    }
}


int main()
{
    init_op();
    feuille_t f1;
    s_cell a_1;
    s_cell a_2;
    s_cell a_3;
    s_cell a_4;
    feuille_t * f = &f1;
    s_cell * a1 = &a_1;
    s_cell * a2 = &a_2;
    s_cell * a3 = &a_3;
    s_cell * a4 = &a_4;

    char * saisie1 = "= B4 A2 +";
    char * saisie2 = "= 7 B4 +";
    char * saisie3 = "Je suis 1 test";
    char * saisie4 = "= 1 2 + ";
    a1->nom = "A1";
    a2->nom = "A2";
    a3->nom = "B3";
    a4->nom = "B4";
    a1->contenu = saisie1;
    a2->contenu = saisie2;
    a3->contenu = saisie3;
    a4->contenu = saisie4;
    f->cell = list_create();
    f->cell = list_insert(f->cell,a1);
    f->cell = list_insert(f->cell,a2); // parce qu'on evalue pas bien pour l instant, la case sans predecesseur doit etre en tete
    //f->cell = list_append(f->cell,a3);
    f->cell = list_insert(f->cell,a4);

    analyze(f,a4);
    evaluate(a4);
    analyze(f,a2);
    evaluate(a2);
    analyze(f,a1);
    viewListCell(a1->token);

    viewListCell(a2->token);
    viewListCell(a4->token);
    evaluate(a1);

//    topologicalSort(f,a1);


    printCell(a1);
    printCell(a2);
    printCell(a3);
    printCell(a4);


   /* if(a1->val != -14.0)
        printf("erreur case A1");
    if(a2->val != 16.0)
        printf("erreur case A2");
    if(strcmp(a3->contenu,saisie3) != 0)
        printf("erreur case B3");
    if(strcmp(a4->contenu,saisie4)!=0)
        printf("erreur B4");*/
    /*printCell(a1);
    printCell(a2);
    printCell(a3);*/
}