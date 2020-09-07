#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node Node;
Node *CreateNode(int data){
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void push(Node **Head, int data){
	Node *temp = CreateNode(data);
	temp->next = *Head;
	if(*Head == NULL){
		 temp->next = temp;
		 *Head = temp;
		 return;
	}
	Node *trv = *Head;
	while(trv->next != *Head){
		trv = trv->next;
	}
	trv->next =temp;
	*Head = temp;
}
void print(Node *Head){
	if(Head == NULL){
		printf("Empty!\n");
		return;
	}else{
		Node *trv = Head;
		do{
			printf("%d ", trv->data);
			trv = trv->next;
		}while(trv != Head);
			printf("\n");
	}
}
void Delete(Node **Head, int value){
	Node *trv = *Head;
	Node *temp;
	//Kiem tra link list chi co 1 nut
	if( (*Head)->next == *Head && trv->data == value){
		 *Head = NULL;
		 return;
	}
	//Link list co hon 1 nut
	if(trv->data == value){
		temp = *Head;
		while(trv->next != *Head){
			trv = trv->next;
		}
		trv->next = (*Head)->next;
		*Head = (*Head)->next;
		free(temp);	
	}else{
		Node *prev;
		while(trv->data != value){
			prev = trv;
			trv = trv->next;
			if(trv->next == *Head && trv->data != value){
				printf("Not found!\n");
				return;
			}
		}
		temp = trv;
		prev->next = trv->next;
		free(temp);
	}
}
int main(){
	Node *Head = NULL;
	push(&Head, 2);
	push(&Head, 3);
	push(&Head, 5);
	push(&Head, 7);
	print(Head);
	Delete(&Head, 1);
	print(Head);
	Delete(&Head, 2);
	print(Head);
	Delete(&Head, 3);
	print(Head);
	Delete(&Head, 5);
	print(Head);
	Delete(&Head, 7);
	print(Head);
return 0;
}

