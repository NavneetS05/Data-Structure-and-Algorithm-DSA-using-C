#include<stdio.h>
#include<stdlib.h>
struct Node{
    int coeff;
    int exp;
    struct Node *next;
};
struct Node* createHeaderNode(){
    struct Node* header=(struct Node*)malloc(sizeof(struct Node));
    if(!header){
        printf("not defined");
    }
    header->coeff=0;
    header->exp=-1;
    header->next=NULL;

    return header;
}
void insert(struct Node*header,int c,int e){
    struct Node* temp;
    temp=header;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    struct Node* temp2=(struct Node*)malloc(sizeof(struct Node));
    temp2->coeff=c;
    temp2->exp=e;
    temp2->next=NULL;
    temp->next=temp2;
}
void addpolynomial(struct Node* p1,struct Node*p2){
    struct Node* temp1;
    struct Node* temp2;
    temp1=p1->next;
    temp2=p2->next;
    struct Node*result=createHeaderNode();
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->exp>temp2->exp){
            insert(result,temp1->coeff,temp1->exp);
            temp1=temp1->next;
        }
        else if(temp2->exp>temp1->exp){
            insert(result,temp2->coeff,temp2->exp);
            temp2=temp2->next;
        }
        else{
            int sum=0;
            sum=temp1->coeff+temp2->coeff;
            if(sum!=0){
                insert(result,sum,temp1->exp);
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
    }
    struct Node*temp3=result->next;
    while(temp3!=NULL){
        printf("%d",temp3->coeff);
        if(temp3->exp==0){
            break;
        }
        printf("x");
        printf("%d",temp3->exp);
        printf("+");
        temp3=temp3->next;
    }
}
void display(){
    
}
int main(){
    struct Node*p1=createHeaderNode();
    struct Node*p2=createHeaderNode();
    insert(p1,4,3);
    insert(p1,2,2);
    insert(p1,5,1);
    insert(p1,2,0);

    insert(p2,2,2);
    insert(p2,2,1);
    insert(p2,2,0);
    addpolynomial(p1,p2);
}