#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
}Node;
int max(int a, int b)
{
    return (a>b)?a:b;
}
int height(Node *N)
{
    if (N == NULL)
        return 0;
    return 1+max(height(N->left), height(N->right));
}
Node* newNode(int key)
{
    Node* node=malloc(sizeof(Node));
    node->data=key;
    node->left=NULL;
    node->right=NULL;
    node->height=0;
    return(node);
}
Node* rightRotate(Node *y)
{
    Node *x=y->left;
    Node *T2=x->right;
    x->right=y;
    y->left=T2;
    y->height=height(y);
    x->height=height(x);
    return x;
}
Node* leftRotate(Node *x)
{
    Node *y=x->right;
    Node *T2=y->left;
    y->left=x;
    x->right=T2;
    x->height=height(x);
    y->height=height(y);
    return y;
}
int getBalance(Node *N)
{
    if(N==NULL)
        return 0;
    return height(N->left)-height(N->right);
}
Node* insert(Node *n, int key)
{
    if(n==NULL)
        return (newNode(key));
    if(key<n->data)
        n->left=insert(n->left, key);
    else if(key>n->data)
        n->right=insert(n->right, key);
    else
        return n;
    n->height=height(n);
    int balance=getBalance(n);
    if(balance>1 && key<n->left->data)
        return rightRotate(n);
    if(balance<-1 && key>n->right->data)
        return leftRotate(n);
    if(balance>1 && key>n->left->data)
    {
        n->left=leftRotate(n->left);
        return rightRotate(n);
    }
    if(balance<-1 && key<n->right->data)
    {
        n->right=rightRotate(n->right);
        return leftRotate(n);
    }
    return n;
}
void preorder(Node *root)
{
    if(root!=NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    Node *root=NULL;
    root=insert(root, 10);
    root=insert(root, 20);
    root=insert(root, 30);
    root=insert(root, 40);
    root=insert(root, 50);
    root=insert(root, 25);
    printf("Preorder traversal of the constructed AVL tree is \n");
    preorder(root);
    return 0;
}

 