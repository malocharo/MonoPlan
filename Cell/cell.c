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

void evaluate(s_cell * cell)
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
        else if(sscanf(ex,"%p",ref))
        {
            s_token *tmp = malloc(sizeof(s_token));
            tmp->type = s_token.VALUE;
            tmp->ref = ref;
            list = list_insert(list,tmp);
            //pile_empiler(pile_elem,)
        }
        ex = strtok(str," ");

    }
}

