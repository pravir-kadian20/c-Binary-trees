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

int height(node *root){
    if(root==NULL){
        return 0;
    }
    int lt=height(root->left);
    int rt=height(root->right);

    return max(rt,lt)+1;
}

bool isheightBalanced(node *root){
    if(root==NULL){
        return true;
    }
    int lt=height(root->left);
    int rt=height(root->right);
    if(lt-rt<=1 && lt-rt>=-1 && isheightBalanced(root->left) && isheightBalanced(root->right)){
        return true;
    }
    return false;

}

int main(){
    node *root=buildtree();
    print(root);
    cout << endl;
    if(isheightBalanced(root)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
}