#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node Node;
Node *createNode(int data){
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = newNode->prev = NULL;
	return newNode;
}
void insert(Node **Head, int data){
	Node *temp = createNode(data);
	temp->prev = *Head;
	if(*Head == NULL){
		*Head = temp;
		return;
	}
	Node *i = *Head;
	while(i->next != NULL){
		i = i->next;
	}
	i->next = temp;	
	temp->prev = i;

}
void reverseDouble(Node **Head){
	Node *Prev = NULL;
	Node *Current = *Head;
	Node *Next;
	while(Current != NULL){
		Next = Current->next;
		Current->next = Prev;
		Current->prev = Next;
		Prev = Current;
		Current = Next;
	}
	*Head = Prev;
	(*Head)->prev = NULL;
}

void print(Node *Head){
	while(Head){
		printf("%d ", Head->data);
		Head = Head->next;
	}
	printf("\n");
}
int main(){
	Node *Head = NULL;
	insert(&Head, 1);
	insert(&Head, 2);
	insert(&Head, 3);
	insert(&Head, 4);
	insert(&Head, 5);
	print(Head);
	reverseDouble(&Head);
	print(Head);
return 0;
}

