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

	int lh=height(root->left);
	int rh=height(root->right);

	return max(lh,rh)+1;
}

void printKthLevel(node *root,int k){
	if(root==NULL){
		return;
	}
	if(k==1){
		cout << root->data << " ";
		return;
	}
	printKthLevel(root->left,k-1);
	printKthLevel(root->right,k-1);

}

void printAllLevel(node *root){
	int h=height(root);

	for(int i=1;i<=h;i++){
		printKthLevel(root,i);
		cout << endl;
	}
}

int main(){
	node *root=buildtree();

	print(root);
	cout << endl;

	cout << height(root) << endl;

	printAllLevel(root);
}
