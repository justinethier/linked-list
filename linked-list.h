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

/**
 * Create a new list
 */
struct node *list();

/**
 * Add a new node to the end of the linked list. Memory is 
 * allocated from the heap for the new node.
 *
 * Constructs a new linked list if a null pointer is passed.
 * Returns a pointer to the beginning of the modified list
 */
int list_add(struct node *ptr, void *val);

/**
 * Free all memory allocated to the list
 */
void list_destroy(struct node *head, void (free_val(void *)));

/**
 * Removes nodes from the list with the given value,
 * and frees any memory allocated for them.
 */
void list_remove(struct node* ptr, void *val, int (*cmp_val)(void *, void *), void (free_val(void *)));

/** 
 * A predicate to determine if the list is empty
 */
int list_is_empty(struct node *head);

/**
 * Return the value at the front of the list
 */
void *list_value(struct node *head);
void *list_car(struct node *head);

/**
 * Return the tail of the list
 */
struct node *list_rest(struct node *head);
struct node *list_cdr(struct node *head);

/**
 * Apply function "func" to each element of the list
 */
void list_for_each(struct node *head, void (*func)(void *));
int list_length(struct node *head);
void list_reverse(struct node* head);

//struct node *list_from_array(void **data, int length);
// TODO: find? anything else?
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
