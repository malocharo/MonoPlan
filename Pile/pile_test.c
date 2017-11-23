//
// Created by polesmal on 23/11/17.
//
#include "pile.h"
#include <stdlib.h>
#include <stdio.h>
int main()
{
    pile_t *p;

    p = pile_creer(50);

    if (pile_places_occupees(p) != 0 ) printf("erreur places occupees : %d devrait etre 0\n", pile_places_occupees(p));
    if (pile_places_libres(p) != 50 ) printf("erreur places libres : %d devrait etre 50\n", pile_places_occupees(p));

    pile_empiler(p, 4.0);
    double a;
    pile_depiler(p, &a);

    if (a != 4.0) printf("erreur a : %d devrait etre 4.0\n", pile_places_occupees(p));

    if (pile_depiler(p, &a) != -1) printf("devrait etre une erreur\n");

    pile_empiler(p, 5.0);
    pile_depiler(p, &a);

    if (a != 5.0) printf("erreur a : %d devrait etre 5.0\n", pile_places_occupees(p));



    for (double i = 0.0; i < 50.0; i=1.0+i) {
        pile_empiler(p, i);
    }



    if (pile_places_occupees(p) != 50 ) printf("erreur places occupees : %d devrait etre 50\n", pile_places_occupees(p));
    if (pile_places_libres(p) != 0 ) printf("erreur places libres : %d devrait etre 0\n", pile_places_occupees(p));

    if (pile_empiler(p, 50.0) != -1) printf("devrait etre une erreur\n");

    pile_initialiser(p);

    if (pile_places_occupees(p) != 0 ) printf("erreur places occupees : %d devrait etre 0\n", pile_places_occupees(p));
    if (pile_places_libres(p) != 50 ) printf("erreur places libres : %d devrait etre 50\n", pile_places_occupees(p));

    pile_detruire(p);
    printf("Fin de test sur pile\n");
}