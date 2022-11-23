#include <stdio.h>
#include <stdlib.h>
typedef struct ll
{
    int data;
    struct ll* next;
}LL;
void insert(LL** head, int n)
{
    LL* newnode=malloc(sizeof(LL));
    newnode->data=n;
    newnode->next=NULL;
    if((*head)==NULL)
    {
        (*head)=newnode;
        return;
    }
    else if(n<(*head)->data)
    {
        newnode->next=(*head);
        (*head)=newnode;
        return;
    }
    insert(&(*head)->next, n);
}
void insert_s(LL** head, int n)
{
    LL* newnode=malloc(sizeof(LL));
    newnode->data=n;
    if((*head)==NULL)
    {
        *head=newnode;
        return;
    }
    newnode->next=(*head);
    (*head)=newnode;
}
void delete(LL** head, int key)
{
    if(*head==NULL)
    {
        printf("\n Empty List");
        return;
    }
    else if((*head)->data==key)
    {
        (*head)=(*head)->next;
        return;
    }
    else{
        delete(&(*head)->next, key);
    }
}
void print(LL* node)
{
    while(node!=NULL)
    {
        printf("%d ", node->data);
        node=node->next;
        if(node!=NULL)
        printf("-->");
    }
    printf("\n");
}
void main()
{
    LL* head=NULL;
    insert_s(&head, 45);
    insert_s(&head, 23);
    insert_s(&head, 65);
    insert_s(&head, 53);
    insert_s(&head, 34);
    print(head);
    delete(&head, 53);
    print(head);
}