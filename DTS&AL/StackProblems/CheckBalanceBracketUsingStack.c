#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	char data;
	struct node *next;
};
typedef struct node Node;
Node *createNode(char data){
	Node *newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void push(Node **Root, char data){
	Node *newNode = createNode(data);
	newNode->next = *Root;
	*Root = newNode;
}
void pop(Node **Root){
	Node *temp = *Root;
	*Root = (*Root)->next;
	free(temp);
}
char peek(Node *Root){
	return Root->data;
}
int isEmpty(Node *Root){
	return Root == NULL;
}
int isMatching(char c1, char c2){
	if(c1 == '(' && c2 == ')') return 1;
	if(c1 == '{' && c2 == '}') return 1;
	if(c1 == '[' && c2 == ']') return 1;
	return 0;
}
int isBalance(char *s){
	int i;
	Node *Root = NULL;
	while(s[i]){
		if(s[i] == '(' || s[i] == '{' || s[i] == '[') push(&Root, s[i]);
		if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
			if(Root == NULL) return 0;
			if(isMatching( peek(Root), s[i]) ) pop(&Root);
			else return 0;
		}
		++i;
	}
	if(isEmpty(Root)) return 1;
	return 0;
}
void print(Node *root){
	while(root){
		printf("%c ", root->data);
		root = root->next;
	}
	printf("\n");
}
int main(){
	char s[] = "{([])}";
	if(isBalance(s)) printf("Chuoi can bang\n");
	else printf("Chuoi khong can bang\n");
	
return 0;
}

