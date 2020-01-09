#include<iostream>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;

	node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};

node *buildtree(){
	
	int data;
	cin>>data;
	//base case
	if(data==-1){
		return NULL;
	}

	node *root=new node(data);
	root->left=buildtree();
	root->right=buildtree();

	return root;
}

void print(node *root){
	//base case
	if(root==NULL){
		return;
	}

	cout << root->data << " ";
	print(root->left);
	print(root->right);
}

int main(){
	node *root=buildtree();
	print(root);
}
