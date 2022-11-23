#include  <stdio.h>
#include <stdlib.h>
typedef struct bs_tree
{
    int data;
    struct bs_tree* left;
    struct bs_tree* right;
}BS_TREE;
void insert(BS_TREE** head, int n)
{
    if(*head==NULL)
    {
        *head =(BS_TREE*) malloc(sizeof(BS_TREE));
        (*head)->data=n;
        (*head)->left=NULL;
        (*head)->right=NULL;
    }
    else if(n<(*head)->data)
    {
        insert(&(*head)->left, n);
    }
    else
    {
        insert(&(*head)->right, n);
    }
}
void preorder(BS_TREE* temp)
{
    if(temp)
    {
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}
void inorder(BS_TREE* temp)
{
    if(temp)
    {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}
void postorder(BS_TREE* temp)
{
    if(temp)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->data);
    }
}
/*int inordersuccessor(BS_TREE** node)
{
    node=&(*node)->right;
    while(1)
    {
        if((*node)->left==NULL && (*node)->right==NULL)
        {
            int data=(*node)->data;
            *node=NULL;
            return data;
        }
        node=&(*node)->left;
    }
}
void delete(BS_TREE** head, int key)
{
    if(*head==NULL)
    {
        printf("Empty Binary tree");
    }
    else if((*head)->data==key)
    {
        if((*head)->left==NULL && (*head)->right==NULL)
        {
            *head=NULL;
        }
        else if((*head)->left!=NULL && (*head)->right==NULL)
        {
            (*head)=(*head)->left;
        }
        else if((*head)->left==NULL && (*head)->right!=NULL)
        {
            (*head)=(*head)->right;
        }
        else if((*head)->left!=NULL && (*head)->right!=NULL)
        {
            (*head)->data=inordersuccessor(head);
        }
    }
    delete(&(*head)->left, key);
    delete(&(*head)->right, key);
}*/
int inorder_successor(BS_TREE **rp){
    rp = &(*rp)->right;
    while(1){
        if((*rp)->left == NULL && (*rp)->right == NULL){
            int data = (*rp)->data;
            *rp = NULL;
            return data;
        }
        rp = &(*rp)->left;
    }
}
void delete(BS_TREE **rp, int data){
    if(*rp == NULL) return;
    else if((*rp)->data == data){
        if((*rp)->left == NULL && (*rp)->right == NULL){
            *rp = NULL;
            return;
        }
        else if((*rp)->left != NULL && (*rp)->right == NULL){
            *rp = (*rp)->left;
            return;
        }
        else if((*rp)->left == NULL && (*rp)->right != NULL){
            *rp = (*rp)->right;
            return;
        }
        else if((*rp)->left != NULL && (*rp)->right != NULL){
            (*rp)->data = inorder_successor(rp);
            return;
        }
    }
    delete(&(*rp)->left, data);
    delete(&(*rp)->right, data);
}

int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    BS_TREE* root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);
  
    printf("Inorder traversal of the given tree \n");
    inorder(root);
  
    printf("\nDelete 20\n");
    delete(&root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
  
    printf("\nDelete 30\n");
    delete(&root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
  
    printf("\nDelete 50\n");
    delete(&root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
  
    return 0;
}