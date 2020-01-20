#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

node *buildnode(){
    int data;
    cin>>data;

    if(data==-1){
        return NULL;
    }

    node *root=new node(data);
    root->left=buildnode();
    root->right=buildnode();

    return root;
}

int changeTree(node *root){
    if(root==NULL){
        return 0;
    }
    
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }

    int ls= changeTree(root->left);
    int rs= changeTree(root->right);

    int temp=root->data;

    root->data=ls+rs;

    return temp+root->data;
}

void print(node *root){
    if(root==NULL){
        return;
    }

    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

int main(){
    node *root=buildnode();
    print(root);
    cout << endl;
    changeTree(root);
    print(root);
}