#include<iostream>
#include<queue>
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

	return max(lt,rt)+1;
}

void printLevel(node *root){
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		node *f=q.front();
		cout << f->data << " ";
		q.pop();

		if(f->left!=NULL){
			q.push(f->left);
		}

		if(f->right!=NULL){
			q.push(f->right);
		}
	}
	
}

int main(){
	node *root=buildtree();
	print(root);
	cout << endl;
	printLevel(root);
}