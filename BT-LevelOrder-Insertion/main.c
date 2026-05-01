#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

struct Node *queue[100];
int front =0,rear=0;

void insert(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    if(root==NULL){
        root = newNode;
        queue[rear++] = root;
        return;
    }

    struct Node *temp = queue[front];

    if(temp->left==NULL){
        temp->left=newNode;
    }
    else{
        temp->right=newNode;
        front++;
    }
    queue[rear++]=newNode;
}

void inorder(struct Node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main(){

    int val;
    do{
        scanf("%d",&val);
        if(val!=-1)
            insert(val);
    }while(val!=-1);

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);

    return 0;
}