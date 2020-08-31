#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node Node;
Node *createNode(int data){
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void insert(Node **Head, int data){
	Node *temp = createNode(data);
	if(*Head == NULL){
		*Head = temp;
		return;
	}
	Node *i = *Head;
	while(i->next != NULL){
		i = i->next;
	}
	i->next = temp;
}
int getLength(Node *Head){
	int count = 0;
	while(Head->next){
		Head = Head->next;
		count++;
	}
	return count;
}
void deleteNode(Node **Head, int pos){
	int match = 0;
	Node *temp = *Head;
	if(pos > getLength(*Head) || pos < 0){
		printf("Error size!\n");
		return;
	}
	while(temp){
		Node *prev = temp;
		temp = temp->next;
		if(match+1 == pos){
			prev->next = temp->next;
			free(temp);
			return;
		}
		match++;
	}
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
	insert(&Head, 1); //0
	insert(&Head, 2); //1
	insert(&Head, 3); //2
	insert(&Head, 4); //3
	insert(&Head, 5); //4
	print(Head);
	deleteNode(&Head, 1);
	print(Head);
return 0;
}

