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

	//base case
	if(data==-1){
		return NULL;
	}

	node *root=new node(data);
	
	root->left=buildtree();
	root->right=buildtree();

	return root;
}

void printPreorder(node *root){
	if(root==NULL){
		return;
	}

	//print root left right

	cout << root->data << " ";

	printPreorder(root->left);
	printPreorder(root->right);

}

void printInorder(node *root){
	if(root==NULL){
		return;
	}

	//print left root right
	printInorder(root->left);
	
	cout << root->data << " ";

	printInorder(root->right);
}

void printPostorder(node *root){
	if(root==NULL){
		return;
	}

	//print left right root

	printPostorder(root->left);
	printPostorder(root->right);

	cout << root->data << " ";
}

int main(){
	node *root=buildtree();
	
	cout << "PREORDER" << endl;
	printPreorder(root);
	cout << endl;
	cout << "INORDER" << endl;
	printInorder(root);
	cout << endl;
	cout << "POSTORDER" << endl;
	printPostorder(root);
}