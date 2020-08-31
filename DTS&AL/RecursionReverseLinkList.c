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
Node* reverse(Node* head) { 
    if (head == NULL || head->next == NULL) 
        return head; 
    Node* rest = reverse(head->next); 
    head->next->next = head; 
    head->next = NULL; 
    return rest; 
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
	Head = reverse(Head);
	print(Head);
return 0;
}

