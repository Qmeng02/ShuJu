#include <stdio.h>
#include <stdlib.h>

typedef int E;
struct ListNode{
    E element;
    struct ListNode * next;
    struct ListNode * prev;
};

typedef struct ListNode * node;

void init(node head){
    head->next = NULL;
    head->prev = NULL;
}

//插入操作
_Bool insert(node head,E element,int index){
    if(index<1) return 0;
     while(--index){
        head=head->next;
        if(head==NULL) return 0;
    }
    node node= malloc(sizeof(struct ListNode));     //创建新节点
    if(node==NULL) return 0;
    node->element =element;

    if(head->next!=NULL){       //如果插入的节点不是最后一个
    node->next=head->next;      //新节点的下一个是原来的下一个
    head->next->prev = node;      //原来的前驱节点指向新创建的节点
    }else{
        node->next=NULL;
    }

    head->next=node;            //原来节点的后继结点指向新创建的
    node->prev=head;            //新节点的前驱节点为原来的节点

    return 1;
}

//删除操作
_Bool delete(node head,int index){
    if(index<1) return 0;
    while(--index){
        head=head->next;
        if(head==NULL) return 0;
    }
    if(head->next==NULL) return 0;

    node tmp = head->next;
    if(head->next->next){
        head->next = head->next->next;
        head->next->next->prev = head; 
    } //head->next为待删除节点，其next为其后继节点，其next的prev为其前驱节点指向
    else{
        head->next = NULL;
    }
    free(tmp);
    return 1;
}

int main(){
    struct ListNode head;
    init(&head);
    for(int i=1;i<6;i++) {   //五个元素
        insert(&head,i*100,i);
    }
    node node =&head;

    
    //正向遍历
    while (node->next != NULL) {
        node = node->next;
        printf("%d -> ", node->element);
    }
    printf("\n");
    //反向遍历
    
    while (node!= NULL) {
        printf("%d -> ", node->element);
        node = node->prev;
    }
 
    return 0;
}
