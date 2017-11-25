//
// Created by polesmal on 23/11/17.
//

#ifndef MONOPLAN_CELL_H
#define MONOPLAN_CELL_H

#include "feuille.h"
#include "../Liste/liste.h"
#include "../Pile/pile.h"
#include <string.h>


typedef struct cell
{
    char *contenu;
    double val;
    node_t * token;
    node_t * ref;

}s_cell;

typedef struct token
{
    enum{VALUE,REF,OPERATOR} type;
    union{
        double cst;
        s_cell *ref;
        void(*operator)(pile_t *eval);
    };
}s_token;

typedef struct operator
{
    char *op_name;
    void(*operator)(pile_t * eval);
}operator_t;

extern operator_t op[5]; // +,-,*,/,%
void init();
void evaluate(feuille_t*,s_cell *);
void * getCellRef(node_t*,char*);

#endif //MONOPLAN_CELL_H
