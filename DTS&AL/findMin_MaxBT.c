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
int findMin(Node *root){
	if(root == NULL){
		printf("Empty Tree\n");
		return;
	}
	if(root->left == NULL) return root->data;
	return findMin(root->left);
}
int findMax(Node *root){
	if(root == NULL){
		printf("Empty Tree\n");
		return;
	}
	if(root->right == NULL) return root->data;
	return findMax(root->right);
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
	root = insert(root, 11);
	root = insert(root, 1);
	root = insert(root, 10);
	root = insert(root, 60);
	root = insert(root, 100);
	printf("%d \n", findMin(root));
	printf("%d \n", findMax(root));
return 0;
}

