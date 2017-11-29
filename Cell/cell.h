//
// Created by polesmal on 23/11/17.
//

#ifndef MONOPLAN_CELL_H
#define MONOPLAN_CELL_H


#include "../Liste/liste.h"
#include "../Pile/pile.h"
#include <string.h>

#define NB_OPERATOR 4
#define NB_COLUMNS  26
#define NB_LINES 50

typedef struct cell
{
    char * nom;
    char *contenu;
    double val;
    node_t * token;
    node_t * ref;

    int nb_tk;
    int nb_op;
    int nb_val;

}s_cell;

typedef struct token
{
    enum{VALUE,REF,OPERATOR} type;
    union{
        double cst;
        s_cell *ref;
        void(*operator)(pile_t *eval);
    }value;
}s_token;

typedef struct operator
{
    char *op_name;
    void(*operator)(pile_t * eval);
}operator_t;

typedef struct feuille
{
    char * nomFichier;
    double ligne,colonne;
    node_t * cell;
}feuille_t;

extern operator_t op[5]; // +,-,*,/,%
void init_op();
void analyze(feuille_t*,s_cell *);
void evaluate(s_cell *);
void * getCellRef(node_t*,const char*);
void add(pile_t*);
void minus(pile_t*);
void multip(pile_t*);
void divi(pile_t*);


#endif //MONOPLAN_CELL_H
