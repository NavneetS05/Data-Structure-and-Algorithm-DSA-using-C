#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*prev;
    struct node*next;
};
struct node* head;
struct node* last;
struct node*create_node(int data){
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if (!newnode){
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
        last->next=newnode;
        newnode->next=head;
        newnode->prev=last;
        head=newnode;
    }
}
void show(){
    struct node*temp=head;
    printf("\ndata:");
    while(temp->next!=head){
        printf(" %d",temp->data);
        temp=temp->next;
    }
    printf(" %d",temp->data);
    free(temp);
}
int main(){
    add_beg(10);
    add_beg(20);
    add_beg(30);
    show();
    return 0;
}
