#include<stdio.h>
#define size 10
int a[size];
int front =-1,rear=-1;
void enqueue(int x);
void dequeue();
void peek();
void isEmpty();
void isFull();
int main()
{
	int n,el;
	do
	{
		printf("1 - Enqueue\n");
		printf("2 - Dequeue\n");
		printf("3 - Peek\n");
		printf("4 - isEmpty\n");
		printf("5 - isFull\n");
		printf("6 - Exit\n");
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
				isEmpty();
				break;
			case 5 :
				isFull();
				break;
			case 6 :
				break;
			default :
				printf("Invalid choice\n");
		}
	}while(n!=6);

}
void enqueue(int x)
{
	if(rear + 1 == size)
	printf("Queue is Full!!\n");
	else
	{
		if(rear == -1){
			front = 0;
			a[++rear] = x;}
		else
			a[++rear] = x;
	}
}
void dequeue()
{
	if(rear == -1 || front >  rear)
	printf("Queue is Empty\n");
	else
	printf("%d\n",a[front++]);
}
void isEmpty()
{
	if(rear == -1 || front > rear)
	printf("Queue is Empty!!\n");
	else
	printf("Queue is not Empty\n");
}
void isFull()
{
	if(rear + 1 == size)
	printf("Queue is Full\n");
	else
	printf("Queue is not Full\n");
}
void peek()
{
	if(rear == -1 || front > rear)
	printf("Queue is Empty\n");
	else
	printf("Peek\t=%d\n",a[front]);
}

