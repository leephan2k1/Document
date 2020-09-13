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
void push(Node **Head, int data){
	Node *newNode = createNode(data);
	Node *trv = *Head;
	if(*Head == NULL){
		*Head = newNode;
		return;
	}
	while(trv->next){
		trv = trv->next;
	}
	trv->next = newNode;
}
void FrontBackSplit(Node *source, Node **frontRef, Node **backRef){
	Node *fast;
	Node *slow;
	slow = source;
	fast = source->next;
	while(fast){
		fast = fast->next;
		if(fast){
			slow = slow->next;
			fast = fast->next;
		}
	}
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}
Node *SortedMerge(Node *a, Node *b){
	Node *res = NULL;
	while(a && b){
		if(a->data <= b->data){
			push(&res, a->data);
			a = a->next;
		}else{
			push(&res, b->data);
			b = b->next;
		}
	}
	while(a){
		push(&res, a->data);
		a = a->next;
	}
	while(b){
		push(&res, b->data);
		b = b->next;
	}
	return (res);
}
//De quy
//Node* SortedMerge(Node* a,   Node* b) 
//{ 
//      Node* result = NULL; 
//  
//    /* Base cases */
//    if (a == NULL) 
//        return (b); 
//    else if (b == NULL) 
//        return (a); 
//  
//    /* Pick either a or b, and recur */
//    if (a->data <= b->data) { 
//        result = a; 
//        result->next = SortedMerge(a->next, b); 
//    } 
//    else { 
//        result = b; 
//        result->next = SortedMerge(a, b->next); 
//    } 
//    return (result); 
//} 
void MergeSort(Node **headRef){
	Node *head = *headRef;
	Node *a;
	Node *b;
	if((head == NULL) || (head->next == NULL)){ // length == 0 hoac == 1
		return;
	}
	FrontBackSplit(head, &a, &b);
	
	MergeSort(&a);
	MergeSort(&b);
	
	*headRef = SortedMerge(a,b);
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
	push(&Head, 5);
	push(&Head, 2);
	push(&Head, 1);
	push(&Head, 4);
	push(&Head, 10);
	push(&Head, 0);
	MergeSort(&Head);
	print(Head);
return 0;
}

