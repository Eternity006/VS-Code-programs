#include <stdio.h>
#include <stdlib.h>
typedef struct polynomial
{
int coefficient, exp;
struct polynomial * nxt;
}POLYNOMIAL;
void initialize(POLYNOMIAL **head)
{
    *head = NULL;
}
void insert(POLYNOMIAL **aap, int c, int e)
{
    POLYNOMIAL *cur, *prv, *t;
    if (c == 0)
        return;
    for (cur = *aap, prv = NULL; cur && e < cur->exp; cur = cur->nxt)
        prv = cur;
    if (cur && e == cur->exp)
    {
        (cur->coefficient) += c;
        if (cur->coefficient == 0)
        {
            if (prv)
                prv->nxt = cur->nxt;
            else
                *aap = cur->nxt;
            free(cur);
        }
        return;
    }
    t = (POLYNOMIAL *)malloc(sizeof(POLYNOMIAL));
    t->coefficient = c;
    t->exp = e;
    t->nxt = cur;
    if (prv)
        prv->nxt = t;
    else
        *aap = t; 
}
void mul(POLYNOMIAL *ap1, POLYNOMIAL *ap2, POLYNOMIAL **aar)
{
    POLYNOMIAL *cur;
    initialize(aar);
    for (; ap1; ap1 = ap1->nxt)
        for (cur = ap2; cur; cur = cur->nxt)
            insert(aar, (ap1->coefficient) * (cur->coefficient), (ap1->exp) + (cur->exp));
}
void polyadd(POLYNOMIAL * aph1, POLYNOMIAL * aph2, POLYNOMIAL * *aar)
{
    initialize(aar);
    for (; aph1; aph1 = aph1->nxt)
        insert(aar, aph1->coefficient, aph1->exp);
    for (; aph2; aph2 = aph2->nxt)
        insert(aar, aph2->coefficient, aph2->exp);
}
void input(POLYNOMIAL** aah)
{
    int c, e;
    char ans;
    initialize(aah);
    do
    {
        printf("\nEnter the coefficient: ");
        scanf("%d", &c);
        printf("Enter the exponent: ");
        scanf("%d", &e);
        insert(aah, c, e);
        printf("\n Do you want to continue?(Y/N)\n");
        scanf("%*c %c", &ans);
    } while (ans != 'N' && ans != 'n');
}
void display(POLYNOMIAL* ap)
{
    POLYNOMIAL *cur = ap;
    printf("\n\t %d x^%d", cur->coefficient, cur->exp);
    for (cur = ap->nxt; cur; cur = cur->nxt)
    {
        if (cur->coefficient == 0)
            continue;
        else if (cur->coefficient > 0)
            printf("+%d x^%d", cur->coefficient, cur->exp);
        else
            printf("%d x^%d", cur->coefficient, cur->exp);
    }
}
void main()
{
    POLYNOMIAL *L = NULL;
    initialize(&L);
    printf("\nEnter the first polynomial:");
    input(&L);
    printf("\nThe first polynomial is:");
    display(L);
    POLYNOMIAL *L1 = NULL;
    initialize(&L1);
    printf("\nEnter the second polynomial:");
    input(&L1);
    printf("\nThe second polynomial is:");
    display(L1);
    POLYNOMIAL*L2 = NULL;
    initialize(&L2);
    polyadd(L, L1, &L2);
    printf("\nThe added polynomial is:");
    display(L2);
    POLYNOMIAL *L3 = NULL;
    initialize(&L3);
    mul(L, L1, &L3);
    printf("\nThe multiplied polynomial is:");
    display(L3);
}