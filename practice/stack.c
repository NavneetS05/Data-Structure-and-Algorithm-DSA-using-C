#include<stdio.h>
int top=-1;
int n=10;
int arr[10];
void push(int data){
    if(top==n-1){
        printf("Overflow");
    }
    else{
        top++;
        arr[top]=data;
    }
}
int pop(){
    if(top==-1){
        printf("Underflow");
    }
    else{
        int temp=arr[top];
        top--;
        printf("\n%d is deleted",temp);
        return temp;
    }
}
int peek(){
    if(top==-1){
        printf("Underflow");
    }
    else{
        printf("\n%d is top element",arr[top]);
    }

}
int show(){
    if(top==-1){
        printf("Underflow");
    }
    else{
        printf("\n");
        for(int i=0;i<=top;i++){
            printf("%d\t",arr[i]);
        }
    }
}
int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    show();
    pop();
    peek();
    show();
}