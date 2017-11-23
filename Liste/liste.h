//
// Created by malo on 18/11/17.
//

#ifndef MONOPLAN_LISTE_H
#define MONOPLAN_LISTE_H
#include <stdlib.h>

typedef struct node
{
    void *data;
    struct node * next;
}node_t;

node_t * list_create();
 void * list_get_data(const node_t*);
 void list_set_data(node_t*, void*);
node_t * list_insert(node_t *head,void * data);
node_t * list_append(node_t *head,void * data);
node_t * list_remove(node_t *head,void * data);
node_t * list_headRemove(node_t*head);
void * list_destroy(node_t *head);


#endif //MONOPLAN_LISTE_H
