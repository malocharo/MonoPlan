//
// Created by polesmal on 23/11/17.
//

#include <stdio.h>
#include "cell.h"

operator_t op[5];

void init()
{
    op[0].op_name ="+";
    op[0].operator = &add;

    op[1].op_name ="-";
    op[1].operator = &minus;

    op[2].op_name ="*";
    op[2].operator = &multip;

    op[3].op_name ="/";
    op[3].operator = &divi;

    op[4].op_name ="%";
    op[4].operator = &mod;
}

void evaluate(feuille_t* feuille,s_cell * cell)
{
    char *str;
    char *ex;
    double val;
    s_cell * ref = NULL;
    node_t * list = list_create();
    pile_t * pile_elem = pile_creer((int)strlen(cell->contenu));

    str = strdup(cell->contenu);
    ex = strtok(str," ");
    while(ex != NULL)
    {
        if(strtod(ex,NULL)!=0.0) // si on trouve un double
        {
            s_token *tmp = malloc(sizeof(s_token));
            tmp->type = s_token.VALUE;
            tmp->cst = strtod(ex,NULL);
            list = list_insert(list,tmp);
            pile_empiler(pile_elem,strtod(ex,NULL));
        }
        else{
            s_cell* dep = getCellRef(feuille->cell,ex);
            if(dep) // on a trouve une reference vers une cellule
            {
                cell->ref = list_insert(cell->ref,dep);
                pile_empiler(pile_elem,dep->val);
            }
            else{ // c 'est une operation
                for(int i = 0;i<5;i++)
                    if(op[i].op_name == ex)
                    {
                        s_token *tmp = malloc(sizeof(s_token));
                        tmp->type = s_token.OPERATOR;
                        tmp->operator = op[i].operator;
                        list = list_insert(list,tmp);
                        op[i].operator(list); // operation
                    }
            }


        }
        ex = strtok(NULL," "); // c est le 'man strtok' qui dit de mettre a NULL

    }
    pile_depiler(pile_elem,&cell->val); // si value il y a sinon vaudra 0.0
    cell->token = list; //on donne l'adresse de la liste des tokens de cette cellule spécifique
}

void * getCellRef(node_t * n, char* ref)
{
    while(n)
    {
        if(((s_cell*)n->data)->contenu == ref)
            return n->data;
        n = n->next;
    }
    return NULL;
}
