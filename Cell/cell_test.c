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
    feuille_t * f = &f1;
    s_cell * a1 = &a_1;
    s_cell * a2 = &a_2;

    char * saisie1 = "= 2 A2 +";
    char * saisie2 = "= 3";
    a1->nom = "A1";
    a2->nom = "A2";
    a1->contenu = saisie1;
    a2->contenu = saisie2;

    f->cell = list_create();
    f->cell= list_insert(f->cell,a1);
    f->cell = list_insert(f->cell,a2);

    analyze(f,a2);
    analyze(f,a1);
    evaluate(a1);
    printCell(a1);
}