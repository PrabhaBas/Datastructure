#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *link;
};
struct node *root=NULL;
void append(void);
int length(void); //prototype
void display(void);
void addaft(void);
void del(void);
void beg(void);
void reverse();
void swap(void);
int len;
int main()
{
	int n;
	while(1)
	{	
	printf("Append   = 1\n");
	printf("beg      = 2\n");
	printf("Addafter = 3\n");
	printf("Delete   = 4\n");
	printf("length   = 5\n");
	printf("Display  = 6\n");
	printf("Exit     = 7\n");
	printf("Reverse  = 8\n");
	printf("Swap  	 = 9\n");
	printf("Enter choice : ");
	scanf("%d",&n);
	switch(n)
	{
		
		case 1 :	
				append();
				break;

		case 2:
				beg();
				break;
		case 3:
				addaft();
				break;
		case 4:
				del();
				break;
		case 5 :
				len=length();
				printf("\nLength = %d\n\n",len);
				break;
		case 6:
				display();
				break;
		case 7:
			exit(1);
		case 8:
			reverse();
			break;
		case 9 : 
			swap();
			break;
		default :
				printf("\nInvalid choice\n\n");
	}
	}
	
}
void beg()
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	temp->link=root;
	root=temp;	
	
}
void swap()
{
	struct node *p,*q,*r;
	int i=1,loc;
	printf("Enter location : ");
	scanf("%d",&loc);
	p=root;
	while(i<loc-1)
	{
		p=p->link;
		i++;
	}
	q=p->link;
	r=q->link;
	q->link=r->link;
	r->link=q;
	p->link=r;
	
}
void append()
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data : \t");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL)
		root=temp;
	else
	{
		struct node *p;
		p=root;
		while(p->link!= NULL) // important p->link
			p=p->link;
			
		p->link=temp;
	}
}
void display()
{
	struct node *p;
	p=root;
	if(p==NULL)
	printf("\nList is empty\n\n");
	else
	{
		while(p!=NULL)
		{
		printf("%d--->",p->data);
		p=p->link;
		}
		printf("\n\n");
	}
}
int length()
{
	int c=0;
	struct node *p;
	p=root;
	while(p!=NULL)
	{
		c++;
		p=p->link;	
	}
	return c;
}
void addaft()
{
	int loc,len,i=1;
	struct node *temp,*p;
	printf("Enter location : ");
	scanf("%d",&loc);
	len=length();
	if(loc>len)
	printf("\nInvalid Location!!\n\n");
	else
	{
		p=root;
		while(i<loc)
		{
			p=p->link;
			i++;
		}
		temp=(struct node*)malloc(sizeof(struct node*));
		printf("Enter data : \n");
		scanf("%d",&temp->data);
		temp->link=NULL;
		temp->link=p->link;//right side connection is always 1st
		p->link=temp;
	}
		
}
void reverse()
{
	struct node*p,*q;
	int len,i,j,k,t;
	len=length();
	i=0;
	j=len-1;
	p=root;
	q=root;
	while(i<j)
	{
		k=0;
		while(k<j)
		{
			q=q->link;
			k++;
		}
		t=p->data;
		p->data=q->data;
		q->data=t;
		i++;
		j--;
		p=p->link;
		q=root;
	}
}
void del()
{
	int loc,len;
	struct node *temp;
	printf("Enter location : ");
	scanf("%d",&loc);
	len=length();
	if(loc>len)
	printf("\nInvalid location!!\n\n");
	else if(loc==1)
	{
		temp=root;
		root=temp->link;
		temp->link=NULL;
		free(temp);
		printf("\nDeleted successfully\n\n");
	}
	else
	{
		struct node *p;
		temp=root;
		int i=1;
		while(i<loc-1)
		{
			temp=temp->link;
			i++;
		}
		p=temp->link;
		temp->link=p->link;// left side connection cut
		p->link=NULL;//right side connnection cut
		free(p);
		printf("\nDeleted successfully\n");
	}
}

