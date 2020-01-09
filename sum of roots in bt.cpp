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

int sumOfRoots(node *root){
    if(root==NULL){
        return 0;
    }

    int lt=sumOfRoots(root->left);
    int rt=sumOfRoots(root->right);

    return root->data+lt+rt;
}

int main(){
    node *root=buildtree();
    cout << "SUM OF ROOTS IN THE TREE IS:" << endl;
    cout << sumOfRoots(root) << endl;
}