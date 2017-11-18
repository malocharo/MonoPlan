//
// Created by malo on 18/11/17.
//

#include "liste.h"

node_t * list_create()
{
    node_t * node = malloc(sizeof(node_t));
    if(node == NULL) return NULL;
    node->data = NULL;
    node->next = NULL;
    return node;
}

inline void * list_get_data(const node_t * node)
{
    if(node == NULL) return NULL;
    return node->data;
}

inline void list_set_data(node_t* node, void * data)
{
    if(node == NULL)return;
    node->data = data;
}

node_t * list_insert(node_t * head,void * data)
{
    if(head == NULL || data == NULL) return NULL;
    node_t * new = malloc(sizeof(node_t));
    if(new == NULL) return NULL;
    new->data = data;
    new->next = head;
    return new;
}
node_t * list_append(node_t *head,void *data)
{
    node_t *tmp = NULL;
    node_t *new = list_create();
    new->data = data;
    if(head->next == NULL)
    {
        head->next = new;
        return head;
    }
    for(tmp = head;tmp->next!=NULL;tmp = tmp->next);
    tmp->next = new;
    return head;
}

node_t * list_remove(node_t * head, void*data)
{
    node_t *tmp;
    node_t *prec = NULL;
    for(tmp = head;tmp->next!=NULL;tmp=tmp->next)
    {
        if(tmp->data == data)
        {
            if(prec == NULL)
                return head = head->next;
            else
            {
                prec->next = tmp->next;
                return head;
            }

        }
        prec = tmp;
    }
    if(tmp->data == data)
        prec->next = NULL;
    return head;


}

node_t * list_headRemove(node_t * head)
{
    if(head == NULL) return NULL;
    node_t *tmp = head;
    head=head->next;
    free(tmp);
    return head;
}

void list_destroy(node_t *head)
{
    if(head == NULL)
    {
        free(head);
        return;
    }
    list_destroy(list_headRemove(head));
}



