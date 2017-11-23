//
// Created by polesmal on 23/11/17.
//
#include "liste.h"
#include <stdlib.h>
#include <stdio.h>
int main()
{
    /**
    * Test de la fonction list_create()
    */
    node_t *node = list_create();
    if(node != NULL)
        printf("Erreur lors de la creation du noeud %p",node);



    /**
    * Test de la fonction list_get_data()
    */
    void *data;
    int testvoid = 5;
    data = &testvoid;


    node = malloc(sizeof(node_t));
    list_set_data(node, data);
    void *data2;
    data2 = list_get_data(node);

    if (*(int*)data2 != 5)
        printf("erreur testvoid : %d devrait etre 5\n", *((int *)data2));

    /**
     * Test de la fonction list_insert()
     */
    int testvoid2 = 6;
    data2 = &testvoid2;
    node_t *node2 = list_insert(node, data2);

    if (node2 == node)
        printf("c'est une erreur \n");
    data2 = NULL;

    data2 = list_get_data(node2);
    if (*(int*)data2 != 6)
        printf("erreur testvoid : %d devrait etre 6\n", *((int *)data2));

    /**
     * Test de la fonction list_append()
     */
    int n = 4;
    void * testdat3 = &n;
    node_t *node3  = list_append(node2,testdat3);
    node_t *tmp = node3;
    while(tmp->next!=NULL)
        tmp = tmp->next;
    testdat3 = list_get_data(tmp);
    if(*(int*)testdat3 != 4)
        printf("Erreur  list_append : %d devrait etre 4\n",*((int*)testdat3));

    /**
     * Test de la fonction list_remove()
     */
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


    /**
     * Test de la fonction list_headRemove()
     */
    n = 5;

    node_t * node6 = list_create();
    node_t * test_Headremove = list_headRemove(node6);
    if(test_Headremove != NULL)
        printf("Erreur list_headRemove()\n");

    node6 = list_create();
    node6 = list_append(node6,&n);
    node_t* node7 = list_append(node6,&n);

    test_Headremove = list_headRemove(node7);
    if(*(int*)list_get_data(test_Headremove) != 5)
        printf("Erreur list remove sur tete %d devrait etre 5",*(int*)list_get_data(test_Headremove));

    list_destroy(node);

    printf("Fin de test sur Liste\n");
    return 0;
}