#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack{
	int top;
	unsigned capicity;
	int *arr;
};
typedef struct stack Stack;
//Khoi tao 1 stack dung array
Stack *createStack(unsigned capicity){
	Stack *newStack = (Stack *)malloc(sizeof(Stack));
	newStack->capicity = capicity;
	newStack->top = -1;
	newStack->arr = (int *)malloc(newStack->capicity * sizeof(int));
	return newStack;
}
int isFull(Stack *stack){//Kiem tra stack day
	return stack->top == stack->capicity-1;
}
int isEmpty(Stack *stack){ //Kiem tra stack rong
	return stack->top == -1;
}
void push(Stack *stack, int item){//Them vao 1 item
	if(isFull(stack)){
		return;
	}
	stack->top++;
	stack->arr[stack->top] = item;	
}
int pop(Stack *stack){//Lay ra 1 item
	if(isEmpty(stack)){
		return -1;
	}
	return stack->arr[stack->top-1];
}
int peek(Stack *stack){// Tra ve item tren cung
	if(isEmpty(stack)){
		return -1;
	}
	return stack->arr[stack->top];	
}
int main(){
	Stack *stack = createStack(100);
	int i, n = 10, item;
	for(i=0;i<n;i++){
		printf("Item: ");
		scanf("%d", &item);
		push(stack, item);
	}
	for(i=0;i<=stack->top;i++){
		printf("%d | ", stack->arr[i]);
	}
return 0;
}

