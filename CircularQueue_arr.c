#include<stdio.h>
# define N 5
int queue[N];
int front = -1;
int rear = -1;
void enqueue();
void dequeue();
void display();
int isEmpty();
int isFull();
void peek();

int main()
{
	printf("IsEmpty -- %d\n",isEmpty());
	printf("IsFull -- %d\n",isFull());
	enqueue(10);
	enqueue(20);
	enqueue(30);
	display();
	dequeue();
		dequeue();
		display();
		peek();
		printf("front  == %d\nrear == %d\n",front,rear);
	
			dequeue();
		printf("front  == %d\nrear == %d\n",front,rear);
	
	return 0 ;

}
void enqueue(int x)
{
	if(isFull())
	printf("Queue is full\n");
	else
	{
		if(rear == -1)
		{
			front = 0 ;
			queue[++rear]  = x;
		}
		else
		{
			rear = (rear+1)%N;
			queue[rear]  = x;
		}
	}
}
void dequeue()
{
	if(isEmpty())
	printf("Queue is Empty\n");
	else
	{
		if(front == rear)
		{
			front =-1;
			rear = -1;
		}
		else
		front = (front+1)%N;		
	}
	
}
void peek()
{
	printf("Peek is  %d\n",queue[front]);
}
void display()
{
	int i;
	if(isEmpty())
	printf("Queue is Empty\n");
	else
	{
	for(i=front ; i!=rear ; i = (i+1)%N)
		printf("%d   ",queue[i]);
	printf("%d\n",queue[rear]);
	}
}
int isEmpty()
{
	return rear == -1;
}
int isFull()
{
	return (rear+1)%N == front;
}

