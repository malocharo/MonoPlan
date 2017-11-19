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

 void * list_get_data(const node_t * node)
{
    if(node == NULL ) return NULL;
    return node->data;
}

 void list_set_data(node_t* node, void * data)
{
    if(node == NULL || data == NULL)return;
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
    if(head->next == NULL && head->data == NULL)
    {
        head->data = data;
        return head;
    }
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
    node_t *tmp = head;
    node_t *prec = NULL;
    if(head == NULL) return NULL;
    if(head->data == data && head->next == NULL)
    {
        free(head);
        return NULL;
    }

    while(head->next != NULL)
    {
        if(tmp->data == data)
        {
            if(prec == NULL) //tete
            {
                 head = tmp->next;
                 free(tmp);
                return head;

            }
            if(tmp->next == NULL) //queue
            {
                prec->next = NULL;
                free(tmp);
                return head;
            }
            prec->next = tmp->next; //elem au milieu
            free(tmp);
            return head;
        }
        prec = tmp;
        tmp = tmp->next;
    }
    return head;
}

node_t * list_headRemove(node_t * head)
{
    if(head == NULL) return NULL;
    if(head->next == NULL)
    {
        free(head);
        return NULL;
    }
    node_t *tmp = head;
    head=head->next;
    free(tmp);
    return head;
}

void list_destroy(node_t *head)
{
    if(head == NULL)
        return;
    list_destroy(list_headRemove(head));
}



