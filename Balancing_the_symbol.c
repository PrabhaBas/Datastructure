#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct node
{
	char data;
	struct node *next;
};
bool isEmpty();
void push(char x);
char pop();
char peek();
struct node *root = NULL;
void push(char x)
{
	struct node *temp =(struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;
	temp->next = root;
	root = temp;
}
char pop()
{
	char elem;
	if(!isEmpty())
	{
		struct node *p;
		p = root;
		elem = p->data;
		root = p->next;
		p->next = NULL;
		free(p);
	}
	return(elem);
}
char peek()
{
	return root->data;
}
bool isEmpty()
{
	return root == NULL;
}
int main()
{
	if(func("[()]{}{[()()]()}") != 0)
	printf("Balanced\n");
	else
	printf("Unbalanced\n");
	
	if(func("[(])") != 0)
	printf("Balanced\n");
	else
	printf("Unbalanced\n");
	
	if(func("[][)]") != 0)
	printf("Balanced\n");
	else
	printf("Unbalanced\n");
	return 0;
}
int func(char *s)
{
	printf("%s\n",s);
	int i;
	char c;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i] =='['||s[i] == '{'|| s[i]=='(')
		{

			if(s[i] == '(')
			push(')');
			else if(s[i] == '{')
			push('}');
			else
			push(']');
		}
		else
		{
			if(pop()!= s[i])	
			return 0;
		
		}
	}
	if(!isEmpty())
	return 0;
	return 1;
}

