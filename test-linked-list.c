/**
 * An example implementation of a singly-linked list
 *
 * Written by Justin Ethier, 2012
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

void *int_alloc(int val)
{
    int *result = (int *) malloc(sizeof(int));
    *result = val;
    return result;
}
void int_dealloc(void *val)
{
    if (val){
        free(val);
    }
}
int int_cmp(void *a, void *b)
{
    if (!a || !b) return 0;

    return *((int *) a) == *((int *) b);
}
void int_print(void *val)
{
    if (val){
        printf("%d\n", *((int *)val));
    }
}

void assertEqualList(struct node *lst, int *data)
{
    struct node *l = lst;
    int i, val;

    while (!list_is_empty(l)){
        val = *((int *)list_car(l));
        assert(*data == val);

        i++;
        data++;
        l = list_cdr(l);
    }
}

void testBasic()
{
    struct node *l = list(), *ltmp;
    int contents[5] = {1, 2, 3, 3, 4}, i, *tmp;

    for (i = 0; i < 5; i++){
        list_add(l, int_alloc(contents[i]));
    }

    ltmp = l;
    for (i = 0; i < 5; i++){
        tmp = (int *)list_value(ltmp);
        ltmp = list_rest(ltmp);
        printf("%d / %d\n", contents[i], *tmp);
        assert(contents[i] == *tmp);
    }

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
void testReading()
{
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
void test()
{
    struct node* l = NULL;
    int cmp1[] = {10, 20, 3, 1},
        cmp2[] = {100, 1100, 1101},
        cmp3[] = {20, 3, 1},
        cmp4[] = {10, 20, 3};

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
    assert(list_length(l) == 4);

    printf("Testing list_set_value:\n");
    list_set_value(l, int_alloc(10));
    list_set_value(list_rest(l), int_alloc(20));
    list_for_each(l, int_print);
    assertEqualList(l, cmp1);

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
    assertEqualList(l2, cmp2);
    assert(list_length(l2) == 3);

    printf("Rest:\n");
    list_for_each(list_rest(l), int_print);
    //TODO: assertEqualList(l, cmp4);
    printf("\n");

    list_remove(l, int_alloc(1), int_cmp, int_dealloc);
    list_remove(l, int_alloc(1), int_cmp, int_dealloc);
    list_remove(l, int_alloc(1), int_cmp, int_dealloc);
    list_remove(l, int_alloc(5), int_cmp, int_dealloc);
    list_for_each(l, int_print);
    assertEqualList(l, cmp4);
    assert(list_length(l2) == 3);
}

int main(int argc, char **argv){
    testBasic();
    testReading();
    printf("\n");
    test();
    return 0;
}
