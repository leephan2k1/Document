#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// Circular Link List
struct node{
	int data;
	struct node *next;
};
typedef struct node Node;
void push(Node **Head, int data){
	Node *temp = (Node *)malloc(sizeof(Node));
	Node *traversal = *Head;
	temp->data = data;
	temp->next = *Head;
	if(*Head == NULL){
		temp->next = temp;
		*Head = temp;
		return;
	}
	while(traversal->next != *Head){
		traversal = traversal->next;
	}
	traversal->next = temp;
	*Head = temp;
}
void printList(Node *head) 
{ 
    Node *temp = head; 
    if (head != NULL) 
    { 
        do
        { 
            printf("%d ", temp->data); 
            temp = temp->next; 
        } 
        while (temp != head); 
    } 
} 
int main(){
	Node *Head = NULL;
	push(&Head,1);
	push(&Head,2);
	push(&Head,3);
	push(&Head,4);
	push(&Head,5);
	printList(Head);
return 0;
}

