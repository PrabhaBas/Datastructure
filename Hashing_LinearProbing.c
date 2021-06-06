#include<stdio.h>
#define size 10
int a[size];
void init();
void insert(int);
void del(int);
void search(int);
int main()
{
	init();
	printf("-----------Hash Table-----------\n");
	insert(10);
	insert(4);
	insert(20);
	insert(30);
	insert(17);
	insert(40);
	search(3);
	search(17);
	del(2);
	search(40);
	
}
void init()
{
	int i;
	for(i=0;i<size;i++)
	a[i] = -1;
}
void insert(int x)
{
	int key;
	key = x%size;
	if(a[key] == -1)
	{
	printf("%d inserted at index %d\n",x,key);
	a[key] = x;
	}
	else
	{
		printf("/-----Collision Occurs-----/\n");
		int i=1,f=0;
		do
		{
		i = (key+i)%size;
		if(i<size & a[i] == -1)
		{
		a[i] = x;
		printf("%d inserted at index %d\n",x,i);
		f=1;
		}
		i++;
		}while(i<size & f==0);
		if(f==0)
		printf("Can't Insert data\n");
	}
}
void del(int value)
{
	int key = value % size;
	if(a[key] == value)
	{
	a[key] = -1;
	printf("%d - deleted\n",value);
	}
	else
	printf("Value is not present\n");
}
void search(int x)
{
	int key = x % size;
	if(a[key] == x)
	printf("Value found at the index : %d\n",key);
	else
	printf("Value not found\n");
}

