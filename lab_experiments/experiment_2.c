#include<stdio.h>
const int size=70;
int front=-1;
int end=size;
void add_at_beg(int data,int arr[]){
    if(front+1==end){
        printf("the array is full");
    }
    else{
        front++;
        arr[front]=data;
    }
}
void add_at_end(int data,int arr[]){
    if(front+1==end){
        printf("the array is full");
    }
    else{
        end--;
        arr[end]=data;
    }
}
void add_at_specific_pos(int arr[],int pos,int data){
    if((0<pos) && (pos<size)){
        if(0<pos && pos<front || end<pos && pos<size){
            arr[pos]=data;
        }
        else{
            printf("position cannot be used:");
            return;
        }
    }
    else{
        printf("position not valid");
    }
}
void display(int arr[]){
    int i=0;
    if(front==-1 && end==size){
        printf("array is empty:");
    }
    else{
    printf("the elements in array are:");
        if(front>0 && end==size){
            for(i=0;i<=front;i++){
                printf("%d.%d\t",i+1,arr[i]);
            }
        }
        else if(front==-1 && end<size){
            for(i=end;i<size;i++){
                printf("%d.%d\t",i+1,arr[i]);
            }
        }
        else{
            for(i=0;i<=front;i++){
                printf("%d.%d\t",i+1,arr[i]);
            }
            for(i=end;i<size;i++){
                printf("%d.%d\t",i+1,arr[i]);
            }
        }
    }
}
int main(){
    int i=1;
    int arr[size];
    int pos;
    int data;
    int choice;
    printf("welcome to array insertion software\n");
    while(i){
        printf("\n1.to add element at begining\n");
        printf("2.to add element at end\n");
        printf("3.to add element at specific position\n");
        printf("4.to display\n");
        printf("5.to exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                printf("Enter element to add at begining");
                scanf("%d",&data);
                add_at_beg(data,arr);
                break;
            }
            case 2: {
                printf("Enter element to add at end");
                scanf("%d",&data);
                add_at_end(data,arr);
                break;
            }
            case 3: {
                printf("Enter element to add at specific position");
                scanf("%d",&data);
                printf("Enter position:");
                scanf("%d",&pos);
                add_at_specific_pos(arr,pos,data);
                break;
            }
            case 4: {
                display(arr);
                break;
            }
            case 5: {
                i=0;
                break;
            }
            default:{
                printf("wrong input");
                break;
            }
        }
    }
    return 0;
}