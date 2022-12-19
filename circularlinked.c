#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}node;

void createlist(node **head,node **temp,int n)
{
	int i,x;
	node*newnode;
	*head=(node*)malloc(sizeof(node));
	printf("Enter the no");
	scanf("%d",&x);
	if(*head==NULL)
	 printf("Memory cannot be allocated");
	else
	{
		(*head)->data=x;
		(*head)->next=*head;
		(*temp)=(*head);
		for(i=2;i<=n;i++)
		{
			newnode=(node*)malloc(sizeof(node));
			printf("Enter the no=");
			scanf("%d",&newnode->data);
			newnode->next=*head;
			(*temp)->next=newnode;
			(*temp)=newnode;
		}
	}
}

void traverse(node **head)
{
	node* temp;
	temp=*head;
	while(temp->next!=*head)
	{
		printf("Value=%d, Address=%u\n",temp->data,temp);
		temp=temp->next;
	}
    printf("Value=%d, Address=%u\n",temp->data,temp);
}
void insertatbeg(node **head,node **temp)
{
	node *p;
    if(*head==NULL)
     printf("Insertion not possible");
    else
    {
     p=(node*)malloc(sizeof(node));
     printf("Enter the data=");
     scanf("%d",&p->data);
     p->next=*head;
     *head=p;
     (*temp)->next=p;
    }   
}
void insertatend(node **head,node **temp)
{
  node *end;
  int x;
  if(*head==NULL)
     printf("Insertion not possible");
  else
  {
  end=(node*)malloc(sizeof(node));
  printf("Enter the data");
  scanf("%d",&x);
  end->data=x;
  end->next=*head;
  (*temp)->next=end;
  *temp=end;
  }
}
void insertatspecific(node **head,node **temp)
{
  node *p,*q,*t;
  int x,pos,i;
  t=*head;
  printf("Enter the position=");
  scanf("%d",&pos);
  if(pos==1)
   insertatbeg(&*head,&*temp);
  else
  {
  	for(i=1;i<pos;i++)
  	{
  		p=t;
  		t=t->next;
	}
	q=(node*)malloc(sizeof(node));
	printf("Enter the data=");
    scanf("%d",&x);
	q->data=x;
	q->next=t;
	p->next=q;
  }	
}

void deleteatbeg(node **head,node **temp)
{
	node *p;
	if(*head==NULL)
	 printf("Deletion not possible \n");
	else
	{
	 p=*head;
	 (*temp)->next=p->next;
	 *head=p->next;
	 printf("Deleted element=%d\n",p->data);
	 free(p);	
	}	
}

void deleteatend(node **head,node **temp)
{
	node *p,*q; 
	p=*temp;
	q=*head;
	if(*head==NULL)
		printf("Deletion not possible\n");
	else
	{
		while(q->next!=*temp)
		{
			q=q->next;
		}
		*temp=q;
		q->next=*head;
		printf("Deleted element=%d\n",p->data);
	    free(p);
	}
}

void deleteatsp(node **head,node **temp)
{
	node *p,*q;
	int i,pos;
	p=*head;
	if(*head==NULL)
		printf("Deletion not possible\n");
	else
	{
		printf("\nEnter the position=");
		scanf("%d",&pos);
		if(pos==1)
		 deleteatbeg(&*head,&*temp);
		else
		{
			for(i=1;i<pos;i++)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;
		printf("Deleted element=%d\n",p->data);
	    free(p);
		}
		
	}
}
void main()
{
  node *head,*temp;
  printf("Press 1 for Create\nPress 2 for Display\nPress 3 for Insert at beginning\nPress 4 for Insert at End\nPress 5 for Insert at Specific\nPress 6 for Delete at Beginning\nPress 7 for Delete at End\nPress 8 for Delete at Specific\n");
  int ch,n;
  while(1)//for(;;)
  {
  printf("Enter the Choice = ");
  scanf("%d",&ch);
  switch(ch)
   {
     case 1:
           printf("Enter the Range = ");
           scanf("%d",&n);
           createlist(&head,&temp,n);//calling
           break;
     case 2:
           traverse(&head);//calling
           break;
     case 3:
           insertatbeg(&head,&temp);//calling
           break;
    case 4:
           insertatend(&head,&temp);//calling
           break;
     case 5:
           insertatspecific(&head,&temp);//calling
           break;
    case 6:
           deleteatbeg(&head,&temp);//calling
           break;
    case 7:
           deleteatend(&head,&temp);//calling
           break;
    case 8:
           deleteatsp(&head,&temp);//calling
           break;
     default:
           exit(0);
    }
  }
}
