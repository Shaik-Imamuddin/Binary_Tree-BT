import java.util.Scanner;

class Node{
    int data;
    Node left,right;

    Node(int val){
        data=val;
        left=right=null;
    }
}

class BinaryTree{

    Node root;
    Scanner sc = new Scanner(System.in);

    BinaryTree(){
        root=null;
    }

    int idx = 0;

    Node insert(){
        int val = sc.nextInt();

        if (val == -1)
            return null;

        Node node = new Node(val);

        node.left = insert();
        node.right = insert();

        return node;
    }

    void BuildBT(){
        root = insert();
    }

    void inorder(Node root){
        if(root == null)
            return;

        inorder(root.left);
        System.out.print(root.data+" ");
        inorder(root.right);
    }

    void preorder(Node root){
        if(root==null) 
            return;

        System.out.print(root.data+" ");
        preorder(root.left);
        preorder(root.right);
    }

    void postorder(Node root){
        if(root==null)
            return;

        postorder(root.left);
        postorder(root.right);
        System.out.print(root.data+" ");
    }

}

public class Main{
    public static void main(String[] args){

        BinaryTree bt = new BinaryTree();
        bt.BuildBT();

        bt.inorder(bt.root);
        System.out.println();
        bt.preorder(bt.root);
        System.out.println();
        bt.postorder(bt.root);
    }
}