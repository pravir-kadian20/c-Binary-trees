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

int height(node *root){
    if(root==NULL){
        return 0;
    }

    int lt=height(root->left);
    int rt=height(root->right);

    return max(lt,rt)+1;
}

class Pair{
public:
    int height;
    int diameter;
};

Pair fastDiameter(node *root){
    Pair p;
    if(root==NULL){
        p.height=0;
        p.diameter=0;
        return p;
    }

    Pair left=fastDiameter(root->left);
    Pair right=fastDiameter(root->right);

    p.height=max(left.height,right.height)+1;

    p.diameter=max(left.height+right.height,max(left.diameter,right.diameter));

    return p;
}
int main(){
    node *root=buildtree();
    cout << "THE DIAMETER OF B T IS:" << endl;
    cout << fastDiameter(root).diameter << endl;
}
