#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

node* create(int data){
    node* root = new node(data);
    return root;
}

node* insert(node* root,int data){
    if(data==-1){
        return root;
    }
    if(root==NULL){
        return create(data);
    }
    if(data < root->data){
        //insert in the left
        root->left = insert(root->left,data);
    }
    else{
        //insert in the right
        root->right = insert(root->right,data);
    }
    return root;
    
    
}

int search(node* root,int d){
    if(root==NULL){
        return 0;
    }
    if(root->data==d){
       return 1;
       
    }

    if(d < root->data){
        node* temp = root->left;
        return search(temp,d);
        
    }
    else{
        node* temp = root->right;
        return search(temp,d);
        
    }
}

int main()
{
node* root=NULL;
create(10);
root = insert(root,5);
root = insert(root,20);

if(search(root,5)){
    cout << "yeeeeeeeee";
}
else{
    cout <<"nooooooooo";
}
return 0;
}
