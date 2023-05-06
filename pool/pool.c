//
// Created by QuJunqiao on 2020/11/26.
//

#include "pool.h"
#include <stdlib.h>
#include <stdio.h>
void* compute(void* args){
Args *arg=args;
int* result=malloc(sizeof(int));
*result=arg->operation->op(arg->operation->a,arg->operation->b);
arg->is_complete=true;
    return result;
}
bool read_operations(char* filename, Queue* q ){
    FILE* file = fopen(filename,"r");
    int a,b,opCode;
    for (int i=0;i<10000;i++){
        fscanf(file,"%d",&opCode);
        fscanf(file,"%d",&a);
        fscanf(file,"%d",&b);
        Operation *oper=malloc(sizeof(Operation));
        oper->a=a;
        oper->b=b;
        if(opCode==0) {
                 
            oper->op = add;
        }
         if(opCode== 1) {
             oper->op = sub;
         }
          if (opCode==2){
                oper->op=mul;
        }
        queue_enqueue(q,oper);


    }
     fclose(file);
    return true;
}
ArrayList* execute_thread_pool(char* filename, int poolsize){
	pthread_t threads[poolsize];
    ArrayList *allist=alist_initialize(10000,sizeof(int),"int");
    Queue *q=queue_initialize(sizeof(Operation),"Operation");
    read_operations(filename,q);
    Args arg[poolsize];
    int *result=NULL;
    for (int i=0;i<poolsize;i++){
       arg[i].operation=queue_dequeue(q);

        arg[i].is_complete=false;

        pthread_create(&threads[i],NULL,compute,&arg[i]);
        pthread_join(threads[i],(void**)&result);
        alist_add(allist,(int*)result);
	if (allist->size==10000){
		break;}
//if it is the last thread, make next compution use the first thread
	if(i>=poolsize-1){
		i=0;
    }}
    return allist;

}
void print_sorted(ArrayList* al)
{
 void* temp;
for (int i=0;i<al->size-1;i++){
    for(int j=0;j<al->size-1;j++){
        if (*(int*)al->arr[j]>*(int*)al->arr[j+1]){
            temp=al->arr[j];
            al->arr[j]=al->arr[j+1];
            al->arr[j+1]=temp;
        }
    }
}

for (int i=0;i<al->size;i++){
printf("%d\n",*(int*)alist_get(al,i));
}
}
int add(int a, int b) {
    int c=a+b;
    return c;
}

int sub(int a, int b) {
    int c= a-b;
    return c;
}

int mul(int a, int b) {
    int c= a*b;
    return c;
}
