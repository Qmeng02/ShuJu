#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct Lstack{
    E element;
    struct Lstack * next;
};

typedef struct Lstack * Stack;

void init(Stack node){
    node->next = NULL;
}

//入栈操作
_Bool push(Stack stack,E element){
    Stack newstack =malloc(sizeof(struct Lstack));
    if(newstack==NULL) return 0;
    newstack->element =element;
    newstack->next = stack->next;
    stack->next = newstack;
    return 1;
}

E pop(Stack stack){
    Stack tmp =stack->next;
    E e =tmp->element;
    stack->next =stack->next->next;
    free(tmp);
    return e;
}

_Bool isempty(Stack stack){
    return stack->next ==NULL;
}

void print(Stack head){
    while(head->next){
        head=head->next;
        printf("%d ",head->element);
    }
    printf("\n");
}



int main(){
    struct Lstack head;
    init(&head);
    for(int i=1;i<=3;i++){
        push(&head,i*100);
    }
    print(&head);
    while(!isempty(&head)){
        printf("%d ",pop(&head));
    }
    return 0;
}
