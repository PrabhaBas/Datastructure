#include<stdio.h>
#define size 10
// stack creation 
int s[size];
int top = -1;
// stack functions
void push(int);
void pop();
void peek();
int isFull();
int isEmpty();
int main()
{
	int n,elem;
	do{
	printf("1 - Push\n2 - Pop\n3 - Peek\n4 - Exit\n");
	printf("Enter your choice : \n");
	scanf("%d",&n);
	switch(n)
	{
		case 1 :
			printf("Enter element : \n");
			scanf("%d",&elem);
			push(elem);
			break;
		case 2 :
			pop();
			break;







		case 3 :
			peek();
			break;
		case 4 :
			break;
		default :
			printf("Invalid choice\n");
	}
}while(n != 4);	
}
void push(int element)
{
	if(isFull())
	printf("Stack is full\n");
	else
	s[++top] = element;
}
void pop()
{
	if(isEmpty())
	printf("Stack is Empty\n");
	else
	printf("Popped element : %d\n",s[top--]);
}
void peek()
{
	if(isEmpty())
	printf("Stack is Empty\n");
	else
	printf("Peek element : %d\n",s[top]);
}
int isFull()
{
	return top+1 == size;
}
int isEmpty()
{
	return top == -1;
}

