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
 *
 * @return Pointer to the new list
 */
struct node *list();

/**
 * Add a new node to the end of the linked list. Memory is 
 * allocated from the heap for the new node.
 *
 * @param ptr   Pointer to the linked list
 * @param val   New value to add to the list
 * @return 1 if the add succeeded and 0 if an error occurred
 */
int list_add(struct node *ptr, void *val);

/**
 * Construct a list containing the given value at the
 * start of the given list.
 *
 * The given list is modified and its pointer should be
 * reassigned to the return value. If you want to use 
 * the given list again, it can be generated from the
 * return value using list_rest().
 *
 * @param val   Value to add at the front of the list
 * @param list  List to add the value to.
 *
 * @return Pointer to the new list
 */
struct node *list_cons(void *val, struct node *list);

/**
 * A wrapper of list_cons
 */
struct node *list_add_at_head(void *val, struct node *list);

/**
 * Free all memory allocated to the list
 *
 * @param head     List to deallocate
 * @param free_val A function to free memory for each value in the list
 */
void list_destroy(struct node *head, void (free_val(void *)));

/**
 * Removes nodes from the list with the given value,
 * and frees any memory allocated for them.
 *
 * This function checks all elements of the list and
 * will remove all instances of the value.
 *
 * @param ptr       List to remove the value from
 * @param val       Value to remove from the list
 * @param cmp_value Function used to compare values for equality
 */
void list_remove(struct node* ptr, void *val, int (*cmp_val)(void *, void *), void (free_val(void *)));

/** 
 * A predicate to determine if the list is empty
 *
 * @param head  List to inspect
 * @return 0 for an empty list, otherwise 1
 */
int list_is_empty(struct node *head);

/**
 * Return the value at the front of the list
 * 
 * @param head List to inspect
 * @return Value at the front of the list, or NULL if none
 */
void *list_value(struct node *head);

/**
 * A wrapper for list_value
 */
void *list_car(struct node *head);

/**
 * Change the value at the front of the list
 *
 * TODO: does this make sense? Maybe provide a function that does free memory?
 * NOTE: this function does not free memory used by the old value
 *
 * @param head  The list to modify
 * @param val   The new value to put at the front of the list 
 */
void list_set_value(struct node *head, void *val);

/**
 * A wrapper for list_set_value
 */
void list_set_car(struct node *head, void *val);

/**
 * Return the tail of the list. In other words, a list containing
 * all items except the first one.
 *
 * @param head  Return the tail of this list
 * @return A pointer to the tail
 */
struct node *list_rest(struct node *head);

/**
 * A wrapper for list_rest
 */
struct node *list_cdr(struct node *head);

/**
 * Change the tail of the list
 *
 * TODO: should old tail be freed? Or maybe we provide another function that does this and also frees it?
 * Note: this function does not free memory used by the old tail
 *
 * @param head  The list to modify
 * @param tail  The list to insert in tail position
 * @return 1 upon success, or 0 if an error occurs
 */
int list_set_rest(struct node *head, struct node *tail);

/**
 * A wrapper for list_set_rest
 */
int list_set_cdr(struct node *head, struct node *tail);

/**
 * Call function "func" for each element of the list.
 * The list is traversed in order and the function is called
 * once with the current element passed in as a parameter.
 *
 * @param head The list to traverse
 * @param func The function to execute for each list element
 */
void list_for_each(struct node *head, void (*func)(void *));

/**
 * Return the length of the list
 *
 * @param head The list to inspect
 * @return the length of the given list
 */
int list_length(struct node *head);

/**
 * Reverse the given list
 * The list is modified in-place.
 *
 * @param head  The list to modify
 */
void list_reverse(struct node* head);

/**
 * Add the second list to the end of the first
 *
 *
TODO: is this API to hard to use correctly WRT free? should it be
simplified some way (such as doing away with a special list head) in
order to make it easier to use?
 * This function modifies the lists pointed to by the given pointers.
 * Neither list pointer should be used after this operation.
 *
 * @param first The first list, which will contain the first element of the new list
 * @param second The second list, which will contain the last element of the new list
 */
void list_append(struct node *first, struct node *second);

/**
 * Return the value at 'index', or NULL if there is no value
 * at that location
 *
 * @param head  The list to inspect
 * @param index Get the list value at this position
 * @return Value at the given position, or NULL if none
 */
void *list_value_at(struct node *head, int index);

/**
 * A predicate that determines if the list contains the given value.
 *
 * @param head The list to inspect
 * @param val  The value to search for
 * @param cmp_val A function to compare values for equality
 * @return 1 if the value is found, and 0 if not
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
