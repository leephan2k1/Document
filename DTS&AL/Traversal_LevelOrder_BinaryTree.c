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
struct QNODE{
	Node *element;
	struct QNODE *next;
};
typedef struct QNODE qNode;
typedef struct{
	qNode *rear, *front;
}Queue;
Queue *createQueue(){
	Queue *newQueue = (Queue *)malloc(sizeof(Queue));
	newQueue->front = newQueue->rear = NULL;
	return newQueue;
}
void enQueue(Queue *q, Node *root){
	qNode *newNode = (qNode *)malloc(sizeof(qNode));
	newNode->element = root;
	newNode->next = NULL;
	if(q->rear == NULL){
		q->rear = q->front = newNode;
		return;
	}
	q->rear->next = newNode;
	q->rear = newNode;
}
void deQueue(Queue *q){
	if(q->front == NULL) return;
	qNode *temp = q->front;
	q->front = q->front->next;
	if(q->front == NULL){
		q->rear = NULL;
	}
	free(temp);
}
int Empty(Queue *q){
	return q->front == NULL;
}
Node *createNode(int data){
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void print(Node *root){
	if(root != NULL){
		printf(" %d ", root->data);
		print(root->left);
		print(root->right);
	}
}
void levelOrder(Node *root){
	Queue *q = createQueue();
	enQueue(q, root);
	while(!Empty(q)){
		qNode *Current = q->front;
		printf("%d ", Current->element->data);
		if(Current->element->left != NULL) enQueue(q, Current->element->left);
		if(Current->element->right != NULL) enQueue(q, Current->element->right);
		deQueue(q);
	}
}
int main(){
	Node *root = NULL;
	root = createNode(2);
	root->left = createNode(7);
	root->left->left = createNode(2);
	root->left->right = createNode(6);
	root->left->right->left = createNode(5);
	root->left->right->right = createNode(11);
	root->right = createNode(5);
	root->right->right = createNode(9);
	root->right->right->left = createNode(4);

/*							Traversal Level Order
			2                 		 2--->
		   /\		             	   /
		 7   5             		   7------->5
		/\    \               		   /
	   2 6    9		           2--->6--------->9
	    /\    /				             /
	   5 11  4                  5------>11------>4
*/
	levelOrder(root);
return 0;
}

