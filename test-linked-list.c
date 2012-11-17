/**
 * An example implementation of a singly-linked list
 *
 * Written by Justin Ethier, 2012
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

void testBasic(){
    struct node *l = list();

    list_add(l, 1);
    list_add(l, 2);
    list_add(l, 3);
    list_add(l, 3);
    list_add(l, 4);
    list_remove(l, 3);
    list_reverse(l);
    assert( 3 == list_length(l));
    assert( 4 == list_value(l));
    list_destroy(l);
    printf("Passed testBasic()\n");
}

/**
 * Test reading data from a list
 */
void testReading(){
    struct node* l = list(), *lp;
    int i, len = 100;
    for (i = 0; i < len; i++){
        list_add(l, i);
    }
    lp = l;
    i = 0;
    while (!list_is_empty(lp)){
        assert( i == list_car(lp) );
        lp = list_cdr(lp);
        i++;
    }

    list_destroy(l);
    printf("Passed testReading()\n");
}

// TODO: should use assert for tests
void test(){
    struct node* l = NULL, *r;
    int data[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
//assert(0);
    l = list_from_array(data, 11);
    list_print(l);
    printf("List length = %d\n\n", list_length(l));
    list_destroy(l);

    l = list();
    list_add(l, 1);
    list_add(l, 2);
    list_add(l, 2);
    list_add(l, 2);
    list_add(l, 2);
    list_add(l, 3);
    list_add(l, 4);
    list_add(l, 5);
    list_remove(l, 2);
    list_reverse(l);
    list_print(l);
    printf("List length = %d\n\n", list_length(l));

    printf("Rest:\n");
    list_print(list_rest(l));
    printf("\n");

    list_remove(l, 1);
    list_remove(l, 1);
    list_remove(l, 1);
    list_remove(l, 5);
    list_print(l);
    printf("List length = %d\n\n", list_length(l));
}

int main(int argc, char **argv){
    testBasic();
    testReading();
    printf("\n");
    test();
    return 1;
}
