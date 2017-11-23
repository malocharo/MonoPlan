//
// Created by polesmal on 23/11/17.
//

#ifndef MONOPLAN_FEUILLE_H
#define MONOPLAN_FEUILLE_H

typedef struct feuille
{
    char * nomFichier;
    double ligne,colonne;
    list_t * cell;
}feuille_t;

#endif //MONOPLAN_FEUILLE_H
