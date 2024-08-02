#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node {
    int val;
    struct node* next;
    struct node* prev;
} node;

typedef struct linked_list {
    node* head;
} linked_list;

void list_insert(linked_list *ll, node* n)
{
    n->next = ll->head;
    if(ll->head != NULL)
        ll->head->prev = n;
    ll->head = n;
    n->prev = NULL;
}

void list_delete(linked_list *ll, node* n)
{
    if(n->prev != NULL)
        n->prev->next = n->next;
    else
        ll->head = n->next;
    if(n->next != NULL)
        n->next->prev = n->prev;
}

node* list_search(const linked_list *ll, int k)
{
    node* cur = ll->head;
    while(cur != NULL && cur->val != k) {
        cur = cur->next;
    }
    return cur;
}

#endif