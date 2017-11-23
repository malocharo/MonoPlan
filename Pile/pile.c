//
// Created by malo on 18/11/17.
//

#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

pile_t * pile_creer(int nb_places)
{
    if(nb_places<=0) return NULL;
    pile_t *pile = malloc(sizeof(pile_t));
    if(pile == NULL) return NULL;
    pile->elem_pile = malloc(sizeof(double)*nb_places);
    if(pile->elem_pile == NULL)
    {
        free(pile);
        return NULL;
    }
    pile->nbelem_pile = 0;
    pile->size_pile = nb_places;
    return pile;
}

void pile_detruire(pile_t * p)
{
    free(p->elem_pile);
    free(p);
}

void pile_initialiser(pile_t *p)
{
    p->nbelem_pile = 0;
}

int pile_places_occupees(const pile_t *p)
{
    return p->nbelem_pile;
}

int pile_places_libres(const pile_t *p)
{
    return p->size_pile - p->nbelem_pile;
}

 int pile_depiler(pile_t *p, double *elem)
{
    if(p->nbelem_pile == 0) return -1;
    p->nbelem_pile--;
    *elem = p->elem_pile[p->nbelem_pile];

    return 0;
}

 int pile_empiler(pile_t *p, double el)
{
    if(p->nbelem_pile == p->size_pile) return -1;
    p->elem_pile[p->nbelem_pile++] = el;
    return 0;
}

void pile_initialiser_iterateur(pile_t* p)
{
    p->iterateur = p->nbelem_pile-1;
}

int pile_obtenir_element_suivant(pile_t *p, double *el)
{
    if(p->nbelem_pile == 0 || p->iterateur == -1)
    {
        p->iterateur = 0;
        return -1;
    }
    *el = p->elem_pile[p->iterateur--];

    return 0;
}





