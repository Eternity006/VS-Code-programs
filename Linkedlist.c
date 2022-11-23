#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
void push(node** head, int n)
{
    node* newnode=malloc(sizeof(node));
    node* cur=(*head);
    node* prv=NULL;
    /*if((*head)==NULL)
    {
        (*head)=newnode;
        return;
    }*/
    newnode->data=n;
    while(cur&&n>cur->data)
    {
        prv=cur;
        cur=cur->next;
    }
    newnode->next=cur;
    if(prv!=NULL)
    {
        prv->next=newnode;
    }
    else{
        (*head)=newnode;
    }
    /*newnode->next=(*head);
    (*head)=newnode;*/
}
/*void insert(node* prevnode, int n)
{
    node* newnode=malloc(sizeof(node));
    if(prevnode==NULL)
    {
        printf("The given node cannot be null");
        return;
    }
    else{
        newnode->data=n;
        newnode->next=prevnode->next;
        prevnode->next=newnode;
    } 
}
void insertback(node** head, int n)
{
    node* newnode=malloc(sizeof(node));
    node* last=(*head);
    newnode->data=n;
    newnode->next=NULL;
    if((*head)==NULL)
    {
        *head=newnode;
        return;
    }
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=newnode;
    return;
}*/
void deletepos(node** head, int pos)
{
    node* temp;
    temp=(*head);
    node* prev;
    prev=(*head);
    for(int i=0; i<pos;i++)
    {
        if(i==0 && pos==1)
        {
            *head=(*head)->next;
            free(temp);
        }
        else{
            if((i==pos-1) && temp)
            {
                prev->next=temp->next;
                free(temp);
            }
        
            else
            {
                prev=temp;
                if(prev==NULL)
                {
                    break;
                }
                temp=temp->next;
            }
        }
    }

}
void delete(node** head, int key)
{
    node* temp;
    node* prv=NULL;
    temp=(*head);
    if(temp!=NULL && temp->data==key)
    {
        *head=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=key)
    {
        prv=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        return;
    }
    prv->next=temp->next;
    free(temp);
}
void print(node* nd)
{
    while(nd!=NULL)
    {
        printf("%d ", nd->data);
        nd=nd->next;
    }
    printf("\n");
}
void main()
{
    node* head=NULL;
    push(&head, 64);
    push(&head, 9);
    push(&head, 7);
    push(&head, 12);
    /*insert(head->next, 8);
    insertback(&head, 4);*/
    printf("Created linkedlist is:");
    print(head);
    printf("Linked list after deleting third element:");
    deletepos(&head, 3);
    print(head);
    printf("Deleting another element from the linkrd list: ");
    delete(&head , 64);
    print(head);
}
