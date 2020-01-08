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

	int ls=height(root->left);
	int rs=height(root->right);

	return max(ls,rs)+1;
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
	node *root=buildtree();
	print(root);
	cout << endl;
	cout << "HEIGHT OF THE BINARY TREE IS:" << endl;
	cout << height(root) << endl;
}