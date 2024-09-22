#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*prev;
};
struct node*head;
struct node*last;
struct node*create_node(int data){
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode){
        printf("overflow");
    }
    else{
        newnode->data=data;
        newnode->next=NULL;
        newnode->prev=NULL;
        return newnode;
    }
}
void add_beg(int data){
    struct node*newnode=create_node(data);
    if(head==NULL){
        head=newnode;
        last=newnode;
    }
    else{
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    }
}
void show(){
    struct node*temp=head;
    printf("data:");
    while(temp->next!=NULL){
        printf(" %d",temp->data);
        temp=temp->next;
    }
    printf(" %d",temp->data);
    printf("\nreverse:");
    while(temp!=NULL){
        printf(" %d",temp->data);
        temp=temp->prev;
    }
}
void add_end(int data){
    struct node*newnode=create_node(data);
    if(head==NULL){
        head=newnode;
        last=newnode;
    }
    else{
        last->next=newnode;
        newnode->prev=last;
        last=newnode;
    }
}
int main(){
    add_beg(10);
    add_beg(20);
    add_beg(30);
    show();
    add_end(40);
    add_end(50);
    show();
    return 0;
}
