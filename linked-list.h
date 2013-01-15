/**
 * An example implementation of a singly-linked list
 * https://github.com/justinethier/linked-list
 *
 * Written by Justin Ethier, 2012
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef __LINKED_LIST_HEADER__
#define __LINKED_LIST_HEADER__

/**
 * The basic structure that is used to build a list.
 * Each lists consists of a string of these nodes.
 * 
 * There is also an empty head node that points to the
 * first node. This is done as a convenience so the
 * caller can always use that same pointer without
 * having to reassign it after various operations.
 */
struct node {
    struct node *next;
    void *val;
};

// TODO: comment each of the functions below

/**
 * Add a new node to the end of the linked list. Memory is 
 * allocated from the heap for the new node.
 *
 * Constructs a new linked list if a null pointer is passed.
 * Returns a pointer to the beginning of the modified list
 */
int list_add(struct node *ptr, void *val);

/**
 * Create a new list
 */
struct node *list();

// TODO: need to pass a func to cleanup each val
void list_destroy(struct node*);


/**
 * Removes nodes from the list with the given value,
 * and frees any memory allocated for them.
 */
// TODO: need a way to free memory, maybe pass a function
void list_remove(struct node* head, void *val);

int list_is_empty(struct node *head);
int list_car(struct node *head);
int list_value(struct node *head);

struct node *list_cdr(struct node *head);
struct node *list_rest(struct node *head);
struct node *list_from_array(void **data, int length);
void list_print(struct node *head);
int list_length(struct node *head);
void list_reverse(struct node* head);

// TODO: remaining functions from R5RS that make sense (eg: pair? list? probably do not make any sense)
// cons (?)
// set-car (?)
// set-cdr (?)
// append
// list-ref
// member
// assoc (????)
// 
// Selected functions from SRFI-1
// http://srfi.schemers.org/srfi-1/srfi-1.html#TheProcedures
// iota
// take
// drop
// split-at
// last

#endif
