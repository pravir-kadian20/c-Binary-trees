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

node *buildTreeFromPreAndIn(int *pre,int *io,int s,int e){

	static int i=0;//to prevent i to backtrack

	//base case
	if(s>e){
		return NULL;
	}

	//recursive case
	node *root=new node(pre[i]);

	int index;

	for(int j=s;j<=e;j++){
		if(io[j]==pre[i]){
			index=j;
			break;
		}
	}
	i++;

	root->left=buildTreeFromPreAndIn(pre,io,s,index-1);
	root->right=buildTreeFromPreAndIn(pre,io,index+1,e);

	return root;
}

void printPreOrder(node *root){
	if(root==NULL){
		return;
	}

	cout << root->data << " ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}

int main(){
	int pre[]={1,2,3,4,8,5,6,7};
	int io[]={3,2,8,4,1,6,7,5};

	int n=sizeof(pre)/sizeof(int);
	node *root=buildTreeFromPreAndIn(pre,io,0,n-1);
	printPreOrder(root);
	cout << endl;

	return 0;
}