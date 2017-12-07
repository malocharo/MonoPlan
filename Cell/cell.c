//
// Created by polesmal on 23/11/17.
//

#include <stdio.h>
#include "cell.h"



operator_t op[NB_OPERATOR];

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
    pile_empiler(eval,d1+d);
}

void minus(pile_t* eval)
{
    double d;
    double d1;

    pile_depiler(eval,&d);
    pile_depiler(eval,&d1);
    pile_empiler(eval,d1-d);


}

void multip(pile_t* eval)
{
    double d;
    double d1;

    pile_depiler(eval,&d);
    pile_depiler(eval,&d1);
    pile_empiler(eval,d1*d);
}

void divi(pile_t* eval) {
    double d;
    double d1;

    pile_depiler(eval, &d);
    pile_depiler(eval, &d1);
    pile_empiler(eval, d1 / d);
}

void evaluate(s_cell *cell)
{
   if(cell->token == NULL)
       return;
    if(cell->nb_val-cell->nb_op !=1) //cohérence de la formule
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

    }
    pile_depiler(pile_elem,&(cell->val)); // ancienne valeur

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
    node_t *head = feuille->cell;
    pile_t * pile_elem = pile_creer((int)strlen(cell->contenu));
    cell->token = list_create();
    cell->ref = list_create();
    str = strdup(cell->contenu);
    ex = strtok(str," ");

    if(strcmp(ex,"=") != 0) // C est une string ou une valeur seul
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
            if(sscanf(ex,"%c%d",&c,&d) == 2) {      // trouve ref pattern évite de faire une recherche de ref pour rien
                s_cell *dep = getCellRef(head, ex);
                if (dep) // on a trouve une reference vers une cellule
                {
                    s_token *tmp = malloc(sizeof(s_token));
                    if (tmp == NULL) return;
                    tmp->type = REF;
                    tmp->value.ref = dep;
                    cell->token = list_append(cell->token, tmp);
                    cell->ref = list_append(cell->ref, dep); // dep->ref
                   // feuille->cell = list_append(feuille->cell,tmp); // idk
                    cell->nb_tk++;
                    cell->nb_val++;
                }
            }
            else{ // c 'est une operation
                for(int i = 0;i<NB_OPERATOR;i++)
                    if(strcmp(op[i].op_name,ex)==0)
                    {
                        s_token *tmp = malloc(sizeof(s_token));
                        if(tmp == NULL) return;
                        tmp->type = OPERATOR;
                        tmp->value.operator = op[i].operator;
                        cell->token= list_append(cell->token,tmp);
                        cell->nb_tk++;
                        cell->nb_op++;

                    }
            }


        }
        ex = strtok(NULL," ");

    }


}



node_t * degreeCalc(s_cell * init,node_t* list)
{
    if(init->ref== NULL)
        return list;
    if(init->ref->next == NULL)
        return list = list_insert(list,init->ref->data);
    list = list_insert(list,init->ref->data);
    degreeCalc((s_cell*)init->ref->next,list);

}

void topologicalSort(feuille_t * feuille,s_cell* cell)
{
    node_t * order_ref = list_create();
    /*s_cell * tmp_cell = cell;
    if(order_ref == NULL)
        return;
    while(cell->ref != NULL)
    {

    }*/
  order_ref = degreeCalc(cell,order_ref);



}


void * getCellRef(node_t * n, const char* ref)
{
    node_t * tmp = n;
    while(tmp)
    {
        printf("%s\n",((s_cell*)n->data)->nom);
        if(strcmp(((s_cell*)n->data)->nom ,ref) == 0)
            return tmp->data;
        tmp = tmp->next;
    }
    return NULL;
}
