#include <stdio.h>
#include <stdlib.h>

typedef int E;
struct ListNode{
    E element;
    struct ListNode * next;
};

typedef struct ListNode * node;

void init(node node){
    node->next = NULL;
}
//struct LinkedNode{ node head;};第二种写法

_Bool insert(node head,int element,int index){
    if(index<1) return 0;
    while(--index){
        head=head->next;
        if(head==NULL) return 0;
    }

    node node =malloc(sizeof(struct ListNode));
    if(node==NULL) return 0;
    node->element =element;
    node->next=head->next;
    head->next = node;
    return 1;
}

_Bool delete(node head,int index){
    if(index<1) return 0;
    while(--index){
        head=head->next;
        if(head==NULL) return 0;
    }
    if(head->next==NULL);
    node tmp =head->next;
    head->next=head->next->next;
    free(tmp);
    return 1;
}

E * getlist(node head,int index){
    if(index<1) return 0;
    do{
        head =head->next;
        if(head->next==NULL) return 0;
    }while(index--);
    return &head->element;
}

int find(node head,E element){
    head=head->next;
    int i=1;
    while(head){
        if(head->element==element) return i;
        head=head->next;
        i++;
    }
    return -1;
}

int sizelist(node head){
    int i=0;       
    while(head->next){          //因为头节点不算在链表之内
        head=head->next;
        i++;
    }
    return i;
}

void print(node head){
    while(head->next){
        head=head->next;
        printf("%d ",head->element);
    }
}

int main(){
    struct ListNode head;
    init(&head);
    for(int i=1;i<=3;i++){
        insert(&head,i*100,i);
    }
    print(&head);
    return 0;
}