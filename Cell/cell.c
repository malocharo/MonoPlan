//
// Created by polesmal on 23/11/17.
//

#include <stdio.h>
#include "cell.h"



operator_t op[5];

void init_op()
{
    op[0].op_name ="+";
    op[0].operator = &add;

    op[1].op_name ="-";
    op[1].operator = &minus;

    op[2].op_name ="*";
    op[2].operator = &multip;

    op[3].op_name ="/";
    op[3].operator = &divi;


}


void add(pile_t * eval)
{
    double d;
    double d1;

    pile_depiler(eval,&d);
    pile_depiler(eval,&d1);
    pile_empiler(eval,d+d1);
}

void minus(pile_t* eval)
{
    double d;
    double d1;

    pile_depiler(eval,&d);
    pile_depiler(eval,&d1);
    pile_empiler(eval,d-d1);


}

void multip(pile_t* eval)
{
    double d;
    double d1;

    pile_depiler(eval,&d);
    pile_depiler(eval,&d1);
    pile_empiler(eval,d*d1);
}

void divi(pile_t* eval)
{
    double d;
    double d1;

    pile_depiler(eval,&d);
    pile_depiler(eval,&d1);
    pile_empiler(eval,d/d1);
}
/*void viewPile(pile_t *p)
{
    pile_t *tmp = p;
    double val;
    int i = 0;
    pile_initialiser_iterateur(tmp);
    while(pile_obtenir_element_suivant(tmp,&val) == 0)
    {
        printf("%d val %lf\n",i,val);
        i++;
    }

}*/
void evaluate(s_cell *cell)
{
   if(cell->token == NULL)
       return;
    if(cell->nb_val-cell->nb_op !=1)
    {
        cell->val = 0.0;
        return;
    }
    double d;
    node_t * tmp = cell->token;
    pile_t * pile_elem = pile_creer(cell->nb_tk);
    s_token * tok;
    while(tmp !=NULL)
    {
        tok = list_get_data(tmp);
        if(tok->type == VALUE)
            pile_empiler(pile_elem,tok->value.cst);
        if(tok->type == REF)
        {
            s_cell * c = tok->value.ref;
            pile_empiler(pile_elem,c->val);
        }
        if(tok->type == OPERATOR)
            tok->value.operator(pile_elem);

        tmp = tmp->next;
        //viewPile(pile_elem);
    }
    pile_depiler(pile_elem,&(cell->val));

}


void analyze(feuille_t* feuille,s_cell * cell)
{
    char *str;
    char *ex;
    double val;
    int d;
    char c;
    cell->nb_tk =0;
    cell->nb_op = 0;
    cell->nb_val= 0;
    s_cell * ref = NULL;

    pile_t * pile_elem = pile_creer((int)strlen(cell->contenu));
    cell->token = list_create();
    cell->ref = list_create();
    str = strdup(cell->contenu);
    ex = strtok(str," ");

    if(strcmp(ex,"=") != 0)
    {
       if(sscanf(ex,"%lf",&val) == 1) {
           cell->val = val;
           return;
       }
        cell->val = 0.0;
        return;


    }
    while(ex != NULL)
    {
        if(strtod(ex,NULL)!=0.0) // si on trouve un double
        {
            s_token *tmp = malloc(sizeof(s_token));
            if(tmp == NULL) return;
            tmp->type = VALUE;
            tmp->value.cst = strtod(ex,NULL);
            cell->token = list_append(cell->token,tmp);
            cell->nb_val++;
            cell->nb_tk++;

        }
        else{
            if(sscanf(ex,"%c%d",&c,&d) == 2) {
                s_cell *dep = getCellRef(feuille->cell, ex);
                if (dep) // on a trouve une reference vers une cellule
                {
                    s_token *tmp = malloc(sizeof(s_token));
                    if (tmp == NULL) return;
                    tmp->type = REF;
                    tmp->value.ref = dep;
                    cell->token = list_append(cell->token, tmp);
                    cell->ref = list_append(cell->ref, dep->ref);
                    cell->nb_tk++;
                    cell->nb_val++;
                }
            }
            else{ // c 'est une operation
                for(int i = 0;i<NB_OPERATOR;i++)
                    if(strcmp(op[i].op_name,ex)==0)
                    {
                        s_token *tmp = malloc(sizeof(s_token));
                        tmp->type = OPERATOR;
                        tmp->value.operator = op[i].operator;
                        cell->token= list_append(cell->token,tmp);
                        cell->nb_tk++;
                        cell->nb_op++;

                    }
            }


        }
        ex = strtok(NULL," "); // c est le 'man strtok' qui dit de mettre a NULL

    }

}

void * getCellRef(node_t * n, const char* ref)
{
    node_t * tmp = n;
    while(tmp)
    {
        if(strcmp(((s_cell*)n->data)->nom ,ref) == 0)
            return tmp->data;
        tmp = tmp->next;
    }
    return NULL;
}
