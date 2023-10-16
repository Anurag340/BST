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

void delete_node(Node*root,int key){

    //base case
    if(root==NULL)return;

    //leaf node
        if(root->data==key && (root->left==NULL && root->right==NULL)){
            delete(root);

            
            return;
        }

        //node with single child

        // if(root->data==key && (root->left!=NULL || root->right!=NULL)){
        //     if(root->left==NULL){
        //         swap(root->data,root->right->data);
        //         delete(root->right);
        //         return;
        //     }
        //     if(root->right==NULL){
        //         swap(root->data,root->left->data);
        //         delete(root->left);
        //         return;
        //     }

        // }
        cout<<root->data<<endl;
        delete_node(root->left,key);
        delete_node(root->right,key);
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

void preorder(Node*root){
    //base case
    if(root==NULL){
        return;
    }

    cout<<root->data<<endl;

    preorder(root->left);
    preorder(root->right);
}


int main(){
    Node*root=NULL;

    cout<<"Enter the no of elements to insert : "<<endl;

    int n;
    cin>>n;


    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        root=insertNode(root,x);

    }
    cout<<endl;

    cout<<"Inorder of your data : "<<endl;



    inorder(root);
    cout<<endl;

    delete_node(root,55);

    preorder(root);

    
    cout<<endl;
    

}