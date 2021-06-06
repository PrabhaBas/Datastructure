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
	insert(10);
	insert(4);
	insert(3);
	insert(2);
	insert(17);
	
	printf("-----------Hash Table-----------\n");
	search(3);
	search(17);
	del(2);
	search(2);
	
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
	a[key] = x;
	else
	printf("Collision \n");
}
void del(int value)
{
	int key = value % size;
	if(a[key] == value)
	{
	a[key] = -1;
	printf("Value %d deleted\n",value);
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

