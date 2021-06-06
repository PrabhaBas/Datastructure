#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
struct node *front,*rear = NULL;
void enqueue(int);
void dequeue();
void peek();
void display();
int main()
{
enqueue(10);
display();
enqueue(20);
display();
dequeue();
display();
dequeue();
display();


return 0;	
}

void enqueue(int x)
{
	struct node *temp= (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;
	if(rear==NULL)
	{
		front =temp;
		rear = temp;
		rear->next = front;
	}
	else
	{
		rear->next = temp;
		rear = temp;
		rear->next = front;
	}
	
	printf("Enqueued\n");
	
}
void dequeue()
{
	if(rear == NULL)
	printf("Queue is Empty\n");
	else
	{
		struct node *p = front;
		if(front==rear)
		{
			front=NULL;
			rear=NULL;
			free(p);
		}
		else
		{
			front = p->next;
			p->next = NULL;
			free(p);
			rear->next = front;
			
		}
	}
	printf("Dequeued\n");
}
void peek()
{
	if(rear == NULL)
	printf("Queue is Empty\n");
	else
	printf("Peek  =  %d\n",front->data);
}
void display()
{
	if(rear == NULL)
	printf("Queue is Empty\n");
	else
	{
		struct node *p =front;
		while(p->next != front)
		{
			printf("%d   ",p->data);
			p = p->next;
		}
		printf("%d   \n",p->data);	
		
	}
}

