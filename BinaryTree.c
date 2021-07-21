#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
};
struct node* create();
void preOrder(struct node *);
void inOrder(struct node *);
void postOrder(struct node *);
int main()
{
	struct node *root;
	root = create();
	printf("\nThe preorder traversal of tree is:\n");
	preOrder(root);
	printf("\nThe inorder traversal of tree is:\n");
	inOrder(root);
	printf("\nThe postorder traversal of tree is:\n");
	postOrder(root);
	return 0;
}
struct node* create()
{
	int x;
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	printf("Enter Data & -1 for no data:\n");
	scanf("%d",&x);
	if(x == -1)
	return NULL;
	newNode->data = x;
	printf("Enter left child of %d\n",x);
	newNode->left = create();
	printf("Enter right child of %d\n",x);
	newNode->right = create();
	return newNode;
}
void preOrder(struct node *head) //Root-Left-Right
{
	if(head!=NULL)
	{
		printf("%d --> ",head->data);
		preOrder(head->left);
		preOrder(head->right);
	}
	
}
void inOrder(struct node *head)//Left-Root-Right
{
	if(head!=NULL)
	{
		inOrder(head->left);
		printf("%d --> ",head->data);
		inOrder(head->right);
	}
}
void postOrder(struct node *head)//Left-Right-Root
{
	if(head!=NULL)
	{
		postOrder(head->left);
		postOrder(head->right);
		printf("%d --> ",head->data);
	}
	
}

	
	



