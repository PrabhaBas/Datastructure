#include<stdio.h>
#define MAX 1000
int hash[MAX][2];
void insert(int* a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i] > 0)
		hash[a[i]][0] = a[i];
		else
		hash[ abs(a[i]) ][1] = a[i] ;
	}
}
void search(int x)
{
	if(x >= 0)
	{
		if(hash[x][0] == x)
		printf("%d is Present at index [%d][%d]\n",hash[x][0] ,x,0);
		else
		printf("%d is not present\n",x);
	}
	else
	{
		if(hash[abs(x)][1] == x)
			printf("%d is Present at index [%d][%d]\n",hash[x][1] ,x,1);
		else
		printf("%d is not present\n",x);
	}
	
}
int main()
{
	int a[15],n,i;
	printf("Enter n\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("Enter %d element\n",i+1);
	scanf("%d",&a[i]);
	}
	insert(a,n);
	search(1);
	search(300);
	search(10);
	return 0;	
}

