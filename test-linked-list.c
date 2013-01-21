/**
 * An example implementation of a singly-linked list
 *
 * Written by Justin Ethier, 2012
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

void *int_alloc(int val){
    int *result = (int *) malloc(sizeof(int));
    *result = val;
    return result;
}
void int_dealloc(void *val){
    if (val){
        free(val);
    }
}
int int_cmp(void *a, void *b){
    if (!a || !b) return 0;

    return *((int *) a) == *((int *) b);
}
void int_print(void *val){
    if (val){
        printf("%d\n", *((int *)val));
    }
}

void testBasic(){
    struct node *l = list();

    list_add(l, int_alloc(1));
    list_add(l, int_alloc(2));
    list_add(l, int_alloc(3));
    list_add(l, int_alloc(3));
    list_add(l, int_alloc(4));
    list_remove(l, int_alloc(3), int_cmp, int_dealloc);
    list_reverse(l);
    assert( 3 == list_length(l));
    assert( 4 == *((int *)list_value(l)));
    list_destroy(l, int_dealloc);
    printf("Passed testBasic()\n");
}

/**
 * Test reading data from a list
 */
void testReading(){
    struct node* l = list(), *lp;
    int i, len = 100, val;
    for (i = 0; i < len; i++){
        list_add(l, int_alloc(i));
    }
    lp = l;
    i = 0;
    while (!list_is_empty(lp)){
        val = *((int *)list_car(lp));
        assert(i == val);
        lp = list_cdr(lp);
        i++;
    }

    list_destroy(l, int_dealloc);
    printf("Passed testReading()\n");
}

// TODO: should use assert or xunit for tests
void test(){
    struct node* l = NULL, *r;
//    int data[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
//    l = list_from_array((void **)data, 11);
//    list_for_each(l, int_print);
//    printf("List length = %d\n\n", list_length(l));
//    list_destroy(l, int_dealloc);

    l = list();
    list_add(l, int_alloc(1));
    list_add(l, int_alloc(2));
    list_add(l, int_alloc(2));
    list_add(l, int_alloc(2));
    list_add(l, int_alloc(2));
    list_add(l, int_alloc(3));
    list_add(l, int_alloc(4));
    list_add(l, int_alloc(5));
    list_remove(l, int_alloc(2), int_cmp, int_dealloc);
    list_reverse(l);
    list_for_each(l, int_print);
    printf("List length = %d\n\n", list_length(l));

    printf("Testing list_set_value:\n");
    list_set_value(l, int_alloc(10));
    list_set_value(list_rest(l), int_alloc(20));
    list_for_each(l, int_print);

    printf("Testing list_set_rest:\n");
    struct node *l2 = list();
    list_add(l2, int_alloc(100));
    list_add(l2, int_alloc(101));
    list_add(l2, int_alloc(101));
    list_add(l2, int_alloc(101));
    list_add(l2, int_alloc(101));
    struct node *l3 = list();
    list_add(l3, int_alloc(1100));
    list_add(l3, int_alloc(1101));
    list_set_rest(l2, l3);
    list_for_each(l2, int_print);
    printf("l2 length = %d\n", list_length(l2));

    printf("Rest:\n");
    list_for_each(list_rest(l), int_print);
    printf("\n");

    list_remove(l, int_alloc(1), int_cmp, int_dealloc);
    list_remove(l, int_alloc(1), int_cmp, int_dealloc);
    list_remove(l, int_alloc(1), int_cmp, int_dealloc);
    list_remove(l, int_alloc(5), int_cmp, int_dealloc);
    list_for_each(l, int_print);
    printf("List length = %d\n\n", list_length(l));
}

int main(int argc, char **argv){
    testBasic();
    testReading();
    printf("\n");
    test();
    return 0;
}
