#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// complexcity : O(n).
struct node{
	char data;
	struct node *next;
};
typedef struct node Node;
void insert(Node **Head, char value){
	Node *p;
	p = (Node *)malloc(sizeof(Node));
	p->data = value;
	p->next = NULL;
	if(*Head == NULL){
		*Head = p;
		return;
	}
	Node *i = *Head;
	while(i->next != NULL){
		i = i->next;
	}
	i->next = p;
	return;
}
int getLength(Node *Head){
	int count = 0;
	while(Head->next){
		Head = Head->next;
		count++;
	}
	return count;
}
void push(Node **Root, char data){
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	temp->next = *Root;
	*Root = temp;
}
void Stack(Node **Root, Node *Head){
	int match = 0;
	while(Head){
		if(match > (getLength(Head)/2)+1){
			push(&(*Root),Head->data);
		}
		match++;
		Head = Head->next;
	}
}
int isPalindrome(Node *Head){
	Node *Root = NULL;
	Stack(&Root, Head);
	while(Root->next){
		if(Root->data != Head->data) return 0;
		Head = Head->next;
		Root = Root->next;
	}
	return 1;
}
int main(){
	Node *Head = NULL;
	char s[] = "123211";
	int i;
	for(i=0;i<strlen(s); i++){
		insert(&Head, s[i]);
	}
	if(isPalindrome(Head)) printf("Sequence is Palindrome!\n");
	else printf("Sequence is not Palindrome!\n");
return 0;
}

