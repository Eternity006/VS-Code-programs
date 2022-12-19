#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node
{
	int data;
    struct node *next;
    struct node *prev;
}node;
void create(node **head, int n)
{
	node *newnode,*temp;
	int x,i;
	*head=(node*)malloc(sizeof(node));
	if((*head)==NULL)
	printf("Memory can't be allocated");
	else
	{
		printf("\nEnter the no.=");
		scanf("%d",&x);
		(*head)->data=x;
		(*head)->next=NULL;
		(*head)->prev=NULL;
		temp=(*head);
		for(i=2;i<=n;i++)
		{
			newnode=(node*)malloc(sizeof(node));
			printf("\nEnter the no=");
			scanf("%d",&x);
			newnode->data=x;
			newnode->next=NULL;
			newnode->prev=temp;
			temp->next=newnode;
			temp=newnode;
		}
	}
//	return head;
}

void traverseforward(node *head)
{
	node* temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
}

node* insertatbeg(node* head)
{
	node *beg;
	int x;
	beg=(node*)malloc(sizeof(node));
	printf("\nEnter the no.=");
	scanf("%d",&x);
	beg->data=x;
	beg->next=head;
	beg->prev=NULL;
	head->prev=beg;
	head=beg;
	return head;
}

node* insertatend(node *head)
{
	node *end,*temp;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	int x;
	end=(node*)malloc(sizeof(node));
	printf("\nEnter the no.=");
	scanf("%d",&x);
	end->data=x;
	end->next=NULL;
	end->prev=temp;
	temp->next=end;
	;
	return head;
}

node* insertatsp(node* head)
{
	node *temp,*q,*newnode;
	temp=head;
	int i,pos,x;
	printf("\nEnter the position = ");
	scanf("%d",&pos);
	if(pos==1)
	 insertatbeg(head);
	else
	{
  	for(i=1;i<pos;i++)
	{
		q=temp;
		temp=temp->next;
	}
	newnode=(node*)malloc(sizeof(node));
	printf("\nEnter the no= ");
	scanf("%d",&x);
	newnode->data=x;
	newnode->next=q->next;
	newnode->prev=q;
	temp->prev=newnode;
	q->next=newnode;
  }
  return head;
}

void deleteatbeg(node** head)
{
	node* p;
	p=(*head);
	if(p==NULL)
	{
		printf("Linkedlist is empty!\n");
		return;
	}
	else
	{
		printf("\nDeleted element= %d",p->data);
		*head=(*head)->next;
		free(p);
		printf("\nDeleted successfully!!\n");
	}
//	return head;	
}

node* deleteatend(node* head)
{
	node* p,*q;
	p=head;
	if(p==NULL)
	{
		printf("Linkedlist is empty!\n");
		return;
	}
	else
	{
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
		}
		printf("Deleted element= %d",p->data);
		free(p);
		q->next=NULL;
	}
	return head;
}

node* deleteatsp(node* head)
{
	node* p,*q,*r;
	int i,pos;
	p=head;
	if(p==NULL)
	{
		printf("Linkedlist is empty!\n");
		return;
	}
	else
	{
		printf("\nEnter the position=");
		scanf("%d",&pos);
		if(pos==1)
		deleteatbeg(&head);
		else
		{
		for(i=1;i<pos;i++)
		{
			q=p;
			p=p->next;
		}
		r=p->next;
		printf("\nDeleted element= %d",p->data);
		free(p);
		q->next=r;
		r->prev=q;
	}
	}
	return head;
}

void reverse(node *head)
{
	node* temp;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	while(temp!=NULL)
	{
		printf("%d -> ",temp->data);
		temp=temp->prev;
	}
}

void sort(node** head)
{
   node* current,*temp;
   current=(*head);
   while(current!=NULL)
   {
   	temp=current->next;
   	while(temp!=NULL)
   	{
   	 if(current->data>temp->data)
		{
		 int swap=current->data;
		 current->data=temp->data;
		 temp->data=swap;	
		}
	 temp=temp->next;	
	}
	current=current->next;
   }
   printf("Sorted!!");	
}
void main()
{
	node *head,*temp;
	int ch,n;
	printf("1.Create List\n2.Display\n3.Insert at beginning\n4.Insert at end\n5.Insert at specific\n6.Delete at beginning\n7.Delete at end\n8.Delete at specific\n9.Reverse");
	while(1)
	{
	printf("\nEnter the choice=");
	scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the range=");
				scanf("%d",&n);
				create(&head,n);
				break;
			case 2:
				traverseforward(head);
				break;
			case 3:
				head=insertatbeg(head);
				break;
			case 4:
				head=insertatend(head);
				break;
			case 5:
				head=insertatsp(head);
				break;
			case 6:
				deleteatbeg(&head);
				break;
			case 7:
				head=deleteatend(head);
				break;
			case 8:
				head=deleteatsp(head);
				break;
			case 9:
				reverse(head);
				break;
			case 10:
				sort(&head);
				break;
			default:
				exit(0);
		}
	}
}
