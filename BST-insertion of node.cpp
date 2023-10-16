#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};


Node* create(int data){
    Node*temp=new Node(data);

    return temp;
}

Node* insertNode(Node* root,int data){
    if(root==NULL)return create(data);

    if(data<root->data){
        root->left=insertNode(root->left,data);
    }

    if(data>root->data){
        root->right=insertNode(root->right,data);
    }
    return root;
}


void inorder(Node*root){
    //base case
    if(root==NULL){
        return;
    }

    

    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}

int main(){
    Node*root=NULL;

    root=insertNode(root,40);
    root=insertNode(root,50);
    root=insertNode(root,60);
    root=insertNode(root,70);
    root=insertNode(root,30);
    root=insertNode(root,43);
    root=insertNode(root,64);

    inorder(root);
}