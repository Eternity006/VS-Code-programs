#include<stdio.h>
#include<stdlib.h>

struct QNode{
	int key;
	struct QNode *next;
};

struct Queue{
	struct QNode *front,*rear;
};

struct QNode *newNode(int k)
{
	struct QNode *temp=(struct QNode *)malloc(sizeof(struct QNode));
	temp->key=k;
	temp->next=NULL;
	return temp;
};

struct Queue *createQueue()
{
	struct Queue *q=(struct Queue *)malloc(sizeof(struct Queue));
	q->front=q->rear=NULL;
	return q;
};

void enQueue(struct Queue *q,int k)
{
	struct QNode *temp=newNode(k);
	if(q->rear==NULL)
	{
		q->front=q->rear=temp;
		return;
	}
	q->rear->next=temp;
	q->rear=temp;
}

void deQueue(struct Queue *q)
{
	if(q->front==NULL)
		return;
	struct QNode *temp=q->front;
	q->front=q->front->next;
	if(q->front==NULL)
		q->rear=NULL;
	free(temp);
}

int main()
{
	struct Queue *q=createQueue();
	int i=0,c,d=0;
	printf("Enter the no of inputs: ");
	scanf("%d",&c);
	for(i=1;i<=c;i++){
		
		printf("Enter the %d element:",i);
		scanf("%d",&d);
		enQueue(q,d);
	}
	
	for(i=1;i<=c;i++)
	{
		printf("Queue Front : %d\n",q->front->key);
		printf("Queue Rear : %d\n",q->rear->key);
		deQueue(q);
	}
	return 0;
}
