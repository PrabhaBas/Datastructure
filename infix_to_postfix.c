#include<stdio.h>
#include<string.h>
#define size 20 
char s[size];
int top = -1;
char con[size]="";
void push(int);
char pop();
char peek();
int isFull();
int isEmpty();
void InToFix(char *);
int prec(char);
int main()
{
	InToFix("A*B+(C-D/E)#");
	printf("%s\n",con);
	return 0;
}
void InToFix(char *str)
{
	int i;char r;
	for(i=0;i<strlen(str);i++)
	{
		if(str[i] >= 'A' & str[i] <= 'Z')
		strncat(con,&str[i],1);
		else if(str[i] =='(')
		push(str[i]);
		else if(str[i]==')')
			while(!isEmpty())
			{
			r=pop();
			if(r=='(') break;	
			strncat(con,&r,1);
			}
		else
		{
			while(!isEmpty() & prec(str[i]) <= prec(peek()))
			{				
			r= pop();
			strncat(con,&r,1);
			}
			push(str[i]);			
		}
		if(str[i] == '#')
		break;
	}
}
int prec(char h)
{
	switch(h)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
	}
	return -1;
}
void push(int element)
{
	s[++top] = element;
}
char pop()
{
	return s[top--];
}
char peek()
{
	return s[top];
}

int isFull()
{
	return top+1 == size;
}
int isEmpty()
{
	return top == -1;
}

