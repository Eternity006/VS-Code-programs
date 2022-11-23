#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 100
typedef struct queue
{
    int elements[MAX_QUEUE_SIZE];
    int front,rear;
}QUEUE;
void initialiseQueue(QUEUE *);
int addQueue(int,QUEUE *);
int deleteQueue(int *,QUEUE *);
int isEmptyQueue(QUEUE);
int isOverflow(QUEUE);
int front(QUEUE *);
int rear(QUEUE *);
void initialiseQueue(QUEUE *aq)
{
    aq -> front = -1;
    aq -> rear = -1;
}
int addQueue(int item,QUEUE *aq)
{
    if(aq -> rear == MAX_QUEUE_SIZE -1)
    {
        return 0;
    }
    else
    {
        aq -> elements [++(aq -> rear)]=item;
        printf("\n Data : %d enqueued to the Queue",item);
        return 1;
    }
}

int deleteQueue(int *data,QUEUE *aq)
{
    if(aq -> front == aq -> rear)
    {
        printf("\n Empty Queue....");
        aq -> front = -1;
        aq -> rear = -1;
        data = NULL;
        return 0;
    }
    else
    {
        *data = aq -> elements[++(aq -> front)];
        return 1;
    }
}

int isEmptyQueue(QUEUE q)
{
    return(q.front == q.rear);
}

int isOverflow(QUEUE q)
{
    return(q.rear == MAX_QUEUE_SIZE -1);
}

int front(QUEUE *aq)
{
    if(isEmptyQueue(*aq))
    {
        return INT_MIN;
    }
    int *data;
    *data = aq -> elements[aq -> front];
    return(*data);
}

int rear(QUEUE *aq)
{
    if(isEmptyQueue(*aq))
    {
        return INT_MIN;
    }
    int *data;
    *data = aq -> elements[aq -> rear];
    return(*data);
}

void main()
{
    QUEUE Q;
    int data;
    initialiseQueue(&Q);

    printf("\nImplementation of Queue using Array : - ");

    printf("\n");

    if(isEmptyQueue(Q))
    {
        printf("\n Empty Queue....\n");
    }

    printf("\n Implementation of the Enqueue Operation into the Queue : -\n");

    addQueue(10,&Q);
    addQueue(11,&Q);
    addQueue(12,&Q);
    addQueue(13,&Q);
    addQueue(14,&Q);
    addQueue(15,&Q);
    addQueue(16,&Q);

    printf("\n");

    printf("\n Implementation of the Dequeue Operation into the Queue and side by side printing the front value and rear value : - \n");

    while(deleteQueue(&data,&Q) == 1)
    {
        printf("\n The front element is : %d", front(&Q));
        printf("\n The rear element is : %d", rear(&Q));
        printf("\n Data : %d dequeued from Queue", data);
    }
    printf("\n Empty Queue....");
}