#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

class BinaryTree{
public:
    Node *root;
    Node *queue[100];
    int front,rear;
    BinaryTree(){
        root=nullptr;
        front=0;
        rear=0;
    }

    void insert(int val){
        Node *newNode = new Node(val);

        if(root==nullptr){
            root=newNode;
            queue[rear++]=root;
            return;
        }

        Node *temp = queue[front];

        if(temp->left==nullptr){
            temp->left=newNode;
        }
        else{
            temp->right=newNode;
            front++;
        }
        queue[rear++]=newNode;
    }

    void inorder(Node *root){
        if(root!=nullptr){
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }

    void preorder(Node *root){
        if(root!=nullptr){
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node *root){
        if(root!=nullptr){
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
        }
    }
};


int main(){

    BinaryTree bt;

    int val;
    
    do{
        cin>>val;
        if(val!=-1)
            bt.insert(val);
    }while(val!=-1);

    bt.inorder(bt.root);
    cout<<endl;
    bt.preorder(bt.root);
    cout<<endl;
    bt.postorder(bt.root);

    return 0;
}