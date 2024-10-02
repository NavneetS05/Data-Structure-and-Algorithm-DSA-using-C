#include<stdio.h>
struct priority{
    int data;
    int pri;
};
int size=10;
struct priority arr[10];
int curr_size=0;
void insert(int data,int pri){
    int i=0;
    if(curr_size==size){
        printf("overflow");
        return;
    }
    for(i=curr_size-1;i>=0;i--){
        if(pri<arr[i].pri){
            arr[i+1]=arr[i];
        }
        else{
            break;
        }
    }
    arr[i+1].pri=pri;
    arr[i+1].data=data;
    curr_size++;
    return;
}
void delete(){
    if(curr_size==0){
        printf("underflow");
        return;
    }
    else{
        for(int i=0;i<curr_size;i++){
            arr[i]=arr[i+1];
        }
        curr_size--;
    }
}
void show(){
    if(curr_size==0){
        printf("underflow");
        return;
    }
    else{
        printf("\ndata:");
        for(int i=0;i<curr_size;i++){
            printf("%d",arr[i]);
        }
    }
}
int main(){
    insert(10,2);
    insert(30,1);
    insert(20,3);
    show();
    delete();
    show();
}