#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Stack: Push, Pop, DeleteMiddle, FindMiddle 0(1).
struct node{
	int data;
	struct node *next, *prev;
};
typedef struct node Node;
typedef struct{
	Node *Head;
	Node *Mid;
	int count;
}Stack;
void createStack(Stack **Root){
	*Root = malloc(sizeof(Stack));
	(*Root)->Head = (*Root)->Mid = NULL;
	(*Root)->count = 0;
}
Node *createNode(int data){
	Node *newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = newNode->prev = NULL;
	return newNode;
}
void push(Stack *Root, int data){
	Node *newNode = createNode(data);
	newNode->next = Root->Head;
	Root->count ++;
	if(	Root->count == 1	){
		Root->Mid = newNode;
	}else{
		Root->Head->prev = newNode;
		if(	Root->count & 1 ){
			Root->Mid = Root->Mid->prev;
		}
	}
	Root->Head = newNode;
}
void pop(Stack *Root){
	Node *temp = Root->Head;
	Root->Head = Root->Head->next;
	if(Root->Head != NULL){
		Root->Head->prev = NULL;
	}
	Root->count--;
	if(Root->count % 2 == 0){
		Root->Mid = Root->Mid->next;
	}
	free(temp);
}
void print(Node *Root){
	Node *tmp = Root;
	while(tmp){
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}
int findMidlle(Stack *Root){
	if(Root->count == 0) return -1;
	return Root->Mid->data;
}
void deleteMiddle(Stack *Root){
	if(Root->count == 1){
		pop(Root);
		return;
	}
	Node *temp = Root->Mid;
	Root->Mid->next->prev = Root->Mid->prev;
	Root->Mid->prev->next = Root->Mid->next;
	free(temp);
}
int main(){
	Stack *Root = NULL;
	createStack(&Root);
	push(Root, 1);
	push(Root, 2);
	push(Root, 3);
	push(Root, 4);
	push(Root, 5);
	print(Root->Head);
	printf("MIDDLE ELEMENT: %d\n", findMidlle(Root));
	pop(Root);
	print(Root->Head);
	printf("MIDDLE ELEMENT: %d\n", findMidlle(Root));
	deleteMiddle(Root);
	print(Root->Head);
return 0;
}

