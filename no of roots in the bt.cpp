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
}

int noOfRoots(node *root){
    if(root==NULL){
        return 0;
    }

    int lt=noOfRoots(root->left);
    int rt=noOfRoots(root->right);

    return lt+rt+1;
}

int main(){
    node *root=buildtree();
    cout << "NO OF ROOTS IN THE TREE ARE:" << endl;
    cout << noOfRoots(root) << endl;
}