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
 * Construct a list containing the given value at the
 * start of the given list
 */
struct node *list_cons(void *val, struct node *list);

/**
 * A wrapper of list_cons
 */
struct node *list_add_at_head(void *val, struct node *list);

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
 * Change the value at the front of the list
 */
void list_set_value(struct node *head, void *val);
void list_set_car(struct node *head, void *val);

/**
 * Return the tail of the list
 */
struct node *list_rest(struct node *head);
struct node *list_cdr(struct node *head);

/**
 * Change the tail of the list
 */
int list_set_rest(struct node *head, struct node *tail);
int list_set_cdr(struct node *head, struct node *tail);

/**
 * Apply function "func" to each element of the list
 */
void list_for_each(struct node *head, void (*func)(void *));
int list_length(struct node *head);
void list_reverse(struct node* head);

/**
 * Add the second list to the end of the first
 */
void list_append(struct node *first, struct node *second);

/**
 * Return the value at 'index', or NULL if there is no value
 * at that location
 */
void *list_value_at(struct node *head, int index);

/**
 * A predicate that determines if the list contains the given value.
 */
int list_contains(struct node *head, void *val, int (*cmp_val)(void *, void *));

//struct node *list_from_array(void **data, int length);
// TODO: are there any remaining functions from R5RS that make sense (eg: pair? list? probably do not make any sense)?
// 
// Selected functions from SRFI-1
// http://srfi.schemers.org/srfi-1/srfi-1.html#TheProcedures
// iota
// take
// drop
// split-at
// last

#endif
