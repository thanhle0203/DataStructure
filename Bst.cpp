#include <iostream>
using namespace std;
//Implementation Binary Search Tree in C/C++
struct BstNode{
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* GetNewNode(int data){
	BstNode* newNode = new BstNode();
	newNode -> data = data;
	newNode -> left = newNode -> right = NULL;
	return newNode;
}
BstNode* Insert(BstNode* root, int data){
	if (root == NULL) {//empty tree
		root = GetNewNode(data);
		return root;
	}else if(data <= root->data){
		root->left = Insert(root->left, data);
	}else{
		root->right = Insert(root->right, data);
	}
	return root;
}
void display(BstNode* root){
	if (root!=NULL)
	{
		display(root->left);
		cout<<root->data<<" ";
		display(root->right);
	}
}
bool Search(BstNode* root, int data){
	if (root == NULL) return false;
	else if (root->data == data) 
		return true;
	else if (data <= root->data) 
		return Search(root->left, data);
	else 
		return Search(root->right, data);
}
int FindMin(BstNode* root){
	if (root == NULL){
		cout<<"Error: Tree is empty\n";
		return -1;
	}else if(root->left == NULL){
		return root->data;
	}
	//Search in left subtree
	return FindMin(root->left);
}
int FindMax(BstNode* root){
	if (root == NULL){
		cout<<"Error: Tree is empty\n";
		return -1;
	}else if (root->right == NULL){
		return root->data;
	}
	//Search in right subtree
	return FindMax(root->right);
}
int main(){	
	BstNode* root = NULL; //Setting a tree as empty
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);

	cout<<"Inorder traversal of the given tree\n";
	display(root);
	cout<<endl;

	int number;
	cout<<"Enter a numner to search\n";
	cin>>number;
	if(Search(root, number) == true)
		cout<<"Found\n";
	else
		cout<<"Not Found\n";

	cout<<"Min of Tree is "<<FindMin(root)<<endl;
	cout<<"Max of Tree is "<<FindMax(root)<<endl;

	return 0;
}

