#include<stdio.h>
# define N 5
int dequeue[N];
int f = -1, r= -1;
void enqueueFront(int);
void enqueueRear(int);
void dequeueFront()
void dequeueRear();
int getFront();
int getRear();
int isEmpty();
int isFull();
void display();

int main()
{
	printf("IsEmpty   %d\n",isEmpty());
	
	printf("Isfull   %d\n",isFull());
	enqueueFront(10);
	display();
	enqueueFront(20);
		display();
	enqueueFront(30);
		display();
		enqueueFront(40);
			display();
			enqueueFront(50);
				display();
				return 0;
}
int isEmpty()
{
	return r == -1 ; 
}
int isFull()
{
	return (r+1)%N == f ; // front  = rear+1 or rear = front -1
}

void dequeueFront()
{
	if(isEmpty())
	printf("Queue is Empty\n");
	else if(f==0)
	f=N-1;
	else
	f++;
}
void dequeueRear()
{
	if(isEmpty())
	printf("Queue is Full\n");
	else if(r==N-1)
	r=0;
	else
	r--;
}
void enqueueFront(int x)
{
	if(isFull())
	printf("Queue is Full\n");
	else if(f==0)
	{
	f=N-1;
	dequeue[f]  = x
	}
	else
	dequeue[--f] = x ;
}


void enqueueRear(int x)
{
	if(isFull())
	printf("Queue is Full\n");
	else if(r==N-1)
	{
	r = 0;
	dequeue[r]  = x
	}
	else
	dequeue[++r] = x ;
}

void display()
{
	int i = f;
	while(i!=r)
	{
		printf("%d   ",dequeue[i]);
		i = (i+1)%N;
	}
	printf("%d   \n",dequeue[r]);
}
int getFront()
{
	return dequeue[f];
}
int getRear()
{
	return dequeue[r];
}

