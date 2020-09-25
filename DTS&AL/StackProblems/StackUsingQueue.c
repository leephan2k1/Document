#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "Queue.c"
typedef struct{
	Queue *q1, *q2;
}Stack;
Stack *createStack(){
	Stack *s = malloc(sizeof(Stack));
	s->q1 = createQueue();
	s->q2 = createQueue();
	return s;
}
// Implement Method 1: Push costly
//void push(Stack *s, int data){
//	enQueue(&s->q2, data);
//	while(!isEmpty(s->q1)){
//		enQueue(&s->q2, s->q1->front->data);
//		deQueue(&s->q1);
//	}
//	Queue *q = s->q1;
//	s->q1 = s->q2;
//	s->q2 = q;
//}
//void pop(Stack *s){
//	deQueue(&s->q1);
//}

// Implement Method 2: Pop costly
void push(Stack *s, int data){
	enQueue(&s->q1, data);
}
void pop(Stack *s){
	if(isEmpty(s->q1)){
		printf("Empty Stack!\n");
		return;
	}
	while(s->q1->front->next){
		enQueue(&s->q2, s->q1->front->data);
		deQueue(&s->q1);
	}
	deQueue(&s->q1);
	Queue *q = s->q1;
	s->q1 = s->q2;
	s->q2 = q;
}
int main(){
	Stack *Root = createStack();
	push(Root, 2);
	push(Root, 3);
	push(Root, 4);
	print(Root->q1->front);
	pop(Root);
	print(Root->q1->front);
	push(Root, 4);
	print(Root->q1->front);
return 0;
}

