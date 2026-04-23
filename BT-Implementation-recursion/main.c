#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left,*right;
};

struct Node *insert(){
    int val;
    scanf("%d",&val);

    if (val==-1)
        return NULL;

    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data=val;
    node->left=insert();
    node->right=insert();

    return node;
}

void inorder(struct Node *root){
    if(root==NULL) 
        return;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct Node *root){
    if(root==NULL)
        return;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root){
    if(root == NULL) 
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main(){
    struct Node *root = insert();

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    return 0;
}