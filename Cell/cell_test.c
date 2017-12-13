//
// Created by polesmal on 23/11/17.
//
#include "cell.h"
#include <stdio.h>

/*void printCell(s_cell *c)
{
    if(c->val == 0.0)
        printf("Value of %s is %s\n",c->nom,c->contenu);
    else
        printf("Value of %s is %lf\n",c->nom,c->val);
}*/

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

void create_cell(s_cell *c,char *nom,char * saisie)
{
    c->nom = malloc(sizeof(char)* strlen(nom)+1);
    strcpy(c->nom,nom);
    c->ref = list_create();
    c->succ = list_create();
    c->contenu = malloc(sizeof(char)* strlen(saisie)+1);
    strcpy(c->contenu,saisie);

}

int main()
{
    init_op();
    feuille_t f1;
    feuille_t * f = &f1;
    s_cell *a1 = malloc(sizeof(s_cell));
    s_cell *a2 = malloc(sizeof(s_cell));
    s_cell *a4 = malloc(sizeof(s_cell));
    create_cell(a1,"A1","= A2 2 +");
    create_cell(a2,"A2", "= 7 B4 +");
    create_cell(a4,"B4", "= 1 2 +");

    f->cell = list_create();
    f->cell = list_insert(f->cell,a1);
    f->cell = list_insert(f->cell,a2); // parce qu'on evalue pas bien pour l instant, la case sans predecesseur doit etre en tete
    f->cell = list_insert(f->cell,a4);

    analyze(f,a4);
    Sort(a4);
    analyze(f,a2);
    Sort(a2);
    analyze(f,a1);
    Sort(a1);

    if(a1->val != 12)
        printf("erreur A1\n");
    if(a2->val != 10)
        printf("erreur A2\n");
    if(a4->val != 3)
        printf("erreur A4\n");

    a1->contenu = "= A2 6 +";
    analyze(f,a1);
    Sort(a1);
    if(a1->val != 16)
        printf("erreur A1");


    printf("Fin de test Cell");
}