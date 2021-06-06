#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *front = NULL;
struct node *rear  = NULL;
void enqueue(int);
void dequeue();
int isEmpty();
void peek();
int main()
{
	int n,el;
	do
	{
		printf("1 - Enqueue\n");
		printf("2 - Dequeue\n");
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
				enqueue(el);
				break;
			case 2 :
				dequeue();
				break;
			case 3 :
				peek();
				break;
			case 4 :
				printf("Empty ? %d\n",isEmpty());
				break;
			case 5 :
				break;
			default :
				printf(
				"Invalid choice\n");
		}
	}while(n!=5);
}
void enqueue(int x)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;
	if(rear == NULL)
	{
		front = temp;
		rear  = temp;
	}
	else
	{
		rear->next = temp;
		rear = temp;
	}
}
void dequeue()
{
	if(isEmpty())
	printf("Queue is Empty\n");
	else // 2 possibilities 
	{
		if(front == rear)
		{
			printf("Dequeue value\t:%d\n",front->data);
			free(front);
			front = NULL;
			rear = NULL;
		}
		else
		{
			struct node *p;
			p = front;
			printf("Dequeue value\t:%d\n",p->data);
			front = p->next;
			p->next = NULL;
			free(p);
		}
	}
}
int isEmpty()
{
	return rear == NULL;
}
void peek()
{
	if(isEmpty())
	printf("Queue is Empty\n");
	else
	printf("%d\n",front->data);
}

