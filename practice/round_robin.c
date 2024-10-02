#include<stdio.h>
#include<string.h>
struct queue {
    char task[4];
    int time;
};
int max_time=4;
int front=-1;
int rear=-1;
struct queue arr[5];
int size=5;
void insert(char task[],int time){
    if(front==-1){
        front=0;
        rear=0;
        strcpy(arr[rear].task,task);
        arr[rear].time=time;
        return;
    }
    else if(front==(rear+1)%size){
        printf("overflow");
        return ;
    }
    else{
        rear=(rear+1)%size;
        strcpy(arr[rear].task,task);
        arr[rear].time=time;
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        printf("underflow");
    }
    else if(front==rear){
        rear=front=-1;
    }
    else{
        front=(front+1)%size;
    }
}
void calculate(){
    int i=0;
    while(front!=-1){
        if(arr[i].time<max_time){
            printf("\n");
            printf("%s\t",arr[i].task);
            printf("0");
            i=(i+1)%size;
            dequeue();
            
        }
        else{
            printf("\n");
            printf("%s\t",arr[i].task);
            printf("%d",arr[i].time-max_time);
            insert(arr[i].task,arr[i].time-max_time);
            dequeue();
            i=(i+1)%size;
        }
    }
    printf("\nall task completed!");
}
void show(){
    int i=0;
    for(i=front;i!=rear;){
        printf("\n");
        printf("%s\t",arr[i].task);
        printf("%d",arr[i].time);
        i=(i+1)%size;
    }
    printf("\n");
    printf("%s\t",arr[i].task);
    printf("%d",arr[i].time);
}

int main(){
    insert("p1",1);
    insert("p2",6);
    insert("p3",8);
   // show();
    calculate();

}