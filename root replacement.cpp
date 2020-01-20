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

node *buildtree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    node *root=new node(data);
    root->left=buildtree();
    root->right=buildtree();

    return root;
}

void print(node *root){
    if(root==NULL){
        return;
    }
    cout << root->data << " ";
    print(root->left);
    
    print(root->right);
}
int replaceSum(node *root){
    if(root==NULL){
        return 0;
    }

    if(root->left==NULL && root->right==NULL){
        return root->data;
    }

    int ls=replaceSum(root->left);
    int rs=replaceSum(root->right);

    int temp=root->data;
    root->data=ls+rs;
    return temp+root->data;
}
int main(){
    node *root=buildtree();
    print(root);
    cout << endl;
    replaceSum(root);
    print(root);
}