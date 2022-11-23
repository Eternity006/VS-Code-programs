#include <stdio.h>
#include <stdlib.h>
typedef struct s_linked_list
{
    int data;
    struct s_linked_list *nxt;
} S_LINKED_LIST;
void initialisation(S_LINKED_LIST **);
void insertion_sorted_order(S_LINKED_LIST **, int);
void display(S_LINKED_LIST *);
void initialisation(S_LINKED_LIST **aa_head)
{
    *aa_head = NULL;
}
void insertion_sorted_order(S_LINKED_LIST **aa_head, int n)
{
    S_LINKED_LIST *t, *prv, *cur;
    t = (S_LINKED_LIST *)malloc(sizeof(S_LINKED_LIST));
    t->data = n;
    for (cur = *aa_head, prv = NULL; cur && n > cur->data; cur = cur->nxt)
        prv = cur;
    t->nxt = cur;
    if (prv != NULL)
        prv->nxt = t;
    else
        *aa_head = t;
}
void display(S_LINKED_LIST *a_head)
{
    for (; a_head; a_head = a_head->nxt)
        printf("\t %d", a_head->data);
}

void search(S_LINKED_LIST *aa_head, int x)
{
    int flag = 0;
    S_LINKED_LIST *cur = aa_head;
    while (cur != NULL)
    {
        if (cur->data == x)
        {
            printf("Present");
            flag = 1;
        }

        cur = cur->nxt;
    }
    if (flag == 0)
    {
        printf("Absent");
    }
}

int main()
{
    S_LINKED_LIST *L = NULL;

    initialisation(&L);
    insertion_sorted_order(&L, 12);
    insertion_sorted_order(&L, 4);
    insertion_sorted_order(&L, 13);
    insertion_sorted_order(&L, 6);
    insertion_sorted_order(&L, 2);
    insertion_sorted_order(&L, 5);
    insertion_sorted_order(&L, 1);
    insertion_sorted_order(&L, 11);
    insertion_sorted_order(&L, 8);
    insertion_sorted_order(&L, 6);
    insertion_sorted_order(&L, 3);
    insertion_sorted_order(&L, 9);
    insertion_sorted_order(&L, 15);
    search(L, 15);
    display(L);
    return 0;
}