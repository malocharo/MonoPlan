//
// Created by malo on 18/11/17.
//

#ifndef MONOPLAN_PILE_H
#define MONOPLAN_PILE_H

typedef struct pile
{
    double  *elem_pile;
    int nbelem_pile;
    int size_pile;
    int iterateur;
}pile_t;

pile_t* pile_creer(int);
void pile_detruire(pile_t*);
void pile_initialiser(pile_t*);
int pile_places_occupees(const pile_t*);
int pile_places_libres(const pile_t*);
 int pile_depiler(pile_t*,double*);
 int pile_empiler(pile_t*,double);
void pile_initialiser_iterateur(pile_t*);
int pile_obtenir_element_suivant(pile_t*, double*);
#endif //MONOPLAN_PILE_H
