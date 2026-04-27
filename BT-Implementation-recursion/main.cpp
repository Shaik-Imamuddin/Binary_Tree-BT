#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    Node *insert(){
        int val;
        cin >> val;

        if (val==-1)
            return NULL;

        Node *node = new Node(val);

        node->left = insert();
        node->right = insert();

        return node;
    }

    void buildBT() {
        root = insert();
    }

    void inorder(Node *root){
        if (root==NULL)
            return;

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void preorder(Node *root){
        if(root==NULL) 
            return;

        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node *root){
        if (root==NULL) 
            return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
};

int main(){
    BinaryTree bt;
    bt.buildBT();

    bt.inorder(bt.root);
    cout << endl;
    bt.preorder(bt.root);
    cout << endl;
    bt.postorder(bt.root);
    return 0;
}