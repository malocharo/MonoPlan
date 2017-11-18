//
// Created by malo on 18/11/17.
//
#include <stdio.h>
#include "test_unit.h"


int aff(node_t *node)
{
    node_t * tmp;
    for(tmp=node;tmp->next!=NULL;tmp=tmp->next)
        printf("%p -> %p | data->%d \n",tmp,tmp->next,(void*)list_get_data(tmp));
    printf("%p -> %p    | data->%d\n\n", tmp,tmp->next,(void*)list_get_data(tmp));
}

int test_liste()
{
   /* node_t * head = list_create();
    list_set_data(head,(void*)2);


    head = list_insert(head,(void*)3);


    head = list_append(head,(void*)1);
    printf("doit afficher 3 2 1 : affiche\n");
    aff(head);

    head = list_remove(head,(void*)3);
    printf("doit afficher  2 1 : affiche\n");
    aff(head);
    head = list_insert(head,(void*)3);
    head = list_remove(head,(void*)1);
    printf("doit afficher 3 2  : affiche\n");
    aff(head);
    head = list_append(head,(void*)1);

    head = list_remove(head,(void*)2);
    printf("doit afficher 3  1 : affiche\n");
    aff(head);



    head = list_headRemove(head);
    printf("doit afficher  1 : affiche\n");
    aff(head);
    head = list_append(head,(void*)5);
    printf("doit afficher  1 5: affiche\n");
    aff(head);*/

    node_t *node = list_create();
    void *data;
    int testvoid = 5;
    data = &testvoid;

    list_set_data(node, data);
    void *data2;
    data2 = list_get_data(node);

    if (*(int*)data2 != 5) printf("erreur testvoid : %d devrait etre 5\n", *((int *)data2));

    int testvoid2 = 6;
    data2 = &testvoid2;
    node_t *node2 = list_insert(node, data2);
    if (node2 == node) printf("c'est une erreur \n");
    data2 = NULL;

    data2 = list_get_data(node2);
    if (*(int*)data2 != 6) printf("erreur testvoid : %d devrait etre 6\n", *((int *)data2));

    list_destroy(node);


    return 0;
}

int test_pile()
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

}