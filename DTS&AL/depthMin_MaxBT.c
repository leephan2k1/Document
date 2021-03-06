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
int max(int x, int y){
	if(x>y) return x;
	else return y;
}
int min(int x, int y){
	if(x<y) return x;
	else return y;
}
int depthMax(Node *root){
	if(root == NULL){
		return -1;
	}
	return max(depthMax(root->left), depthMax(root->right))+1;
}
int depthMin(Node *root){
	if(root == NULL){
		return -1;
	}
	return min(depthMin(root->left),depthMin(root->right))+1;
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
	root = insert(root, 0);
	root = insert(root, 10);
	root = insert(root, 60);
	root = insert(root, 100);
	root = insert(root, 5);
	root = insert(root, 101);
	root = insert(root, 102);
	printf("depth Max: %d \n", depthMax(root));
	printf("depth Min: %d \n", depthMin(root));
return 0;
}

