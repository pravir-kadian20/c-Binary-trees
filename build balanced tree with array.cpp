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
void print(node *root){
    if(root==NULL){
        return;
    }
    cout << root->data << " ";
    print(root->left);
    
    print(root->right);
}
node *buildTreeFromArray(int *a,int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    node *root=new node(a[mid]);
    root->left=buildTreeFromArray(a,s,mid-1);
    root->right=buildTreeFromArray(a,mid+1,e);

    return root;
}

int main(){
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    node *root=buildTreeFromArray(a,0,n-1);
    print(root);
}