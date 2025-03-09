#include <stdio.h>
#include <stdlib.h>
//顺序表实现用循环队列（无法扩容）

typedef int E;

struct Queue{
    E * array;
    int capacity;
    int front,rear;
};

typedef struct Queue * ArrayQueue;

_Bool init(ArrayQueue queue){
    queue->array =malloc(sizeof(E)*10);
    if(queue->array==NULL) return 0;
    queue->capacity =10;
    queue->front =queue->rear =0;
    return 1;
}

_Bool in(ArrayQueue queue,E element){//进队操作
    int pos =(queue->rear +1)%queue->capacity;
    if(pos==queue->front) return 0;
    queue->rear =pos;
    queue->array[queue->rear]=element;
    return 1;
}

_Bool isempty(ArrayQueue queue){
    return queue->rear==queue->front;
}

E poll(ArrayQueue queue){//出队操作
    queue->front =(queue->front +1)%queue->capacity;
    return queue->array[queue->front];

}

void print(ArrayQueue queue){
    printf("<<<");
    int i=queue->front;
    while (i != queue->rear) {
        i = (i + 1) % queue->capacity;
        printf("%d ", queue->array[i]);
    }
    printf(">>>\n");
}

int main(){
    struct Queue queue;
    init(&queue);
    for(int i=0;i<5;i++){
        in(&queue,i*100);
    }
    print(&queue);

    return 1;
}