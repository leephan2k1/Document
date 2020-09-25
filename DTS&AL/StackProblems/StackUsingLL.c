#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node Node;
Node *createNode(int data){
	Node *newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void push(Node **Root, int data){
	Node *newNode = createNode(data);
	newNode->next = *Root;
	*Root = newNode;
}
void pop(Node **Root){
	if(*Root == NULL){
		printf("Empty Stack!\n");
		return;
	}
	Node *temp = *Root;
	*Root = (*Root)->next;
	free(temp);
}
void print(Node *Root){
	while(Root){
		printf("%d ", Root->data);
		Root = Root->next;
	}
	printf("\n");
}

