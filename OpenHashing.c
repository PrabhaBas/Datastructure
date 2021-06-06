#include<stdio.h>
#include<stdlib.h>
#define size 7
struct node
{
	int data;
	struct node *next;
};
struct node *chain[size];
void init();
void insert(int);
void del(int);
void print();
void search(int);
int main()
{
	init();
	insert(7);
    insert(0);
    insert(3);
    insert(21);
    insert(14);
    insert(4);
    insert(5);
    print();
    search(14);
    search(2);
    search(5);
    del(21);
    print();
     
     
     
}
void init()
{
	int i;
	for(i=0;i<size;i++)
	chain[i] = NULL;
}
void insert(int x)
{
	int key;
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;
	key = x%size;
	if(chain[key] == NULL)
	{
	chain[key] = temp;
	printf("%d Inserted at chain[%d]\n",x,key);
	}
	else
	{
		struct node *p;
		p = chain[key];
		while(p->next)
			p = p->next;
		p->next = temp;
		printf("%d Inserted at chain[%d]\n",x,key);
	}
}
void print()
{
	int i;
	for(i=0;i<size;i++)
	{
		struct node *p = chain[i];
	printf("Chain[%d]-->",i);
	while(p)
	{
		printf("%d-->",p->data);
		p = p->next;
	}
	printf("NULL\n");
	}
}
void del(int x)
{
	int key = x % size;
	struct node *p = chain[key];
	if(p)
	{
	if(p->data == x)
	{
		chain[key] = p->next;
		printf("%d is Deleted\n",x);
		free(p);
	}
	else
	{
		struct node *q;
		q = p->next;
		while(q)
		{
			if(q->data == x)
			{
				p->next = q->next;
				printf("%d is Deleted\n",x);
				free(q);
				break;
			}
			q = q->next;
			p = p->next;
		}
			if(q == NULL)
		printf("Value no Found\n");
	}
	}
	else
	printf("Value no Found\n");
}

void search(int x)
{
	int key = x % size;
	struct node *p = chain[key];
	while(p)
	{
		if(p->data == x)
		{
		printf("%d is Found at chain[%d]\n",x,key);
		break;
		}
		p = p->next;
	}
	if(p == NULL)
	printf("Value not Found\n");
}

