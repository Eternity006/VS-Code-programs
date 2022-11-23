#include<stdio.h>
#include<stdlib.h>

 typedef struct linked_list
 {
    int data;
    struct linked_list *nxt;
 }ll;

 void initialisation(ll **head)
 {
    *head=NULL;
 }


 void insertionserial( ll **head, int n)
 {
   ll *t, *prv, *cur;
   t = (ll*) malloc(sizeof(ll));
   t->data=n;
   for (cur=*head, prv=NULL;cur; cur=cur->nxt)
   {
      prv = cur;
   }
   t->nxt=cur;
   if (prv!=NULL)
   {
      prv->nxt=t;
   }
   else
   {
      *head=t;
   }
 }

void insertion_sorted(ll **head, int n)
{
   ll *t,*prv,*cur;
   t = (ll*) malloc(sizeof(ll));
   t->data=n;
   for (cur = *head, prv=NULL; cur && n>cur->data; cur=cur->nxt)
   {
      prv = cur;
   }
   t->nxt = cur;
   if (prv!=NULL)
   {
      prv->nxt=t;
   }
   else
   {
      *head=t;
   }
}


void reverse(ll *head)
{
   if(head->nxt)
   {
      reverse(head->nxt);
   }
   printf("\t", head->data);
}

int count(ll* head)
{
   if(head==NULL)
   {
      return 0;
   }
   else
   {
      return count((head->nxt)+1);
   }
}

void display(ll *head)
{
   while(head!=NULL)
   {
      printf("\t%d", head->data);
      head=head->nxt;
   }
}

void deletion(ll **head, int n)
{
   ll *prv, *cur;
   int found=0;
   for(cur=*head,prv=NULL;cur;cur=cur->nxt)
   {
      if(prv!=NULL && n==cur->data)
      {
         found=1;
         prv->nxt=cur->nxt;
         free(cur);
         return;
      }
      else if(prv==NULL && n==cur->data)
      {
         found=1;
         *head=cur->nxt;
         free(cur);
         return;
      }
      else
      {
         prv=cur;
      }
      if(!found)
      {
         printf("\n Data not found 🙂");
      }
   }
}