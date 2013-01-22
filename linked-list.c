/**
 * An example implementation of a singly-linked list
 * https://github.com/justinethier/linked-list
 *
 * Written by Justin Ethier, 2012
 */
#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

/**
 * Create a new list
 */
struct node *list()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->val = NULL;
    head->next = NULL;
    return head;
}

void list_destroy(struct node *head, void (free_val(void *)))
{
    struct node *tmp;
    while (head != NULL){
        tmp = head;
        head = head->next;

        if (free_val != NULL && tmp->val != NULL){
            free_val(tmp->val);
        }

        free(tmp);
    }
}

/**
 * Add a new node to the end of the linked list. Memory is 
 * allocated from the heap for the new node.
 *
 * Constructs a new linked list if a null pointer is passed.
 * Returns a pointer to the beginning of the modified list
 */
int list_add(struct node *head, void *val)
{
    struct node *ptr = head;

    if (ptr == NULL) return 0;

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = (struct node *)malloc(sizeof(struct node));
    ptr = ptr->next;

    ptr->next = NULL;
    ptr->val = val;

    return 1;
}

/**
 * Construct a list containing the given value at the
 * start of the given list
 */
struct node *list_cons(void *val, struct node *lst)
{
    struct node *head = list();

    // The head node never contains a value, so create another
    // node to hold the first value of the list
    head->next = (struct node *)malloc(sizeof(struct node));
    head->next->val = val;

    if (list_is_empty(lst)){
        head->next->next = NULL;
    } else {
        head->next->next = lst->next;

        // Deallocate the old lst head
        free(lst);
    }

    return head;
}

struct node *list_add_at_head(void *val, struct node *list)
{
    return list_cons(val, list);
}

void list_append(struct node *first, struct node *second)
{
    // TODO
}

/**
 * Removes nodes from the list with the given value,
 * and frees any memory allocated for them.
 */
void list_remove(struct node* ptr, void *val, int (*cmp_val)(void *, void *), void (free_val(void *)))
{
    struct node *tmp;

    if (ptr == NULL || val == NULL) return;

    while(ptr->next != NULL){
        if (cmp_val(ptr->next->val, val)){
            tmp = ptr->next->next;

            if (free_val != NULL && ptr->next->val != NULL){
                free_val(ptr->next->val);
            }

            free(ptr->next);
            ptr->next = tmp;
        } else {
            ptr = ptr->next;
        }
    }

    return;
}


void list_reverse(struct node* head)
{
    struct node *ptr, *prev = NULL, *tmp;

    if (head == NULL) return;
    ptr = head->next;

    // Change
    //
    //  prev => ptr => next
    // to
    //  prev <= ptr <= next
    //
    while (ptr){
       tmp = ptr->next;
       ptr->next = prev;
       prev = ptr;
       ptr = tmp;
    }

    head->next = prev;
    return;
}

int list_is_empty(struct node *head)
{
    return (head == NULL || head->next == NULL);
}

void *list_car(struct node *head)
{
    if (head == NULL || head->next == NULL) return NULL;
    return head->next->val;
}

void *list_value(struct node *head)
{
    return list_car(head);
}

void list_set_value(struct node *head, void *val)
{
    if (head == NULL || head->next == NULL) return;
    head->next->val = val;
    return;
}

void list_set_car(struct node *head, void *val)
{
    list_set_value(head, val);
}

struct node *list_cdr(struct node *head)
{
    if (head == NULL) return NULL;

    // No need to allocate a new head, we just
    // ignore the next node's value and can 
    // treat it as head
    return head->next;
}

struct node *list_rest(struct node *head)
{
    return list_cdr(head);
}

int list_set_rest(struct node *head, struct node *tail)
{
    if (head == NULL || tail == NULL) return 0;
    head->next->next = tail->next;
    return 1;
}

int list_set_cdr(struct node *head, struct node *tail)
{
    return list_set_rest(head, tail);
}

//// void listCreate-from-array (name TBD)
//struct node *list_from_array(void **data, int length)
//{
//    struct node *l = list();
//    int i;
//    void *next = data[0];
//
//    for (i = 0; i < length; i++){
//        list_add(l, next);
//        next++;
//    }
//
//    return l;
//}

void list_for_each(struct node *head, void (*func)(void *))
{
    struct node *ptr;
    
    if (head == NULL) return;

    ptr = head->next;
    while (ptr){
        func(ptr->val);
        ptr = ptr->next;
    }
}

int list_length(struct node *head)
{
    int count = -1;
    
    while (head){
        head = head->next;
        count++;
    }

    return count;
}
