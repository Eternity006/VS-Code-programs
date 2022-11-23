#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct bs_tree
{
	int data;
	struct bs_tree *left, *right;
}bs;
void initialise(bs **aar)
{
	*aar=NULL;
}
void recinsert(bs **aar, int n)
{
	if(*aar == NULL)
	{
		*aar=(bs*)malloc(sizeof(bs));
		(*aar)->data=n;
		(*aar)->left=(*aar)->right=NULL;
	}
	else if(n<(*aar)->data)
	{
		recinsert(&((*aar)->left), n);
	}
	else
		recinsert(&((*aar)->right), n);
}
void preorder(bs*ar)
{
	if(ar)
	{
		printf("%d ", ar->data);
		preorder(ar->left);
		preorder(ar->right);
	}
}
void postorder(bs*ar)
{
	if(ar)
	{
		postorder(ar->left);
		postorder(ar->right);
		printf("%d ", ar->data);
	}
}
void inorder(bs*ar)
{
	if(ar)
	{
		inorder(ar->left);
		printf("%d ", ar->data);
		inorder(ar->right);
	}
}
int height(bs *t)
{
	if(t==NULL)
	{
		return 0;
	}
	else
		return (1+max(height(t->left),height(t->right)));
}
int max(int x, int y)
{
	return ((x>y)?x:y);
}
int main()
{
	bs *b;
	initialise(&b);
	int ch,n;
	while(1)
	{
		printf("Enter\n1 to insert\n2 for preorder transversal\n3 for inorder transversal \n4 for postorder transversal\n5 to find the height \n6 to exit \n Enter your choice:");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
			printf("Enter the number:");
			scanf("%d", &n);
			recinsert(&b,n);
			break;
			case 2:
			preorder(b);
			break;
			case 3:
			inorder(b);
			break;
			case 4:
			postorder(b);
			break;
			case 5:
			printf("Height of the tree: %d\n", height(b));
			break;
			case 6:
			exit(0);
			break;
			default:
			printf("Wrong Choice!! Try Again..\n");
			break;
		}
	}
}
