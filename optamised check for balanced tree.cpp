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
class Pair{
public:
    int height;
    bool balance;
};

Pair optaIsHeightBalanced(node *root){
    Pair p;
    if(root==NULL){
        p.height=0;
        p.balance=true;
        return p;
    }
    Pair left=optaIsHeightBalanced(root->left);
    Pair right=optaIsHeightBalanced(root->right);

    p.height=max(left.height,right.height)+1;

    if(abs(left.height-right.height)<=1 && left.balance && right.balance){
        p.balance=true;
    }
    else{
        p.balance=false;
    }
    return p;

}

int main(){
    node *root=buildtree();
    print(root);
    cout << endl;
    //replaceSum(root);
    //print(root);
    if(isheightBalanced(root)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    if(optaIsHeightBalanced(root).balance){
        cout << "Balanced Tree" << endl;
    }
    else{
        cout << "Not Balanced" << endl;
    }
}