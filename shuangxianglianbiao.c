#include <stdio.h>
#include <stdlib.h>

typedef int E;
struct ListNode{
    E element;
    struct ListNode * next;
    struct ListNode * prev;
};

typedef struct ListNode * node;

void init(node node){
    node->next = NULL;
    node->prev = NULL;
}