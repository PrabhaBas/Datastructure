#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
struct node *root = NULL;
void push(int x);
void pop();
void isEmpty();
void peek();
int main()
{
	int n,el;
	do
	{
		printf("1 - Push\n");
		printf("2 - Pop\n");
		printf("3 - Peek\n");
		printf("4 - isEmpty\n");
		printf("5 - Exit\n");
		printf("Enter your chioce :\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1 :
				printf("Enter elem to push\n");
				scanf("%d",&el);
				push(el);
				break;
			case 2 :
				pop();
				break;
			case 3 :
				peek();
				break;
			case 4 :
				isEmpty();
				break;
			case 5 :
				break;
			default :
				printf("Invalid choice\n");
		}
	}while(n!=5);
}
void push(int x)
{
	struct node *temp =(struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;
	temp->next = root;
	root = temp;	
}
void pop()
{
	int elem;
	if(root == NULL)
	printf("Stack is Empty\n");
	else
	{
		struct node *p;
		p = root;
		elem = p->data;
		root = p->next;
		p->next = NULL;
		free(p);
		printf("%d\n",elem);
	}
}
int peek()
{
	if(root == NULL)
	printf("Stack is Empty\n");
	return root->data;
}
void isEmpty()
{
	if(root == NULL)
	printf("Stack is Empty\n");
	else
	printf("Stack is not Empty\n");
}

