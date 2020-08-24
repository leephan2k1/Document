#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Binary Tree
struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node Node;
Node *createNode(int data){
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
Node *insert(Node *root, int data){
	if(root == NULL){
		root = createNode(data);
	}else if(data <= root->data){
		root->left = insert(root->left, data);
	}else{
		root->right = insert(root->right, data);
	}
	return root;
}
int search(Node *root, int data){
	if(root == NULL) return 0;
	else if(root->data == data) return 1;
	else if(data <= root->data) return search(root->left, data);
	else return search(root->right, data);
}
void print(Node *root){
	if(root != NULL){
		printf(" %d ", root->data);
		print(root->left);
		print(root->right);
	}
}
int main(){
	Node *root = NULL;
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 5);
	root = insert(root, 25);
//	print(root);
	printf("%d ", search(root, 4));
return 0;
}

