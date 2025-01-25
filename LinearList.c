#include <stdio.h>
#include <stdlib.h>
typedef int E;

struct List
{
    E * array;//为了配合malloc使用
    int capacity;//数组大小
    int size;//数组元素
    };

typedef struct List * ArrayList;
//初始化操作
int init(ArrayList list){
    
    list->array=malloc(sizeof(E) * 10);//动态分配内存空间方便修改
    if(list->array==NULL)return 0;//分配失败返回0
    list->capacity=10;
    list->size=0;
    return 1;
}

//插入操作
_Bool insert(ArrayList list,E element,int index){
    if(index<1||index>(list->size+1)) return 0;
    //扩容操作,可以动态扩充表大小
    if(list->size == list->capacity){
        int newcapacity = list->capacity +(list->capacity>>1);
        E * newArray=realloc(list->array,newcapacity * sizeof(E));
        list->array=newArray;
        list->capacity=newcapacity;
    }

    for(int i=list->size; i>index-1; i--)
        {list->array[i]=list->array[i-1];}
    list->array[index-1]=element;
    list->size++;
    return 1;

}

//删除
_Bool delete(ArrayList list,int index){
    if(index<1||(index>list->size))return 0;
    for(int i=index-1;i<list->size-1;++i)
        list->array[i]=list->array[i+1];
    list->size--;
    return 1;
}

//打印表中元素
void print(ArrayList list){
    
    for(int i=0;i<list->size;++i){
        printf("%d ",list->array[i]);
    }
    printf("\n");
}

int size(ArrayList list){
    return list->size;
}
//获取某一位序的元素
E * getlist(ArrayList list,int index){
    if(index<1||(index>list->size)) return NULL;//超出范围就返回NULL
    return &list->array[index-1];
}
//查找数字返回位序
int find(ArrayList list,E element){
    for(int i=0;i<list->size;i++){
        if(list->array[i]==element) return i+1;
    }
    return -1;
}
int main(){
    struct List list;
    if(init(&list)){
    insert(&list,666,1);
    print(&list);
    insert(&list,777,1);
    print(&list);
    delete(&list,1);
    print(&list);
    insert(&list,888,2);
    print(&list);
    }
    else{
        printf("false");
    }
}