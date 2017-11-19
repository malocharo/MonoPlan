//
// Created by malo on 18/11/17.
//
#include <stdio.h>
#include "test_unit.h"


int aff(node_t *node)
{
    node_t * tmp;
    for(tmp=node;tmp->next!=NULL;tmp=tmp->next)
        printf("%p -> %p | data->%d \n",tmp,tmp->next,*(int*)list_get_data(tmp));
    printf("%p -> %p    | data->%d\n\n", tmp,tmp->next,*(int*)list_get_data(tmp));
}

int test_liste()
{
    node_t *node = list_create();
    if(node == NULL)
        printf("Erreur lors de la creation du noeud %p",node);
    void *data;
    int testvoid = 5;
    data = &testvoid;

    list_set_data(node, data);
    void *data2;
    data2 = list_get_data(node);

    if (*(int*)data2 != 5)
        printf("erreur testvoid : %d devrait etre 5\n", *((int *)data2));

    int testvoid2 = 6;
    data2 = &testvoid2;
    node_t *node2 = list_insert(node, data2);

    if (node2 == node)
        printf("c'est une erreur \n");
    data2 = NULL;

    data2 = list_get_data(node2);
    if (*(int*)data2 != 6)
        printf("erreur testvoid : %d devrait etre 6\n", *((int *)data2));

    int n = 4;
    void * testdat3 = &n;
    node_t *node3  = list_append(node2,testdat3);
    node_t *tmp = node3;
    while(tmp->next!=NULL)
        tmp = tmp->next;
    testdat3 = list_get_data(tmp);
    if(*(int*)testdat3 != 4)
        printf("Erreur  list_append : %d devrait etre 4\n",*((int*)testdat3));

    int m = 7;
    void* testvoid4 = &m;
    node_t * node4 = list_create();
     node_t *node5 = list_append(node4,testvoid4);
    testvoid4 = NULL;
    testvoid4 = list_get_data(node5);
    if(*(int*)testvoid4 != 7)
        printf("Erreur list append : %d devrait etre 7\n",*(int*)testvoid4);
    node_t * test_removehead = list_remove(node3,&testvoid2);
    if(*(int*)list_get_data(test_removehead) != 5)
        printf("Erreur list remove sur tete %d devrait etre 5",*(int*)list_get_data(test_removehead));
    test_removehead = list_remove(test_removehead,&n);
    if(*(int*)list_get_data(test_removehead) != 5 && test_removehead->next != NULL)
        printf("Erreur list remove sur queue %d %p devrait etre 4 nil",*(int*)list_get_data(test_removehead),test_removehead->next);


     n = 5;

    node_t * node6 = list_create();
    node_t * test_Headremove = list_headRemove(node6);


    node6 = list_create();
    node6 = list_append(node6,&n);
    node_t* node7 = list_append(node6,&n);

    test_Headremove = list_headRemove(node7);


    if(*(int*)list_get_data(test_Headremove) != 5)
         printf("Erreur list remove sur tete %d devrait etre 5",*(int*)list_get_data(test_Headremove));



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