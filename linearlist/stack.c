#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct Stack
{
   E *array;
   int capacity;
   int top;//表示栈顶位置，存栈顶元素的下标
};

typedef struct Stack * arraystack;

_Bool init(arraystack Stack){
    Stack->array =malloc(sizeof(E)*10);
    if(Stack->array==NULL) return 0;
    Stack->capacity=10;
    Stack->top=-1;
    return 1;
}

//入栈push
_Bool push(arraystack Stack,E element){
    if(Stack->top+1==Stack->capacity){//判断栈是否满
    //扩容操作，同线性表
        int newcapacity = Stack->capacity +(Stack->capacity>>1);
        E * newArray=realloc(Stack->array,newcapacity * sizeof(E));
        if(newArray==NULL) return 0;
        Stack->array =newArray;
        Stack->capacity=newcapacity;
    }
    //不扩容就直接return 0；
    Stack->top++;
    Stack->array[Stack->top]=element;
    return 1;
}

//判断栈是否为空
_Bool isempty(arraystack Stack){
    return Stack->top ==-1;
}

//出栈pop
E pop(arraystack Stack){
    return Stack->array[Stack->top--];
}

//打印元素
void print(arraystack list){
    printf("|");
    for(int i=0;i<list->top+1;++i){
        printf("%d, ",list->array[i]);
    }
    printf("\n");
}



int main(){
    struct Stack stack;
    init(&stack);
    for(int i=0;i<10;i++)
    {
        push(&stack,i*10);
    }
    print(&stack);
}