#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* pre;
    node(int d){
        this->data = d;
        this->next = NULL;
        this->pre = NULL;
    }
};

void insertH(node**head,int data){
    node* newnode = new node(data);
    newnode->next = *head;
    *head = newnode;
    newnode->pre = NULL;
}

void insertE(node**head,int data){
    node* newnode = new node(data);
    node* temp = *head;
    if(temp==NULL){
        newnode->data = data;
        newnode->next = NULL;
        newnode->pre = NULL;
        *head = newnode;
    }
    else{
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->pre = temp;
    }
}
void insertSP(node**head,int data,int pos){
    node* newnode = new node(data);
    if(pos==0){
        newnode->data = data;
        newnode->next = NULL;
        newnode->pre = NULL;
        *head = newnode;
    }
    else{
        node* temp = *head;
        for(int i=0;i<pos-1;i++){
            temp = temp->next;
            if(temp==NULL){
                cout<<"Glt position hai bhai"<<endl;
                return;
            }
        }
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->pre = temp;
    }
}

void deleteB(node**head){
    if(*head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    else{
        node* temp = *head;
        *head = (*head)->next;
        (*head)->pre = NULL;
    }
}

void deleteSP(node**head,int pos){
    if(pos==0){
        cout<<"Khali hai"<<endl;
    }
    if(pos==1){
        deleteB(head);
    }
    else{
        node* del = *head;
        node* temp;
        for(int i=0;i<pos-1;i++){
            temp = del;
            del = del->next;
            if(del==NULL){
                cout<<"GALAT PSOITION HAI"<<endl;
                break;
            }
           }
        temp->next = del->next;
        del->next = NULL;
        delete del;
    }
}

void print(node*head){
        node* temp  = head;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
        cout<<endl;
}

int main() {
    node* head = NULL;
    insertH(&head,10);
    insertH(&head,20);
    insertE(&head,30);
    insertE(&head,40);
    insertSP(&head,25,3);
    print(head);
    deleteB(&head);
    print(head);
    deleteSP(&head,4);
    print(head);
    return 0;
}
