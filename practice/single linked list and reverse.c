#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node *head;
struct node *last;
struct node*create_node(int data){
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode){
        printf("overflow");
    }
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void add_beg(int data){
    struct node*newnode=create_node(data);
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}
void show(){
    struct node* temp;
    temp=head;
    printf("\ndata:");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
        free(temp);
}
void reverse(){
    struct node*prev,*curr,*forw;
    prev=NULL;
    curr=head;
    forw=curr->next;
    while(curr!=NULL){
        forw=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forw;
    }
    head=prev;
    printf("\nreversed");
    show();
    
}
void add_end(int data){
    last=head;
    while(last->next!=0){
        last=last->next;
    }
    struct node*newnode=create_node(data);
    if(head==NULL){
        head=newnode;
    }
    else{
        last->next=newnode;
        last=newnode;
    }

}
int main(){
    add_beg(10);
    add_beg(20);
    add_beg(30);
    add_beg(40);
    show();
    add_end(50);
    show();
    reverse();
    add_end(60);
    show();
   return 0;
}
