// 3. Circular Queue using Link list.

#include <stdio.h>
#include <stdlib.h>

typedef struct ll{
    int data;
    struct ll *nxt;
}Node;
Node *tail;
void printqueue(Node *tail, Node *np){
    if(np == tail){
        printf("%d\n", np->data);
        return;
	}
	printf("%d ", np->data);
	printqueue(tail, np->nxt);
}

void enqueue(Node **tail, int data){
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->data = data;
    if(*tail == NULL){
        temp->nxt = temp;
        *tail = temp;
        return;
    }
    else{
        temp->nxt = (*tail)->nxt;
        (*tail)->nxt = temp;
        *tail = temp;
        return;
    }
    enqueue(&(*tail)->nxt, data);
}

int dequeue(Node **tail){
    if(*tail == NULL) return -1;
    int data = (*tail)->nxt->data;
    (*tail)->nxt = (*tail)->nxt->nxt;
    return data;
}

int main()
{  
    int ch,data;
    while(1)
    {
        printf("\nEnter 1 for Insert in the Circular Queue\n");
        printf("Enter 2 for Deletion in Circular Queue\n");
        printf("Enter 3 for Display\n");
        printf("Enter your Choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d",&data);
            enqueue(&tail,data);
            break;
            case 2:
            dequeue(&tail);
            printf("Element Deleted!");
            break;
            case 3:
            printqueue(tail, tail->nxt);
            break;
            case 4:
            printf("Program Terminated!");
            exit(1);
            break;
            default:
            printf("Wrong Choice!!\n");
        }
    }
}