#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
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

void print(Node *Head){
	while(Head->next != NULL){
		printf("%c -> ", Head->data);
		Head = Head->next;
	}
	printf("NULL\n");
}
bool control(Node **Left, Node *Right){
	if(Right == NULL) return true;
	bool isp = control(Left, Right->next);
	if(isp == false) return false;
	bool isp1 = (Right->data == (*Left)->data);
	*Left = (*Left)->next;
	return isp1;
}
bool isPalindrome(Node *Head){
	control(&Head, Head);
}
int main(){
	Node *Head = NULL;
	char s[] = "abcba";
	int i;
	for(i=0;i<strlen(s); i++){
		insert(&Head, s[i]);
	}
	print(Head);
	if(isPalindrome(Head)) printf("Palindrome!");
	else printf("Not Palindrome!");
return 0;
}

