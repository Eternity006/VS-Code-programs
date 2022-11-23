void deletion(Tree **rp, int data){
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
            return;
        }
    }
    deletion(&(*rp)->left, data);
    deletion(&(*rp)->right, data);
}