#include <stdio.h>
#include <stdlib.h>
//不用关心容量问题

typedef int E;

struct LQueue
{
    E element;
    struct LQueue * next;
};

typedef struct LQueue * Queue;

struct QUeue{
    Queue front,rear;
};

typedef struct QUeue *LinkedQueue;

_Bool init(LinkedQueue queue){
    Queue node =malloc(sizeof(struct LQueue));
    if(node==NULL)return 0;
    queue->rear=queue->front =node;
    return 1;
}

_Bool in(LinkedQueue queue,E element){
    Queue node =malloc(sizeof(struct LQueue));
    if(node==NULL)return 0;
    node->element =element;
    node->next = NULL;
    queue->rear->next =node;//先让尾节点的下一个指向新的结点
    queue->rear=node;//再让队尾指针指向新的尾节点
    return 1;
}

_Bool isempty(LinkedQueue queue){
    return queue->rear==queue ->front;
}

E poll(LinkedQueue queue){
    Queue tmp =queue->front->next;
    E e=tmp->element;
    queue->front->next= queue->front->next->next;//直接让头节点指向下下个节点
    if(queue->rear==tmp) queue->rear = queue->front;//如果队尾就是待出队的节点，那么队尾回到队首位置上
    free(tmp);//释放内存
    return e;

}

void print(LinkedQueue queue){
    printf("<<<");
    Queue node =queue->front->next;
    while(node){
        printf("%d ",node->element);
        node =node ->next;
    }
    printf(">>>\n");
}

int main(){
    struct QUeue queue;
    init(&queue);
    for(int i=0;i<5;i++){
        in(&queue,100*i);
    }
    print(&queue);
    return 0;
}